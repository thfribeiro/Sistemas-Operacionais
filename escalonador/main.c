#include "teste.h"


int contadorProcessos = 0;


int main()
{
  LISTA listaProcessos;
inicializar(&listaProcessos);
PROCESSO novo;
int op, auxNum, i;
char auxChar;

menu:
puts("1 - Inserir Processo \t 2 - Lista Processos \t 3 - Executar Processos \t 4 - Limpar processos \t 5 - Sair");
scanf("%d", &op);
setbuf(stdin, NULL);
if(op == 1){
    puts("PID: ");
    scanf("%d", &novo.PID);
    setbuf(stdin, NULL);
    puts("Nome: ");
    fgets(novo.nome, 30, stdin);
    setbuf(stdin, NULL);
    puts("Prioridade: ");
    scanf("%d", &novo.prioridade);
    setbuf(stdin, NULL);
    puts("Tempo de Processamento: ");
    scanf("%d" ,&novo.tempoTotal);
    setbuf(stdin, NULL);
    novo.tempoParcial = novo.tempoTotal;
    puts("Possui dependencia? S/N");
    scanf("%c",&auxChar);
    setbuf(stdin, NULL);
    if(auxChar == 'S' || auxChar == 's'){
    novo.dependencia = 1;
    novo.estado = BLOQUEADO;
    puts("PID do processo que este é dependente: ");
    scanf("%d", &novo.pidDEP);
    setbuf(stdin, NULL);

	if(buscaPidDEPUsuario(&listaProcessos, novo.pidDEP)== -1){

        puts("Entrada inválida - Processo não adicionado");
        goto menu;
}
    }
    else if (auxChar == 'N' || auxChar == 'n'){
        novo.dependencia = -1;
        novo.estado = PRONTO;
        novo.pidDEP = -1;
    }
    else{
        puts("Entrada inválida - Processo não adicionado");
        goto menu;
    }
    if(contadorProcessos < 2048){
  auxNum = inserirProcessoUsuario(&listaProcessos, novo);

    if(auxNum == 1){
      contadorProcessos ++;
      puts("Processo adicionado!!");
      sleep(1);
      system("clear");
    }
    }
    else{
  puts("Limite de memória atingido, favor limpar os processos para adicionar um novo!");
    }

    auxChar = '\0';
    novo.dependencia = -1;
    goto menu;
}
else if(op==2){
    system("clear");
    puts("LISTA DE PROCESSOS");
    exibirProcessosUsuario(&listaProcessos);
    goto menu;
}
else if (op==3){
    system("clear");
    systemCallUsuario(&listaProcessos);
    goto menu;
}
else if(op==4){
    puts("Finalizando todos os processos");
    sleep(2);
    finalizarProcessosUsuario(&listaProcessos);
    goto menu;
}
else if (op == 5){
    puts("Finalizando todos os processos");
    sleep(2);
    finalizarProcessosUsuario(&listaProcessos);
    contadorProcessos = 0;
    return 0;
}
else{
    puts("Opção errada, tente novamente");
    contadorProcessos = 0;
    goto menu;
}



}
