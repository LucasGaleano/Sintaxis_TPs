

scanner: lex.yy.c yacc.tab.y
	gcc -o scanner yacc.tab.c -ly -ll

lex.yy.c:
	flex lex.l

yacc.tab.y:
	bison yacc.y

clean:
	rm scanner
	rm lex.yy.c
	rm yacc.tab.c
