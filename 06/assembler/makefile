assembler : main.o parser.o code.o symbol.o
		cc -o assembler main.o parser.o code.o symbol.o

main.o : main.c
		cc -c main.c
parser.o : parser.c
		cc -c parser.c
code.o : code.c
		cc -c code.c
symbol.o : symbol.c
		cc -c symbol.c
clean :
		rm assembler main.o parser.o code.o symbol.o
