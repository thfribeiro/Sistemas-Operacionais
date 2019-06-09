Alunos:
Willian Molina Ibanez - 120175
Thiago Fernandes Ribeiro - 120160
Daniel Bernardo Rocha - 120174
Jose Eduardo de Oliveira - 120178
Fernando Masuda - 120074

SIMULADOR DE PROCESSOS

Descrição do Trabalho:

A implementação dos Algoritmos foi feita apartir da Linguagem de Programação C++. E tem como parte na aprovação da disciplina de Sistemas Operacionais do Curso de Ciências da Computação, na Universidade Estadual do Norte do Paraná (UENP).

Neste Trabalho será apresentado um simulador para Processos, aplicando as ideias vistas nas aulas da disciplina. A implementação foi feita utilizando principalmente a estrutura de dados: Lista Simplesmente Encadeada. O trabalho conta com 4 arquivos: main.cpp, kernel.cpp, util.h e biblioteca.cpp. Além de apresentar as funções: inicializar, exibirProcessos, inserirProcesso, busca, systemCall, finalizarProcesso como as principais tarefas.

Arquivos: 

Serão agora Explicados o Funcionamento de cada arquivo do Trabalho

main.cpp- Neste arquivo ocorre basicamente a interação do usuário com o programa, podendo ser retratado como: Modo Usuário.

kernel.cpp- Neste arquivo estarão contidas as principais funções do programa, podendo ser retratado como: Modo Núcleo.

biblioteca.cpp- Faz a intermediação das chamadas do usuário com as chamadas do núcleo (todas as funções aqui listadas são de modo usuário), podendo ser retradado como: Modo Biblioteca.

util.h- Neste arquivo, estão as structs e definições utilizadas para a construção do programa.


Funções:

Serão agora Explicados o Funcionamento de cada Função do Trabalho

kernel.cpp -  Modo núcleo:

inicializar()- Responsável por inicializar a lista simplesmente encadeada, que servirá como base para a alocação dos processos.
exibirProcessos()- Responsável por percorrer a lista, e mostrar para o usuário os processos contidos até então.
inserirProcesso()- Responsável por inserir um processo na lista.
busca()- Responsável por realizar a busca de determinado processo na lista, a fim de verificar se esta finalizado e liberar processos dependentes;
systemCall()- Responsável por executar os processos contidos na lista.
finalizarProcessos()- Responsável por liberar a memória alocada anteriormente para todos os processos.
finalizarProcessosFINALIZADOS()- Responsável por liberar a memória alocada anteriormente para os processos finalizados.
buscarPidDEP() - Responsável por verificar a existencia do processo ao qual o novo processo é dependente.


biblioteca.cpp - Faz a intermediação das chamadas do usuário com as chamadas do núcleo (todas as funções aqui listadas são de modo usuário):

exibirProcessosUsuario()- Responsável por chamar a função 'exibirProcessos()'
inserirProcessoUsuario()- Responsável por chamar a função 'inserirProcesso()'
systemCallUsuario()- Responsável por chamar a função 'systemCall()'
finalizarProcessosUsuario()- Responsável por chamar a função 'finalizarProcesso()'
buscarPidDEPUsuario() - Responsável por chamar a função 'buscarPidDEP()'

