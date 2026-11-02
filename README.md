ProVerif's Typed Pi Calculus Grammar for Tree-Sitter
====================================================

This repository contains a [tree-sitter][] grammar for ProVerif's typed pi
calculus. It is a community grammar, not an official ProVerif parser; coverage
is a work in progress. It follows the structure of Appendix A of the ProVerif
2.05 manual. Consult the [current ProVerif manual][] for authoritative syntax.

Helix
-----

A Helix language configuration and queries are provided in
[`examples/helix/languages.toml`](examples/helix/languages.toml) and
[`queries/`](queries/). The sample configuration recognizes `.pv` files and
uses a local checkout so you get these improvements rather than the unchanged
upstream parser. Set `source.path` to this checkout's **absolute** path, then
merge its entries into your existing
`languages.toml` (normally `~/.config/helix/languages.toml`); do not replace
your other language settings. Then fetch and build the grammar:

```sh
hx --grammar fetch
hx --grammar build
```

These commands operate on all configured grammars. To build only ProVerif,
temporarily add `use-grammars = { only = ["proverif"] }` at the top level of
`languages.toml` (before any `[[...]]` sections), then remove it afterward.

If you publish a fork, you can instead use `source.git` and pin `source.rev`
to a commit containing these changes (see the commented example). Put the query
files in Helix's runtime at `queries/proverif/` (for example,
`~/.config/helix/runtime/queries/proverif/`), or set `HELIX_RUNTIME` to a
runtime directory containing that path. Copy `highlights.scm`,
`textobjects.scm`, and `indents.scm` there. Helix's grammar configuration
fetches/compiles the parser; it does not automatically install this repository's
query files. From this repository, install them with:

```sh
mkdir -p ~/.config/helix/runtime/queries/proverif
cp queries/*.scm ~/.config/helix/runtime/queries/proverif/
hx --health proverif
```

Restart Helix after changing the grammar or queries. The parser and all three
query files were checked with Helix 25.07.1.

The supplied queries provide syntax highlights, declaration/process/comment
textobjects, and delimiter-based indentation. No ProVerif language server,
formatter, or semantic name resolution is configured. As grammar coverage
expands, some constructs may parse with errors or have only generic highlighting.

Development
-----------

The parser is generated from `grammar.js`; corpus tests live in `test/corpus/`.
The development dependency pins Tree-sitter CLI **0.27.1**, the latest published
release when this update was made. Generated parsers use ABI 15 for Helix
compatibility. With Node.js and a C compiler available, run:

```sh
npm install
npm run generate
npm test
```

`npm test` checks corpus trees, parses an editor fixture, and compiles every
shipped query. CI also verifies that generated sources are up to date.
`npm run test:bindings` separately tests an installed Node binding.

[tree-sitter]: https://tree-sitter.github.io/
[ProVerif]: https://bblanche.gitlabpages.inria.fr/proverif/
[current ProVerif manual]: https://bblanche.gitlabpages.inria.fr/proverif/manual.pdf
