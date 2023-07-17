
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
extern DataType_t dataType;
extern ASTnode_t *root;
extern ASTnode_t *exprRoot;
extern FILE* traverseFile;
char* buff;
void print_sentence(char* sentence);
void storeInSymbolTable(char *name, Type_t type, DataType_t dataType, int lineNo, char* value);
void yyerror(const char* s);

/* Additional function declarations */


#line 32 "wordlang.y"
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



#define	YYFINAL		104
#define	YYFLAG		-32768
#define	YYNTBASE	40

#define YYTRANSLATE(x) ((unsigned)(x) <= 291 ? yytranslate[x] : 67)

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
    28,    30,    32,    34,    36,    40,    41,    47,    49,    51,
    53,    55,    57,    59,    63,    67,    69,    72,    74,    76,
    78,    80,    82,    84,    87,    88,    89,    99,   100,   107,
   108,   112,   113,   114,   121,   123,   127,   130,   132,   134,
   136,   138,   140,   142,   144,   146,   148,   150,   152,   154,
   156,   157,   166,   167,   174,   175,   184,   185
};

static const short yyrhs[] = {    41,
     0,    42,     0,    41,    42,     0,    45,     0,     0,     7,
    43,    48,    33,     0,    12,     6,     7,    33,     0,    13,
    47,    33,     0,    50,     0,    62,     0,     8,     0,     9,
     0,    10,     0,    11,     0,    44,     7,    33,     0,     0,
    44,     7,    46,    48,    33,     0,    32,     0,    33,     0,
    34,     0,    35,     0,    36,     0,    37,     0,    36,    47,
    37,     0,    47,    61,    47,     0,    49,     0,    30,    47,
     0,     4,     0,     3,     0,     5,     0,     6,     0,     7,
     0,    51,     0,    51,    55,     0,     0,     0,    15,    36,
    59,    37,    52,    34,    53,    41,    35,     0,     0,    15,
    36,    59,    37,    54,    42,     0,     0,    16,    56,    42,
     0,     0,     0,    16,    57,    34,    58,    41,    35,     0,
    49,     0,    47,    60,    47,     0,    31,    59,     0,    18,
     0,    19,     0,    26,     0,    27,     0,    28,     0,    29,
     0,    25,     0,    24,     0,    31,     0,    20,     0,    22,
     0,    21,     0,    23,     0,     0,    14,    36,    47,    37,
    63,    34,    41,    35,     0,     0,    14,    36,    47,    37,
    64,    42,     0,     0,    17,    36,    59,    37,    65,    34,
    41,    35,     0,     0,    17,    36,    59,    66,    37,    42,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    63,    69,    72,    79,    83,    83,    91,   100,   106,   110,
   117,   120,   123,   126,   131,   142,   142,   155,   156,   157,
   158,   159,   160,   163,   167,   171,   178,   186,   193,   200,
   207,   214,   225,   226,   228,   228,   228,   233,   233,   238,
   238,   242,   242,   242,   249,   254,   261,   268,   275,   284,
   285,   286,   287,   288,   289,   290,   292,   293,   294,   295,
   297,   298,   303,   304,   309,   310,   315,   316
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","CHAR_CONSTANT",
"INT_CONSTANT","WORD_CONSTANT","SENTENCE_CONSTANT","IDENTIFIER","CHAR_TYPE",
"INT_TYPE","WORD_TYPE","SENTENCE_TYPE","INPUT","OUTPUT","LOOP","IF","ELSE","WHILE",
"TRUE","FALSE","ADD","REMOVE","CONCAT","GET","LT","GT","LE","GE","EQ","NE","EQUAL",
"NOT","COMMA","SEMI_COLON","OPEN_BRACKET","CLOSE_BRACKET","OPEN_PAREN","CLOSE_PAREN",
"'('","')'","program","statement_list","statement","@1","datatype","declaration",
"@2","expression","assignment","value","conditional_statement","if_clause","@3",
"@4","@5","else_clause","@6","@7","@8","condition","relop","arthop","loop_statement",
"@9","@10","@11","@12", NULL
};
#endif

static const short yyr1[] = {     0,
    40,    41,    41,    42,    43,    42,    42,    42,    42,    42,
    44,    44,    44,    44,    45,    46,    45,    -1,    -1,    -1,
    -1,    -1,    -1,    47,    47,    47,    48,    49,    49,    49,
    49,    49,    50,    50,    52,    53,    51,    54,    51,    56,
    55,    57,    58,    55,    59,    59,    59,    59,    59,    60,
    60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
    63,    62,    64,    62,    65,    62,    66,    62
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     0,     4,     4,     3,     1,     1,
     1,     1,     1,     1,     3,     0,     5,     1,     1,     1,
     1,     1,     1,     3,     3,     1,     2,     1,     1,     1,
     1,     1,     1,     2,     0,     0,     9,     0,     6,     0,
     3,     0,     0,     6,     1,     3,     2,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     0,     8,     0,     6,     0,     8,     0,     6
};

static const short yydefact[] = {     0,
     5,    11,    12,    13,    14,     0,     0,     0,     0,     0,
     1,     2,     0,     4,     9,    33,    10,     0,     0,    29,
    28,    30,    31,    32,     0,     0,    26,     0,     0,     0,
     3,    16,    40,    34,     0,     0,     0,     0,    57,    59,
    58,    60,     8,     0,     0,    48,    49,     0,     0,    26,
     0,     0,    15,     0,     0,     0,    27,     6,     7,    24,
    25,    63,    47,    55,    54,    50,    51,    52,    53,    56,
     0,    38,    65,     0,     0,    41,    43,     0,     0,    46,
     0,     0,     0,     0,    17,     0,     0,    64,    36,    39,
     0,    68,     0,     0,     0,     0,    44,    62,     0,    66,
    37,     0,     0,     0
};

static const short yydefgoto[] = {   102,
    11,    12,    18,    13,    14,    54,    49,    36,    27,    15,
    16,    81,    95,    82,    34,    55,    56,    86,    51,    71,
    44,    17,    78,    79,    83,    74
};

static const short yypact[] = {   127,
-32768,-32768,-32768,-32768,-32768,    15,     4,   -13,    -3,    -2,
   127,-32768,    29,-32768,-32768,    21,-32768,     9,    34,-32768,
-32768,-32768,-32768,-32768,     4,   110,-32768,     4,    -1,    -1,
-32768,    10,    11,-32768,     4,    22,    24,     5,-32768,-32768,
-32768,-32768,-32768,     4,    38,-32768,-32768,    -1,   128,    25,
    26,    27,-32768,     9,   127,    32,    56,-32768,-32768,-32768,
    56,    33,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     4,    35,-32768,    43,    37,-32768,-32768,    47,   127,    56,
    50,   127,    52,   127,-32768,   127,   127,-32768,-32768,-32768,
   127,-32768,    39,    82,   127,    93,-32768,-32768,   112,-32768,
-32768,    72,    87,-32768
};

static const short yypgoto[] = {-32768,
   -71,   -11,-32768,-32768,-32768,-32768,    -6,    44,   -17,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -16,-32768,
-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		159


static const short yytable[] = {    31,
    26,    20,    21,    22,    23,    24,    20,    21,    22,    23,
    24,    50,    50,    52,    93,    94,    46,    47,    38,    96,
    19,    45,    28,    99,    39,    40,    41,    42,    57,    48,
    50,    63,    29,    30,    25,    32,    33,    61,    35,    25,
    37,    60,    53,    76,   -42,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    58,    10,    59,    39,    40,    41,
    42,   -45,    72,    73,    80,    77,   -61,    88,   -35,    85,
    90,   103,    92,    97,    62,    39,    40,    41,    42,    84,
    87,    31,    31,    89,    31,    91,   104,    31,     1,     2,
     3,     4,     5,     6,     7,     8,     9,    75,    10,     1,
     2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
     0,     0,     0,     0,     0,     0,    98,     0,     1,     2,
     3,     4,     5,     6,     7,     8,     9,   100,    10,    39,
    40,    41,    42,     1,     2,     3,     4,     5,     6,     7,
     8,     9,    43,    10,     0,     0,   101,    39,    40,    41,
    42,    64,    65,    66,    67,    68,    69,     0,    70
};

static const short yycheck[] = {    11,
     7,     3,     4,     5,     6,     7,     3,     4,     5,     6,
     7,    29,    30,    30,    86,    87,    18,    19,    25,    91,
     6,    28,    36,    95,    20,    21,    22,    23,    35,    31,
    48,    48,    36,    36,    36,     7,    16,    44,    30,    36,
     7,    37,    33,    55,    34,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    33,    17,    33,    20,    21,    22,
    23,    37,    37,    37,    71,    34,    34,    79,    34,    33,
    82,     0,    84,    35,    37,    20,    21,    22,    23,    37,
    34,    93,    94,    34,    96,    34,     0,    99,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    54,    17,     7,
     8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    35,    17,    20,
    21,    22,    23,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    33,    17,    -1,    -1,    35,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    -1,    31
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
#line 63 "wordlang.y"
{
        //printf("Program is syntactically correct.\n");
        yyval.nodeType.nd = AST_mkNode(yyvsp[0].nodeType.nd, NULL, "start");
        root = yyval.nodeType.nd;
;
    break;}
case 2:
#line 69 "wordlang.y"
{
            yyval.nodeType.nd = yyvsp[0].nodeType.nd;
        ;
    break;}
case 3:
#line 72 "wordlang.y"
{ 
            yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, yyvsp[0].nodeType.nd, "statement_list");
            //printf("statement_list\n");
        ;
    break;}
case 4:
#line 79 "wordlang.y"
{ 
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                //printf("declaration\n");
         ;
    break;}
case 5:
#line 83 "wordlang.y"
{codeGen_id(yyvsp[0].nodeType.name);;
    break;}
case 6:
#line 83 "wordlang.y"
{
                //printf("start assignment\n");
                checkDeclaration(yyvsp[-3].nodeType.name);
                yyvsp[-3].nodeType.varType = getDataType(yyvsp[-3].nodeType.name);
                checkType(yyvsp[-3].nodeType.varType, yyvsp[-1].nodeType.varType);                
                yyvsp[-3].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-3].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-3].nodeType.name);                
         ;
    break;}
case 7:
#line 91 "wordlang.y"
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
#line 100 "wordlang.y"
{
            yyval.nodeType.nd = exprRoot = AST_mkNode(NULL, yyvsp[-1].nodeType.nd, yyvsp[-2].nodeType.name);
            char* expr = strdup(codeGen_expression(exprRoot->right));
            codeGen_output(expr);
            //printf("output\n");
         ;
    break;}
case 9:
#line 106 "wordlang.y"
{ 
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                //printf("conditional_statement\n");
          ;
    break;}
case 10:
#line 110 "wordlang.y"
{ 
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                //printf("loop_statement\n");
          ;
    break;}
case 11:
#line 117 "wordlang.y"
{ insert_type(yytext); 
                    //printf("char\n");                    
;
    break;}
case 12:
#line 120 "wordlang.y"
{ insert_type(yytext); 
                //printf("int\n");
        ;
    break;}
case 13:
#line 123 "wordlang.y"
{ insert_type(yytext); 
                //printf("word\n");
        ;
    break;}
case 14:
#line 126 "wordlang.y"
{ insert_type(yytext); 
                //printf("sentence\n");
        ;
    break;}
case 15:
#line 131 "wordlang.y"
{
                isValidVarName(yyvsp[-1].nodeType.name);
                checkMultiDeclaration(yyvsp[-1].nodeType.name);
                storeInSymbolTable(yyvsp[-1].nodeType.name, VARIABLE, dataType, yylineno, "");
                yyvsp[-1].nodeType.varType = dataType;
                yyvsp[-1].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-1].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, NULL, "declaration");
                codeGen_declare(yyvsp[-1].nodeType.name, dataType);
                codeGen_initVar(dataType);
                //printf("declaration without assignment\n");
             ;
    break;}
case 16:
#line 142 "wordlang.y"
{codeGen_declare(yyvsp[0].nodeType.name, dataType);;
    break;}
case 17:
#line 142 "wordlang.y"
{
                isValidVarName(yyvsp[-3].nodeType.name);
                checkMultiDeclaration(yyvsp[-3].nodeType.name);
                checkType(dataType, yyvsp[-1].nodeType.varType);
                storeInSymbolTable(yyvsp[-3].nodeType.name, VARIABLE, dataType, yylineno, "");
                yyvsp[-3].nodeType.varType = dataType;
                yyvsp[-3].nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[-3].nodeType.name);
                yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[-1].nodeType.nd, "declaration");
                //printf("declaration with assignment\n");
            ;
    break;}
case 18:
#line 155 "wordlang.y"
{ codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 19:
#line 156 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 20:
#line 157 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 21:
#line 158 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 22:
#line 159 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 23:
#line 160 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 24:
#line 163 "wordlang.y"
{                
                yyval.nodeType.varType = yyvsp[-1].nodeType.varType;
                yyval.nodeType.nd = yyvsp[-1].nodeType.nd;
            ;
    break;}
case 25:
#line 167 "wordlang.y"
{                                           
                yyval.nodeType.varType = checkExprDataType(yyvsp[-2].nodeType.varType, yyvsp[0].nodeType.varType, yyvsp[-1].nodeType.name);     
                yyval.nodeType.nd = AST_mkNode(yyvsp[-2].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);                                
            ;
    break;}
case 26:
#line 171 "wordlang.y"
{
                yyval.nodeType.varType = yyvsp[0].nodeType.varType;
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
            ;
    break;}
case 27:
#line 178 "wordlang.y"
{    
                yyval.nodeType.varType = yyvsp[0].nodeType.varType;
                yyval.nodeType.nd = exprRoot = AST_mkNode(yyvsp[-1].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);
                char* expr = strdup(codeGen_expression(exprRoot->right));
                codeGen_assign(expr, yyvsp[0].nodeType.varType);
;
    break;}
case 28:
#line 186 "wordlang.y"
{        
        storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, INT, yylineno, yytext);
        yyval.nodeType.varType = INT;
        yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
        yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
        //printf("int\n");
    ;
    break;}
case 29:
#line 193 "wordlang.y"
{
        storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, CHAR, yylineno, yytext);
        yyval.nodeType.varType = CHAR;
        yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
        yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
        //printf("char\n");
    ;
    break;}
case 30:
#line 200 "wordlang.y"
{ 
        storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, WORD, yylineno, yyvsp[0].nodeType.wordVal);
        yyval.nodeType.varType = WORD;
        yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
        yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
        //printf("word\n");
    ;
    break;}
case 31:
#line 207 "wordlang.y"
{
         printf("sentence\n"); 
         storeInSymbolTable(yyvsp[0].nodeType.name, CONSTANT, SENTENCE, yylineno, yyvsp[0].nodeType.wordVal);
         yyval.nodeType.varType = SENTENCE;
         yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
         yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
    ;
    break;}
case 32:
#line 214 "wordlang.y"
{
            checkDeclaration(yyvsp[0].nodeType.name);
            yyval.nodeType.varType = getDataType(yyvsp[0].nodeType.name);
            //printf("varType: %d\n", $1.varType);
            yyval.nodeType.nd = AST_mkNode(NULL, NULL, yyvsp[0].nodeType.name);
            yyval.nodeType.name = strdup(yyvsp[0].nodeType.name);
            //printf("identifier\n");
    ;
    break;}
case 35:
#line 228 "wordlang.y"
{codeGen_if(yyvsp[-1].nodeType.wordVal);;
    break;}
case 36:
#line 228 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 37:
#line 228 "wordlang.y"
{
        yyval.nodeType.nd = AST_mkNode(yyvsp[-6].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-8].nodeType.name);
        codeGen_punc(yyvsp[0].nodeType.name);
        //printf("if with brackets\n");
     ;
    break;}
case 38:
#line 233 "wordlang.y"
{codeGen_if(yyvsp[-1].nodeType.wordVal);;
    break;}
case 39:
#line 233 "wordlang.y"
{ 
        yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-5].nodeType.name);
        //printf("if\n");
     ;
    break;}
case 40:
#line 238 "wordlang.y"
{codeGen_else();;
    break;}
case 41:
#line 238 "wordlang.y"
{ 
        yyval.nodeType.nd = AST_mkNode(NULL, yyvsp[0].nodeType.nd, "else");
        //printf("else\n");
 ;
    break;}
case 42:
#line 242 "wordlang.y"
{codeGen_else();;
    break;}
case 43:
#line 242 "wordlang.y"
{codeGen_punc(yyvsp[0].nodeType.name);;
    break;}
case 44:
#line 242 "wordlang.y"
{
        yyval.nodeType.nd = AST_mkNode(NULL, yyvsp[-1].nodeType.nd, "else");
        codeGen_punc(yyvsp[0].nodeType.name);
        //printf("else with brackets\n");
     ;
    break;}
case 45:
#line 249 "wordlang.y"
{
                yyval.nodeType.nd = yyvsp[0].nodeType.nd;
                yyval.nodeType.wordVal = yyvsp[0].nodeType.name;
                //printf("value-only condition\n");
            ;
    break;}
case 46:
#line 254 "wordlang.y"
{
                checkType(yyvsp[-2].nodeType.varType, yyvsp[0].nodeType.varType);
                yyval.nodeType.varType = INT;
                yyval.nodeType.nd = AST_mkNode(yyvsp[-2].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);                
                yyval.nodeType.wordVal = codeGen_codition(yyvsp[-2].nodeType.name, yyvsp[0].nodeType.name, yyvsp[-1].nodeType.name);
                //printf("value relop value condition\n");
            ;
    break;}
case 47:
#line 261 "wordlang.y"
{
                checkType(yyvsp[0].nodeType.varType, INT);
                yyval.nodeType.varType = INT;
                yyval.nodeType.nd = AST_mkNode(yyvsp[-1].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-1].nodeType.name);
                yyval.nodeType.wordVal = strdup(codeGen_codition(yyvsp[-1].nodeType.name, yyvsp[0].nodeType.wordVal, yyvsp[-1].nodeType.name));
                //printf("not condition\n");
          ;
    break;}
case 48:
#line 268 "wordlang.y"
{
            storeInSymbolTable(yyvsp[0].nodeType.name, KEYWORD, INT, yylineno, "1");
            yyval.nodeType.varType = INT;
            yyval.nodeType.nd = NULL;
            yyval.nodeType.wordVal = "1";
            //printf("true\n");
          ;
    break;}
case 49:
#line 275 "wordlang.y"
{
            storeInSymbolTable(yyvsp[0].nodeType.name, KEYWORD, INT, yylineno, "0");
            yyval.nodeType.varType = INT;
            yyval.nodeType.nd = NULL;
            yyval.nodeType.wordVal = "0";
            //printf("false\n");
        ;
    break;}
case 61:
#line 297 "wordlang.y"
{exprRoot = AST_mkNode(NULL, yyvsp[-1].nodeType.nd, yyvsp[-1].nodeType.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_loop(expr);;
    break;}
case 62:
#line 298 "wordlang.y"
{    
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-5].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-7].nodeType.name);                    
                    codeGen_punc(yyvsp[0].nodeType.name);
                    //printf("loop\n");                    
                ;
    break;}
case 63:
#line 303 "wordlang.y"
{exprRoot = AST_mkNode(NULL, yyvsp[-1].nodeType.nd, yyvsp[-1].nodeType.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_loop(expr);;
    break;}
case 64:
#line 304 "wordlang.y"
{                 
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[0].nodeType.nd, yyvsp[-5].nodeType.name);                    
                    codeGen_punc("}");
                    //printf("loop\n");
                ;
    break;}
case 65:
#line 309 "wordlang.y"
{exprRoot = AST_mkNode(NULL, yyvsp[-1].nodeType.nd, yyvsp[-1].nodeType.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_while(expr);;
    break;}
case 66:
#line 310 "wordlang.y"
{
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-5].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-7].nodeType.name); 
                    codeGen_punc(yyvsp[0].nodeType.name);                    
                    //printf("while\n");
                ;
    break;}
case 67:
#line 315 "wordlang.y"
{exprRoot = AST_mkNode(NULL, yyvsp[0].nodeType.nd, yyvsp[0].nodeType.name);
                    char* expr = strdup(codeGen_expression(exprRoot->right)); codeGen_while(expr);;
    break;}
case 68:
#line 317 "wordlang.y"
{ 
                    yyval.nodeType.nd = AST_mkNode(yyvsp[-3].nodeType.nd, yyvsp[-1].nodeType.nd, yyvsp[-5].nodeType.name);
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
#line 324 "wordlang.y"


void yyerror(const char* s) {
    //printf("at line %d: Error; %s\n", yylineno, s);
    exit(1);
}

int main(int argc, char* argv[]) {
    static int WriteOnce = 0;
    if (argc < 2) {
        //printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        //printf("Error opening input file.\n");
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
