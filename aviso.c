#include "shell.h"

/*
   aviso.c – calcula uma operação entre dois números
*/

void Aviso(char *mesg, int tempo)
{
  while (tempo > 0)
  {
    sleep (1);
    tempo--;
  }
  fprintf (stderr, "Aviso : %s\n", mesg);
}

void Aviso_Countdown(char *message, int tempo)
{
  while(tempo > 0)
  {
    fprintf(stderr, "%s %s: %d\n", WARNING_PREFIX, message, tempo);
    sleep(1);
    tempo--;
  }
}

void *AvisoWrapper(void *args)
{
  aviso_t *ptr = (aviso_t *) args;
  Aviso(ptr->msg, ptr->tempo);
  free(ptr);
  return NULL;
}
