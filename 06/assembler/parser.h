#include <stdio.h>

// Constants
const int MAX_LINES = 100;
const int MAX_LENGTH = 32;

// Enums
typedef enum {A_COMMAND, C_COMMAND, L_COMMAND, COMMENT, EMPTY_LINE} cmd_type;

// Structures
// Parser
typedef struct Parser {
    FILE* program;
    char currentCmd[MAX_LENGTH];
    char dest[MAX_LENGTH];
    char jump[MAX_LENGTH];
    char comp[MAX_LENGTH];
    int pc;
    int ended;
} Parser;

// Functions
Parser* initialize(char*);

void parse();

int hasMoreCommands();

void advance(Parser*);

cmd_type commandType();

char* symbol();

void dest(Parser*);

void comp(Parser*);

void jump(Parser*);
