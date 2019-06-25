import collections
import sys
import time
import random
from enum import Enum
import datetime
import threading
from threading import Thread

import os
import multiprocessing

filosofos = []
garfos = []
n = 0


class Filosofo():
    def __init__(self, nome):
        self.nome = nome
        self.comendo = False
        self.comeu = False
        self.nVezes = 0


def Comer(filosofo):
    filosofo.comendo = True
    SetGarfoEsquerdo(filosofo, True)
    SetGarfoDireito(filosofo, True)
    filosofo.nVezes+=1

    time.sleep(5)

    filosofo.comendo = False
    filosofo.comeu = True
    SetGarfoEsquerdo(filosofo, False)
    SetGarfoDireito(filosofo, False)


def TodosJaComeram():
    for filosofo in filosofos:
        if not filosofo.comeu:
            return False
    return 1


def NovoCiclo():
    for filosofo in filosofos:
        filosofo.comeu =False



def Jantar():#semaforo, seleciona o proximo e escalonamento pq ele vai escolher o prox

    if TodosJaComeram() <= 2:#timesharing, ele so vai comer denovo quando todos os outros estiverem comidos
        NovoCiclo();

    filosofo = random.choice(filosofos)

    if filosofo.comendo == False and filosofo.comeu == False:
        GarfoEsquerdo = GetGarfoEsquerdo(filosofo)
        GarfoDireito = GetGarfoDireito(filosofo)

        if not GarfoEsquerdo and not GarfoDireito: #dois garfos falsos = LIVRES
            Thread(target=Comer, args=(filosofo,)).start()


    time.sleep(5)
    Jantar()


def Tela():
    while True:

        print('')
        print('----------------------')
        print('')

        for filosofo in filosofos:

            if filosofo.comendo:
                estado = 'esta comendo'
            else:
                estado = 'esta pensando'
            print(filosofo.nome, estado, filosofo.nVezes)


        time.sleep(5)



def SetGarfoEsquerdo(filosofo, garfo):
    posicao = filosofos.index(filosofo)
    garfos[posicao] = garfo


def SetGarfoDireito(filosofo, garfo):
    posicao = filosofos.index(filosofo)
    if posicao == 4:
        garfos[0] = garfo
    else:
        garfos[posicao+1] = garfo


def GetGarfoEsquerdo(filosofo):
    posicao = filosofos.index(filosofo)
    return garfos[posicao]

def GetGarfoDireito(filosofo):
    posicao = filosofos.index(filosofo)
    if posicao == 4:
        return garfos[0]
    else:
        return garfos[posicao+1]



if __name__ == '__main__':
    garfos.append(False)
    garfos.append(False)
    garfos.append(False)
    garfos.append(False)
    garfos.append(False)

    filosofos.append(Filosofo('Aristóteles'))
    filosofos.append(Filosofo('Descartes'))
    filosofos.append(Filosofo('Platão'))
    filosofos.append(Filosofo('Pitágoras'))
    filosofos.append(Filosofo('Euclides'))

    Thread(target=Tela, args=()).start() ##paralela
    Jantar()