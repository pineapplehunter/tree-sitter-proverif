ProVerif's Typed Pi Calculus Grammar for Tree-Sitter
====================================================

This repository contains a [tree-sitter][] grammar for the Type Pi Calculus
language used by [ProVerif][].

Note that the author of this grammar is no expert in ProVerif and was writing
this grammar as an exercise to learn the language. There might be obvious
issues in the grammar.

The grammar is following closely the structure of Appendix A
"Language reference" the [ProVerif manual][] in version 2.05: A reference to
each figure containing the grammar specific matching to the grammar
implementation here is given. It should be mostly possible to compare the
language reference with the grammar here side by side.

There are some derivations:

1.  Language constructs are grouped a bit more fine grained. (E.g. while the
    language reference has the `<decl>` entity that matches the `$.decl` rule
    in the tree-sitter grammar, the tree-sitter gramer also has `$.decl_channel`,
    `$.decl_free`, `$.decl_const`, ...).
    -   The main benefit is that this make the grammar a bit easier to navigate
        and writing more targeted queries easy
2.  At some places a recursive definition in the language specification is used
    to define lists / sequences. The tree-sitter grammar here chose to implement
    them with `repeat()` instead of recursion
    -   The motivation is that the generated tree is more balanced.
    -   E.g. the [helix editor][] allows growing/shrinking the selection
        according to the grammar tree and a more balanced tree makes this more
        practical.

[tree-sitter]: https://tree-sitter.github.io/
[ProVerif]: https://bblanche.gitlabpages.inria.fr/proverif/
[ProVerif manual]: https://bblanche.gitlabpages.inria.fr/proverif/manual.pdf
[helix editor]: https://helix-editor.com/
