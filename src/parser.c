#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 80
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 41
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 10

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_type = 2,
  anon_sym_DOT = 3,
  anon_sym_channel = 4,
  anon_sym_COMMA = 5,
  anon_sym_free = 6,
  anon_sym_COLON = 7,
  anon_sym_let = 8,
  anon_sym_EQ = 9,
  anon_sym_LPAREN = 10,
  anon_sym_RPAREN = 11,
  anon_sym_LBRACK = 12,
  anon_sym_private = 13,
  anon_sym_RBRACK = 14,
  anon_sym_SEMI = 15,
  anon_sym_0 = 16,
  anon_sym_yield = 17,
  anon_sym_out = 18,
  anon_sym_in = 19,
  sym_source_file = 20,
  sym__declaration = 21,
  sym_type_declaration = 22,
  sym_channel_declaration = 23,
  sym_free_declaration = 24,
  sym_let_declaration = 25,
  sym_parameter_list = 26,
  sym_type_annotation = 27,
  sym__option_list = 28,
  sym_process = 29,
  sym__atomic_process = 30,
  sym_out_process = 31,
  sym_in_process = 32,
  sym__process_term = 33,
  sym__type_identifier = 34,
  aux_sym_source_file_repeat1 = 35,
  aux_sym_channel_declaration_repeat1 = 36,
  aux_sym_free_declaration_repeat1 = 37,
  aux_sym_parameter_list_repeat1 = 38,
  aux_sym__option_list_repeat1 = 39,
  aux_sym_process_repeat1 = 40,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_type] = "type",
  [anon_sym_DOT] = ".",
  [anon_sym_channel] = "channel",
  [anon_sym_COMMA] = ",",
  [anon_sym_free] = "free",
  [anon_sym_COLON] = ":",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_private] = "private",
  [anon_sym_RBRACK] = "]",
  [anon_sym_SEMI] = ";",
  [anon_sym_0] = "0",
  [anon_sym_yield] = "yield",
  [anon_sym_out] = "out",
  [anon_sym_in] = "in",
  [sym_source_file] = "source_file",
  [sym__declaration] = "_declaration",
  [sym_type_declaration] = "type_declaration",
  [sym_channel_declaration] = "channel_declaration",
  [sym_free_declaration] = "free_declaration",
  [sym_let_declaration] = "let_declaration",
  [sym_parameter_list] = "parameter_list",
  [sym_type_annotation] = "type_annotation",
  [sym__option_list] = "_option_list",
  [sym_process] = "process",
  [sym__atomic_process] = "_atomic_process",
  [sym_out_process] = "out_process",
  [sym_in_process] = "in_process",
  [sym__process_term] = "_process_term",
  [sym__type_identifier] = "_type_identifier",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_channel_declaration_repeat1] = "channel_declaration_repeat1",
  [aux_sym_free_declaration_repeat1] = "free_declaration_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym__option_list_repeat1] = "_option_list_repeat1",
  [aux_sym_process_repeat1] = "process_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_channel] = anon_sym_channel,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_free] = anon_sym_free,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_private] = anon_sym_private,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_0] = anon_sym_0,
  [anon_sym_yield] = anon_sym_yield,
  [anon_sym_out] = anon_sym_out,
  [anon_sym_in] = anon_sym_in,
  [sym_source_file] = sym_source_file,
  [sym__declaration] = sym__declaration,
  [sym_type_declaration] = sym_type_declaration,
  [sym_channel_declaration] = sym_channel_declaration,
  [sym_free_declaration] = sym_free_declaration,
  [sym_let_declaration] = sym_let_declaration,
  [sym_parameter_list] = sym_parameter_list,
  [sym_type_annotation] = sym_type_annotation,
  [sym__option_list] = sym__option_list,
  [sym_process] = sym_process,
  [sym__atomic_process] = sym__atomic_process,
  [sym_out_process] = sym_out_process,
  [sym_in_process] = sym_in_process,
  [sym__process_term] = sym__process_term,
  [sym__type_identifier] = sym__type_identifier,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_channel_declaration_repeat1] = aux_sym_channel_declaration_repeat1,
  [aux_sym_free_declaration_repeat1] = aux_sym_free_declaration_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym__option_list_repeat1] = aux_sym__option_list_repeat1,
  [aux_sym_process_repeat1] = aux_sym_process_repeat1,
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
  [anon_sym_COMMA] = {
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
  [anon_sym_EQ] = {
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
  [anon_sym_SEMI] = {
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
  [anon_sym_out] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
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
  [sym_type_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym__option_list] = {
    .visible = false,
    .named = true,
  },
  [sym_process] = {
    .visible = true,
    .named = true,
  },
  [sym__atomic_process] = {
    .visible = false,
    .named = true,
  },
  [sym_out_process] = {
    .visible = true,
    .named = true,
  },
  [sym_in_process] = {
    .visible = true,
    .named = true,
  },
  [sym__process_term] = {
    .visible = false,
    .named = true,
  },
  [sym__type_identifier] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_channel_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_free_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__option_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_process_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_channel = 1,
  field_message = 2,
  field_name = 3,
  field_parameters = 4,
  field_process = 5,
  field_type = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_channel] = "channel",
  [field_message] = "message",
  [field_name] = "name",
  [field_parameters] = "parameters",
  [field_process] = "process",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 3},
  [6] = {.index = 10, .length = 2},
  [7] = {.index = 12, .length = 3},
  [8] = {.index = 15, .length = 3},
  [9] = {.index = 18, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 0, .inherited = true},
    {field_name, 1, .inherited = true},
  [3] =
    {field_name, 1},
    {field_type, 3},
  [5] =
    {field_name, 1},
    {field_process, 3},
  [7] =
    {field_name, 1},
    {field_name, 2, .inherited = true},
    {field_type, 4},
  [10] =
    {field_name, 0},
    {field_type, 2},
  [12] =
    {field_name, 1},
    {field_parameters, 2},
    {field_process, 4},
  [15] =
    {field_name, 0},
    {field_name, 1, .inherited = true},
    {field_type, 3},
  [18] =
    {field_channel, 2},
    {field_message, 4},
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
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == '(') ADVANCE(15);
      if (lookahead == ')') ADVANCE(16);
      if (lookahead == ',') ADVANCE(12);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == '0') ADVANCE(21);
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == ';') ADVANCE(19);
      if (lookahead == '=') ADVANCE(14);
      if (lookahead == '[') ADVANCE(17);
      if (lookahead == ']') ADVANCE(18);
      if (lookahead == 'i') ADVANCE(32);
      if (lookahead == 'o') ADVANCE(34);
      if (lookahead == 'y') ADVANCE(30);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (lookahead == '\'' ||
          ('1' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 1:
      if (lookahead == '0') ADVANCE(20);
      if (lookahead == 'i') ADVANCE(6);
      if (lookahead == 'o') ADVANCE(8);
      if (lookahead == 'y') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == 'd') ADVANCE(22);
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
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 7:
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == 'u') ADVANCE(7);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9)
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_0);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_0);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_yield);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_yield);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_out);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(23);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(31);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(29);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(28);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(27);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(25);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(33);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
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
  [1] = {.lex_state = 9},
  [2] = {.lex_state = 9},
  [3] = {.lex_state = 9},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 9},
  [8] = {.lex_state = 9},
  [9] = {.lex_state = 9},
  [10] = {.lex_state = 9},
  [11] = {.lex_state = 9},
  [12] = {.lex_state = 9},
  [13] = {.lex_state = 9},
  [14] = {.lex_state = 9},
  [15] = {.lex_state = 9},
  [16] = {.lex_state = 9},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 9},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 9},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 9},
  [41] = {.lex_state = 9},
  [42] = {.lex_state = 9},
  [43] = {.lex_state = 9},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 9},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 9},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 9},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 9},
  [66] = {.lex_state = 9},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 9},
  [69] = {.lex_state = 9},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 9},
  [72] = {.lex_state = 9},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 9},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_channel] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_free] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_private] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_0] = ACTIONS(1),
    [anon_sym_yield] = ACTIONS(1),
    [anon_sym_out] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(62),
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
    ACTIONS(31), 1,
      anon_sym_out,
    ACTIONS(33), 1,
      anon_sym_in,
    STATE(73), 1,
      sym_process,
    ACTIONS(29), 2,
      anon_sym_0,
      anon_sym_yield,
    STATE(33), 3,
      sym__atomic_process,
      sym_out_process,
      sym_in_process,
  [67] = 5,
    ACTIONS(31), 1,
      anon_sym_out,
    ACTIONS(33), 1,
      anon_sym_in,
    STATE(58), 1,
      sym_process,
    ACTIONS(29), 2,
      anon_sym_0,
      anon_sym_yield,
    STATE(33), 3,
      sym__atomic_process,
      sym_out_process,
      sym_in_process,
  [86] = 4,
    ACTIONS(31), 1,
      anon_sym_out,
    ACTIONS(33), 1,
      anon_sym_in,
    ACTIONS(35), 2,
      anon_sym_0,
      anon_sym_yield,
    STATE(51), 3,
      sym__atomic_process,
      sym_out_process,
      sym_in_process,
  [102] = 1,
    ACTIONS(37), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [110] = 1,
    ACTIONS(39), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [118] = 1,
    ACTIONS(41), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [126] = 1,
    ACTIONS(43), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [134] = 1,
    ACTIONS(45), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [142] = 1,
    ACTIONS(47), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [150] = 1,
    ACTIONS(49), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [158] = 1,
    ACTIONS(51), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [166] = 1,
    ACTIONS(53), 5,
      ts_builtin_sym_end,
      anon_sym_type,
      anon_sym_channel,
      anon_sym_free,
      anon_sym_let,
  [174] = 2,
    STATE(44), 1,
      sym__type_identifier,
    ACTIONS(55), 2,
      anon_sym_channel,
      sym_identifier,
  [182] = 3,
    ACTIONS(57), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_channel_declaration_repeat1,
  [192] = 3,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    ACTIONS(61), 1,
      anon_sym_DOT,
    STATE(25), 1,
      aux_sym_channel_declaration_repeat1,
  [202] = 3,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(65), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      aux_sym_process_repeat1,
  [212] = 2,
    STATE(27), 1,
      sym__type_identifier,
    ACTIONS(68), 2,
      anon_sym_channel,
      sym_identifier,
  [220] = 3,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(72), 1,
      anon_sym_COLON,
    STATE(29), 1,
      aux_sym_free_declaration_repeat1,
  [230] = 3,
    ACTIONS(74), 1,
      anon_sym_COMMA,
    ACTIONS(76), 1,
      anon_sym_RBRACK,
    STATE(39), 1,
      aux_sym__option_list_repeat1,
  [240] = 3,
    ACTIONS(78), 1,
      anon_sym_COMMA,
    ACTIONS(80), 1,
      anon_sym_RPAREN,
    STATE(32), 1,
      aux_sym_parameter_list_repeat1,
  [250] = 3,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(82), 1,
      anon_sym_COLON,
    STATE(29), 1,
      aux_sym_free_declaration_repeat1,
  [260] = 3,
    ACTIONS(84), 1,
      anon_sym_DOT,
    ACTIONS(86), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_channel_declaration_repeat1,
  [270] = 2,
    STATE(53), 1,
      sym__type_identifier,
    ACTIONS(89), 2,
      anon_sym_channel,
      sym_identifier,
  [278] = 3,
    ACTIONS(91), 1,
      anon_sym_DOT,
    ACTIONS(93), 1,
      anon_sym_LBRACK,
    STATE(70), 1,
      sym__option_list,
  [288] = 2,
    STATE(38), 1,
      sym__type_identifier,
    ACTIONS(95), 2,
      anon_sym_channel,
      sym_identifier,
  [296] = 3,
    ACTIONS(97), 1,
      anon_sym_COMMA,
    ACTIONS(100), 1,
      anon_sym_COLON,
    STATE(29), 1,
      aux_sym_free_declaration_repeat1,
  [306] = 3,
    ACTIONS(102), 1,
      anon_sym_COMMA,
    ACTIONS(105), 1,
      anon_sym_RBRACK,
    STATE(30), 1,
      aux_sym__option_list_repeat1,
  [316] = 3,
    ACTIONS(107), 1,
      anon_sym_DOT,
    ACTIONS(109), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      aux_sym_process_repeat1,
  [326] = 3,
    ACTIONS(111), 1,
      anon_sym_COMMA,
    ACTIONS(114), 1,
      anon_sym_RPAREN,
    STATE(32), 1,
      aux_sym_parameter_list_repeat1,
  [336] = 3,
    ACTIONS(109), 1,
      anon_sym_SEMI,
    ACTIONS(116), 1,
      anon_sym_DOT,
    STATE(31), 1,
      aux_sym_process_repeat1,
  [346] = 3,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(118), 1,
      anon_sym_COLON,
    STATE(24), 1,
      aux_sym_free_declaration_repeat1,
  [356] = 3,
    ACTIONS(78), 1,
      anon_sym_COMMA,
    ACTIONS(120), 1,
      anon_sym_RPAREN,
    STATE(23), 1,
      aux_sym_parameter_list_repeat1,
  [366] = 3,
    ACTIONS(70), 1,
      anon_sym_COMMA,
    ACTIONS(122), 1,
      anon_sym_COLON,
    STATE(21), 1,
      aux_sym_free_declaration_repeat1,
  [376] = 3,
    ACTIONS(124), 1,
      anon_sym_EQ,
    ACTIONS(126), 1,
      anon_sym_LPAREN,
    STATE(79), 1,
      sym_parameter_list,
  [386] = 3,
    ACTIONS(93), 1,
      anon_sym_LBRACK,
    ACTIONS(128), 1,
      anon_sym_DOT,
    STATE(64), 1,
      sym__option_list,
  [396] = 3,
    ACTIONS(74), 1,
      anon_sym_COMMA,
    ACTIONS(130), 1,
      anon_sym_RBRACK,
    STATE(30), 1,
      aux_sym__option_list_repeat1,
  [406] = 2,
    ACTIONS(132), 1,
      sym_identifier,
    STATE(76), 1,
      sym__process_term,
  [413] = 2,
    ACTIONS(134), 1,
      sym_identifier,
    STATE(56), 1,
      sym__process_term,
  [420] = 2,
    ACTIONS(136), 1,
      sym_identifier,
    STATE(57), 1,
      sym__process_term,
  [427] = 2,
    ACTIONS(138), 1,
      sym_identifier,
    STATE(77), 1,
      sym__process_term,
  [434] = 1,
    ACTIONS(140), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [439] = 1,
    ACTIONS(105), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [444] = 1,
    ACTIONS(142), 2,
      anon_sym_COMMA,
      anon_sym_COLON,
  [449] = 1,
    ACTIONS(84), 2,
      anon_sym_DOT,
      anon_sym_COMMA,
  [454] = 2,
    ACTIONS(144), 1,
      sym_identifier,
    STATE(54), 1,
      sym_type_annotation,
  [461] = 1,
    ACTIONS(146), 2,
      anon_sym_DOT,
      anon_sym_SEMI,
  [466] = 2,
    ACTIONS(144), 1,
      sym_identifier,
    STATE(35), 1,
      sym_type_annotation,
  [473] = 1,
    ACTIONS(63), 2,
      anon_sym_DOT,
      anon_sym_SEMI,
  [478] = 1,
    ACTIONS(148), 2,
      anon_sym_DOT,
      anon_sym_SEMI,
  [483] = 1,
    ACTIONS(150), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [488] = 1,
    ACTIONS(114), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [493] = 1,
    ACTIONS(152), 1,
      anon_sym_LPAREN,
  [497] = 1,
    ACTIONS(154), 1,
      anon_sym_COMMA,
  [501] = 1,
    ACTIONS(156), 1,
      anon_sym_COMMA,
  [505] = 1,
    ACTIONS(158), 1,
      anon_sym_DOT,
  [509] = 1,
    ACTIONS(160), 1,
      anon_sym_EQ,
  [513] = 1,
    ACTIONS(162), 1,
      anon_sym_DOT,
  [517] = 1,
    ACTIONS(164), 1,
      sym_identifier,
  [521] = 1,
    ACTIONS(166), 1,
      ts_builtin_sym_end,
  [525] = 1,
    ACTIONS(168), 1,
      anon_sym_EQ,
  [529] = 1,
    ACTIONS(170), 1,
      anon_sym_DOT,
  [533] = 1,
    ACTIONS(172), 1,
      sym_identifier,
  [537] = 1,
    ACTIONS(174), 1,
      anon_sym_private,
  [541] = 1,
    ACTIONS(176), 1,
      anon_sym_DOT,
  [545] = 1,
    ACTIONS(178), 1,
      sym_identifier,
  [549] = 1,
    ACTIONS(180), 1,
      sym_identifier,
  [553] = 1,
    ACTIONS(182), 1,
      anon_sym_DOT,
  [557] = 1,
    ACTIONS(184), 1,
      anon_sym_private,
  [561] = 1,
    ACTIONS(186), 1,
      sym_identifier,
  [565] = 1,
    ACTIONS(188), 1,
      anon_sym_DOT,
  [569] = 1,
    ACTIONS(190), 1,
      anon_sym_DOT,
  [573] = 1,
    ACTIONS(192), 1,
      sym_identifier,
  [577] = 1,
    ACTIONS(194), 1,
      anon_sym_RPAREN,
  [581] = 1,
    ACTIONS(196), 1,
      anon_sym_RPAREN,
  [585] = 1,
    ACTIONS(198), 1,
      anon_sym_LPAREN,
  [589] = 1,
    ACTIONS(200), 1,
      anon_sym_EQ,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 67,
  [SMALL_STATE(6)] = 86,
  [SMALL_STATE(7)] = 102,
  [SMALL_STATE(8)] = 110,
  [SMALL_STATE(9)] = 118,
  [SMALL_STATE(10)] = 126,
  [SMALL_STATE(11)] = 134,
  [SMALL_STATE(12)] = 142,
  [SMALL_STATE(13)] = 150,
  [SMALL_STATE(14)] = 158,
  [SMALL_STATE(15)] = 166,
  [SMALL_STATE(16)] = 174,
  [SMALL_STATE(17)] = 182,
  [SMALL_STATE(18)] = 192,
  [SMALL_STATE(19)] = 202,
  [SMALL_STATE(20)] = 212,
  [SMALL_STATE(21)] = 220,
  [SMALL_STATE(22)] = 230,
  [SMALL_STATE(23)] = 240,
  [SMALL_STATE(24)] = 250,
  [SMALL_STATE(25)] = 260,
  [SMALL_STATE(26)] = 270,
  [SMALL_STATE(27)] = 278,
  [SMALL_STATE(28)] = 288,
  [SMALL_STATE(29)] = 296,
  [SMALL_STATE(30)] = 306,
  [SMALL_STATE(31)] = 316,
  [SMALL_STATE(32)] = 326,
  [SMALL_STATE(33)] = 336,
  [SMALL_STATE(34)] = 346,
  [SMALL_STATE(35)] = 356,
  [SMALL_STATE(36)] = 366,
  [SMALL_STATE(37)] = 376,
  [SMALL_STATE(38)] = 386,
  [SMALL_STATE(39)] = 396,
  [SMALL_STATE(40)] = 406,
  [SMALL_STATE(41)] = 413,
  [SMALL_STATE(42)] = 420,
  [SMALL_STATE(43)] = 427,
  [SMALL_STATE(44)] = 434,
  [SMALL_STATE(45)] = 439,
  [SMALL_STATE(46)] = 444,
  [SMALL_STATE(47)] = 449,
  [SMALL_STATE(48)] = 454,
  [SMALL_STATE(49)] = 461,
  [SMALL_STATE(50)] = 466,
  [SMALL_STATE(51)] = 473,
  [SMALL_STATE(52)] = 478,
  [SMALL_STATE(53)] = 483,
  [SMALL_STATE(54)] = 488,
  [SMALL_STATE(55)] = 493,
  [SMALL_STATE(56)] = 497,
  [SMALL_STATE(57)] = 501,
  [SMALL_STATE(58)] = 505,
  [SMALL_STATE(59)] = 509,
  [SMALL_STATE(60)] = 513,
  [SMALL_STATE(61)] = 517,
  [SMALL_STATE(62)] = 521,
  [SMALL_STATE(63)] = 525,
  [SMALL_STATE(64)] = 529,
  [SMALL_STATE(65)] = 533,
  [SMALL_STATE(66)] = 537,
  [SMALL_STATE(67)] = 541,
  [SMALL_STATE(68)] = 545,
  [SMALL_STATE(69)] = 549,
  [SMALL_STATE(70)] = 553,
  [SMALL_STATE(71)] = 557,
  [SMALL_STATE(72)] = 561,
  [SMALL_STATE(73)] = 565,
  [SMALL_STATE(74)] = 569,
  [SMALL_STATE(75)] = 573,
  [SMALL_STATE(76)] = 577,
  [SMALL_STATE(77)] = 581,
  [SMALL_STATE(78)] = 585,
  [SMALL_STATE(79)] = 589,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(72),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(69),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(65),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(61),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_free_declaration, 7, .production_id = 5),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 6, .production_id = 7),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_free_declaration, 6, .production_id = 5),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_free_declaration, 6, .production_id = 3),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 5, .production_id = 4),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_free_declaration, 5, .production_id = 3),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_declaration, 3, .production_id = 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_channel_declaration, 3),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_channel_declaration, 4),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_process_repeat1, 2),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_process_repeat1, 2), SHIFT_REPEAT(6),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_channel_declaration_repeat1, 2),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_channel_declaration_repeat1, 2), SHIFT_REPEAT(75),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_free_declaration_repeat1, 2, .production_id = 2), SHIFT_REPEAT(68),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_free_declaration_repeat1, 2, .production_id = 2),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__option_list_repeat1, 2), SHIFT_REPEAT(66),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__option_list_repeat1, 2),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_process, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(48),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_process, 1),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 4, .production_id = 8),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_free_declaration_repeat1, 2, .production_id = 1),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_out_process, 6, .production_id = 9),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_process, 6, .production_id = 9),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 3, .production_id = 6),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [166] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__option_list, 3),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__option_list, 4),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
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
