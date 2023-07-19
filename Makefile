LEX = flex
YACC = bison
CC = gcc

wordlang_compiler: lex.yy.c y.tab.c
	$(CC) lex.yy.c wordlang.tab.c */*.c */*/*.c -o wordlang_compiler

lex.yy.c: wordlang.lex
	$(LEX) wordlang.lex

y.tab.c y.tab.h: wordlang.y
	"$(YACC)" -v -d wordlang.y

clean:
	rm -f lex.yy.c wordlang.tab.c *.tab.h *.tab.c wordlang_compiler *.output *.txt *.exe

run: wordlang_compiler
	./wordlang_compiler

.PHONY: clean run