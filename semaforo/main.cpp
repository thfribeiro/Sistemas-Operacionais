#include <iostream>
#include <time.h> 
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//------------------Declaração das variáveis e estruturas----------------------------

struct processo{
  string nome;
  bool inclusao;
  int id;
  int valor[10];
};

queue<processo> fila;
vector<int> RC(1000);
int ordem[10];
int quantidade = 0;
char auxChar[2];
int contador = 1;
processo p1;
processo p2;
processo p3;
processo p4;
processo p5;
processo p6;
processo p7;
processo p8;
processo p9;
processo p10;

FILE *arq = fopen("/home/cc08462311900/Área de Trabalho/Log.txt", "wt");

//------------------------------------------------------------------------------------------


//---------------------Funções referentes a região critica e execução-----------------------

void executar(){

  processo aux;
  fprintf(arq, "##################################### Interação %i #####################################\n", contador);
  contador++;
  for(int i = 0; i < 10; i++){
    aux = fila.front();
    auxChar[0] = aux.nome[0];
    auxChar[1] = aux.nome[1];
    if(aux.inclusao==true){
        RC.insert(RC.begin(), aux.valor, aux.valor+10);	
        quantidade += 10;
	for(int j=0; j<10; j++){
	    fprintf(arq,"Processo %s inseriu na RC o valor:  %i\n",auxChar,aux.valor[j]);	
	}
    }
    else{
      if(RC.front()==0){
	for(int j=0; j < 10; j++){
           fprintf(arq, "Processo %s tentou remover da RC, mas a mesma estava vazia\n", auxChar);
        }
	  
      }
      else{
	vector<int>::iterator it;
	int auxInt;
        for(int j=0; j < 10; j++){
	  it = RC.begin();
	  auxInt = (int) * it;
	  fprintf(arq,"Processo %s removeu da RC o valor:  %i\n",auxChar,auxInt);
          RC.erase(RC.begin());	
        }
        quantidade -=10;
      }
    }
  fprintf(arq, "------------------------------------------------------------------------------\n");
  fila.pop();
  }

}
//------------------------------------------------------------------------------------------


//------------------Inserir em ordem aleatória na fila e mostrar semaforo-------------------

void inserirProcessoFila(processo p){
    fila.push(p);
}

void verSemaforo(){
  
  cout<< endl << "FILA: ";
  queue<processo>aux = fila;
  while(!aux.empty()){
    processo aux1 = aux.front();
    cout << endl << aux1.nome << endl;
    for (int i = 0; i < 10; i ++){
      cout << "[" << aux1.valor[i] << "]";
    }
    aux.pop();
  }
  cout << endl;
  cout << "RC: "<< endl;
fprintf(arq,"Restou na RC após a execução de 200 processos aleatórios:\n");	
for (int i = 0; i< quantidade; i++){
      cout << "["<< RC[i] << "]";
      fprintf(arq,"[%i]",RC[i]);	
    }
  }
//------------------------------------------------------------------------------------------


//-----------------Gerar ordem aleatória de processos na fila---------------------------

bool Existe (int valores[], int tam, int valor){
  for(int i = 0; i < tam; i++){
    if(valores[i]==valor){
      return true;
    }
  }
  return false;
}

void GerarAleatorios(int numeros[]){
  int v;
  for(int i = 0; i<10;i++){
    v = rand() % 10 + 1;
    while(Existe(numeros,i,v)){
      v = rand() % 10 + 1;
    }
  numeros[i] = v;
  }
}
//---------------------------------------------------------------------------------------


//---------------------------Inserir processos de forma aleatória---------------------------

void inserirProcessos(int ordem[]){
  for (int i = 0; i < 10; i ++){
    if(ordem[i]==p1.id){
      inserirProcessoFila(p1);
    }
    else if(ordem[i]==p2.id){
      inserirProcessoFila(p2);
    }
    else if(ordem[i]==p3.id){
      inserirProcessoFila(p3);
    }
    else if(ordem[i]==p4.id){
      inserirProcessoFila(p4);
    }
    else if(ordem[i]==p5.id){
      inserirProcessoFila(p5);
    }
    else if(ordem[i]==p6.id){
      inserirProcessoFila(p6);
    }
    else if(ordem[i]==p7.id){
      inserirProcessoFila(p7);
    }
    else if(ordem[i]==p8.id){
      inserirProcessoFila(p8);
    }
    else if(ordem[i]==p9.id){
      inserirProcessoFila(p9);
    }
    else if(ordem[i]==p10.id){
      inserirProcessoFila(p10);
    }
  }
}
//------------------------------------------------------------------------------------------

int main() {

  srand (time(NULL));


p1.nome = "P1";
p1.inclusao = true;
p1.id = 1;
p2.nome = "P2";
p2.inclusao = true;
p2.id = 2;
p3.nome = "P3";
p3.inclusao = true;
p3.id = 3;
p4.nome = "P4";
p4.inclusao = true;
p4.id = 4;
p5.nome = "P5";
p5.inclusao = true;
p5.id = 5;
p6.nome = "P6";
p6.inclusao = false;
p6.id = 6;
p7.nome = "P7";
p7.inclusao = false;
p7.id = 7;
p8.nome = "P8";
p8.inclusao = false;
p8.id = 8;
p9.nome = "P9";
p9.inclusao = false;
p9.id = 9;
p10.nome = "P10";
p10.inclusao = false;
p10.id = 10;


for(int j = 0; j<200; j++){
for (int i = 0; i < 10; i ++){
p1.valor[i] = rand() % 1000 + 1;
p2.valor[i] = rand() % 1000 + 1;
p3.valor[i] = rand() % 1000 + 1;
p4.valor[i] = rand() % 1000 + 1;
p5.valor[i] = rand() % 1000 + 1;
p6.valor[i] = 0;
p7.valor[i] = 0;
p8.valor[i] = 0;
p9.valor[i] = 0;
p10.valor[i] = 0;
}
GerarAleatorios(ordem);
inserirProcessos(ordem);
executar();
}
verSemaforo();
fclose(arq);
}