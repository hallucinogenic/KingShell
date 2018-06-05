#include "shell.h"

/*
   main.c – cria um processo progénito e executa um programa
*/

char prompt[100] = {0};

int main(int argc, char *argv[])
{
  char buf[1024];
  char *args[64];
  int id, parse_v;

  strcpy(prompt, DEFAULT_PREFIX);

  if(argv[1] != NULL && atoi(argv[1]) >= 0)
  {
    Aviso_Countdown("A Shell vai ser iniciada em", atoi(argv[1]));
  }
  else
  {
    Aviso_Countdown("A Shell vai ser iniciada em", 3);
  }


  while(1)
  {

    printf("%s ", prompt);

    if((fgets(buf, sizeof(buf), stdin) == NULL))
    {
      printf("\n");
      exit(0);
    }

    id = strlen(buf);
    buf[id-1] = '\0';

    parse_v = parse(buf,args);

    /*
      Caso o utilizador não escreva um comando (pressione apenas Enter),
      o pedido será anulado para que o utilizador escreva de novo!
    */

    if(parse_v == 0)
    {
      continue;
    }

    if(!builtin(args, parse_v))
    {
        execute(args, parse_v);    /* executa o commando se não for uma funcionalidade embutida */
    }
  }

  return 0;

}



int builtin( char *args[], int num_args ) /* verifiicar se o comando é embutido no shell */
{
    if((0 == strcmp (args[0], "sair")) || (0 == strcmp(args[0], "quit")) || (0 == strcmp(args[0], "exit")))
    {
      int time;
      if(args[1] != NULL)
      {
        time = atoi(args[1]);
      }
      else
      {
        time = 3;
      }

      Aviso_Countdown("A Shell vai ser encerrada em", time);

      exit(0);
      return 1;
    }


    if(0 == strcmp(args[0], "avisoth"))
    {
      if(num_args < 3)
      {
        fprintf(stderr, "%s O número de argumentos é menor que 3!\n", ERROR_PREFIX);
        return 1;
      }

      pthread_t th;
      aviso_t * ptr = (aviso_t *) malloc(sizeof(aviso_t));
      strcpy(ptr->msg, args[1]);
      ptr->tempo=atoi(args[2]);
      pthread_create(&th, NULL, AvisoWrapper, (void *)ptr);
      return 1;
    }

    if(0 == strcmp(args[0], "aviso"))
    {
      if(num_args < 3)
      {
        fprintf(stderr, "%s O número de argumentos é menor que 3!\n", ERROR_PREFIX);
        return 1;
      }

      Aviso(args[1], atoi(args[2]));
      return 1;
    }

    /*
      This command is just for fun purposes!
    */

    if(0 == strcmp(args[0], "rocket"))
    {
        Rocket();
        return 1;
    }

    if (0 == strncmp(args[0], "42", 2))
    {
      printf("%s 42 is the answer to life the universe and everything\n", INFO_PREFIX);
      return 1;
    }

    if(0 == strcmp(args[0], "sols"))
    {
      sols(num_args, args);
      return 1;
    }

    if(0 == strcmp(args[0], "quemsoueu"))
    {
      system("id");
      return 1;
    }


    if(0 == strcmp(args[0], "socp"))
    {
      socp(args[1], args[2]);
      return 1;
    }

    if(0 == strcmp(args[0], "socpth"))
    {
      if(num_args < 3)
      {
        fprintf(stderr, "%s O número de argumentos é menor que 3!\n", ERROR_PREFIX);
        return 1;
      }

      pthread_t th;
      copiar_t * ptr = (copiar_t *) malloc(sizeof(copiar_t));
      strcpy(ptr->fonte, args[1]);
      strcpy(ptr->destino, args[2]);
      pthread_create(&th, NULL, SOCPWrapper, (void *)ptr);
      return 1;
    }

    if(strlen(args[0]) > 4 && 0 == strncmp(args[0], "PS1=", 4))
    {
      if(0 == strcmp(args[0], "PS1={default}"))
      {
        strcpy(prompt, DEFAULT_PREFIX);
        return 1;
      }
      else
      {
        strcpy(prompt, "\x1B[1m\x1B[32m[");
        strcat(prompt, args[0]+4);
        strcat(prompt, "] ►\x1B[0m");
      }
      return 1;
    }

    if (0 == strcmp(args[0],"cd"))
    {
      char cwd[1024];
      int err;
      if((args[1]== NULL) || (0 == strcmp(args[1], "~")))
      {
        err = chdir(getenv("HOME"));
      }
      else
      {
        err = chdir(args[1]);
      }

      if(err < 0)
      {
        printf("%s Esta diretoria não existe!\n", ERROR_PREFIX);
      }
      else if (getcwd(cwd, sizeof(cwd)) != NULL)
      {
        printf("%s Nova Diretoria: %s%s%s%s\n", INFO_PREFIX, BOLD, GREEN, cwd, NORMAL);
      }

      return 1;
    }

    if(0 == strcmp(args[0], "calc"))
    {
      if(num_args < 4)
      {
        printf("%s O número de argumentos tem de ser igual a 4!\n", ERROR_PREFIX);
      }
      else
      {
            calc(args[1], args[2], args[3]);
      }
      return 1;
    }

    if(0 == strcmp(args[0], "bits"))
    {
      if(num_args < 4)
      {
        printf("%s O número de argumentos tem de ser igual a 4!\n", ERROR_PREFIX);
      }
      else
      {
        bits(args[1], args[2], args[3]);
      }
      return 1;
    }



    if(0 == strcmp(args[0], "help"))
    {
      Help();
      return 1;
    }

    if(0 == strcmp(args[0], "jpeg") || (0 == strcmp(args[0], "jpg")))
    {
      int fd;
      fd = open(args[1], O_RDONLY);

      isjpg(fd);

      return 1;
    }

   return (0) ;
    ;    /* indicar que vamos continuar para a função execute*/

}
