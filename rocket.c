#include "shell.h"

/*
   rocket.c – verifica se existe algum redirecionamento para colocar!

   Code from: https://helloacm.com/simple-cc-rocket-animation/
*/

const char rocket[] =
"           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |S|\n\
          |H|\n\
          |E|\n\
          |L|\n\
          |L|\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";


void Rocket()
{
    for (int i = 0; i < 50; i ++) printf("\n"); // jump to bottom of console
    printf("%s", rocket);
    int j = 300000;
    for (int i = 0; i < 50; i ++) {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
}
