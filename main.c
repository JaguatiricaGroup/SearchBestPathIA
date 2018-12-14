/*#include "src/leHeapEsq.h"*/
#include "src/lePairHeap.h"
#include <stdio.h>
/*#include "src/mapa.h" */
#include "src/buscas.h"
#include <stdlib.h>
#include <string.h>
#define X_TOTAL 1000 // limite de x para coordenada da cidade
#define Y_TOTAL 1000 // limite de y para coordenada da cidade
#define NUM_CIDADES 1000 //numero padrao de cidades quando nao houver argumento
#define CHANCE_CIDADE 2 // chance de ter cidade mais que três gera problemas
#define COEFICIENTE_ESTRADA 5000 //o quando a estrada é pior em relaçao ao caminho reto

int main(int argc, char *argv[]){ //./buscas NUMEROCIDADES NOMEALGORITMO SEED
	int numeroCidades = NUM_CIDADES;
    char algoritmo = 'p';
	if (argc > 1){
		numeroCidades = atoi(argv[1]);
       if(argc > 2) {
        algoritmo = argv[2][0];
       }
	}
	srand(atoi(argv[3]));
	// srand(12323);
    printf("Gerando Mapa\n");
	Mapa *L = geraMapa((int)X_TOTAL, (int)Y_TOTAL, numeroCidades, (int)CHANCE_CIDADE, COEFICIENTE_ESTRADA);
	busca(L,0,numeroCidades-1, algoritmo);
    /*limpaCidades(L);*/
    /*printDistancias(L);*/
    /*printInfos(backTrack(L, 0, numeroCidades - 1),L);*/
    /*limpaDiagonal(L);*/
    // printDistancias(L);
		// printHeuristicas(L);
    /*printInfos(buscaProfundidade(L, 0, numeroCidades - 1),L);*/
    /*printInfos(buscaLargura(L, 0, numeroCidades - 1),L);*/
    /*printInfos(buscaOrdenada(L,0, numeroCidades-1),L);*/
    /*printf("%lf   \n", distancia(L,0,9999));*/

		// buscaIdaEstrela( L, 0, numeroCidades-1);
		// busca(L,0,numeroCidades-1, 'a');
    /*limpaDiagonal(L);*/
    /*buscaProfundidade(L, 0 ,numeroCidades -1);*/
    /*busca(L,0,numeroCidades-1, argv[2][0]);*/
    /*HeapEsq* L1 = iniHeap();*/
    /*insereHeap(L1,7);*/
    /*double *s = malloc(sizeof(double)*8);*/
    /*s[0]= 4;*/
    /*s[1]= 3;*/
    /*s[2]= 5;*/
    /*s[3]= 7;*/
    /*s[4]= 2;*/
    /*s[5]= 2;*/
    /*s[6]= 2;*/
    /*s[7]= 1;*/
    /*LePairHeap* heap = iniPairHeap(5,s);*/
    /*insereLePairHeap(heap,0);*/
    /*insereLePairHeap(heap,4);*/
    /*insereLePairHeap(heap,3);*/
    /*insereLePairHeap(heap,5);*/
    /*insereLePairHeap(heap,7);*/
    /*insereLePairHeap(heap,6);*/
    /*insereLePairHeap(heap,2);*/
    /*insereLePairHeap(heap,1);*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    /*printf("heap:  %d \n", extraiMin(heap));*/
    // printInfos(buscaOrdenada(L,0, numeroCidades-1),L);
	return 0;
}
