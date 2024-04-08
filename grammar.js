/**
 * @file ProVerif grammar for tree-sitter
 * @author Kat Fox <katiewatsonag@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'proverif',

  word: $ => $.identifier,

  rules: {
    // TODO: optional process/equivalence
    source_file: $ => repeat($._declaration),

    _declaration: $ => choice(
      $.type_declaration,
      $.channel_declaration,
      $.free_declaration,
      $.let_declaration,
      // TODO: other declarations
    ),

    type_declaration: $ => seq(
      'type',
      field('name', $.identifier),
      '.'
    ),

    channel_declaration: $ => seq(
      'channel',
      field('names', $.identifier_list),
      '.'
    ),

    free_declaration: $ => seq(
      'free',
      field('names', $.identifier_list),
      ':',
      field('type', $._type_identifier),
      optional(
        field('options', $.reduc_free_options_list),
      ),
      '.'
    ),

    let_declaration: $ => seq(
      'let',
      field('name', $.identifier),
      '(',
      field('params', repeat($.parameter_list)),
      ')',
      '=',
      field('process', $.process),
      '.'
    ),

    parameter_list: $ => commaSep($.parameter_type_declaration),

    parameter_type_declaration: $ => seq(
      field('names', $.identifier_list),
      ':',
      field('type', $._type_identifier),
    ),

    reduc_free_options_list: _ => seq('[', 'private', ']'),

    process: _ => choice(
      '0',
      'yield',
    ),

    _type_identifier: $ => choice($.identifier, 'channel'),

    identifier_list: $ => commaSep($.identifier),

    identifier: _ => /[a-z0-9_']+/,

  }
})

function commaSep(rule) {
  return seq(
    rule,
    repeat(seq(',', rule))
  )
}
