

micro: lex.yy.c yacc.tab.y
	gcc micro.c -o micro -ly -ll

lex.yy.c:
	flex lex.l

yacc.tab.y:
	bison yacc.y

clean:
	rm -f micro
	rm -f lex.yy.c
	rm -f yacc.tab.c
