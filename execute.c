#include "shell.h"

/*
   execute.c – cria um processo progénito e executa um programa
*/

int ultimo(char **args, int numargs)
{
  if (args[numargs-1][0] == '&')
  {
    args[numargs-1] = NULL;
    return BG;
  }

  return FG;
}

/* Detect PIPE SYMBOL in array of Strings  return its index or -1 if it does not exist */
int containsPipe(int numArgs,char **args)
{
  int index;
  for(index = 0; index < numArgs; index++)
  {
    if(args[index][0] == '|')
    {
      return index;
    }
  }

  return -1;
}


void execute(char **args, int num_args)
{
         int pid, status; // Variáveis defaults do execute!
         int pidNovoFilho = 0, fd[2]; // No que diz respeito aos pipes!

         int indice = containsPipe(num_args, args);
         // No que diz respeito ao background/foreground;
         int code = ultimo(args, num_args);

         if(code == BG)
         {
           num_args--;
         }

         if((pid = fork()) < 0)
         {
           perror("fork");
           exit(1);
         }

         if(pid == 0)
         {

           redirects(args, num_args);
           if(indice > 0)
           {
              args[indice] = NULL;
              num_args -=1;
              pipe(fd);
              pidNovoFilho = fork();

              if(pidNovoFilho == 0)
              {
                //write
                num_args = indice;
                dup2(fd[1],STDOUT_FILENO);
                close(fd[0]);
                execvp(*args, args);
              }
              else
              {
                //read
                args = args+indice+1;
                num_args=num_args-indice-1;

                dup2(fd[0], STDIN_FILENO);
                close(fd[1]);
                execvp(*args, args);
              }

           }
           else
           {
             execvp(*args, args);
           }


           perror(*args);
           exit(1);
         }


         if(code == FG)
         {
           while(wait(&status) != pid)
          ;
        }
}
