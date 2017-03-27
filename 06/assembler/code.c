#include <stdio.h>
#include "code.h"

char* destToBinary(char mnemonic[]) {
    char first = mnemonic[0];
    char second = mnemonic[1];
    char third = mnemonic[2];

    if(first == 'M') {
        if(second == 'D') {
            return "011";
        } else if(second == '\0') {
            return "001";
        }
    } else if (first == 'A') {
        if(second == 'M') {
            if(third == 'D') {
                return "111";
            } else if(third == '\0') {
                return "101";
            }
        } else if(second == 'D') {
            return "110";
        } else if(second == '\0') {
            return "100";
        }
    } else if (first == 'D') {
        return "010";
    } else if (first == '\0') {
        return "000";
    }

    return "000";
}

char* compToBinary(char mnemonic[]) {
    char first = mnemonic[0];
    char second = mnemonic[1];
    char third = mnemonic[2];

    if(first == '0') {
        return "0101010";
    } else if(first == '1') {
        return "0111111";
    } else if(first =='-') {
        if(second == '1') {
            return "0111010";
        } else if(second == 'D') {
            return "0001111";
        } else if(second == 'A') {
            return "0110011";
        } else if(second == 'M') {
            return "1110011";
        }
    } else if(first == 'D') {
        if(second == '\0') {
            return "0001100";
        } else if(second == '+') {
            if(third == '1') {
                return "0011111";
            } else if(third == 'A') {
                return "0000010";
            } else if(third == 'M') {
                return "1000010";
            }
        } else if(second == '-') {
            if(third == '1') {
                return "0001110";
            } else if(third == 'A') {
                return "0010011";
            } else if(third == 'M') {
                return "1010011";
            }
        } else if(second == '&') {
            if(third == 'A') {
                return "0000000";
            } else if(third == 'M') {
                return "1000000";
            }
        } else if(second == '|') {
            if(third == 'A') {
                return "0010101";
            } else if(third == 'M') {
                return "1010101";
            }
        }
    } else if(first == 'A') {
        if(second == '\0') {
            return "0110000";
        } else if(second == '+') {
            if(third == '1') {
                return "0110111";
            }
        } else if(second == '-') {
            if(third == '1') {
                return "0110010";
            } else if(third == 'D') {
                return "0000111";
            }
        }
    } else if(first == 'M') {
        if(second == '\0') {
            return "1110000";
        } else if(second == '+') {
            if(third == '1') {
                return "1110111";
            }
        } else if(second == '-') {
            if(third == '1') {
                return "1110010";
            } else if(third == 'D') {
                return "1000111";
            }
        }
    } else if(first == '!') {
        if(second == 'D') {
            return "0001101";
        } else if(second == 'A') {
            return "0110001";
        } else if(second == 'M') {
            return "1110001";
        }
    }

    return "0101010";
}

char* jumpToBinary(char mnemonic[]) {
    char first = mnemonic[0];
    char second = mnemonic[1];
    char third = mnemonic[2];

    if(first == '\0') {
        return "000";
    } else if(first == 'J') {
        if(second == 'G') {
            if(third == 'T') {
                return "001";
            } else if(third == 'E') {
                return "011";
            }
        } else if(second == 'E') {
            if(third == 'Q') {
                return "010";
            }
        } else if(second == 'L') {
            if(third == 'T') {
                return "100";
            } else if(third == 'E') {
                return "110";
            }
        } else if(second == 'N') {
            if(third == 'E') {
                return "101";
            }
        } else if(second == 'M') {
            if(third == 'P') {
                return "111";
            }
        }
    }

    return "000";
}
