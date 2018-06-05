#include "shell.h"

/*

    parse.c – particiona o comando Unix (armazenado em buf) em argumentos

*/



int parse (char *buf, char **args)
{
        if(strlen(buf) == 0 || *buf == '\0')
        {
          return 0;
        }
        int cnt = 0;
        while (*buf != '\0')
        {

        /* strip whitespace. Usa um NULL para indicar que o argumento anterior e’ o ultimo */

          while ((*buf == ' ' ) || (*buf == '\t'))
          {
            *buf++ = '\0';
          }


          *args++ = buf;
          cnt++;



          while ((*buf != '\0') && (*buf != ' ') && (*buf != '\t'))   /* salta sobre o argumento*/
          {
            buf++;
          }
        }

        *args = NULL;               /* o ultimo argumento e’ NULL */

        return cnt;

}
