#include "teste.h"

void exibirProcessosUsuario(LISTA *l){
exibirProcessos(l);
}

int inserirProcessoUsuario(LISTA *l, PROCESSO elem){
return inserirProcesso(l, elem);
}

void systemCallUsuario(LISTA *l){
systemCall(l);
}

void finalizarProcessosUsuario(LISTA *l){
finalizarProcessos(l);
}

int buscaPidDEPUsuario(LISTA *l, int pidBusca){
return buscaPidDEP(l, pidBusca);
}
