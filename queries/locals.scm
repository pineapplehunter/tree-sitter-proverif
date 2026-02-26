;; Scopes
(process) @local.scope
(function_macro_def) @local.scope
(function_def) @local.scope

;; Definitions
(typedecl
  (ident) @local.definition.type)

(decl_channel
  (ident) @local.definition.variable)

(decl_free
  (ident) @local.definition.variable)

(decl_const
  (ident) @local.definition.variable)

(function_def
  name: (ident) @local.definition.function)

;; References

(ident) @local.reference
