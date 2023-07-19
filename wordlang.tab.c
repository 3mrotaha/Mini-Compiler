
/*  A Bison parser, made from wordlang.y
 by  GNU Bison version 1.27
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	CHAR_CONSTANT	257
#define	INT_CONSTANT	258
#define	WORD_CONSTANT	259
#define	SENTENCE_CONSTANT	260
#define	IDENTIFIER	261
#define	CHAR_TYPE	262
#define	INT_TYPE	263
#define	WORD_TYPE	264
#define	SENTENCE_TYPE	265
#define	INPUT	266
#define	OUTPUT	267
#define	LOOP	268
#define	IF	269
#define	ELSE	270
#define	WHILE	271
#define	TRUE	272
#define	FALSE	273
#define	ADD	274
#define	REMOVE	275
#define	CONCAT	276
#define	GET	277
#define	LT	278
#define	GT	279
#define	LE	280
#define	GE	281
#define	EQ	282
#define	NE	283
#define	EQUAL	284
#define	NOT	285
#define	COMMA	286
#define	SEMI_COLON	287
#define	OPEN_BRACKET	288
#define	CLOSE_BRACKET	289
#define	OPEN_PAREN	290
#define	CLOSE_PAREN	291

#line 1 "wordlang.y"

#include "SymbolTable\symbolTable.h"
#include "SymanticAnalyzer/symanticAnalyzer.h"
#include "AST\AST.h"
#include "CodeGenerator/codeGenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int yywrap();
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yydebug = 1;
FILE* file;
int tempCount = 0;
extern char outputFile[50];
extern DataType_t dataType;
extern ASTnode_t *root;
extern ASTnode_t *exprRoot;
extern FILE* traverseFile;
char condExpr[500] = "";
void print_sentence(char* sentence);
void storeInSymbolTable(char *name, Type_t type, DataType_t dataType, int lineNo, char* value);
void yyerror(const char* s);

/* Additional function declarations */


#line 33 "wordlang.y"
typedef union {
    struct {
        char* name;
        int intVal;
        char charVal;
        char* wordVal;
        DataType_t varType;
        Type_t type;
        ASTnode_t *nd;
    }nodeType;
} YYSTYPE;
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		108
#define	YYFLAG		-32768
#define	YYNTBASE	40

#define YYTRANSLATE(x) ((unsigned)(x) <= 291 ? yytranslate[x] : 68)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
    39,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    10,    15,    20,    24,    26,
    28,    30,    32,    34,    36,    40,    44,    45,    51,    54,
    55,    60,    63,    65,    67,    69,    71,    73,    75,    79,
    83,    85,    88,    90,    92,    94,    96,    98,   100,   102,
   104,   107,   108,   109,   119,   120,   127,   128,   132,   133,
   134,   141,   145,   148,   150,   152,   154,   156,   158,   160,
   162,   164,   166,   168,   170,   172,   173,   182,   183,   190,
   191,   200,   201
};

static const short yyrhs[] = {    41,
     0,    42,     0,    41,    42,     0,    45,     0,     0,     7,
    43,    49,    33,     0,    12,     6,     7,    33,     0,    13,
    48,    33,     0,    51,     0,    63,     0,     8,     0,     9,
     0,    10,     0,    11,     0,    44,     7,    33,     0,    44,
     7,    32,     0,     0,    44,     7,    46,    49,    33,     0,
     7,    32,     0,     0,     7,    47,    49,    33,     0,     7,
    33,     0,    32,     0,    33,     0,    34,     0,    35,     0,
    36,     0,    37,     0,    36,    48,    37,     0,    48,    62,
    48,     0,    50,     0,    30,    48,     0,     4,     0,     3,
     0,     5,     0,     6,     0,     7,     0,    18,     0,    19,
     0,    52,     0,    52,    56,     0,     0,     0,    15,    36,
    60,    37,    53,    34,    54,    41,    35,     0,     0,    15,
    36,    60,    37,    55,    42,     0,     0,    16,    57,    42,
     0,     0,     0,    16,    58,    34,    59,    41,    35,     0,
    48,    61,    48,     0,    31,    60,     0,    48,     0,    26,
     0,    27,     0,    28,     0,    29,     0,    25,     0,    24,
     0,    31,     0,    20,     0,    22,     0,    21,     0,    23,
     0,     0,    14,    36,    60,    37,    64,    34,    41,    35,
     0,     0,    14,    36,    60,    37,    65,    42,     0,     0,
    17,    36,    60,    37,    66,    34,    41,    35,     0,     0,
    17,    36,    60,    37,    67,    42,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    64,    70,    73,    80,    84,    84,    93,   102,   108,   112,
   119,   122,   125,   128,   133,   145,   157,   157,   168,   184,
   184,   192,   211,   212,   213,   214,   215,   216,   219,   223,
   227,   235,   243,   250,   257,   264,   271,   279,   286,   296,
   297,   300,   300,   300,   306,   306,   312,   312,   316,   316,
   316,   323,   333,   341,   350,   351,   352,   353,   354,   355,
   356,   358,   359,   360,   361,   363,   363,   369,   369,   375,
   375,   381,   382
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","CHAR_CONSTANT",
"INT_CONSTANT","WORD_CONSTANT","SENTENCE_CONSTANT","IDENTIFIER","CHAR_TYPE",
"INT_TYPE","WORD_TYPE","SENTENCE_TYPE","INPUT","OUTPUT","LOOP","IF","ELSE","WHILE",
"TRUE","FALSE","ADD","REMOVE","CONCAT","GET","LT","GT","LE","GE","EQ","NE","EQUAL",
"NOT","COMMA","SEMI_COLON","OPEN_BRACKET","CLOSE_BRACKET","OPEN_PAREN","CLOSE_PAREN",
"'('","')'","program","statement_list","statement","@1","datatype","declaration",
"@2","@3","expression","assignment","value","conditional_statement","if_clause",
"@4","@5","@6","else_clause","@7","@8","@9","condition","relop","arthop","loop_statement",
"@10","@11","@12","@13", NULL
};
#endif

static const short yyr1[] = {     0,
    40,    41,    41,    42,    43,    42,    42,    42,    42,    42,
    44,    44,    44,    44,    45,    45,    46,    45,    45,    47,
    45,    45,    -1,    -1,    -1,    -1,    -1,    -1,    48,    48,
    48,    49,    50,    50,    50,    50,    50,    50,    50,    51,
    51,    53,    54,    52,    55,    52,    57,    56,    58,    59,
    56,    60,    60,    60,    61,    61,    61,    61,    61,    61,
    61,    62,    62,    62,    62,    64,    63,    65,    63,    66,
    63,    67,    63
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     0,     4,     4,     3,     1,     1,
     1,     1,     1,     1,     3,     3,     0,     5,     2,     0,
     4,     2,     1,     1,     1,     1,     1,     1,     3,     3,
     1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
     2,     0,     0,     9,     0,     6,     0,     3,     0,     0,
     6,     3,     2,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     0,     8,     0,     6,     0,
     8,     0,     6
};

static const short yydefact[] = {     0,
     5,    11,    12,    13,    14,     0,     0,     0,     0,     0,
     1,     2,     0,     4,     9,    40,    10,    19,    22,     0,
     0,     0,    34,    33,    35,    36,    37,    38,    39,     0,
     0,    31,     0,     0,     0,     3,    17,    47,    41,     0,
     0,     0,     0,     0,    62,    64,    63,    65,     8,     0,
     0,    54,     0,     0,     0,    16,    15,     0,     0,     0,
    32,     6,    21,     7,    29,    30,    53,    60,    59,    55,
    56,    57,    58,    61,     0,    68,    45,    72,     0,    48,
    50,    52,     0,     0,     0,     0,     0,     0,    18,     0,
     0,    69,    43,    46,     0,    73,     0,     0,     0,     0,
    51,    67,     0,    71,    44,     0,     0,     0
};

static const short yydefgoto[] = {   106,
    11,    12,    20,    13,    14,    58,    21,    52,    41,    32,
    15,    16,    85,    99,    86,    39,    59,    60,    90,    53,
    75,    50,    17,    83,    84,    87,    88
};

static const short yypact[] = {   131,
   -24,-32768,-32768,-32768,-32768,     9,     7,   -14,   -13,    -9,
   131,-32768,    21,-32768,-32768,    13,-32768,-32768,-32768,     2,
     2,    23,-32768,-32768,-32768,-32768,-32768,-32768,-32768,     7,
   114,-32768,     0,     0,     0,-32768,   -12,     1,-32768,     7,
     8,    12,    14,    42,-32768,-32768,-32768,-32768,-32768,     7,
     0,   132,     3,    22,    24,-32768,-32768,     2,   131,    15,
    60,-32768,-32768,-32768,-32768,    60,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,     7,    32,    33,    34,    37,-32768,
-32768,    60,    38,   131,    40,   131,    50,   131,-32768,   131,
   131,-32768,-32768,-32768,   131,-32768,    43,    86,   131,    97,
-32768,-32768,   116,-32768,-32768,    71,    76,-32768
};

static const short yypgoto[] = {-32768,
   -53,   -11,-32768,-32768,-32768,-32768,-32768,    -6,   -19,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -18,
-32768,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		163


static const short yytable[] = {    36,
    31,    42,    23,    24,    25,    26,    27,    18,    19,    23,
    24,    25,    26,    27,    22,    54,    55,    28,    29,    56,
    57,    33,    34,    44,    28,    29,    35,    37,    38,    43,
    51,    40,    67,    61,   -49,    30,    97,    98,    79,    76,
    62,   100,    30,    66,    63,   103,    64,    80,    81,     1,
     2,     3,     4,     5,     6,     7,     8,     9,    77,    10,
    78,    45,    46,    47,    48,   -66,   -42,   -70,    82,    89,
   107,    91,    92,    93,    94,   108,    96,   101,    65,    45,
    46,    47,    48,    95,     0,    36,    36,     0,    36,     0,
     0,    36,     1,     2,     3,     4,     5,     6,     7,     8,
     9,     0,    10,     1,     2,     3,     4,     5,     6,     7,
     8,     9,     0,    10,     0,     0,     0,     0,     0,     0,
   102,     0,     1,     2,     3,     4,     5,     6,     7,     8,
     9,   104,    10,    45,    46,    47,    48,     1,     2,     3,
     4,     5,     6,     7,     8,     9,    49,    10,     0,     0,
   105,    45,    46,    47,    48,    68,    69,    70,    71,    72,
    73,     0,    74
};

static const short yycheck[] = {    11,
     7,    21,     3,     4,     5,     6,     7,    32,    33,     3,
     4,     5,     6,     7,     6,    34,    35,    18,    19,    32,
    33,    36,    36,    30,    18,    19,    36,     7,    16,     7,
    31,    30,    51,    40,    34,    36,    90,    91,    58,    37,
    33,    95,    36,    50,    33,    99,    33,    59,    34,     7,
     8,     9,    10,    11,    12,    13,    14,    15,    37,    17,
    37,    20,    21,    22,    23,    34,    34,    34,    75,    33,
     0,    34,    84,    34,    86,     0,    88,    35,    37,    20,
    21,    22,    23,    34,    -1,    97,    98,    -1,   100,    -1,
    -1,   103,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    -1,    17,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
    35,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    35,    17,    20,    21,    22,    23,     7,     8,     9,
    10,    11,    12,    13,    14,    15,    33,    17,    -1,    -1,
    35,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    -1,    31
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"
/* This file comes from bison-1.27.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 216 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 64 "wordlang.y"
{
        //printf("Program is syntactically correct.\n");
        yyval.nodeType.nd = AST_mkNode(yyvsp[0].nodeType.nd, NULL, "start");
        root = yyval.nodeType.nd;
;
    break;}
case 2:
#line 70 "wordlang.y"
{
            yyval.nodeType.nd = yyvsp[0].nodeType.nd;
        ;
    break;}
case 3:
#line 73 "wordlang.y"
{ 
            yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, yyvsp[0].nodeType.nd, "statement_list");
            //printf("statement_list\n");
        ;
    break;}
case 4:
#line 80 "wordlang.y"
{ 
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                //printf("declaration\n");
         ;
    break;}
case 5:
#line 84 "wordlang.y"
{codeGen_id(yyvsp[0].nodeType.name);;
    break;}
case 6:
#line 84 "wordlang.y"
{
                //printf("start assignment\n");
                checkDeclaration(yyvsp[-3].nodeType.name);
                yyvsp[-3].nodeType.varType = getDataType(yyvsp[-3].nodeType.name);
                checkType(yyvsp[-3].nodeType.varType, yyvsp[-1].nodeType.varType);                
                yyvsp[-3].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-3].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-3].nodeType.name);
                codeGen_punc(yyvsp[0].nodeType.name);                
         ;
    break;}
case 7:
#line 93 "wordlang.y"
{         
            checkDeclaration(yyvsp[-1].nodeType.name);
            yyvsp[-2].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-2].nodeType.name);
            yyvsp[-1].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-1].nodeType.name);
            yyval.nodeType.nd = AST_mkNode(yyvsp[-2].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-3].nodeType.name);
            yyvsp[-1].nodeType.varType = getDataType(yyvsp[-1].nodeType.name);
            codeGen_input(yyvsp[-2].nodeType.name, yyvsp[-1].nodeType.name, yyvsp[-1].nodeType.varType);
            //printf("input\n");
        ;
    break;}
case 8:
#line 102 "wordlang.y"
{
            yyval.nodeType.nd = exprRoot = AST_mkNode(NULL, yyvsp[-1].nodeType.nd, yyvsp[-2].nodeType.name);
            char* expr = strdup(codeGen_expression(exprRoot->right));
            codeGen_output(expr);
            //printf("output\n");
         ;
    break;}
case 9:
#line 108 "wordlang.y"
{ 
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                //printf("conditional_statement\n");
          ;
    break;}
case 10:
#line 112 "wordlang.y"
{ 
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                //printf("loop_statement\n");
          ;
    break;}
case 11:
#line 119 "wordlang.y"
{ insert_type(yytext); 
                    //printf("char\n");                    
;
    break;}
case 12:
#line 122 "wordlang.y"
{ insert_type(yytext); 
                //printf("int\n");
        ;
    break;}
case 13:
#line 125 "wordlang.y"
{ insert_type(yytext); 
                //printf("word\n");
        ;
    break;}
case 14:
#line 128 "wordlang.y"
{ insert_type(yytext); 
                //printf("sentence\n");
        ;
    break;}
case 15:
#line 133 "wordlang.y"
{
                isValidVarName(yyvsp[-1].nodeType.name);
                checkMultiDeclaration(yyvsp[-1].nodeType.name);
                storeInSymbolTable(yyvsp[-1].nodeType.name, VARIABLE, dataType, yylineno, "");
                yyvsp[-1].nodeType.varType = dataType;
                yyvsp[-1].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-1].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, NULL, "declaration");
                codeGen_declare(yyvsp[-1].nodeType.name, dataType);
                codeGen_initVar(dataType);
                codeGen_punc(yyvsp[0].nodeType.name);
                //printf("declaration without assignment\n");
             ;
    break;}
case 16:
#line 145 "wordlang.y"
{
                isValidVarName(yyvsp[-1].nodeType.name);
                checkMultiDeclaration(yyvsp[-1].nodeType.name);
                storeInSymbolTable(yyvsp[-1].nodeType.name, VARIABLE, dataType, yylineno, "");
                yyvsp[-1].nodeType.varType = dataType;
                yyvsp[-1].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-1].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, yyvsp[0].nodeType.nd, "declaration");
                codeGen_declare(yyvsp[-1].nodeType.name, dataType);
                codeGen_initVar(dataType);
                codeGen_punc(yyvsp[0].nodeType.name);
                //printf("declaration without assignment\n");
             ;
    break;}
case 17:
#line 157 "wordlang.y"
{codeGen_declare(yyvsp[0].nodeType.name, dataType);;
    break;}
case 18:
#line 157 "wordlang.y"
{
                isValidVarName(yyvsp[-3].nodeType.name);
                checkMultiDeclaration(yyvsp[-3].nodeType.name);
                checkType(dataType, yyvsp[-1].nodeType.varType);
                storeInSymbolTable(yyvsp[-3].nodeType.name, VARIABLE, dataType, yylineno, "");
                yyvsp[-3].nodeType.varType = dataType;
                yyvsp[-3].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-3].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[-1].nodeType.nd, "declaration");
                codeGen_punc(yyvsp[0].nodeType.name);
                //printf("declaration with assignment\n");
            ;
    break;}
case 19:
#line 168 "wordlang.y"
{
                isValidVarName(yyvsp[-1].nodeType.name);
                checkMultiDeclaration(yyvsp[-1].nodeType.name);
                storeInSymbolTable(yyvsp[-1].nodeType.name, VARIABLE, dataType, yylineno, "");
                yyvsp[-1].nodeType.varType = dataType;
                yyvsp[-1].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-1].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, yyvsp[0].nodeType.nd, "declaration");
                char* result = strdup("");
                if(dataType != INT && dataType != CHAR)
                    result = strdup("*");
                strcat(result, yyvsp[-1].nodeType.name);
                codeGen_id(result);
                codeGen_initVar(dataType);
                codeGen_punc(yyvsp[0].nodeType.name);                
                //printf("declaration without assignment\n");                
            ;
    break;}
case 20:
#line 184 "wordlang.y"
{codeGen_id(yyvsp[0].nodeType.name);;
    break;}
case 21:
#line 184 "wordlang.y"
{
                checkDeclaration(yyvsp[-3].nodeType.name);
                yyvsp[-3].nodeType.varType = getDataType(yyvsp[-3].nodeType.name);
                checkType(yyvsp[-3].nodeType.varType, yyvsp[-1].nodeType.varType);                
                yyvsp[-3].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-3].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-3].nodeType.name);
                codeGen_punc(yyvsp[0].nodeType.name);
            ;
    break;}
case 22:
#line 192 "wordlang.y"
{
                isValidVarName(yyvsp[-1].nodeType.name);
                checkMultiDeclaration(yyvsp[-1].nodeType.name);
                storeInSymbolTable(yyvsp[-1].nodeType.name, VARIABLE, dataType, yylineno, "");
                yyvsp[-1].nodeType.varType = dataType;
                yyvsp[-1].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-1].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, NULL, "declaration");
                char* result = strdup("");
                if(dataType != INT && dataType != CHAR)
                    result = strdup("*");
                strcat(result, yyvsp[-1].nodeType.name);
                codeGen_id(result);
                codeGen_initVar(dataType);
                codeGen_punc(yyvsp[0].nodeType.name);
                //printf("declaration without assignment\n");
            ;
    break;}
case 23:
#line 211 "wordlang.y"
{ codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 24:
#line 212 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 25:
#line 213 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 26:
#line 214 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 27:
#line 215 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 28:
#line 216 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 29:
#line 219 "wordlang.y"
{                
                yyval.nodeType.varType = yyvsp[-1].nodeType.varType;
                yyval.nodeType.nd = yyvsp[-1].nodeType.nd;
            ;
    break;}
case 30:
#line 223 "wordlang.y"
{                                           
                yyval.nodeType.varType = checkExprDataType(yyvsp[-2].nodeType.varType, yyvsp[0].nodeType.varType, yyvsp[-1].nodeType.name);     
                yyval.nodeType.nd = AST_mkNode(yyvsp[-2].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);                                
            ;
    break;}
case 31:
#line 227 "wordlang.y"
{
                yyval.nodeType.varType = yyvsp[0].nodeType.varType;
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                yyval.nodeType.name = yyvsp[0].nodeType.name;
            ;
    break;}
case 32:
#line 235 "wordlang.y"
{    
                yyval.nodeType.varType = yyvsp[0].nodeType.varType;
                yyval.nodeType.nd = exprRoot = AST_mkNode(yyvsp[-1].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);
                char* expr = strdup(codeGen_expression(exprRoot->right));
                codeGen_assign(expr, yyvsp[0].nodeType.varType);
;
    break;}
case 33:
#line 243 "wordlang.y"
{        
        storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, INT, yylineno, yytext);
        yyval.nodeType.varType = INT;
        yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
        yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
        //printf("int\n");
    ;
    break;}
case 34:
#line 250 "wordlang.y"
{
        storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, CHAR, yylineno, yytext);
        yyval.nodeType.varType = CHAR;
        yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
        yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
        //printf("char\n");
    ;
    break;}
case 35:
#line 257 "wordlang.y"
{ 
        storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, WORD, yylineno, yyvsp[0].nodeType.wordVal);
        yyval.nodeType.varType = WORD;
        yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
        yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
        //printf("word\n");
    ;
    break;}
case 36:
#line 264 "wordlang.y"
{
         printf("sentence\n"); 
         storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, SENTENCE, yylineno, yyvsp[0].nodeType.wordVal);
         yyval.nodeType.varType = SENTENCE;
         yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
         yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
    ;
    break;}
case 37:
#line 271 "wordlang.y"
{
            checkDeclaration(yyvsp[0].nodeType.name);
            yyval.nodeType.varType = getDataType(yyvsp[0].nodeType.name);
            //printf("varType: %d\n", $1.varType);
            yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
            yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
            //printf("identifier\n");
    ;
    break;}
case 38:
#line 279 "wordlang.y"
{
            storeInSymbolTable(yyvsp[0].nodeType.name, KEYWORD, INT, yylineno, "1");
            yyval.nodeType.varType = INT;
            yyval.nodeType.nd = NULL;
            strcpy(yyval.nodeType.name, "1");
            //printf("true\n");
          ;
    break;}
case 39:
#line 286 "wordlang.y"
{
            storeInSymbolTable(yyvsp[0].nodeType.name, KEYWORD, INT, yylineno, "0");
            yyval.nodeType.varType = INT;
            yyval.nodeType.nd = NULL;
            strcpy(yyval.nodeType.name, "0");
            //printf("false\n");
        ;
    break;}
case 42:
#line 300 "wordlang.y"
{codeGen_if(condExpr);;
    break;}
case 43:
#line 300 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 44:
#line 300 "wordlang.y"
{
        yyval.nodeType.nd = AST_mkNode(yyvsp[-6].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-8].nodeType.name);
        strcpy(condExpr, "");
        codeGen_punc(yyvsp[0].nodeType.name);
        //printf("if with brackets\n");
     ;
    break;}
case 45:
#line 306 "wordlang.y"
{codeGen_if(condExpr);;
    break;}
case 46:
#line 306 "wordlang.y"
{ 
        yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-5].nodeType.name);
        strcpy(condExpr, "");
        //printf("if\n");
     ;
    break;}
case 47:
#line 312 "wordlang.y"
{codeGen_else();;
    break;}
case 48:
#line 312 "wordlang.y"
{ 
        yyval.nodeType.nd = AST_mkNode(NULL, yyvsp[0].nodeType.nd, "else");
        //printf("else\n");
 ;
    break;}
case 49:
#line 316 "wordlang.y"
{codeGen_else();;
    break;}
case 50:
#line 316 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 51:
#line 316 "wordlang.y"
{
        yyval.nodeType.nd = AST_mkNode(NULL, yyvsp[-1].nodeType.nd, "else");
        codeGen_punc(yyvsp[0].nodeType.name);
        //printf("else with brackets\n");
     ;
    break;}
case 52:
#line 323 "wordlang.y"
{
                checkType(yyvsp[-2].nodeType.varType, yyvsp[0].nodeType.varType);
                char* expr1 = strdup(codeGen_expression(yyvsp[-2].nodeType.nd));
                codeGen_clearWorkTree();
                char* expr2 = strdup(codeGen_expression(yyvsp[0].nodeType.nd));
                strcpy(condExpr, "");
                strcpy(condExpr, strdup(codeGen_condition(expr1, yyvsp[-2].nodeType.varType, expr2, yyvsp[0].nodeType.varType, yyvsp[-1].nodeType.name)));
                yyval.nodeType.varType = INT;
                yyval.nodeType.nd = AST_mkNode(yyvsp[-2].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);                                
            ;
    break;}
case 53:
#line 333 "wordlang.y"
{
                checkType(yyvsp[0].nodeType.varType, INT);
                yyval.nodeType.varType = yyvsp[0].nodeType.varType;
                char* expr1 = strdup(codeGen_expression(yyvsp[0].nodeType.nd));
                strcpy(condExpr, "");
                strcpy(condExpr, strdup(codeGen_condition(expr1, yyvsp[-1].nodeType.varType, NULL, EMPTY, yyvsp[-1].nodeType.name)));
                yyval.nodeType.nd = AST_mkNode(NULL, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);
          ;
    break;}
case 54:
#line 341 "wordlang.y"
{                
                char* expr1 = strdup(codeGen_expression(yyvsp[0].nodeType.nd));
                strcpy(condExpr, "");
                strcpy(condExpr ,strdup(codeGen_condition(expr1, yyvsp[0].nodeType.varType, NULL, EMPTY, NULL)));
                yyval.nodeType.varType = yyvsp[0].nodeType.varType;
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
          ;
    break;}
case 66:
#line 363 "wordlang.y"
{codeGen_loop(condExpr);;
    break;}
case 67:
#line 363 "wordlang.y"
{    
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-5].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-7].nodeType.name);
                    strcpy(condExpr, "");
                    codeGen_punc(yyvsp[0].nodeType.name);
                    //printf("loop\n");                    
                ;
    break;}
case 68:
#line 369 "wordlang.y"
{codeGen_loop(condExpr);;
    break;}
case 69:
#line 369 "wordlang.y"
{                 
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-5].nodeType.name);
                    strcpy(condExpr, "");                    
                    codeGen_punc("}");
                    //printf("loop\n");
                ;
    break;}
case 70:
#line 375 "wordlang.y"
{codeGen_while(condExpr);;
    break;}
case 71:
#line 375 "wordlang.y"
{
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-5].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-7].nodeType.name);
                    strcpy(condExpr, "");
                    codeGen_punc(yyvsp[0].nodeType.name);                    
                    //printf("while\n");
                ;
    break;}
case 72:
#line 381 "wordlang.y"
{codeGen_while(condExpr);;
    break;}
case 73:
#line 382 "wordlang.y"
{ 
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-5].nodeType.name);
                    strcpy(condExpr, "");
                    codeGen_punc("}");                     
                    //printf("while\n");
                ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 542 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 390 "wordlang.y"


void yyerror(const char* s) {
    printf("at line %d: Error; %s\n", yylineno, s);
    exit(1);
}

int main(int argc, char* argv[]) {
    static int WriteOnce = 0;
    if (argc < 3) {
        printf("Usage: %s <input_wordlang_file> <c_output_file>\n", argv[0]);
        return 1;
    }
    strcpy(outputFile, argv[2]);
    FILE* inputFile = fopen(argv[1], "r");    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    yyin = inputFile;
    
    if(WriteOnce == 0){
        codeGen_Init();
        symbolTable_init();
        WriteOnce++;
    }

    yyparse();
    fclose(inputFile);
    /* print_symbol_table(); */
    /* traverseFile = fopen("traverse.txt", "w+");
    AST_traverse(root, 0);
    fclose(traverseFile); */
    codeGen_Close();
    return 0;
}


/* Helper function definitions */

void storeInSymbolTable(char *name, Type_t type, DataType_t dataType, int lineNo, char* value){
    if(dataType == INT) {
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(value)});
    } else if(dataType == CHAR) {
        char arr[2] = {value[1], '\0'};
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(arr)});
    } else if(dataType == WORD) {
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(value)});
    } else if(dataType == SENTENCE) {
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo, .Value=strdup(value)});
    }
    else{
        insert_symbol((symbolTable_t) {.name=strdup(name), .type=type, .dataType=dataType, .lineNo=lineNo});
    }
}

void print_sentence(char* sentence){
    int i = 0;
    while(sentence[i] != '\n'){
        printf("%c", sentence[i]);
        i++;
    }
}
