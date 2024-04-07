package tree_sitter_proverif_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-proverif"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_proverif.Language())
	if language == nil {
		t.Errorf("Error loading Proverif grammar")
	}
}
