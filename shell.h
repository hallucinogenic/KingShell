/*
    shell.h – ficheiros de inclusao e prototipos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>


// Estrutura de avisos;
typedef struct
{
  char msg[100];
  int tempo;
}aviso_t;

// Estrutura do socp;
typedef struct
{
  char fonte[100];
  char destino[100];
}copiar_t;

int sols(int argc, char *argv[]);

// Funções default da Shell!
int parse(char *buf, char **args);
void execute(char **args, int num_args);

// Ficheiro: calc.c
void calc(char *value1, char *op, char *value2);
void bits(char *op1, char *op, char *op2);

// Ficheiro: socp.c
void socp(char *fonte, char *destino);
void * SOCPWrapper(void *args);

// Ficheiro: redirects.c
int redirects(char *args[], int numargs);

// Ficheiro: aviso.c
void Aviso(char *mesg, int tempo);
void Aviso_Countdown(char *message, int tempo);
void *AvisoWrapper(void *args);


// Functions for fun purposes;
void Rocket();

//Ficheiro: memes.c
void MemesMenu(int IsInMenu);

// Ficheiro: isjpg.c
int isjpg(int fileDescriptor);

// Ficheiro: help.c
void Help();

int builtin (char **args, int num_args);
/* constantes que podem tornar uteis*/

#define BG 0

#define FG 1

// CHARACTERS CHANGES
#define NORMAL  "\x1B[0m"
#define BOLD "\x1B[1m"

// COLOR VALUES!
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

// TAGS DEFAULT DA SHELL

#define DEFAULT_PREFIX "\x1B[32m\x1B[1m[SHELL] ►\x1B[0m"
#define HELP_PREFIX "\x1B[36m\x1B[1m[HELP] ►\x1B[0m"
#define INFO_PREFIX "\x1B[34m\x1B[1m[INFO] ►\x1B[0m"
#define ERROR_PREFIX "\x1B[31m\x1B[1m[ERRO] ►\x1B[0m"
#define WARNING_PREFIX "\x1B[35m\x1B[1m[AVISO] ►\x1B[0m"
