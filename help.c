#include "shell.h"

/*
   help.c – ficheiro com as informações de todos os comandos!
*/


void Help()
{
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///////////////////////// %s%sCOMANDOS DA SHELL%s (%s%sBUILTIN%s) /////////////////////////\n", BOLD, GREEN, NORMAL, BOLD, RED, NORMAL);
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("%s help -> %s%sComando de Ajuda%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s aviso -> %s%sEnvia uma mensagem de aviso passado um determinado tempo;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s avisoth -> %s%sEnvia uma mensagem de aviso passado um determinado tempo, através de Threads;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s PS1=NOME -> %s%sMuda o nome do PROMPT (default: \"[SHELL] ► \")%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s cd -> %s%sMuda a Diretoria para uma determinada pasta;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s sols -> %s%sFaz uma listagem de todos os ficheiros e pastas na pasta atual;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s calc -> %s%sCalcula uma operação entre dois números reais;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s bits -> %s%sCalcula uma operação binária entre dois números inteiros;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s sair/quit/exit -> %s%sA shell é terminada automaticamente, após um countdown de 3 segundos;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s quemsoueu -> %s%sIrá ser imprimido um ID do utilizador;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s socp -> %s%sCopia os dados de um ficheiro para outro;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s socpth -> %s%sCopia os dados de um ficheiro para outro, através de Threads;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s rocket -> %s%sLança um foguete (Fun Purposes);%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("%s jpg (ou jpeg) -> %s%sCopia os dados de um ficheiro para outro;%s\n", HELP_PREFIX, BOLD, YELLOW, NORMAL);
  printf("///////////////////////////////////////////////////////////////////////////////\n");
}
