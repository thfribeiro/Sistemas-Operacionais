#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define MAX 10

typedef struct{
int pid;
char nome[10];
int valor;
}PROCESSO;

typedef struct{
PROCESSO processos[10];
int inicio;
int nroElem;
}FILA;


FILA fila;
PROCESSO elem;
PROCESSO RC;
int vc = -1;


void inicializar(FILA *f){
    f->inicio=0;
    f->nroElem =0;
}


void exibir(FILA *f, PROCESSO RC, int tempoParcial){
    double porcentagem = (RC.valor-tempoParcial) * 100 / RC.valor;
    if(porcentagem> 100.00){
      porcentagem = 100.00;
    }
    puts("----------------------------------------------------------------------------------");
    puts("RC:");
    printf("PID: [%d]\t",RC.pid);
    printf("Nome: %s\t", RC.nome);
    printf("Valor: [%d]\t", RC.valor);
    printf("Porcentagem: [%.2lf]\n", porcentagem);
    printf("----------------------------------------------------------------------------------");

    int i=f->inicio;
    int temp;
    printf("\nFila: \n");
    for(temp=0; temp<f->nroElem; temp++)
    {
        printf("PID: [%d]\t",f->processos[i].pid);
        printf("Nome: %s\t", f->processos[i].nome);
        printf("Valor: [%d]\n", f->processos[i].valor);

        i= (i+1)>=MAX?0:i+1;
    puts("----------------------------------------------------------------------------------");
    }
puts("");
}

int inserir(FILA *f, PROCESSO elem){
    if(vc==-1){
      RC = elem;
      vc++;
    }
    else{
      if(f->nroElem >= MAX)
          return -1;
      int posicao = (f->inicio + f->nroElem) % MAX;
      f->processos[posicao] = elem;
      f->nroElem = f->nroElem+1;
      vc = f->nroElem;
    }

    return 0;
}

int excluir(FILA *f){
    if(f->nroElem==0){
      return -1;
      vc = f->nroElem;
    }

    f->nroElem = f->nroElem -1;
    f->inicio = (f->inicio+1)% MAX;
    vc = f->nroElem;
    return 0;
}

void executar(FILA *f){
  int aux, aux1;
while(vc>0){
  aux = RC.valor;
    while(aux > 0){
      aux1 = rand() % 3;
      exibir(&fila, RC, aux-aux1);
      aux -= aux1;
      if(aux< 0 ){
        aux = 0;
      }
      sleep(1);
      system("clear");
    }
    RC = f->processos[f->inicio];
    excluir(f);
  }
  aux = RC.valor;
    while(aux > 0){
      aux1 = rand() % 3;
      exibir(&fila, RC, aux-aux1);
      aux -= aux1;
      if(aux< 0 ){
        aux = 0;
      }
      sleep(1);
      system("clear");
    }
    RC.pid = -1;
    strcpy(RC.nome, "Vazia");
    RC.valor = -1;

  puts("Terminou a execução dos processos");
  puts("Pressione qualquer tecla para continuar...");
  getchar();
  inicializar(f);
}



int main()
{

inicializar(&fila);
srand(time(NULL));

elem.pid = 1;
strcpy(elem.nome, "p1");
elem.valor = 5;
inserir(&fila, elem);

elem.pid = 2;
strcpy(elem.nome, "p2");
elem.valor = 10;
inserir(&fila, elem);

elem.pid = 3;
strcpy(elem.nome, "p3");
elem.valor = 15;
inserir(&fila, elem);

elem.pid = 4;
strcpy(elem.nome, "p4");
elem.valor = 20;
inserir(&fila, elem);

executar(&fila);




}
