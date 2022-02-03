grammar testLanguage;

import commonTestLanguageLexer;

program: ( statement | defer_statement | scopeBlock )+ ;
statement: 
        expression? ';'
    |   declaration 
    |   assignment
    |   forStatement
    |   ifStatement
;
defer_statement:    Defer statement ;
/*rvalue          : (Id| Integer | Float | Type '{' ( rvalue ',')+ '}' );*/
type:   variable_type | function_type ;
formal_parameter:   (Var? Id variable_type) | function_type ;
formal_parameter_list:  formal_parameter? (',' formal_parameter)* ;
variable_type:  Type('['Integer']')? ;
function_type:  
        '(' formal_parameter_list ')' '->' '(' formal_parameter_list ')'
    |   Type                                                           
;
id_declaration:   Id (',' Id )* variable_type (':=' expression (',' expression)*)? ';' ;
function_declaration: Func Id function_type scopeBlock ;
variable_type_declaration:   'Type' Type ':=' (variable_type | '{' Id variable_type (',' Id variable_type)+ '}') ';';
function_type_declaration:   'Type' Type ':=' function_type ';';
type_declaration: variable_type_declaration | function_type_declaration ;
declaration:    id_declaration | function_declaration | type_declaration ;
member_access: Id '.' Id ;
assignment:     (Id  (',' Id)*) | (member_access (',' member_access)*) ':=' expression (',' expression)* ';' ;
expression:  
        member_access                                       #member_access_expression
    |   expression ( Star | Slash ) expression              #multiply_expression
    |   expression ( Plus | Minus ) expression              #sum_expression
    |   Minus expression                                    #invert_sign_expression
    |   Negation expression                                 #negation_expression
    |   expression (Or | And | Xor) expression              #logical_expression
    |   expression (
            LessOrEqual | Less | GreaterOrEqual 
            | Greater | Equal | NotEqual
            ) 
        expression                                          #comparison_expression
    |   Id                                                  #variable_expression
    |   Integer                                             #constant_integer_expression
    |   Float                                               #constant_float_expression
    |   variable_type '{' expression (',' expression)* '}'  #init_expression
    |   Id '(' expression? (',' expression)* ')'            #function_call
    |   '(' expression ')'                                  #parenthesized_expression
;
scopeBlock:     '{' ( statement | scopeBlock )* '}' ;
forVariable:    Id | '_' ;   
byClause:       By expression ;
range:          From expression To expression ;
forStatement:   For forVariable ',' forVariable (In Reverse? expression | Reverse? range) (byClause)? scopeBlock ;
ifStatement:    If expression Then scopeBlock (Else (scopeBlock | ifStatement))? ;
