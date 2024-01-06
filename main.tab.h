/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MAIN_TAB_H_INCLUDED
# define YY_YY_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TKN_INTEGER = 258,             /* TKN_INTEGER  */
    TKN_DOUBLE = 259,              /* TKN_DOUBLE  */
    TKN_FLOAT = 260,               /* TKN_FLOAT  */
    TKN_VAR_NAME = 261,            /* TKN_VAR_NAME  */
    TKN_INTEGER_NUMBER = 262,      /* TKN_INTEGER_NUMBER  */
    TKN_DOUBLE_NUMBER = 263,       /* TKN_DOUBLE_NUMBER  */
    TKN_FLOAT_NUMBER = 264,        /* TKN_FLOAT_NUMBER  */
    TKN_ERROR = 265,               /* TKN_ERROR  */
    TKN_ADD = 266,                 /* TKN_ADD  */
    TKN_SUB = 267,                 /* TKN_SUB  */
    TKN_MULTIPLICATION = 268,      /* TKN_MULTIPLICATION  */
    TKN_DIVISION = 269,            /* TKN_DIVISION  */
    TKN_LEFT_PARANTHESIS = 270,    /* TKN_LEFT_PARANTHESIS  */
    TKN_RIGHT_PARANTHESIS = 271,   /* TKN_RIGHT_PARANTHESIS  */
    TKN_IF = 272,                  /* TKN_IF  */
    TKN_WHILE = 273,               /* TKN_WHILE  */
    TKN_LEFT_CURLY = 274,          /* TKN_LEFT_CURLY  */
    TKN_RIGHT_CURLY = 275,         /* TKN_RIGHT_CURLY  */
    TKN_ELSE = 276,                /* TKN_ELSE  */
    TKN_IS_EQUAL = 277,            /* TKN_IS_EQUAL  */
    TKN_IS_NOT_EQUAL = 278,        /* TKN_IS_NOT_EQUAL  */
    TKN_IS_LOWER = 279,            /* TKN_IS_LOWER  */
    TKN_IS_HIGHER = 280,           /* TKN_IS_HIGHER  */
    TKN_IS_LOWER_OR_EQUAL = 281,   /* TKN_IS_LOWER_OR_EQUAL  */
    TKN_IS_HIGHER_OR_EQUAL = 282,  /* TKN_IS_HIGHER_OR_EQUAL  */
    TKN_DOUBLE_QUOTE = 283,        /* TKN_DOUBLE_QUOTE  */
    TKN_SINGLE_QUOTE = 284,        /* TKN_SINGLE_QUOTE  */
    TKN_COMMA = 285,               /* TKN_COMMA  */
    TKN_PRINT = 286,               /* TKN_PRINT  */
    TKN_SCAN = 287,                /* TKN_SCAN  */
    TKN_RUN = 288,                 /* TKN_RUN  */
    TKN_FILENAME = 289,            /* TKN_FILENAME  */
    TKN_MESSAGE = 290,             /* TKN_MESSAGE  */
    UMINUS = 291,                  /* UMINUS  */
    ifx = 292                      /* ifx  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 117 "main.y"

    char *sir; 
    int nr_integer;
    double nr_double;
    float nr_float;

#line 108 "main.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */
