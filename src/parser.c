#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 48
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 33
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 8

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_type = 2,
  anon_sym_DOT = 3,
  anon_sym_channel = 4,
  anon_sym_free = 5,
  anon_sym_COLON = 6,
  anon_sym_let = 7,
  anon_sym_LPAREN = 8,
  anon_sym_RPAREN = 9,
  anon_sym_EQ = 10,
  anon_sym_COMMA = 11,
  anon_sym_LBRACK = 12,
  anon_sym_private = 13,
  anon_sym_RBRACK = 14,
  anon_sym_0 = 15,
  anon_sym_yield = 16,
  sym_source_file = 17,
  sym__declaration = 18,
  sym_type_declaration = 19,
  sym_channel_declaration = 20,
  sym_free_declaration = 21,
  sym_let_declaration = 22,
  sym_parameter_list = 23,
  sym_parameter_type_declaration = 24,
  sym_reduc_free_options_list = 25,
  sym_process = 26,
  sym__type_identifier = 27,
  sym_identifier_list = 28,
  aux_sym_source_file_repeat1 = 29,
  aux_sym_let_declaration_repeat1 = 30,
  aux_sym_parameter_list_repeat1 = 31,
  aux_sym_identifier_list_repeat1 = 32,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_type] = "type",
  [anon_sym_DOT] = ".",
  [anon_sym_channel] = "channel",
  [anon_sym_free] = "free",
  [anon_sym_COLON] = ":",
  [anon_sym_let] = "let",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_EQ] = "=",
  [anon_sym_COMMA] = ",",
  [anon_sym_LBRACK] = "[",
  [anon_sym_private] = "private",
  [anon_sym_RBRACK] = "]",
  [anon_sym_0] = "0",
  [anon_sym_yield] = "yield",
  [sym_source_file] = "source_file",
  [sym__declaration] = "_declaration",
  [sym_type_declaration] = "type_declaration",
  [sym_channel_declaration] = "channel_declaration",
  [sym_free_declaration] = "free_declaration",
  [sym_let_declaration] = "let_declaration",
  [sym_parameter_list] = "parameter_list",
  [sym_parameter_type_declaration] = "parameter_type_declaration",
  [sym_reduc_free_options_list] = "reduc_free_options_list",
  [sym_process] = "process",
  [sym__type_identifier] = "_type_identifier",
  [sym_identifier_list] = "identifier_list",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_let_declaration_repeat1] = "let_declaration_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym_identifier_list_repeat1] = "identifier_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_channel] = anon_sym_channel,
  [anon_sym_free] = anon_sym_free,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_private] = anon_sym_private,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_0] = anon_sym_0,
  [anon_sym_yield] = anon_sym_yield,
  [sym_source_file] = sym_source_file,
  [sym__declaration] = sym__declaration,
  [sym_type_declaration] = sym_type_declaration,
  [sym_channel_declaration] = sym_channel_declaration,
  [sym_free_declaration] = sym_free_declaration,
  [sym_let_declaration] = sym_let_declaration,
  [sym_parameter_list] = sym_parameter_list,
  [sym_parameter_type_declaration] = sym_parameter_type_declaration,
  [sym_reduc_free_options_list] = sym_reduc_free_options_list,
  [sym_process] = sym_process,
  [sym__type_identifier] = sym__type_identifier,
  [sym_identifier_list] = sym_identifier_list,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_let_declaration_repeat1] = aux_sym_let_declaration_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym_identifier_list_repeat1] = aux_sym_identifier_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_channel] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_free] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_private] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_0] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_yield] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_type_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_channel_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_free_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_let_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_type_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_reduc_free_options_list] = {
    .visible = true,
    .named = true,
  },
  [sym_process] = {
    .visible = true,
    .named = true,
  },
  [sym__type_identifier] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier_list] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_let_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_name = 1,
  field_names = 2,
  field_options = 3,
  field_params = 4,
  field_process = 5,
  field_type = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_names] = "names",
  [field_options] = "options",
  [field_params] = "params",
  [field_process] = "process",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 3},
  [5] = {.index = 7, .length = 2},
  [6] = {.index = 9, .length = 2},
  [7] = {.index = 11, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_names, 1},
  [2] =
    {field_names, 1},
    {field_type, 3},
  [4] =
    {field_names, 1},
    {field_options, 4},
    {field_type, 3},
  [7] =
    {field_names, 0},
    {field_type, 2},
  [9] =
    {field_name, 1},
    {field_process, 5},
  [11] =
    {field_name, 1},
    {field_params, 3},
    {field_process, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '(') ADVANCE(10);
      if (lookahead == ')') ADVANCE(11);
      if (lookahead == ',') ADVANCE(13);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == '0') ADVANCE(17);
      if (lookahead == ':') ADVANCE(9);
      if (lookahead == '=') ADVANCE(12);
      if (lookahead == '[') ADVANCE(14);
      if (lookahead == ']') ADVANCE(15);
      if (lookahead == 'y') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (lookahead == '\'' ||
          ('1' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 1:
      if (lookahead == '0') ADVANCE(16);
      if (lookahead == 'y') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == 'd') ADVANCE(18);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(5);
      END_STATE();
    case 4:
      if (lookahead == 'i') ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == 'l') ADVANCE(2);
      END_STATE();
    case 6:
      if (eof) ADVANCE(7);
      if (lookahead == ')') ADVANCE(11);
      if (lookahead == ',') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6)
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_0);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_0);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_yield);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_yield);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(19);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(23);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(21);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'c') ADVANCE(1);
      if (lookahead == 'f') ADVANCE(2);
      if (lookahead == 'l') ADVANCE(3);
      if (lookahead == 'p') ADVANCE(4);
      if (lookahead == 't') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'h') ADVANCE(6);
      END_STATE();
    case 2:
      if (lookahead == 'r') ADVANCE(7);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 4:
      if (lookahead == 'r') ADVANCE(9);
      END_STATE();
    case 5:
      if (lookahead == 'y') ADVANCE(10);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 10:
      if (lookahead == 'p') ADVANCE(15);
      END_STATE();
    case 11:
      if (lookahead == 'n') ADVANCE(16);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 14:
      if (lookahead == 'v') ADVANCE(18);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_free);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(21);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_channel);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_private);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 6},
  [2] = {.lex_state = 6},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 6},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 6},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 6},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 6},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 6},
  [27] = {.lex_state = 6},
  [28] = {.lex_state = 6},
  [29] = {.lex_state = 6},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 6},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 6},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 6},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 6},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_channel] = ACTIONS(1),
    [anon_sym_free] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_private] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_0] = ACTIONS(1),
    [anon_sym_yield] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(45),
    [sym__declaration] = STATE(2),
    [sym_type_declaration] = STATE(2),
    [sym_channel_declaration] = STATE(2),
    [sym_free_declaration] = STATE(2),
    [sym_let_declaration] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_type] = ACTIONS(5),
    [anon_sym_channel] = ACTIONS(7),
    [anon_sym_free] = ACTIONS(9),
    [anon_sym_let] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(5), 1,
      anon_sym_type,
    ACTIONS(7), 1,
      anon_sym_channel,
    ACTIONS(9), 1,
      anon_sym_free,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    STATE(3), 6,
      sym__declaration,
      sym_type_declaration,
      sym_channel_declaration,
      sym_free_declaration,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
  [24] = 6,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      anon_sym_type,
    ACTIONS(20), 1,
      anon_sym_channel,
    ACTIONS(23), 1,
      anon_sym_free,
    ACTIONS(26), 1,
      anon_sym_let,
    STATE(3), 6,
      sym__declaration,
      sym_type_declaration,
      sym_channel_declaration,
      sym_free_declaration,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
  [48] = 5,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(31), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      sym_parameter_type_declaration,
    STATE(33), 1,
      sym_identifier_list,
    STATE(5), 2,
      sym_parameter_list,
      aux_sym_let_declaration_repeat1,
  [65] = 5,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(36), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      sym_parameter_type_declaration,
    STATE(33), 1,
      sym_identifier_list,
    STATE(5), 2,
      sym_parameter_list,
      aux_sym_let_declaration_repeat1,
  [82] = 5,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(38), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      sym_parameter_type_declaration,
    STATE(33), 1,
      sym_identifier_list,
    STATE(4), 2,
      sym_parameter_list,
      aux_sym_let_declaration_repeat1,
  [99] = 1,
    ACTIONS(40), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [107] = 1,
    ACTIONS(42), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [115] = 1,
    ACTIONS(44), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [123] = 1,
    ACTIONS(46), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [131] = 1,
    ACTIONS(48), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [139] = 1,
    ACTIONS(50), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [147] = 3,
    ACTIONS(54), 1,
      anon_sym_COMMA,
    STATE(15), 1,
      aux_sym_parameter_list_repeat1,
    ACTIONS(52), 2,
      anon_sym_RPAREN,
      sym_identifier,
  [158] = 3,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_identifier_list_repeat1,
    ACTIONS(56), 2,
      anon_sym_DOT,
      anon_sym_COLON,
  [169] = 3,
    ACTIONS(62), 1,
      anon_sym_COMMA,
    STATE(15), 1,
      aux_sym_parameter_list_repeat1,
    ACTIONS(60), 2,
      anon_sym_RPAREN,
      sym_identifier,
  [180] = 3,
    ACTIONS(54), 1,
      anon_sym_COMMA,
    STATE(13), 1,
      aux_sym_parameter_list_repeat1,
    ACTIONS(65), 2,
      anon_sym_RPAREN,
      sym_identifier,
  [191] = 3,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    STATE(17), 1,
      aux_sym_identifier_list_repeat1,
    ACTIONS(67), 2,
      anon_sym_DOT,
      anon_sym_COLON,
  [202] = 3,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    STATE(17), 1,
      aux_sym_identifier_list_repeat1,
    ACTIONS(72), 2,
      anon_sym_DOT,
      anon_sym_COLON,
  [213] = 2,
    STATE(22), 1,
      sym__type_identifier,
    ACTIONS(74), 2,
      anon_sym_channel,
      sym_identifier,
  [221] = 1,
    ACTIONS(67), 3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_COMMA,
  [227] = 2,
    STATE(46), 1,
      sym_process,
    ACTIONS(76), 2,
      anon_sym_0,
      anon_sym_yield,
  [235] = 3,
    ACTIONS(78), 1,
      anon_sym_DOT,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    STATE(32), 1,
      sym_reduc_free_options_list,
  [245] = 2,
    STATE(27), 1,
      sym__type_identifier,
    ACTIONS(82), 2,
      anon_sym_channel,
      sym_identifier,
  [253] = 1,
    ACTIONS(60), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_identifier,
  [259] = 2,
    STATE(39), 1,
      sym_process,
    ACTIONS(76), 2,
      anon_sym_0,
      anon_sym_yield,
  [267] = 3,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(24), 1,
      sym_parameter_type_declaration,
    STATE(33), 1,
      sym_identifier_list,
  [277] = 1,
    ACTIONS(84), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_identifier,
  [283] = 2,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(41), 1,
      sym_identifier_list,
  [290] = 2,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(42), 1,
      sym_identifier_list,
  [297] = 1,
    ACTIONS(86), 1,
      anon_sym_LPAREN,
  [301] = 1,
    ACTIONS(88), 1,
      anon_sym_private,
  [305] = 1,
    ACTIONS(90), 1,
      anon_sym_DOT,
  [309] = 1,
    ACTIONS(92), 1,
      anon_sym_COLON,
  [313] = 1,
    ACTIONS(94), 1,
      anon_sym_EQ,
  [317] = 1,
    ACTIONS(96), 1,
      sym_identifier,
  [321] = 1,
    ACTIONS(98), 1,
      anon_sym_RBRACK,
  [325] = 1,
    ACTIONS(100), 1,
      anon_sym_EQ,
  [329] = 1,
    ACTIONS(102), 1,
      anon_sym_DOT,
  [333] = 1,
    ACTIONS(104), 1,
      anon_sym_DOT,
  [337] = 1,
    ACTIONS(106), 1,
      sym_identifier,
  [341] = 1,
    ACTIONS(108), 1,
      anon_sym_COLON,
  [345] = 1,
    ACTIONS(110), 1,
      anon_sym_DOT,
  [349] = 1,
    ACTIONS(112), 1,
      anon_sym_DOT,
  [353] = 1,
    ACTIONS(114), 1,
      anon_sym_DOT,
  [357] = 1,
    ACTIONS(116), 1,
      ts_builtin_sym_end,
  [361] = 1,
    ACTIONS(118), 1,
      anon_sym_DOT,
  [365] = 1,
    ACTIONS(120), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 65,
  [SMALL_STATE(6)] = 82,
  [SMALL_STATE(7)] = 99,
  [SMALL_STATE(8)] = 107,
  [SMALL_STATE(9)] = 115,
  [SMALL_STATE(10)] = 123,
  [SMALL_STATE(11)] = 131,
  [SMALL_STATE(12)] = 139,
  [SMALL_STATE(13)] = 147,
  [SMALL_STATE(14)] = 158,
  [SMALL_STATE(15)] = 169,
  [SMALL_STATE(16)] = 180,
  [SMALL_STATE(17)] = 191,
  [SMALL_STATE(18)] = 202,
  [SMALL_STATE(19)] = 213,
  [SMALL_STATE(20)] = 221,
  [SMALL_STATE(21)] = 227,
  [SMALL_STATE(22)] = 235,
  [SMALL_STATE(23)] = 245,
  [SMALL_STATE(24)] = 253,
  [SMALL_STATE(25)] = 259,
  [SMALL_STATE(26)] = 267,
  [SMALL_STATE(27)] = 277,
  [SMALL_STATE(28)] = 283,
  [SMALL_STATE(29)] = 290,
  [SMALL_STATE(30)] = 297,
  [SMALL_STATE(31)] = 301,
  [SMALL_STATE(32)] = 305,
  [SMALL_STATE(33)] = 309,
  [SMALL_STATE(34)] = 313,
  [SMALL_STATE(35)] = 317,
  [SMALL_STATE(36)] = 321,
  [SMALL_STATE(37)] = 325,
  [SMALL_STATE(38)] = 329,
  [SMALL_STATE(39)] = 333,
  [SMALL_STATE(40)] = 337,
  [SMALL_STATE(41)] = 341,
  [SMALL_STATE(42)] = 345,
  [SMALL_STATE(43)] = 349,
  [SMALL_STATE(44)] = 353,
  [SMALL_STATE(45)] = 357,
  [SMALL_STATE(46)] = 361,
  [SMALL_STATE(47)] = 365,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(35),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(29),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(28),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(47),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_declaration_repeat1, 2), SHIFT_REPEAT(14),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_let_declaration_repeat1, 2),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_declaration, 3, .production_id = 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 8, .production_id = 7),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_free_declaration, 5, .production_id = 3),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_free_declaration, 6, .production_id = 4),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_channel_declaration, 3, .production_id = 2),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 7, .production_id = 6),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(26),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_list_repeat1, 2),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_list_repeat1, 2), SHIFT_REPEAT(40),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 2),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_type_declaration, 3, .production_id = 5),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_process, 1),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reduc_free_options_list, 3),
  [116] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_proverif() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
