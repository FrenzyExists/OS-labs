#include "include/ex3.h"


void decode(char* cmd){
    
    // Straight out of the BSD source code hehe
    const char *s;
    for (s = cmd; *s; ++s);    
    int length =  s  - cmd;
    
    double n = sqrt(length);
    if (n != (int)n) {
        // char *cmd = "INVALID";
        strcpy(cmd, "INVALID");
        
    } else {      
        char *temp = malloc(length+1);
        int counter = 0;
        for (int i = 0 ; i < (int)n ; i++) {
            for (int j = 0 ; j < (int)n ; j++) {
                temp[counter] = cmd[j * (int)n + i];
                counter++;
            }
        }
        strcpy(cmd, temp);
        free(temp);
    }  
    printf("%s\n", cmd);
}

int main(void){
    // Tests Variables
    char cmd[MAX_CHARS];

    //Test 1
    strcpy(cmd, "WE OUE OUT LNGSAO H RWDN!");
    decode(cmd); // Expected: WE ARE LOW ON DOUGHNUTS !
    memset(cmd,0,MAX_CHARS);

    //Test 2
    strcpy(cmd, "S EFEM FNOCEDROE");
    decode(cmd); // Expected: SEND MORE COFFEE
    memset(cmd,0,MAX_CHARS);

    //Test 3
    strcpy(cmd, "CSERULES");
    decode(cmd); // Expected: INVALID
    memset(cmd,0,MAX_CHARS);

    return 0;
}