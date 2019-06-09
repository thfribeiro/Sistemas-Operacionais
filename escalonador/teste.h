#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB 1048576
#define PRONTO 256
#define BLOQUEADO 257
#define EXECUTANDO 258
#define FINALIZADO 259

typedef struct{
int PID;
char nome[30];
int estado;
int prioridade;
int tempoTotal;
int tempoParcial;
float porcentagem;
int dependencia;
int pidDEP;
}PROCESSO;

typedef struct aux{
PROCESSO proce;
struct aux *prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
PONT inicio;
}LISTA;

//ROTINAS NUCLEO
void inicializar(LISTA *l);
void exibirProcessos(LISTA *l);
int inserirProcesso(LISTA *l, PROCESSO elem);
void busca(LISTA *l, int ch);
void systemCall(LISTA *l);
void finalizarProcessos(LISTA *l);
void finalizarProcessosFINALIZADOS(LISTA *l);
int buscaPidDEP(LISTA *l, int pidBusca);

//ROTINAS USUARIO
void exibirProcessosUsuario(LISTA *l);
int inserirProcessoUsuario(LISTA *l, PROCESSO elem);
void systemCallUsuario(LISTA *l);
void finalizarProcessosUsuario(LISTA *l);
int buscaPidDEPUsuario(LISTA *l, int pidBusca);

#endif // TESTE_H_INCLUDED

