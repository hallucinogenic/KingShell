#include "shell.h"

/*

   isjpg.c – Verifica se o ficheiro é um jpg

*/
int isjpg(int fileDescriptor) //esboço da função
{
  if(fileDescriptor < 0)
  {
    printf("%s O Ficheiro %snão existe%s!\n", ERROR_PREFIX, RED, WHITE);
    return 0;
  }

  unsigned char b[4];
  read(fileDescriptor,b,4);
  //voltar ao inicio do ficheiro com lseek

  if (b[0]==0xff && b[1]==0xd8 && b[2]==0xff && b[3]==0xe0)
  {
    printf("%s O ficheiro %s%sé%s um JPG!\n", INFO_PREFIX, BOLD, GREEN, NORMAL);
    return 1;
  }

  printf("%s O ficheiro %s%snão é%s um JPG!\n", INFO_PREFIX, BOLD, RED, NORMAL);
  return 0;
}
