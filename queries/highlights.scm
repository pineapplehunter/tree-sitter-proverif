;; fallback for identifiers
(ident) @variable

;; Comments

(comment) @comment

; CryptoVerif-only proof scripts are ignored by ProVerif.
; def bodies are meaningful macros, not comments (currently opaque).
(proof) @comment.unused

;; Types
(type_def
  name: (ident) @type)

(decl_const
  (ident) @constant)

(decl_free
  (ident) @variable)

(typeid) @type
(typeid
  (ident) @type)

(decl_table
  name: (ident) @type)

;; Function & Macro Definitions

(function_def
  name: (ident) @function)

(function_macro_def
  name: (ident) @function.macro)

(decl_pred
  name: (ident) @function)

(decl_event
  name: (ident) @function)

;; Function Calls

(term_function_call
  name: (ident) @function)


(pterm_function_call
  name: (ident) @function)


(decl_process_macro
  name: (ident) @function.macro)
(decl_process_macro
 (failtypedecl (ident) @variable.parameter))
(function_macro_def
 (failtypedecl (ident) @variable.parameter))

(projection) @function

(gterm_function_call
  name: (ident) @function)


(gformat_function_call
  name: (ident) @function)


(process_function_call
  name: (ident) @function.macro)


(process_input "in" @function.builtin)


(process_output "out" @function.builtin)


;; Literals

(nat) @constant.numeric
(int) @constant.numeric
(string) @string

[
  "true"
  "false"
] @constant.builtin.boolean

"fail" @constant.builtin

(process_final_item
  "0" @constant.builtin)

;; Keywords

[
  "among"
  "axiom"
  "choice"
  "clauses"
  "const"
  "def"
  "diff"
  "do"
  "elimtrue"
  "else"
  "equation"
  "equivalence"
  "event"
  "expand"
  "forall"
  "for"
  "foreach"
  "free"
  "fun"
  "get"
  "if"
  "inj-event"
  "insert"
  "lemma"
  "let"
  "letfun"
  "letproba"
  "new"
  "noninterf"
  "noselect"
  "not"
  "nounif"
  "otherwise"
  "or"
  "param"
  "phase"
  "pred"
  "proba"
  "process"
  "proof"
  "public_vars"
  "putbegin"
  "query"
  "reduc"
  "restriction"
  "secret"
  "select"
  "set"
  "suchthat"
  "sync"
  "table"
  "then"
  "type"
  "weaksecret"
  "yield"
] @keyword

(decl_channel "channel" @keyword) ; "channel" can also be used as type, hence the restriction
(process_let "in" @keyword)
(process_get "in" @keyword)
(pterm "in" @keyword)
(gterm "in" @keyword)
(gformat "in" @keyword)
(equality "in" @keyword)
(mayfailequality "in" @keyword)

;; Operators

[
  "="
  "<>"
  "<="
  ">="
  "<"
  ">"
  "+"
  "-"
  "==>"
  "<-"
  "<-R"
  "->"
  "<->"
  "<=>"
  "/"
  "||"
  "&&"
  "|"
  "!"
] @keyword.operator

;; Punctuation

[
  "."
  ","
  ";"
  ":"
] @punctuation.delimiter

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

;; Options

(option) @attribute
(nounifoption) @attribute
