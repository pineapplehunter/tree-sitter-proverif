/**
 * @file ProVerif grammar for tree-sitter
 * @author Kat Fox <katiewatsonag@gmail.com>
 * @license MIT
 */

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
      sep(',', $.identifier),
      '.'
    ),

    free_declaration: $ => seq(
      'free',
      sep(',', field('name', $.identifier)),
      ':',
      field('type', $._type_identifier),
      optional($._option_list),
      '.',
    ),

    let_declaration: $ => seq(
      'let',
      field('name', $.identifier),
      optional(
        field('parameters', $.parameter_list),
      ),
      '=',
      field('process', $.process),
      '.'
    ),

    parameter_list: $ => seq(
      '(',
      sep(',', $.type_annotation),
      ')'
    ),

    type_annotation: $ => seq(
      sep(',', field('name', $.identifier)),
      ':',
      field('type', $._type_identifier)
    ),

    _option_list: _ => seq(
      '[',
      sep(',', choice(
        'private'
      )),
      ']'
    ),

    process: $ => sep(';', $._atomic_process),

    _atomic_process: $ => choice(
      '0',
      'yield',
      $.out_process,
      $.in_process,
    ),

    out_process: $ => seq(
      'out',
      '(',
      field('channel', $._process_term),
      ',',
      field('message', $._process_term),
      ')'
    ),

    in_process: $ => seq(
      'in',
      '(',
      field('channel', $._process_term),
      ',',
      field('message', $._process_term),
      ')'
    ),

    _process_term: $ => choice($.identifier),

    _type_identifier: $ => choice($.identifier, 'channel'),

    identifier: _ => /[a-zA-Z0-9_']+/,
  }
})

function sep(separator, rule) {
  return seq(
    rule,
    repeat(seq(separator, rule))
  )
}
