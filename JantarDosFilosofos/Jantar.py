import time
import random
import sys
from threading import Thread



filosofos = [] #vetor de filosofos
garfos = [] #vetor de garfos
n=0 # contador global de 40 ciclos


class Filosofo(): #declaração da classe filosofo com seus atributos
    def __init__(self, nome, id):
        self.nome = nome
        self.id = id
        self.comendo = False
        self.nVezes = 0


def Comer(filosofo):
    '''
    função comer, estado atual do filosofo é alterado, contador de vezes que come e a posse dos garfos idem
    após 5 segundo(tempo pré determinado) status dos garfos e do estado do filosofo são atualizados
    '''
    filosofo.comendo = True
    SetGarfoEsquerdo(filosofo, True)
    SetGarfoDireito(filosofo, True)
    filosofo.nVezes+=1

    time.sleep(5)

    filosofo.comendo = False
    SetGarfoEsquerdo(filosofo, False)
    SetGarfoDireito(filosofo, False)

def Janta():
    '''
    semaforo, seleciona o proximo filosofo e garante que sempre dois comam ao mesmo tempo, tal escolha é aleatória
    após a seleção do primeiro filosofo o segundo também e escolhido randomicamente, dentre um numero limitado de opções
    sendo as mesmas as únicas possiveis para que dois filosofos comam por vez
    '''
    global n
    if n <= 40: #verificação do contador global de 40 ciclos
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



        if filosofo1.comendo == False and filosofo2.comendo == False:#verifica se os filosofos atuais não estão comendo então faz com que peguem os garfos
            GarfoEsquerdo1 = GetGarfoEsquerdo(filosofo1)
            GarfoDireito1 = GetGarfoDireito(filosofo1)
            GarfoEsquerdo2 = GetGarfoEsquerdo(filosofo2)
            GarfoDireito2 = GetGarfoDireito(filosofo2)

            if not GarfoEsquerdo1 and not GarfoDireito1 and not GarfoEsquerdo2 and not GarfoDireito2: #dois garfos falsos = LIVRES
                Thread(target=Comer, args=(filosofo1,)).start() #inicia a thread com o objetivo a função comer
                Thread(target=Comer, args=(filosofo2,)).start() #inicia a thread com o objetivo a função comer

#       #printa na tela o estado atual dos filosofos
        print('')
        print('----------------------')
        print('')

        for filosofo in filosofos:

            if filosofo.comendo:
                estado = 'esta comendo'
            else:
                estado = 'esta pensando'
            print(filosofo.nome, estado)

        time.sleep(5) #aguarda novamente 5 segundo para reiniciar o loop
        Janta()
    else:#final dos 40 ciclos, printa na tela a quantidade de vezes que cada filosofo comeu
        print('')
        print('----------------------')
        print('')

        for filosofo in filosofos:
            print(filosofo.nome, " comeu ", filosofo.nVezes, " vezes")

        sys.exit()


def SetGarfoEsquerdo(filosofo, garfo):#função para que o filosofo devolva o garfo esquerdo na mesa na posição correta
    posicao = filosofos.index(filosofo)
    garfos[posicao] = garfo


def SetGarfoDireito(filosofo, garfo):#função para que o filosofo devolva o garfo direito na mesa na posição correta
    posicao = filosofos.index(filosofo)
    if posicao == 4:
        garfos[0] = garfo
    else:
        garfos[posicao+1] = garfo


def GetGarfoEsquerdo(filosofo):#função para que o filosofo pegue o garfo esquerdo na mesa
    posicao = filosofos.index(filosofo)
    return garfos[posicao]

def GetGarfoDireito(filosofo):#função para que o filosofo pegue o garfo direito na mesa
    posicao = filosofos.index(filosofo)
    if posicao == 4:
        return garfos[0]
    else:
        return garfos[posicao+1]



if __name__ == '__main__':
    #instancia dos garfos, a principio todos disponiveis  na mesa
    garfos.append(False)
    garfos.append(False)
    garfos.append(False)
    garfos.append(False)
    garfos.append(False)

    #instancia dos filosofos
    filosofos.append(Filosofo('Aristóteles', 1))
    filosofos.append(Filosofo('Descartes', 2))
    filosofos.append(Filosofo('Platão', 3))
    filosofos.append(Filosofo('Pitágoras', 4))
    filosofos.append(Filosofo('Euclides', 5))

    #inicio do ciclo
    Janta()