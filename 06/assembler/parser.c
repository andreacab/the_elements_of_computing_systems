#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "code.h"

void concatenate(int, char[][MAX_LENGTH], char[], char[], char[]);
void printInstructions(char[][MAX_LENGTH], int);

Parser * initialize(char * fileName) {
    FILE * program = fopen(fileName, "r");
    Parser * parser;

    // Parser module initialization
    if((parser = malloc(sizeof(Parser))) != NULL) {
        parser -> program = program;
        parser -> pc = 0;
        parser -> ended = 0;
    }

    // TODO: initialize Code module
    // TODO: initialize Symbolic table module

    return parser;
}

int hasMoreCommands(Parser * parser) {
    return !parser -> ended;
}

cmd_type commandType(char cmd[]) {
    if(cmd[0] == '@') {
        return A_COMMAND;
    } else if(cmd[0] == '(') {
        return L_COMMAND;
    }

    return C_COMMAND;
}

// TODO: implements symbol()
// char* symbol() {

// }

void dest(Parser* parser) {
    int i;

    for(i = 0; i < MAX_LENGTH; i++) {
        if(parser -> currentCmd[i] == '=') {
            *((parser -> dest) + i) = '\0';
            break;
        } else if(parser -> currentCmd[i] == ';') {
            *((parser -> dest) + 0) = '\0';
            break;
        } else {
            *((parser -> dest) + i) = parser -> currentCmd[i];
        }
    }
}

void comp(Parser * parser) {
    int i;
    int record = 0;
    int offset = 0;

    for(i = 0; i < MAX_LENGTH; i++) {
        if(parser -> currentCmd[i] == '=') {
            offset = i + 1;
            record = 1;
        } else if (parser -> currentCmd[i] == ';') {
            *((parser -> comp) + i) = '\0';
            break;
        } else if (parser -> currentCmd[i] == '\0') {
            *((parser -> comp) + i - offset) = '\0';
            break;
        } else {
            if(record) {
                *((parser -> comp) + i - offset) = parser -> currentCmd[i];
            } else {
                *((parser -> comp) + i) = parser -> currentCmd[i];
            }
        }
    }
}

void jump(Parser* parser) {
    int i, offset = 0;

    for(i = 0; i < MAX_LENGTH; i++) {
        if(parser -> currentCmd[i] == '=') {
            *((parser -> jump) + 0) = '\0';
            break;
        } else if(parser -> currentCmd[i] == ';') {
            offset = i + 1;
        } else if (parser -> currentCmd[i] == '\0') {
            *((parser -> jump) + i - offset) = '\0';
            break;
        } else {
            *((parser -> jump) + i - offset) = parser -> currentCmd[i];
        }
    }
}

// TODO: change algorithm, get a line, stop, analyze it, decide if you it becomes currentCmd. If not get next line
int advance(Parser * parser) {
    int i = 0, j = 0, c = getc(parser -> program);
    char next_line[MAX_LENGTH];

    // get line
    do {
        if(c == EOF) {
            parser -> ended = 1;
            i++;
            break;
        }

        next_line[i] = c;
        i++;
        c = getc(parser -> program)
    } while(c != '\n')


    for(;j < i, j++) {
        if(j != 0) {
            // check for comment not at beginning of line
            if(next_line[j] == '/' && next_line[j + 1] == '/') {
                next_line[j] = '\0';
                break;
            }
        } else {
            // check for empty lines or comment at beginning of line
            if(next_line[j] == '\n' || (next_line[j] == '/' && next_line[j + 1] == '/')) {
                advance(parser)
                break;
            }
        }

        // add null char to set end of string
        if(j == i - 1) {
            next_line[j + 1] = '\0';
        }
    }

    // strip white space
    i = 0;
    m = 0;
    while(next_line[i] != '\0') {
        if(next_line[i] != ' ') {
            parser -> currentCmd[m] = next_line[i];
            m++;
        }
        i++
    }

    return 1;
}

void concatenate(int num, char buffer[][MAX_LENGTH], char comp[], char dest[], char jump[]) {
    int djmax = 3;
    int cmax = 7;
    int i;
    buffer[num][0] = '1';
    buffer[num][1] = '1';
    buffer[num][2] = '1';

    for(i = 0; i < cmax; i++) {
        buffer[num][3 + i] = comp[i];
    }
    for(i = 0; i < djmax; i++) {
        buffer[num][3 + cmax + i] = dest[i];
    }
    for(i = 0; i < djmax; i++) {
        buffer[num][3 + cmax + djmax + i] = jump[i];
    }
}

void printInstructions(char buffer[][MAX_LENGTH], int size) {
    int i = 0;
    while(i < size) {
        printf("instruction: %s\n", buffer[i]);
        i++;
    }
}

int main(int argc, char* argv[]) {
    char machineInstructions[MAX_LINES][MAX_LENGTH];

    // Exit if not assembly program provided
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    printf("file path is: %s\n", argv[1]);

    // initialization
    Parser* parser = initialize(argv[1]);

    // Parsing
    if(parser -> program) {
        printf("start parsing!\n");

        while(hasMoreCommands(parser)) {
            // get the next instruction
            advance(parser);
            // init mnemonics
            char* d = NULL; // destination mnemonic
            char* c = NULL; // computation mnemonic
            char* j = NULL; // jump mnemonic

            if(commandType(parser -> currentCmd) == C_COMMAND) {
                dest(parser);
                d = destToBinary(parser -> dest); // 4 bytes ('\0' included)
                comp(parser);
                c = compToBinary(parser -> comp); // 8 bytes ('\0' included)
                jump(parser);
                j = jumpToBinary(parser -> jump); // 4 bytes ('\0' included)

                // save full 16bits instruction
                concatenate(parser -> pc, machineInstructions, c, d, j);
            } else if(commandType(parser -> currentCmd) == A_COMMAND ||
                commandType(parser -> currentCmd) == L_COMMAND) {
                printf("this is a A_COMMAND or L_COMMAND\n");
            }

            // Logging
            printf("command %d: %s\n", parser -> pc, parser -> currentCmd);
            printf("dest: %s, in binary: %s\n", parser -> dest, d);
            printf("comp: %s, in binray: %s\n", parser -> comp, c);
            printf("jump: %s, in binary: %s\n", parser -> jump, j);
            printf("----------------------------------------------------\n");

            // increment program counter
            parser -> pc++;
        }

        printf("********************* PROGRAM **********************\n");
        printInstructions(machineInstructions, parser -> pc);

        fclose(parser -> program);
    }

    return 0;
}
