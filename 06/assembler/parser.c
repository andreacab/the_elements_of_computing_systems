#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

Parser * initialize(char * fileName) {
    FILE * program = fopen(fileName, "r");
    Parser * parser;

    // Parser module initialization
    if((parser = malloc(sizeof(Parser))) != NULL) {
        parser -> program = program;
        parser -> pc = 0;
    }

    // TODO: initialize Code module
    // TODO: initialize Symbolic table module

    if(program) {
        printf("parsing!\n");
        advance(parser);
        fclose(program);
        printf("current cmd is: %s", parser -> currentCmd);
    }

    return parser;
}

// void parse() {

// }

int hasMoreCommands(Parser * parser) {
    return 1;
}

int advance(Parser * parser) {
    int i = 0;
    int c;

    if(!hasMoreCommands(parser)) {
        return 0;
    }

    while((c = getc(parser -> program)) != '\n') {
        parser -> currentCmd[i] = c;
        i++;
    }
    parser -> currentCmd[i] = '\n';

    return 1;
}

cmd_type commandType(char cmd[]) {
    if(cmd[0] == '@') {
        return A_COMMAND;
    } else if(cmd[0] == '(') {
        return L_COMMAND;
    }
    return C_COMMAND;
}

// char* symbol() {

// }

// char* dest() {

// }

// char* comp() {

// }

// char* jump() {

// }

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    // while hasMoreCommands
    //   advance
    //   enum currentCmd = commandType
    //   if currendCmd is not a C_COMMAND
    //      currentSymbol = symbol
    //   else
    //       destination = dest
    //      computaion = comp
    //      jmp = jump
    printf("file path is: %s\n", argv[1]);
    printf("Hello World\n");
    initialize(argv[1]);

    return 0;
}
