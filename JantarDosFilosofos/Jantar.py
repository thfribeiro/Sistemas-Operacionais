
import time
import random
import sys
from threading import Thread



filosofos = []
garfos = []
n=0


class Filosofo():
    def __init__(self, nome, id):
        self.nome = nome
        self.id = id
        self.comendo = False
        self.nVezes = 0


def Comer(filosofo):
    filosofo.comendo = True
    SetGarfoEsquerdo(filosofo, True)
    SetGarfoDireito(filosofo, True)
    filosofo.nVezes+=1

    time.sleep(5)

    filosofo.comendo = False
    SetGarfoEsquerdo(filosofo, False)
    SetGarfoDireito(filosofo, False)

def Janta():#semaforo, seleciona o proximo e escalonamento pq ele vai escolher o prox
    global n
    if n <= 40:
        n += 1

        nFilosofo = random.randrange(1, 6)

        if nFilosofo == 1:
            for filosofo in filosofos:
                if filosofo.id == nFilosofo:
                    filosofo1 = filosofo

            nFilosofo2 = random.randrange(1, 3)

            if nFilosofo2 == 1:
                for filosofo in filosofos:
                    if filosofo.id == 4:
                        filosofo2 = filosofo
            elif nFilosofo2 == 2:
                for filosofo in filosofos:
                    if filosofo.id == 3:
                        filosofo2 = filosofo

        elif nFilosofo == 2:
            for filosofo in filosofos:
                if filosofo.id == nFilosofo:
                    filosofo1 = filosofo

            nFilosofo2 = random.randrange(1, 3)

            if nFilosofo2 == 1:
                for filosofo in filosofos:
                    if filosofo.id == 5:
                        filosofo2 = filosofo
            elif nFilosofo2 == 2:
                for filosofo in filosofos:
                    if filosofo.id == 4:
                        filosofo2 = filosofo

        elif nFilosofo == 3:
            for filosofo in filosofos:
                if filosofo.id == nFilosofo:
                    filosofo1 = filosofo

            nFilosofo2 = random.randrange(1, 3)

            if nFilosofo2 == 1:
                for filosofo in filosofos:
                    if filosofo.id == 1:
                        filosofo2 = filosofo
            elif nFilosofo2 == 2:
                for filosofo in filosofos:
                    if filosofo.id == 5:
                        filosofo2 = filosofo

        elif nFilosofo == 4:
            for filosofo in filosofos:
                if filosofo.id == nFilosofo:
                    filosofo1 = filosofo

            nFilosofo2 = random.randrange(1, 3)

            if nFilosofo2 == 1:
                for filosofo in filosofos:
                    if filosofo.id == 2:
                        filosofo2 = filosofo
            elif nFilosofo2 == 2:
                for filosofo in filosofos:
                    if filosofo.id == 1:
                        filosofo2 = filosofo

        elif nFilosofo == 5:
            for filosofo in filosofos:
                if filosofo.id == nFilosofo:
                    filosofo1 = filosofo

            nFilosofo2 = random.randrange(1, 3)

            if nFilosofo2 == 1:
                for filosofo in filosofos:
                    if filosofo.id == 3:
                        filosofo2 = filosofo
            elif nFilosofo2 == 2:
                for filosofo in filosofos:
                    if filosofo.id == 2:
                        filosofo2 = filosofo



        if filosofo1.comendo == False and filosofo2.comendo == False:
            GarfoEsquerdo1 = GetGarfoEsquerdo(filosofo1)
            GarfoDireito1 = GetGarfoDireito(filosofo1)
            GarfoEsquerdo2 = GetGarfoEsquerdo(filosofo2)
            GarfoDireito2 = GetGarfoDireito(filosofo2)

            if not GarfoEsquerdo1 and not GarfoDireito1 and not GarfoEsquerdo2 and not GarfoDireito2: #dois garfos falsos = LIVRES
                Thread(target=Comer, args=(filosofo1,)).start()
                Thread(target=Comer, args=(filosofo2,)).start()


        print('')
        print('----------------------')
        print('')

        for filosofo in filosofos:

            if filosofo.comendo:
                estado = 'esta comendo'
            else:
                estado = 'esta pensando'
            print(filosofo.nome, estado)

        time.sleep(5)
        Janta()
    else:
        print('')
        print('----------------------')
        print('')

        for filosofo in filosofos:
            print(filosofo.nome, " comeu ", filosofo.nVezes, " vezes")

        sys.exit()


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

    filosofos.append(Filosofo('Aristóteles', 1))
    filosofos.append(Filosofo('Descartes', 2))
    filosofos.append(Filosofo('Platão', 3))
    filosofos.append(Filosofo('Pitágoras', 4))
    filosofos.append(Filosofo('Euclides', 5))

    Janta()