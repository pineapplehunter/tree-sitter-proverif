/**
 * @file ProVerif's typed pi calculus grammar for tree-sitter
 * @author Marian Buschsieweke <marian.buschsieweke@posteo.net>
 * @license 0BSD
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// Helper for what is seq+() and seq() in the appendix
const _seq1 = (separator, rule) => seq(rule, repeat(seq(separator, rule)));
const _seq = (separator, rule) => optional(_seq1(separator, rule));

export default grammar({
  name: "proverif",

  extras: $ => [
    /\s|\\\r?\n/,
    $.comment,
  ],

  externals: $ => [$._block_comment],

  conflicts: $ => [
    [$._query],
    [$._typedecl, $.gterm],
    [$._typedecl, $.nidecl],
    [$.gterm],
    [$.infix, $.equality],
    [$.pattern],
    [$.process],
    [$.process_function_call, $.process_final_item],
    [$.process_get],
    [$.process_item, $.process_replication],
    [$.process_item],
    [$.process_let],
    [$.process_replication, $.process],
    [$.process_replication, $.process_foreach],
    [$.process_replication, $.process_get],
    [$.process_replication, $.process_let],
    [$.process_replication],
    [$.pterm, $.pterm_function_call],
    [$.pterm],
    [$.term],
  ],
  reserved: {
    global: $ => [
      'among',
      'axiom',
      'channel',
      'choice',
      'clauses',
      'const',
      'def',
      'diff',
      'do',
      'elimtrue',
      'else',
      'equation',
      'equivalence',
      'event',
      'expand',
      'fail',
      'forall',
      'foreach',
      'free',
      'fun',
      'get',
      'if',
      'in',
      'inj-event',
      'insert',
      'lemma',
      'let',
      'letfun',
      'letproba',
      'new',
      'noninterf',
      'noselect',
      'not',
      'nounif',
      'otherwise',
      'or',
      'out',
      'param',
      'phase',
      'pred',
      'proba',
      'process',
      'proof',
      'public_vars',
      'putbegin',
      'query',
      'reduc',
      'restriction',
      'secret',
      'select',
      'set',
      'suchthat',
      'sync',
      'table',
      'then',
      'type',
      'weaksecret',
      'yield'
    ]
  },
  word: $ => $.ident,
  rules: {
    source_file: $ => seq(
      repeat($.decl),
      optional(choice(
        seq('process', $.process),
        seq('equivalence', $.process, $.process)
      ))
    ),

    // Keep a stable comment node for both line and nested block comments.
    comment: $ => choice(
      token(seq('#', /.*/)),
      $._block_comment,
    ),

    _binding: $ => choice(
      seq('!', $.nat, '=', $.gformat),
      seq($.ident, '=', $.gformat),
    ),
    binding: $ => _seq1(';', $._binding),

    // From Appendix A in the manual
    // '-' is an operator, never part of an ordinary identifier (x-1).
    ident: $ => token(/[A-Za-z_][A-Za-z0-9_\u00C0-\u00D6\u00D8-\u00F6\u00F8-\u00FF']*/),
    projection: $ => token(/[0-9]+-proj-[A-Za-z0-9][A-Za-z0-9_\u00C0-\u00D6\u00D8-\u00F6\u00F8-\u00FF'-]*/),
    _choice: $ => choice('choice', 'diff'),
    nat: $ => /\d+/,
    int: $ => /-?\d+/,
    typeid: $ => choice(
      $.ident,
      'channel',
    ),
    option: $ => choice(
      'data',
      'private',
      'typeConverter',
      'memberOptim',
      'precise',
      'nonSat',
      'discardSat',
      'instantiateSat',
      'fullSat',
      'nonVerif',
      'discardVerif',
      'instantiateVerif',
      'fullVerif',
      'induction',
      'noInduction',
      'maxSubset',
      'proveAll',
      'reachability',
      'pv_reachability',
      'real_or_random',
      'pv_real_or_random',
      'bounded',
      'fixed',
      'large',
      seq($.ident, optional(seq('=', choice(
        $.ident,
        seq('{', _seq1(',', $.ident), '}'),
      )))),
    ),
    options: $ => seq('[', _seq1(',', $.option), ']'),
    infix: $ => choice(
      '||',
      '&&',
      '=',
      '<>',
      '<=',
      '>=',
      '<',
      '>',
    ),

    // Figure A.1
    term_function_call: $ => seq(
      field('name', choice($.ident, $.projection)), '(', _seq(',', $.term), ')'
    ),
    term: $ => choice(
      $.ident,
      $.nat,
      'fail',
      seq($._choice, '[', $.term, ',', $.term, ']'),
      seq('(', _seq(',', $.term), ')'),
      $.term_function_call,
      prec.left(9, seq($.term, choice('+', '-'), $.nat)),
      prec.left(9, seq($.nat, '+', $.term)),
      prec(3, seq($.term, '=', $.term)),
      prec(4, seq($.term, '<>', $.term)),
      prec(5, seq($.term, '<=', $.term)),
      prec(6, seq($.term, '>=', $.term)),
      prec(7, seq($.term, '>', $.term)),
      prec(8, seq($.term, '<', $.term)),
      prec.right(2, seq($.term, '&&', $.term)),
      prec.right(1, seq($.term, '||', $.term)),
      seq('not', '(', $.term, ')'),
    ),
    pterm_function_call: $ => seq(
      field('name', $.ident), '(', _seq(',', $.pterm), ')'
    ),
    pterm: $ => choice(
      $.ident,
      $.nat,
      seq('(', _seq(',', $.pterm), ')'),
      $.pterm_function_call,
      seq($._choice, '[', $.pterm, ',', $.pterm, ']'),
      prec.left(9, seq($.pterm, choice('+', '-'), $.nat)),
      prec.left(9, seq($.nat, '+', $.pterm)),
      prec(3, seq($.pterm, '=', $.pterm)),
      prec(4, seq($.pterm, '<>', $.pterm)),
      prec(5, seq($.pterm, '<=', $.pterm)),
      prec(6, seq($.pterm, '>=', $.pterm)),
      prec(7, seq($.pterm, '>', $.pterm)),
      prec(8, seq($.pterm, '<', $.pterm)),
      prec.right(2, seq($.pterm, '&&', $.pterm)),
      prec.right(1, seq($.pterm, '||', $.pterm)),
      seq('not', '(', $.pterm, ')'),
      seq(
        'new',
        $.ident,
        optional(seq('[', _seq(',', $.ident), ']')),
        ':',
        $.typeid,
        ';',
        $.pterm,
      ),
      seq($.ident, '<-R', $.typeid, ';', $.pterm),
      seq(
        'if',
        $.pterm,
        'then',
        $.pterm,
        optional(seq('else', $.pterm)),
      ),
      seq(
        'let',
        $.pattern,
        '=',
        $.pterm,
        'in',
        $.pterm,
        optional(seq('else', $.pterm)),
      ),
      seq(
        $.ident,
        optional(seq(':', $.typeid)),
        '<-',
        $.pterm,
        ';',
        $.pterm,
      ),
      seq(
        'let',
        $.typedecl,
        'suchthat',
        $.pterm,
        'in',
        $.pterm,
        optional(seq('else', $.pterm)),
      ),
      seq('insert', $.ident, '(', _seq(',', $.pterm), ')', ';', $.pterm),
      seq(
        'get', $.ident, '(', _seq(',', $.pattern), ')',
        optional(seq('suchthat', $.pterm)),
        optional($.options),
        'in', $.pterm,
        optional(seq('else', $.pterm)),
      ),
      seq(
        'event',
        $.ident,
        optional(seq('(', _seq(',', $.pterm), ')')),
        optional(seq('[', _seq(',', $.ident), ']')),
        ';',
        $.pterm,
      ),
    ),
    pattern: $ => choice(
      seq(
        $.ident,
        optional(seq(':', $.typeid)),
      ),
      $.nat,
      seq($.pattern, '+', $.nat),
      seq($.nat, '+', $.pattern),
      seq('(', _seq(',', $.pattern), ')'),
      seq($.ident, '(', _seq(',', $.pattern), ')'),
      seq($._choice, '[', $.pattern, ',', $.pattern, ']', optional(seq(':', $.typeid))),
      seq('=', $.pterm),
    ),
    mayfailterm: $ => $.term,
    _typedecl: $ => seq(_seq1(',', $.ident), ':', $.typeid),
    typedecl: $ => _seq1(',', $._typedecl),
    _failtypedecl: $ => seq(_seq1(',', $.ident), ':', $.typeid, optional(seq('or', 'fail'))),
    failtypedecl: $ => _seq1(',', $._failtypedecl),

    // Figure A.2
    type_def: $ => seq(
      'type',
      field('name', $.ident),
      optional($.options),
      '.',
    ),
    function_macro_def: $ => seq(
      'letfun',
      field('name', $.ident),
      optional(seq(
        '(',
        optional($.failtypedecl),
        ')',
      )),
      '=',
      $.pterm,
      '.',
    ),
    function_def: $ => seq(
      'fun',
      field('name', $.ident),
      '(',
      _seq(',', $.typeid),
      ')',
      ':',
      $.typeid,
      optional(seq('reduc', $.mayfailreduc)),
      optional($.options),
      '.',
    ),
    /* Compatibility declarations, plus def/expand macros. Probability/proof
     * declarations are ignored by ProVerif. Macro bodies are still opaque in
     * this grammar (but are meaningful to ProVerif); see docs/coverage.md. */
    decl_cryptoverif: $=> choice(
      seq(
        'proba',
        $.ident,
        /* CryptoVerif-only syntax is ignored in ProVerif */
        optional(seq('(', /[^)]*/, ')')),
        optional($.options),
        '.',
      ),
      seq(
        'letproba',
        $.ident,
        optional(seq('(', $.typedecl, ')')),
        '=',
        /* CryptoVerif-only syntax is ignored in ProVerif */
        /[^\.]*/,
        '.',
      ),
      seq('proof', '{', $.proof, '}'),
      seq(
        'def', $.ident, '(', _seq(',', $.typeid),')',
        '{', $.def, '}',
      ),
      seq('expand', $.ident, '(', _seq(',', $.typeid), ')', '.'),
    ),
    decl_pred: $ => seq(
      'pred',
      field('name', $.ident),
      optional(seq(
        '(',
        _seq(',', $.typeid),
        ')',
      )),
      optional($.options),
      '.',
    ),
    decl_table: $ => seq(
      'table',
      field('name', $.ident),
      '(',
      _seq(',', $.typeid),
      ')',
      '.',
    ),
    decl_process_macro: $ => seq(
      'let', field('name', $.ident),
      optional(seq('(', optional($.failtypedecl), ')')),
      '=',
      $.process,
      '.',
    ),
    decl_event: $ => seq(
      'event',
      field('name', $.ident),
      optional(seq(
        '(',
        _seq(',', $.typeid),
        ')',
      )),
      '.',
    ),
    decl_query: $ => seq(
      'query',
      optional(seq($.typedecl, ';')),
      $.query,
      optional($.options),
      '.',
    ),
    decl_channel: $ => seq(
      'channel', _seq1(',', $.ident), '.'
    ),
    decl_free: $ => seq(
      'free', _seq1(',', $.ident), ':', $.typeid,
      optional($.options),
      '.',
    ),
    decl_const: $ => seq(
      'const', _seq1(',', $.ident), ':', $.typeid,
      optional($.options),
      '.',
    ),
    decl: $ => choice(
      $.type_def,
      $.decl_channel,
      $.decl_free,
      $.decl_const,
      $.function_macro_def,
      seq(
        'reduc',
        $.eqlist,
        optional($.options),
        '.',
      ),
      $.function_def,
      seq(
        'equation',
        $.eqlist,
        optional($.options),
        '.',
      ),
      $.decl_pred,
      $.decl_table,
      $.decl_process_macro,
      seq(
        'set',
        $.name,
        '=',
        $.value,
        '.',
      ),
      $.decl_event,
      $.decl_query,
      seq(
        choice('axiom', 'restriction', 'lemma'),
        optional(seq($.typedecl, ';')),
        $.lemma,
        optional($.options),
        '.',
      ),
      seq(
        'noninterf',
        optional(seq($.typedecl, ';')),
        _seq(',', $.nidecl),
        '.',
      ),
      seq(
        'weaksecret',
        $.ident,
        '.',
      ),
      seq(
        'not',
        optional(seq($.typedecl, ';')),
        $.gterm,
        '.',
      ),
      seq(
        choice('select', 'noselect', 'nounif'),
        optional(seq($.typedecl, ';')),
        $.nounifdecl,
        optional(seq('/', $.int)),
        optional(seq('[', _seq1(',', $.nounifoption), ']')),
        '.',
      ),
      seq('elimtrue', optional(seq($.failtypedecl, ';')), $.term, '.'),
      seq('clauses', $.clauses, '.'),
      seq('param', _seq1(',', $.ident), optional($.options), '.',),
      $.decl_cryptoverif,
    ),
    nidecl: $ => seq(
      $.ident,
      optional(seq('among', '(', _seq1(',', $.term), ')'))
    ),
    /* CryptoVerif-only syntax is ignored in ProVerif */
    proof: $ => token(/[^}]*/),
    def: $ => token(/[^}]*/),
    name: $ => $.ident,
    value: $ => choice(
      $.ident,
      $.int,
      $.string,
      'true',
      'false'
    ),
    string: $ => token(seq('"', repeat(choice(/[^"\\]/, /\\./)), '"')),

    // Figure A.3
    equality: $ => choice(
      seq($.term, '=', $.term),
      seq('let', $.ident, '=', $.term, 'in', $.equality),
      seq($.ident, '<-', $.term, ';', $.equality),
    ),
    mayfailequality: $ => choice(
      seq(
        $.ident, '(',
        _seq(',', $.mayfailterm),
        ')',
        '=',
        $.mayfailterm,
      ),
      seq(
        'let',
        $.ident,
        '=',
        $.term,
        'in',
        $.mayfailequality
      ),
      seq($.ident, '<-', $.term, ';', $.mayfailequality),
    ),
    _eqlist: $ => seq(
      optional(seq('forall', $.typedecl, ';')),
      $.equality,
    ),
    eqlist: $ => _seq1(';', $._eqlist),
    _mayfailreduc: $ => seq(
      optional(seq('forall', $.failtypedecl, ';')),
      $.mayfailequality,
    ),
    mayfailreduc: $ => seq(_seq1('otherwise', $._mayfailreduc)),

    // Figure A.4
    _query: $ => choice(
      seq(
        $.gterm,
        optional(seq('public_vars', _seq1(',', $.ident))),
      ),
      seq(
        'secret',
        $.ident,
        optional(seq('public_vars', _seq1(',', $.ident))),
        optional($.options),
      ),
      seq(
        'putbegin',
        choice('event', 'inj-event'),
        ':',
        _seq1(',', $.ident),
      ),
    ),
    query: $ => _seq1(';', $._query),
    lemma: $ => choice(
      seq($.gterm, optional(seq(';', $.lemma))),
      seq(
        $.gterm,
        'for',
        '{',
        'public_vars',
        _seq1(',', $.ident),
        '}',
        optional(seq(';', $.lemma)),
      ),
      seq(
        $.gterm,
        'for',
        '{',
        'secret',
        $.ident,
        optional(seq('public_vars', _seq1(',', $.ident))),
        '[',
        'real_or_random',
        ']',
        '}',
        optional(seq(';', $.lemma)),
      ),
    ),
    gterm_function_call: $ => seq(
      field('name', choice($.ident, 'table')),
      '(',
      _seq(',', $.gterm),
      ')',
      optional(seq('phase', $.nat)),
      optional(seq('@', $.ident)),
    ),
    gterm: $ => choice(
      $.ident,
      $.nat,
      seq('(', optional($.gterm), ')'),
      $.gterm_function_call,
      seq(
        $._choice,
        '[',
        $.gterm,
        ',',
        $.gterm,
        ']',
      ),
      prec.left(9, seq($.gterm, choice('+', '-'), $.gterm)),
      prec.left(9, seq($.nat, '+', $.gterm)),
      prec(3, seq($.gterm, '=', $.gterm)),
      prec(4, seq($.gterm, '<>', $.gterm)),
      prec(5, seq($.gterm, '<=', $.gterm)),
      prec(6, seq($.gterm, '>=', $.gterm)),
      prec(7, seq($.gterm, '>', $.gterm)),
      prec(8, seq($.gterm, '<', $.gterm)),
      prec.right(2, seq($.gterm, '&&', $.gterm)),
      prec.right(1, seq($.gterm, '||', $.gterm)),
      seq(
        choice('event', 'inj-event'),
        '(',
        _seq(',', $.gterm),
        ')',
        optional(seq('@', $.ident)),
      ),
      seq('not', '(', $.gterm, ')'),
      prec.right(0, seq($.gterm, '==>', $.gterm)),
      prec.left(-1, seq($.gterm, ',', $.gterm)),
      seq(
        'new',
        $.ident,
        optional(seq('[', optional($.binding), ']')),
      ),
      seq(
        'let',
        $.ident,
        '=',
        $.gterm,
        'in',
        $.gterm,
      ),
      seq($.ident, '<-', $.gterm, ';', $.gterm),
    ),

    // Figure A.6
    nounifdecl: $ => choice(
      seq('let', $.ident, '=', $.gformat, 'in', $.nounifdecl),
      $.ident,
      seq(
        $.gformat_function_call,
          optional(seq('phase', $.nat)),
      ),
    ),
    gformat_function_call: $ => seq(
      field('name', choice($.ident, 'table', 'event')), '(', _seq(',', $.gformat), ')'
    ),
    gformat: $ => choice(
      $.ident,
      $.nat,
      prec.left(9, seq($.gformat, '+', $.nat)),
      prec.left(9, seq($.nat, '+', $.gformat)),
      seq('*', $.ident),
      $.gformat_function_call,
      seq($._choice, '[', $.gformat, ',', $.gformat, ']'),
      seq('not', '(', _seq(',', $.gformat), ')'),
      seq('(', _seq(',', $.gformat), ')'),
      seq(
        'new',
        $.ident,
        optional(seq(
          '[',
          optional($.binding),
          ']'
        ))
      ),
      seq('let', $.ident, '=', $.gformat, 'in', $.gformat),
      seq($.ident, '<-', $.gformat, ';', $.gformat),
    ),
    nounifoption: $ => choice(
      'hypothesis',
      'conclusion',
      'ignoreAFewTimes',
      seq('inductionOn', '=', $.ident),
      seq('inductionOn', '=', '{', _seq1(',', $.ident), '}'),
      $.option,
    ),

    // Figure A.7
    clauses: $ => seq(
      optional(seq('forall', $.failtypedecl, ';')),
      $.clause,
      optional(seq(';', $.clauses)),
    ),
    clause: $ => choice(
      $.term,
      seq($.term, '->', $.term),
      seq($.term, '<->', $.term),
      seq($.term, '<=>', $.term),
    ),

    // Figure A.8
    process_input: $ => seq(
      'in', '(', $.pterm, ',', $.pattern, ')',
      optional($.options),
    ),
    process_output: $ => seq(
      'out', '(', $.pterm, ',', $.pterm, ')',
    ),
    process_new: $ => prec.left(seq(
      'new',
      $.ident,
      optional(seq('[', _seq(',', $.ident), ']')),
      ':',
      $.typeid,
    )),
    process_item: $ => choice(
      seq($.ident, '<-R', $.typeid, optional(seq(';', $.process))),
      seq('if', $.pterm, 'then', $.process, optional(seq('else', $.process))),
      $.process_input,
      $.process_output,
      $.process_new,
      seq($.ident, optional(seq(':', $.typeid)), '<-', $.pterm),
      seq('insert', $.ident, '(', _seq(',', $.pterm), ')'),
      seq(
        'event',
        $.ident,
        optional(seq('(', _seq(',', $.pterm), ')')),
        optional(seq('[', _seq(',', $.ident), ']')),
      ),
      seq('phase', $.nat),
      seq(
        'sync',
        $.nat,
        optional(seq('[', $.tag, ']')),
      ),
    ),
    process_function_call: $ => seq(
      field('name', $.ident), '(', _seq(',', $.pterm), ')',
    ),
    process_final_item: $ => choice(
      '0',
      'yield',
      $.process_function_call,
      $.ident,
    ),
    process_replication: $ => choice(
      seq($.process, '|', $.process),
      seq('!', optional(seq($.ident, '<=', $.ident)), $.process),
    ),
    process_let: $ => choice(
      seq(
        'let', $.pattern, '=', $.pterm,
        optional(seq(
          'in', $.process,
          optional(seq('else', $.process)),
        )),
      ),
      seq(
        'let', $.typedecl, 'suchthat', $.pterm,
        optional($.options),
        optional(seq(
          'in',
          $.process,
          optional(seq('else', $.process)),
        )),
      ),
    ),
    process_foreach: $ => seq(
      'foreach', $.ident, '<=', $.ident, 'do', $.process
    ),
    process_get: $ => seq(
      'get',
      $.ident,
      '(',
      _seq(',', $.pattern),
      ')',
      optional(seq('suchthat', $.pterm)),
      optional($.options),
      optional(seq(
        'in',
        $.process,
        optional(seq('else', $.process)),
      )),
    ),
    process: $ => choice(
      seq(
        $.process_item,
        optional(seq(';', $.process))
      ),
      $.process_final_item,
      $.process_let,
      $.process_foreach,
      $.process_get,
      seq('(', $.process, ')'),
      $.process_replication,
    ),

    // Add missing tag (not defined in appedix)
    tag: $ => $.ident,
  }
});
