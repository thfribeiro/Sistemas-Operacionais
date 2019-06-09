#include "teste.h"

void inicializar(LISTA *l){
    l->inicio=NULL;
}

void exibirProcessos(LISTA *l){

PONT aux = l->inicio;
int auxNome = strlen(aux->proce.nome) -1;
int i;
puts("--------------------------------------------------------------------------------");
while(aux!=NULL){

printf("PID: [%d] Nome: [", aux->proce.PID);
for(i = 0; i< auxNome; i++){
  printf("%c",aux->proce.nome[i]);
}
printf("] Estado: [");
switch(aux->proce.estado){
case PRONTO:
    printf("PRONTO");
    break;
case BLOQUEADO:
    printf("BLOQUEADO");
    break;
case EXECUTANDO:
    printf("EXECUTANDO");
    break;
case FINALIZADO:
    printf("FINALIZADO");
    break;
default:
    printf("PRONTO");
    break;
}
printf("] Prioridade: [%d] Porcentagem: [%.2f]\n",aux->proce.prioridade, aux->proce.porcentagem);
puts("--------------------------------------------------------------------------------");

aux = aux->prox;
}
}

int inserirProcesso(LISTA *l, PROCESSO elem){
if(elem.PID <=0){
    puts("PID inválido - Processo não inserido");
    return -1;
}
if(elem.tempoTotal <=0){
    puts("Tempo de processamento inválido - Processo não inserido");
    return -1;
}


PONT ant = NULL;
PONT atual = NULL;
PONT novo = NULL;

novo = (PONT) malloc(sizeof(ELEMENTO));


if(novo==NULL){
puts("Erro ao alocar memória - Processo não inserido");
return -1;
}

novo->proce=elem;
novo->prox=NULL;

atual = l->inicio;

while(atual!=NULL && elem.prioridade<atual->proce.prioridade){
ant=atual;
atual=atual->prox;

}
novo->prox=atual;


if(ant==NULL){
l->inicio=novo;
}

else{
ant->prox=novo;
}
return 1;

}


void busca(LISTA *l, int pidBusca){
PONT atual = NULL;

atual = l->inicio;

while(atual!=NULL && atual->proce.pidDEP!=pidBusca){
atual = atual->prox;
}
if(atual!= NULL && atual->proce.pidDEP==pidBusca){
  if(atual->proce.estado == FINALIZADO){
  atual->proce.estado = FINALIZADO;
  }
  else{
  atual->proce.estado = PRONTO;
}
}

}


void systemCall(LISTA *l){
PONT atual = l->inicio;
int tempoProcessamento = 0;

while(atual!=NULL){
    if(atual->proce.estado == PRONTO || atual->proce.estado == BLOQUEADO){
        tempoProcessamento += atual->proce.tempoTotal;
    }
    atual= atual->prox;
}


recall:
atual = l->inicio;
exibirProcessos(l);
while (atual!= NULL && tempoProcessamento > 0 ){
    if(atual->proce.estado == PRONTO && atual->proce.tempoParcial > 0){

if(atual->proce.tempoTotal>=5){
        if(atual->proce.tempoParcial<5){
          tempoProcessamento -= atual->proce.tempoParcial;
                atual->proce.tempoParcial = 0;
        }
        else{
          tempoProcessamento -=5;
          atual->proce.tempoParcial -= 5;
        }

}
else{
	tempoProcessamento -= atual->proce.tempoTotal;
        atual->proce.tempoParcial = 0;
}

        atual->proce.estado = EXECUTANDO;
        atual->proce.porcentagem = ((atual->proce.tempoTotal - atual->proce.tempoParcial)*100)/atual->proce.tempoTotal;

    if(atual->proce.porcentagem >= 100){
        atual->proce.porcentagem = 100;
        atual->proce.tempoParcial = 0;
        atual->proce.estado = FINALIZADO;
        busca(l, atual->proce.PID);
    }
    else if(atual->proce.porcentagem < 100 && atual->proce.estado!= FINALIZADO){
        atual->proce.estado = PRONTO;
    }
        system("clear");
        exibirProcessos(l);
        printf("\nRC:\nEXECUTANDO -> \t PID: [%d] Nome: [%s] Estado: [EXECUTANDO] Porcentagem: [%.2f]\n\n", atual->proce.PID, atual->proce.nome, atual->proce.porcentagem);
        sleep(1);
        system("clear");

    }
        if(atual->proce.porcentagem >= 100){
	atual->proce.estado = FINALIZADO;
        busca(l, atual->proce.PID);
    }

    if(tempoProcessamento > 0 && atual->prox == NULL){
        goto recall;
    }
    else if(tempoProcessamento > 0){
        atual = atual->prox;
    }
}
finalizarProcessosFINALIZADOS(l);
}

void finalizarProcessos(LISTA *l){
PONT aux=l->inicio;


while(aux!=NULL){
l->inicio=l->inicio->prox;
free(aux);
aux=l->inicio;
}
}

void finalizarProcessosFINALIZADOS(LISTA *l){

  PONT atual = NULL;
  PONT ant = NULL;

teste:
  atual= l->inicio;

  while(atual!=NULL && atual->proce.estado !=FINALIZADO){
  ant = atual;
  atual=atual->prox;
  }

  if(atual != NULL && atual->proce.estado == FINALIZADO){

  if(ant==NULL){
  l->inicio=atual->prox;
  }
  else{
  ant->prox=atual->prox;
  }
  free(atual);
goto teste;
}

}


int buscaPidDEP(LISTA *l, int pidBusca){

PONT atual = NULL;

atual = l->inicio;

while(atual!=NULL && atual->proce.PID!=pidBusca){
atual = atual->prox;
}
if(atual!= NULL && atual->proce.PID==pidBusca){
return 1;
}
else{
return -1;
}
}
