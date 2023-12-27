%option noyywrap
%{
    #include "main.tab.h"
    int lineNo = 1;
    int colNo = 1;
%}

%%
"+"                                                 { colNo++; return TKN_ADD; }
"-"                                                 { colNo++; return TKN_SUB; }
"*"                                                 { colNo++; return TKN_MULTIPLICATION; }
"/"                                                 { colNo++; return TKN_DIVISION; }
"int"                                               { colNo+=3; return TKN_INTEGER; }
"double"                                            { colNo+=6; return TKN_DOUBLE; }
"float"                                             { colNo+=5; return TKN_FLOAT; }
"if"                                                { colNo+=2; return TKN_IF; }
"while"                                             { colNo+=5; return TKN_WHILE; }
"else"                                              { colNo+=4; return TKN_ELSE; }
"print"                                             { colNo+=5; return TKN_PRINT; }
""
0|[1-9][0-9]*                                       { 
                                                    yylloc.first_line = lineNo;
                                                    yylloc.first_column = colNo;
                                                    colNo += strlen(yytext);
                                                    yylval.nr_integer = atoi(yytext);
                                                    return TKN_INTEGER_NUMBER;
                                                    }
[0-9]+"."[0-9]+                                     {
                                                    yylloc.first_line = lineNo;
                                                    yylloc.first_column = colNo;
                                                    colNo+=strlen(yytext);
                                                    yylval.nr_double = atof(yytext); 
                                                    return TKN_DOUBLE_NUMBER; 
                                                    }
[0-9]+"."[0-9]+[fF]                                 {
                                                    yylloc.first_line = lineNo;
                                                    yylloc.first_column = colNo;
                                                    colNo+=strlen(yytext);
                                                    yytext[strlen(yytext) - 1] = '\0';
                                                    yylval.nr_float = atof(yytext); 
                                                    return TKN_FLOAT_NUMBER; 
                                                    }
[_]*[a-zA-Z][a-zA-Z0-9]*                            { 
                                                    yylloc.first_line = lineNo;
                                                    yylloc.first_column = colNo;
                                                    colNo+=strlen(yytext); 
                                                    yylval.sir = new char[strlen(yytext) + 1];
                                                    strcpy(yylval.sir, yytext);
                                                    return TKN_VAR_NAME; 
                                                    }
";"                                                 { colNo++; return ';'; }
"="                                                 { colNo++; return '='; }
"("                                                 { colNo++; return TKN_LEFT_PARANTHESIS; }
")"                                                 { colNo++; return TKN_RIGHT_PARANTHESIS; }
"{"                                                 { colNo++; return TKN_LEFT_CURLY; }
"}"                                                 { colNo++; return TKN_RIGHT_CURLY; }
"=="                                                { colNo+=2; return TKN_IS_EQUAL; }
"<"                                                 { colNo++; return TKN_IS_LOWER; }
">"                                                 { colNo++; return TKN_IS_HIGHER; }
"!="                                                { colNo+=2; return TKN_IS_NOT_EQUAL; }
"<="                                                { colNo+=2; return TKN_IS_LOWER_OR_EQUAL; }
">="                                                { colNo+=2; return TKN_IS_HIGHER_OR_EQUAL; }
\"                                                  { colNo++; return TKN_DOUBLE_QUOTE; }
\'                                                  { colNo++; return TKN_SINGLE_QUOTE; }
","                                                 return TKN_COMMA;
"/"([^]|\+[^/])(\n)""+"/"                           { colNo += strlen(yytext); }
"//"([^\n]|\+[^/])*                                 { colNo += strlen(yytext); }
\"[a-zA-Z0-9:,;.\t&%*!?$^#@\-=+_ ]+\"               {
                                                    yylloc.first_line = lineNo;
                                                    yylloc.first_column = colNo;
                                                    yylval.sir = new char[strlen(yytext) + 1];
                                                    strcpy(yylval.sir, yytext);
                                                    return TKN_MESSAGE;
                                                    }
[ ]                                                 { colNo++; }
\r\n                                                { lineNo++; colNo = 1; }
\n                                                  { lineNo++; colNo = 1; }
.                                                   { colNo++; return TKN_ERROR; }
%%