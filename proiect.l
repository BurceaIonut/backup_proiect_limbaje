%option noyywrap
%{
    #include "main.tab.h"
%}

var [_]*[a-zA-Z]+[0-9]*

%%
"int"                                               return TKN_INTEGER;
"double"                                            return TKN_DOUBLE;
"float"                                             return TKN_FLOAT;
0|[1-9]+[0-9]*                                      return TKN_INTEGER_NUMBER;
0|[1-9]+[0-9]*"."[0-9]+                             return TKN_DOUBLE_NUMBER;
0|[1-9]+[0-9]*"."[0-9]+[fF]                         return TKN_FLOAT_NUMBER;
;                                                   return TKN_SEMICOLON;
"+"                                                 return TKN_ADD;
"-"                                                 return TKN_SUB;
"\*"                                                return TKN_MULTIPLICATION;
"/"                                                 return TKN_DIVISION;
"("                                                 return TKN_LEFT_PARANTHESIS;
")"                                                 return TKN_RIGHT_PARANTHESIS;
"if"                                                return TKN_IF;
"while"                                             return TKN_WHILE;
"{"                                                 return TKN_LEFT_CURLY;
"}"                                                 return TKN_RIGHT_CURLY;
"else"                                              return TKN_ELSE;
"printf"                                            return TKN_PRINTF;
"scanf"                                             return TKN_SCANF;
{var}                                               return TKN_VAR_NAME;
"=="                                                return TKN_IS_EQUAL;
"<"                                                 return TKN_IS_LOWER;
">"                                                 return TKN_IS_HIGHER;
"!="                                                return TKN_IS_NOT_EQUAL;
"<="                                                return TKN_IS_LOWER_OR_EQUAL;
">="                                                return TKN_IS_HIGHER_OR_EQUAL;
"="                                                 return TKN_EQUAL;
\"                                                  return TKN_DOUBLE_QUOTE;
\'                                                  return TKN_SINGLE_QUOTE;
\"[a-zA-Z0-9:,;.\n\t&%*!?$^#@\-=+_ ]+\"             return TKN_PROPOSITION;
\,                                                  return TKN_COMMA;
\%[a-z]+\                                           return TKN_SPECIFIER;
[ \t\n]                                             ;
.                                                   return TKN_ERROR;
%%