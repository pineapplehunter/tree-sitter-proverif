module.exports = grammar({
  name: 'proverif',

  rules: {
    // TODO: optional process/equivalence
    source_file: $ => repeat($._declaration),

    _declaration: $ => choice(
      $.type_declaration
      // TODO: other declarations
    ),

    type_declaration: $ => seq(
      'type',
      $.identifier,
      // field('name', $.identifier),
      // optional($.option_list),
      ';'
    ),

    // option_list: $ => seq(
    //   '[',
    //   // TODO: comma separatd lists
    //   ']',
    // ),

    // identifier: $ => /[a-z0-9_']+/,
    identifier: $ => /[a-z]+/,

  }
})
