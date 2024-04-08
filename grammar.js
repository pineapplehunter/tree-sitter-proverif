/**
 * @file ProVerif grammar for tree-sitter
 * @author Kat Fox <katiewatsonag@gmail.com>
 * @license MIT
 */

module.exports = grammar({
  name: 'proverif',

  extras: $ => [
    $.comment,
    /\s/
  ],

  word: $ => $.identifier,

  rules: {
    source_file: $ => seq(
      repeat($._declaration),
      optional(
        seq('process', $.process)
      )
    ),

    // https://github.com/tree-sitter/tree-sitter-go/blob/master/grammar.js#L908
    comment: _ => token(seq(
      '(*',
      /[^*]*\*+([^)*][^*]*\*+)*/,
      ')',
    )),

    _declaration: $ => choice(
      $.type_declaration,
      $.channel_declaration,
      $.free_declaration,
      $.let_declaration,
      $.event_declaration,
      $.query_declaration,
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
      optional(field('options', $.option_list)),
      '.',
    ),

    let_declaration: $ => seq(
      'let',
      field('name', $.identifier),
      optional(
        seq(
          field('parameters', $.parameter_list),
        )
      ),
      '=',
      field('process', $.process),
      '.'
    ),

    event_declaration: $ => seq(
      'event',
      field('name', $.identifier),
      optional(
        seq(
          field('parameters', $.type_list),
        )
      ),
      '.'
    ),

    query_declaration: $ => seq(
      'query',
      optional(
        seq(
          sep(',', field('binding', $.type_annotation)),
          ';'
        ),
      ),
      field('query', $.query),
      optional(field('options', $.option_list)),
      '.'
    ),

    type_list: $ => seq(
      '(',
      sep(',', $._type_identifier),
      ')'
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

    option_list: $ => seq(
      '[',
      sep(',', alias(choice(
        'private'
      ), $.identifier)),
      ']'
    ),

    query: $ => sep(';', $._query_term),

    _query_term: $ => choice(
      $.identifier,
      $.predicate_term,
      $.binary_term,
    ),

    predicate_term: $ => seq(
      field('predicate', $.identifier),
      seq(
        '(',
        field('parameter', sep(',', $._query_term)),
        ')'
      )
      // TODO: add the rest
    ),

    binary_term: $ => {
      const table = [
        [9, choice('+', '-')],
        [8, '>'],
        [7, '<'],
        [6, '>='],
        [5, '<='],
        [4, '<>'],
        [3, '='],
        [2, '&&'],
        [1, '||'],
        [0, '==>'],
      ]

      return choice(...table.map(([precedence, operator]) =>
        prec.left(precedence, seq(
          field('left', $._query_term),
          field('operator', operator),
          field('right', $._query_term)
        ))
      ));
    },

    process: $ => sep(';', choice(
      '0',
      'yield',
      $.message_process,
    )),

    message_process: $ => seq(
      field('direction', choice('in', 'out')),
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
