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


extern YYSTYPE yylval;
