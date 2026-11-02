import assert from "node:assert/strict";
import { readFileSync, readdirSync } from "node:fs";
import { test } from "node:test";
import Parser from "tree-sitter";
import language from "./index.js";

function parser() {
  const parser = new Parser();
  parser.setLanguage(language);
  return parser;
}

test("can parse a typed model", () => {
  const source = readFileSync(new URL("../../test/fixtures/editor.pv", import.meta.url), "utf8");
  const tree = parser().parse(source);
  assert.equal(tree.rootNode.hasError, false, tree.rootNode.toString());
});

test("nested comments survive incremental edits", () => {
  const instance = parser();
  const before = "(* outer comment *)\nfree c: channel.\nprocess out(c, c)";
  const insertion = "(* inner *) ";
  const index = before.indexOf("comment");
  const oldTree = instance.parse(before);
  oldTree.edit({
    startIndex: index,
    oldEndIndex: index,
    newEndIndex: index + insertion.length,
    startPosition: { row: 0, column: index },
    oldEndPosition: { row: 0, column: index },
    newEndPosition: { row: 0, column: index + insertion.length },
  });
  const after = before.slice(0, index) + insertion + before.slice(index);
  const incremental = instance.parse(after, oldTree);
  assert.equal(incremental.rootNode.hasError, false);
  assert.equal(incremental.rootNode.toString(), parser().parse(after).rootNode.toString());
  assert.equal(parser().parse("(* unfinished").rootNode.hasError, true);
});

test("all shipped editor queries compile and match", () => {
  const source = readFileSync(new URL("../../test/fixtures/editor.pv", import.meta.url), "utf8");
  const tree = parser().parse(source);
  const directory = new URL("../../queries/", import.meta.url);
  for (const file of readdirSync(directory).filter(file => file.endsWith(".scm"))) {
    const query = new Parser.Query(language, readFileSync(new URL(file, directory), "utf8"));
    const captures = query.captures(tree.rootNode);
    assert.ok(captures.length > 0, `${file} should capture the fixture`);
    if (file === "highlights.scm") {
      for (const [name, text] of [["comment", "(* A small typed model used to check editor queries. *)"], ["function", "encrypt"], ["function.macro", "sender"]]) {
        assert.ok(captures.some(capture => capture.name === name && capture.node.text === text), `${name}: ${text}`);
      }
    }
  }
});
