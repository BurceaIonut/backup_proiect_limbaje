/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "main.y"

    #include <iostream>
    #include <stdio.h>
    #include <string.h>
    using namespace std;
    int yylex();
    int yyerror(const char* msg);
    char msg[500];

    class TVAR
    {
        char* nume;
        float valoare;
        char type;
        TVAR* next;
    public:
        static TVAR* head;
        static TVAR* tail;
        TVAR(char* n, char type, float v = -1);
        TVAR();
        int exists(char* n);
        void add(char *n, char type, float v);
        float getValue(char* n);
        char getType(char* n);
        void setValue(char*n, float v);
        void printVars();
    };
    TVAR* TVAR::head;
    TVAR* TVAR::tail;

    TVAR::TVAR(char* n, char type, float v)
    {
        this->nume = new char[strlen(n) + 1];
        strcpy(this->nume, n);
        this->valoare = v;
        this->type = type;
        this->next = NULL;
    }
    TVAR::TVAR()
    {
        TVAR::head = NULL;
        TVAR::tail = NULL;
    }
    int TVAR::exists(char* n)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
                return 1;
            tmp = tmp->next;
        }
        return 0;
    }
    void TVAR::add(char* n, char type, float v)
    {
        TVAR* elem = new TVAR(n, type, v);
        if(head == NULL)
        {
            TVAR::head = TVAR::tail = elem;
        }
        else
        {
            TVAR::tail->next = elem;
            TVAR::tail = elem;
        }
    }
    float TVAR::getValue(char* n)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
                return tmp->valoare;
            tmp = tmp->next;
        }
        return -1;
    }
    void TVAR::setValue(char* n, float v)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
            {
                tmp->valoare = v;
            }
            tmp = tmp->next;
        }
    }
    void TVAR::printVars()
	{
		cout<<"\nPrinting table of variables...\n";
		TVAR* tmp = TVAR::head;
		while(tmp != NULL)
		{
			cout<<tmp->nume<<"="<<tmp->valoare<<"\n";
			tmp = tmp->next;
		}	  
	}
    char TVAR::getType(char* n)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
                return tmp->type;
            tmp = tmp->next;
        }
        return 'f';
    }

    TVAR* ts = NULL;

#line 186 "main.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "main.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TKN_INTEGER = 3,                /* TKN_INTEGER  */
  YYSYMBOL_TKN_DOUBLE = 4,                 /* TKN_DOUBLE  */
  YYSYMBOL_TKN_FLOAT = 5,                  /* TKN_FLOAT  */
  YYSYMBOL_TKN_VAR_NAME = 6,               /* TKN_VAR_NAME  */
  YYSYMBOL_TKN_INTEGER_NUMBER = 7,         /* TKN_INTEGER_NUMBER  */
  YYSYMBOL_TKN_DOUBLE_NUMBER = 8,          /* TKN_DOUBLE_NUMBER  */
  YYSYMBOL_TKN_FLOAT_NUMBER = 9,           /* TKN_FLOAT_NUMBER  */
  YYSYMBOL_TKN_ERROR = 10,                 /* TKN_ERROR  */
  YYSYMBOL_TKN_ADD = 11,                   /* TKN_ADD  */
  YYSYMBOL_TKN_SUB = 12,                   /* TKN_SUB  */
  YYSYMBOL_TKN_MULTIPLICATION = 13,        /* TKN_MULTIPLICATION  */
  YYSYMBOL_TKN_DIVISION = 14,              /* TKN_DIVISION  */
  YYSYMBOL_TKN_LEFT_PARANTHESIS = 15,      /* TKN_LEFT_PARANTHESIS  */
  YYSYMBOL_TKN_RIGHT_PARANTHESIS = 16,     /* TKN_RIGHT_PARANTHESIS  */
  YYSYMBOL_TKN_IF = 17,                    /* TKN_IF  */
  YYSYMBOL_TKN_WHILE = 18,                 /* TKN_WHILE  */
  YYSYMBOL_TKN_LEFT_CURLY = 19,            /* TKN_LEFT_CURLY  */
  YYSYMBOL_TKN_RIGHT_CURLY = 20,           /* TKN_RIGHT_CURLY  */
  YYSYMBOL_TKN_ELSE = 21,                  /* TKN_ELSE  */
  YYSYMBOL_TKN_IS_EQUAL = 22,              /* TKN_IS_EQUAL  */
  YYSYMBOL_TKN_IS_NOT_EQUAL = 23,          /* TKN_IS_NOT_EQUAL  */
  YYSYMBOL_TKN_IS_LOWER = 24,              /* TKN_IS_LOWER  */
  YYSYMBOL_TKN_IS_HIGHER = 25,             /* TKN_IS_HIGHER  */
  YYSYMBOL_TKN_IS_LOWER_OR_EQUAL = 26,     /* TKN_IS_LOWER_OR_EQUAL  */
  YYSYMBOL_TKN_IS_HIGHER_OR_EQUAL = 27,    /* TKN_IS_HIGHER_OR_EQUAL  */
  YYSYMBOL_TKN_DOUBLE_QUOTE = 28,          /* TKN_DOUBLE_QUOTE  */
  YYSYMBOL_TKN_SINGLE_QUOTE = 29,          /* TKN_SINGLE_QUOTE  */
  YYSYMBOL_TKN_COMMA = 30,                 /* TKN_COMMA  */
  YYSYMBOL_TKN_PRINT = 31,                 /* TKN_PRINT  */
  YYSYMBOL_TKN_MESSAGE = 32,               /* TKN_MESSAGE  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_START = 36,                     /* START  */
  YYSYMBOL_S = 37,                         /* S  */
  YYSYMBOL_DECLARE_VAR = 38,               /* DECLARE_VAR  */
  YYSYMBOL_OPERATION = 39,                 /* OPERATION  */
  YYSYMBOL_IF = 40,                        /* IF  */
  YYSYMBOL_WHILE = 41,                     /* WHILE  */
  YYSYMBOL_COMPARE = 42,                   /* COMPARE  */
  YYSYMBOL_PRINT = 43                      /* PRINT  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   144,   144,   145,   147,   148,   149,   150,   151,   153,
     160,   167,   174,   192,   205,   218,   232,   233,   234,   245,
     246,   247,   248,   249,   256,   261,   262,   263,   264,   266,
     267,   269,   280,   291,   302,   313,   324,   336,   349
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TKN_INTEGER",
  "TKN_DOUBLE", "TKN_FLOAT", "TKN_VAR_NAME", "TKN_INTEGER_NUMBER",
  "TKN_DOUBLE_NUMBER", "TKN_FLOAT_NUMBER", "TKN_ERROR", "TKN_ADD",
  "TKN_SUB", "TKN_MULTIPLICATION", "TKN_DIVISION", "TKN_LEFT_PARANTHESIS",
  "TKN_RIGHT_PARANTHESIS", "TKN_IF", "TKN_WHILE", "TKN_LEFT_CURLY",
  "TKN_RIGHT_CURLY", "TKN_ELSE", "TKN_IS_EQUAL", "TKN_IS_NOT_EQUAL",
  "TKN_IS_LOWER", "TKN_IS_HIGHER", "TKN_IS_LOWER_OR_EQUAL",
  "TKN_IS_HIGHER_OR_EQUAL", "TKN_DOUBLE_QUOTE", "TKN_SINGLE_QUOTE",
  "TKN_COMMA", "TKN_PRINT", "TKN_MESSAGE", "';'", "'='", "$accept",
  "START", "S", "DECLARE_VAR", "OPERATION", "IF", "WHILE", "COMPARE",
  "PRINT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      60,     0,     2,     8,   -10,   -33,   -33,   -33,    30,    15,
      19,   -12,    28,    44,    60,   -33,    -1,   -33,   -33,   -33,
     -32,   -17,     7,    30,   -33,    81,    30,    30,    60,   -33,
      -3,   -33,   -33,    30,    30,    30,    30,   -33,   -33,    30,
     -33,    30,   -33,    30,     9,   -33,    87,    36,   104,    55,
      52,    57,    58,    33,    33,   -33,   -33,    37,    71,    75,
     -33,    61,    30,    30,    30,    30,    30,    30,    77,    83,
      86,   -33,    43,    46,   -33,   -33,   -33,    60,   110,   110,
     110,   110,   110,   110,    60,    60,    60,   -33,   -33,    70,
      99,   105,   112,   -33,   -33,   -33,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    23,    20,    21,    22,     0,     0,
       0,     0,     0,     0,     2,     4,     0,     6,     7,     8,
       0,     0,     0,     0,    23,     0,     0,     0,     0,    28,
       0,     1,     3,     0,     0,     0,     0,     5,    13,     0,
      14,     0,    15,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    19,    18,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     9,    10,    11,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    37,    38,     0,
       0,     0,     0,    25,    26,    29,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,    92,   -24,   -33,    -8,    96,   -33,   106,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    13,    14,    15,    16,    17,    18,    47,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    38,    39,    51,    50,     9,    20,    28,    21,    11,
      33,    34,    35,    36,    22,    44,    40,    41,    46,    48,
      33,    34,    35,    36,    23,    53,    54,    55,    56,    52,
      26,    57,    37,    58,    27,    59,    24,     5,     6,     7,
      42,    43,    60,    30,    31,     8,    35,    36,    33,    34,
      35,    36,    68,    89,    78,    79,    80,    81,    82,    83,
      90,    91,    92,     1,     2,     3,     4,     5,     6,     7,
      74,    70,    71,    72,    73,     8,    87,     9,    10,    88,
      77,    11,    33,    34,    35,    36,    33,    34,    35,    36,
      93,    12,    33,    34,    35,    36,    84,    45,    33,    34,
      35,    36,    85,    61,    75,    86,    32,    29,    76,    62,
      63,    64,    65,    66,    67,    33,    34,    35,    36,    94,
      69,    33,    34,    35,    36,    95,    62,    63,    64,    65,
      66,    67,    96,    49
};

static const yytype_int8 yycheck[] =
{
       8,    33,    34,     6,    28,    17,     6,    19,     6,    21,
      11,    12,    13,    14,     6,    23,    33,    34,    26,    27,
      11,    12,    13,    14,    34,    33,    34,    35,    36,    32,
      15,    39,    33,    41,    15,    43,     6,     7,     8,     9,
      33,    34,    33,    15,     0,    15,    13,    14,    11,    12,
      13,    14,    16,    77,    62,    63,    64,    65,    66,    67,
      84,    85,    86,     3,     4,     5,     6,     7,     8,     9,
      33,    16,    20,    16,    16,    15,    33,    17,    18,    33,
      19,    21,    11,    12,    13,    14,    11,    12,    13,    14,
      20,    31,    11,    12,    13,    14,    19,    16,    11,    12,
      13,    14,    19,    16,    33,    19,    14,    11,    33,    22,
      23,    24,    25,    26,    27,    11,    12,    13,    14,    20,
      16,    11,    12,    13,    14,    20,    22,    23,    24,    25,
      26,    27,    20,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    15,    17,
      18,    21,    31,    36,    37,    38,    39,    40,    41,    43,
       6,     6,     6,    34,     6,    39,    15,    15,    19,    40,
      15,     0,    36,    11,    12,    13,    14,    33,    33,    34,
      33,    34,    33,    34,    39,    16,    39,    42,    39,    42,
      37,     6,    32,    39,    39,    39,    39,    39,    39,    39,
      33,    16,    22,    23,    24,    25,    26,    27,    16,    16,
      16,    20,    16,    16,    33,    33,    33,    19,    39,    39,
      39,    39,    39,    39,    19,    19,    19,    33,    33,    37,
      37,    37,    37,    20,    20,    20,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    38,
      38,    38,    38,    38,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    42,    42,    42,    42,    43,    43
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     5,
       5,     5,     4,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     7,     7,     4,     2,     7,
       7,     3,     3,     3,     3,     3,     3,     5,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* S: DECLARE_VAR  */
#line 147 "main.y"
                    {printf("Passed var declaration/assignment!\n");}
#line 1392 "main.tab.c"
    break;

  case 5: /* S: OPERATION ';'  */
#line 148 "main.y"
                        {printf("Passed operation!\n");}
#line 1398 "main.tab.c"
    break;

  case 6: /* S: IF  */
#line 149 "main.y"
             {printf("Passed if!\n");}
#line 1404 "main.tab.c"
    break;

  case 7: /* S: WHILE  */
#line 150 "main.y"
                {printf("Passed while!\n");}
#line 1410 "main.tab.c"
    break;

  case 8: /* S: PRINT  */
#line 151 "main.y"
                {printf("Print passed!\n");}
#line 1416 "main.tab.c"
    break;

  case 9: /* DECLARE_VAR: TKN_INTEGER TKN_VAR_NAME '=' OPERATION ';'  */
#line 154 "main.y"
        {
            if(!ts->exists((yyvsp[-3].sir)))
            {
                ts->add((yyvsp[-3].sir), 'i', (yyvsp[-1].nr_float));
            }
        }
#line 1427 "main.tab.c"
    break;

  case 10: /* DECLARE_VAR: TKN_DOUBLE TKN_VAR_NAME '=' OPERATION ';'  */
#line 161 "main.y"
        {
            if(!ts->exists((yyvsp[-3].sir)))
            {
                ts->add((yyvsp[-3].sir), 'd', (yyvsp[-1].nr_float));
            }
        }
#line 1438 "main.tab.c"
    break;

  case 11: /* DECLARE_VAR: TKN_FLOAT TKN_VAR_NAME '=' OPERATION ';'  */
#line 168 "main.y"
        {
            if(!ts->exists((yyvsp[-3].sir)))
            {
                ts->add((yyvsp[-3].sir), 'f', (yyvsp[-1].nr_float));
            }
        }
#line 1449 "main.tab.c"
    break;

  case 12: /* DECLARE_VAR: TKN_VAR_NAME '=' OPERATION ';'  */
#line 175 "main.y"
        {
            if(ts->exists((yyvsp[-3].sir)))
            {
                if(ts->getType((yyvsp[-3].sir)) == 'i')
                    ts->setValue((yyvsp[-3].sir), (int)(yyvsp[-1].nr_float));
                else if(ts->getType((yyvsp[-3].sir)) == 'd')
                    ts->setValue((yyvsp[-3].sir), (double)(yyvsp[-1].nr_float));
                else if(ts->getType((yyvsp[-3].sir)) == 'f')
                    ts->setValue((yyvsp[-3].sir), (float)(yyvsp[-1].nr_float));
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].sir));
	    		yyerror(msg);
	    		YYERROR;
            }
        }
#line 1471 "main.tab.c"
    break;

  case 13: /* DECLARE_VAR: TKN_INTEGER TKN_VAR_NAME ';'  */
#line 193 "main.y"
        {
            if(!ts->exists((yyvsp[-1].sir)))
            {
                ts->add((yyvsp[-1].sir), 'i', 0);
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Declaratii multiple pentru variabila %s!", (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].sir));
				yyerror(msg);
				YYERROR;
            }
        }
#line 1488 "main.tab.c"
    break;

  case 14: /* DECLARE_VAR: TKN_DOUBLE TKN_VAR_NAME ';'  */
#line 206 "main.y"
        {
            if(!ts->exists((yyvsp[-1].sir)))
            {
                ts->add((yyvsp[-1].sir), 'd', 0);
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Declaratii multiple pentru variabila %s!", (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].sir));
				yyerror(msg);
				YYERROR;
            }
        }
#line 1505 "main.tab.c"
    break;

  case 15: /* DECLARE_VAR: TKN_FLOAT TKN_VAR_NAME ';'  */
#line 219 "main.y"
        {
            if(!ts->exists((yyvsp[-1].sir)))
            {
                ts->add((yyvsp[-1].sir), 'f', 0);
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Declaratii multiple pentru variabila %s!", (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].sir));
				yyerror(msg);
				YYERROR;
            }
        }
#line 1522 "main.tab.c"
    break;

  case 16: /* OPERATION: OPERATION TKN_ADD OPERATION  */
#line 232 "main.y"
                                            { (yyval.nr_float) = (yyvsp[-2].nr_float) + (yyvsp[0].nr_float); }
#line 1528 "main.tab.c"
    break;

  case 17: /* OPERATION: OPERATION TKN_SUB OPERATION  */
#line 233 "main.y"
                                      { (yyval.nr_float) = (yyvsp[-2].nr_float) - (yyvsp[0].nr_float); }
#line 1534 "main.tab.c"
    break;

  case 18: /* OPERATION: OPERATION TKN_DIVISION OPERATION  */
#line 235 "main.y"
        { 
            if ((yyvsp[0].nr_float) != 0)
            {
                (yyval.nr_float) = (yyvsp[-2].nr_float) / (yyvsp[0].nr_float);
            } else {
                fprintf(stderr, "%d.%d: Eroare semantica: Impartire la zero.", (yylsp[0]).first_line, (yylsp[0]).first_column);
                yyerror("Impartire la zero.");
                YYERROR;
            }
        }
#line 1549 "main.tab.c"
    break;

  case 19: /* OPERATION: OPERATION TKN_MULTIPLICATION OPERATION  */
#line 245 "main.y"
                                                 { (yyval.nr_float) = (yyvsp[-2].nr_float) * (yyvsp[0].nr_float); }
#line 1555 "main.tab.c"
    break;

  case 20: /* OPERATION: TKN_INTEGER_NUMBER  */
#line 246 "main.y"
                             { (yyval.nr_float) = (yyvsp[0].nr_integer); }
#line 1561 "main.tab.c"
    break;

  case 21: /* OPERATION: TKN_DOUBLE_NUMBER  */
#line 247 "main.y"
                            { (yyval.nr_float) = (yyvsp[0].nr_double); }
#line 1567 "main.tab.c"
    break;

  case 22: /* OPERATION: TKN_FLOAT_NUMBER  */
#line 248 "main.y"
                           { (yyval.nr_float) = (yyvsp[0].nr_float); }
#line 1573 "main.tab.c"
    break;

  case 23: /* OPERATION: TKN_VAR_NAME  */
#line 250 "main.y"
        {
            if(ts->exists((yyvsp[0].sir)))
            {
                (yyval.nr_float) = ts->getValue((yyvsp[0].sir));
            }
        }
#line 1584 "main.tab.c"
    break;

  case 24: /* OPERATION: TKN_LEFT_PARANTHESIS OPERATION TKN_RIGHT_PARANTHESIS  */
#line 257 "main.y"
        {
            (yyval.nr_float) = (yyvsp[-1].nr_float);
        }
#line 1592 "main.tab.c"
    break;

  case 31: /* COMPARE: OPERATION TKN_IS_EQUAL OPERATION  */
#line 270 "main.y"
        {
            if((yyvsp[-2].nr_float) == (yyvsp[0].nr_float))
            {
                (yyval.nr_integer) = 1;
            }
            else 
            {
                (yyval.nr_integer) = 0;
            }
        }
#line 1607 "main.tab.c"
    break;

  case 32: /* COMPARE: OPERATION TKN_IS_NOT_EQUAL OPERATION  */
#line 281 "main.y"
        {
            if((yyvsp[-2].nr_float) != (yyvsp[0].nr_float))
            {
                (yyval.nr_integer) = 1;
            }
            else 
            {
                (yyval.nr_integer) = 0;
            }
        }
#line 1622 "main.tab.c"
    break;

  case 33: /* COMPARE: OPERATION TKN_IS_LOWER OPERATION  */
#line 292 "main.y"
        {
            if((yyvsp[-2].nr_float) < (yyvsp[0].nr_float))
            {
                (yyval.nr_integer) = 1;
            }
            else 
            {
                (yyval.nr_integer) = 0;
            }
        }
#line 1637 "main.tab.c"
    break;

  case 34: /* COMPARE: OPERATION TKN_IS_HIGHER OPERATION  */
#line 303 "main.y"
        {
            if((yyvsp[-2].nr_float) > (yyvsp[0].nr_float))
            {
                (yyval.nr_integer) = 1;
            }
            else 
            {
                (yyval.nr_integer) = 0;
            }
        }
#line 1652 "main.tab.c"
    break;

  case 35: /* COMPARE: OPERATION TKN_IS_LOWER_OR_EQUAL OPERATION  */
#line 314 "main.y"
        {
            if((yyvsp[-2].nr_float) <= (yyvsp[0].nr_float))
            {
                (yyval.nr_integer) = 1;
            }
            else 
            {
                (yyval.nr_integer) = 0;
            }
        }
#line 1667 "main.tab.c"
    break;

  case 36: /* COMPARE: OPERATION TKN_IS_HIGHER_OR_EQUAL OPERATION  */
#line 325 "main.y"
        {
            if((yyvsp[-2].nr_float) >= (yyvsp[0].nr_float))
            {
                (yyval.nr_integer) = 1;
            }
            else 
            {
                (yyval.nr_integer) = 0;
            }
        }
#line 1682 "main.tab.c"
    break;

  case 37: /* PRINT: TKN_PRINT TKN_LEFT_PARANTHESIS TKN_VAR_NAME TKN_RIGHT_PARANTHESIS ';'  */
#line 337 "main.y"
        {
            if(ts->exists((yyvsp[-2].sir)))
            {
                cout << ts->getValue((yyvsp[-2].sir)) << "\n";
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-2].sir));
	    		yyerror(msg);
	    		YYERROR;
            }
        }
#line 1699 "main.tab.c"
    break;


#line 1703 "main.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 351 "main.y"


int main()
{
    yyparse();
    ts->printVars();
    return 0;
}

int yyerror(const char* error)
{
    printf("Eroare: %s!\n", error);
    return 0;
}
