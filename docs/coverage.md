# Coverage and design notes

## Target and evidence

This grammar targets **ProVerif 2.05's typed pi calculus**, including `.pv`
models and `.pvl` libraries. The official release currently offered by the
[ProVerif installation page](https://bblanche.gitlabpages.inria.fr/proverif/install.html)
is 2.05. Its `src/pitparser.mly` and `src/pitlexer.mll` are the implementation
reference; Appendix A of the [manual](https://bblanche.gitlabpages.inria.fr/proverif/manual.pdf)
is the language reference.

All **100 non-m4 `.pv` files** under that release's `examples/pitype/` parse
without ERROR or MISSING nodes. The six `.m4.pv` templates are excluded: m4
input needs preprocessing before it is ProVerif source. These counts measure
example coverage, **not complete language coverage or semantic correctness**.
The original declaration-only corpus already covered many ordinary examples;
the new tests target gaps that those examples did not expose.

To reproduce the example check after downloading/extracting the official
release yourself:

```sh
npm run generate
npm run test:examples -- /path/to/proverif2.05/examples/pitype
```

No third-party example archive is vendored. The check recursively visits `.pv`
files, excludes `.m4.pv`, prints failures, and exits nonzero on any parse error.

## Covered areas

- Typed names, constants, types, functions, equations, reductions, predicates,
  tables, events, process/function macros (including empty argument lists).
- Reduction variables with `or fail`, failed terms, `otherwise` inside function
  reductions, equation-local `let` and assignment syntax, projection names.
- Numeric/tuple terms, `choice`/`diff`, arithmetic, comparisons, Boolean
  operators, and operator ordering based on the official parser directives.
- Correspondence/secrecy queries, event and table facts, phases, public
  variables, lemmas/axioms/restrictions, noninterference, selection directives.
- Input/output, restrictions, patterns (including wildcard and typed choices),
  parallel composition, replication, tests, let/get/insert, events, phases,
  barriers, and CryptoVerif-compatible bounded replication/foreach.
- Nested block comments, ordinary declaration options and option parameters.

The parser deliberately tolerates some nonstandard/semantically invalid input
for editing. In particular, legacy `#` line comments are retained from the
original grammar, but **ProVerif itself uses `(* ... *)` comments**. The Helix
configuration therefore uses block-comment commands, not `#` comments.

## Remaining limitations

- No untyped pi-calculus or Horn-clause *input language* support (typed
  `clauses` declarations are supported).
- `def` macro bodies and CryptoVerif probability/proof bodies are opaque,
  rather than fully structured trees. In particular, nested `def` bodies are
  not balanced by the current opaque-body rule. `def`/`expand` are meaningful
  ProVerif macros, not ignored proof scripts.
- CryptoVerif `implementation` annotations and its full probability/proof
  languages are not implemented. Sharing some syntax does not make this a
  CryptoVerif grammar.
- No m4 preprocessing, type checking, name resolution, or protocol verification.
  Run ProVerif itself for those checks.
- Helix indentation is delimiter-based, not a complete process-layout engine.
  Highlighting is syntactic; it cannot classify every identifier semantically.

## Design choices

- Keep named nodes and fields for editor queries rather than expose only a
  direct transcription of the manual's broad productions.
- Use explicit precedence, as mature grammars such as
  [tree-sitter-rust](https://github.com/tree-sitter/tree-sitter-rust/blob/master/grammar.js)
  do, but take the actual ordering/associativity from ProVerif, not Rust.
- Scan nested comments externally, following the approach used by
  [tree-sitter-ocaml](https://github.com/tree-sitter/tree-sitter-ocaml).
  The scanner is stateless between complete comment tokens; binding tests
  compare incremental edits inside a comment with a fresh parse.
- Keep Tree-sitter CLI pinned to **0.27.1** (latest npm release checked for this
  update), with generated **ABI 15**, which Helix 25.07.1 accepts. Node's runtime
  binding is on the separately versioned 0.25.1 release line.
