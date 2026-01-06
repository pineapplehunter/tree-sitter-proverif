package tree_sitter_proverif_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_proverif "codeberg.org/maribu/tree-sitter-proverif/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_proverif.Language())
	if language == nil {
		t.Errorf("Error loading ProVerif grammar")
	}
}
