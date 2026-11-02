; Top-level declarations and process bodies are useful entry points.
(decl) @entry.around
(process) @function.around

(function_def) @function.around
(function_macro_def
  (pterm) @function.inside) @function.around

; The body of a declared process macro is its editable interior.
(decl_process_macro
  (process) @function.inside) @function.around

; Comments can be selected independently of surrounding declarations.
(comment) @comment.inside
(comment)+ @comment.around
