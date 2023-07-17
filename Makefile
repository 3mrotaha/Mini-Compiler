LEX = flex
YACC = bison
CC = gcc

wordlang_compiler: lex.yy.c y.tab.c
	$(CC) lex.yy.c wordlang.tab.c */*.c */*/*.c -o wordlang_compiler

lex.yy.c: wordlang.lex
	$(LEX) wordlang.lex

y.tab.c y.tab.h: wordlang.y
	"$(YACC)" -v -d -t wordlang.y

clean:
	rm -f lex.yy.c wordlang.tab.c *.tab.h wordlang_compiler wordlang.output symbol_table.txt *.exe

run: wordlang_compiler
	./wordlang_compiler

.PHONY: clean run