assembler : main.o parser.o code.o symbol_table.o
		cc -o assembler main.o parser.o code.o symbol_table.o

main.o : main.c
		cc -c main.c
parser.o : parser.c
		cc -c parser.c
code.o : code.c
		cc -c code.c
symbol_table.o : symbol_table.c
		cc -c symbol_table.c
clean :
		rm assembler main.o parser.o code.o symbol_table.o