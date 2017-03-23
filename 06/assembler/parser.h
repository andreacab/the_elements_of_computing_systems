include <stdio.h>

// Constants
const int MAX_LINES = 100;
const int MAX_LENGTH = 32;
typedef enum {A_COMMAND, C_COMMAND, L_COMMAND} cmd_type;

// Parser
typedef struct Parser {
    FILE * program;
    char currentCmd[MAX_LENGTH];
    int pc;
} Parser;

Parser * initialize(char *);

void parse();

int hasMoreCommands();

int advance(Parser *);

cmd_type commandType();

char * symbol();

char * dest();

char * comp();

char * jump();
