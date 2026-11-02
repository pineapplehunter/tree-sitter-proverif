#include "tree_sitter/parser.h"

#include <wctype.h>

// A comment is emitted as one external token only after all nested delimiters
// have been balanced. No persistent state is needed between tokens.
enum TokenType { BLOCK_COMMENT };

void *tree_sitter_proverif_external_scanner_create(void) { return NULL; }
void tree_sitter_proverif_external_scanner_destroy(void *payload) { (void)payload; }
unsigned tree_sitter_proverif_external_scanner_serialize(void *payload, char *buffer) {
  (void)payload;
  (void)buffer;
  return 0;
}
void tree_sitter_proverif_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  (void)payload;
  (void)buffer;
  (void)length;
}

bool tree_sitter_proverif_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  (void)payload;
  if (!valid_symbols[BLOCK_COMMENT]) return false;
  while (iswspace(lexer->lookahead)) lexer->advance(lexer, true);
  if (lexer->lookahead != '(') return false;
  lexer->advance(lexer, false);
  if (lexer->lookahead != '*') return false;
  lexer->advance(lexer, false);

  unsigned depth = 1;
  while (!lexer->eof(lexer)) {
    if (lexer->lookahead == '(') {
      lexer->advance(lexer, false);
      if (lexer->lookahead == '*') {
        lexer->advance(lexer, false);
        depth++;
      }
    } else if (lexer->lookahead == '*') {
      lexer->advance(lexer, false);
      if (lexer->lookahead == ')') {
        lexer->advance(lexer, false);
        if (--depth == 0) {
          lexer->result_symbol = BLOCK_COMMENT;
          return true;
        }
      }
    } else {
      lexer->advance(lexer, false);
    }
  }
  return false;
}
