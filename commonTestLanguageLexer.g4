lexer grammar commonTestLanguageLexer;

fragment Lowercase  : [a-z] ;
fragment Uppercase  : [A-Z] ;
fragment Digit      : [0-9]; 




Whitespace : (' ' | '\t') -> skip;
Newline    : ('\n' | '\r' '\n'?) -> skip;
/*Comment     : '//' ~Newline* Newline -> skip;*/
Defer           : 'defer' ;
Func            : 'Func' ;
If              : 'if' ;
Then            : 'then' ;
Else            : 'else' ;
For             : 'for' ;
From            : 'from';
To              : 'to';
In              : 'in' ;
By              : 'by' ;
Reverse         : 'reverse' ;
Var             : 'var' ;
Slash           : '/' ;
Star            : '*' ;
Plus            : '+' ;
Minus           : '-' ;
LessOrEqual     : '<=' ;
Less            : '<' ;
GreaterOrEqual  : '>=' ;
Greater         : '>' ;
Equal           : '=' ;
NotEqual        : '!=' ;
Negation        : '!' ;
Or              : '|' ;
And             : '&' ;
Xor             : '^' ;
Type        : Uppercase (Lowercase | Uppercase | '_')* ;
Id          : Lowercase (Lowercase | Uppercase | '_')* ; 
Integer     : Digit+ ;
Float       : (Digit+ '.' Digit*) | (Digit* '.' Digit+) ;
