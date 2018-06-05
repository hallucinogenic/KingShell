#include "shell.h"

/*
    socp.c – copia os dados de um ficheiro para outro
*/

void streamCopy (int entrada, int saida)
{
  int ch;
  char buffer[1];
  while((ch = read(entrada, buffer, 1)) > 0)
  {
    write(saida, buffer, ch);
  }
}

void socp(char *fonte, char *destino)
{
  if(fonte == NULL)
  {
    fprintf(stderr, "%s Erro a inserir no nome do ficheiro fonte!\n", ERROR_PREFIX);
    return;
  }

  if(destino == NULL)
  {
    fprintf(stderr, "%s Erro a inserir no nome do ficheiro destino!\n", ERROR_PREFIX);
    return;
  }

  int fent = open(fonte, O_RDWR);
  int fdest = open(destino, O_WRONLY);

  if(fent < 0)
  {
    fprintf(stderr, "%s Ficheiro fonte não existe!\n", ERROR_PREFIX);
    return;
  }

  if(fdest < 0)
  {
    fdest = creat(destino,  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  }

  streamCopy(fent,fdest);
  printf("%s Ficheiro %s copiado com sucesso para %s!\n", INFO_PREFIX, fonte, destino);

  close(fent);
  close(fdest);
}

void *SOCPWrapper(void *args)
{
  copiar_t *ptr = (copiar_t *) args;
  socp(ptr->fonte, ptr->destino) ;
  free(ptr);
  return NULL;
}
