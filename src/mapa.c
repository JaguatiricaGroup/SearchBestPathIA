//gera cidades para o trabalho de Ia

#include "mapa.h"
#include <stdlib.h>
#include <stdio.h>
/*#include "leFila.h"*/
#include <math.h>
#define ModuloDist(x,x1,y,y1) (sqrt((pow(((x) - (x1)),(2))) + pow(((y) - (y1)),(2))))
#define temEstrada(x) rand()%x //funcao de probabilidade de ter caminho//tentar melhorar a cance de caminho entre proximas

static Mapa* alocaMapa(unsigned xTotal,unsigned yTotal,unsigned numeroCidades){
    Mapa* mapa = malloc(sizeof(Mapa));
    mapa->numeroCidades = numeroCidades;
    mapa->yTotal = yTotal;
    mapa->xTotal = xTotal;
    /*mapa->cidades = malloc(sizeof(Cidade)*numeroCidades);*/
    mapa->distancias = malloc(sizeof(double)*(numeroCidades-1));
    for (int i = 0; i < mapa->numeroCidades; ++i) {
        mapa->distancias[i]  = malloc(sizeof(double)*mapa->numeroCidades);
    }
    /*for (int i = 0; i < mapa->numeroCidades; ++i) {        */
        /*for (int j = 0; j < mapa->numeroCidades; ++j) {*/
           /*mapa->distancias[i][j] = 0; */
        /*}*/
    /*}*/

    return mapa;
}

// Cidade* alocaCidade(){
//     Cidade *cidade = malloc(sizeof(Cidade));
//     cidade->y = 0;
//     cidade->x = 0;
//     /*cidade->numCidadesComCaminhoPara = rand()* chanceCaminho;*/
//     /*cidade->indiceCidadesComCaminhoPara = malloc(sizeof(unsigned)*cidade->numCidadesComCaminhoPara);*/
//     /*cidade->indicesCidadesComCaminhoPara = iniFila();        */
//     return cidade;
// }

static Cidade geraCidade(Mapa* m, double chanceCaminho){
    Cidade cidade ;//= alocaCidade();
    cidade.y = (rand()/1000)% m->yTotal;
    /*cidade->y = (rand()/1000)% m->yTotal;*/
    cidade.x = (rand()/1000)% m->xTotal;
    /*cidade->x = (rand()/1000)% m->xTotal;*/
    /*cidade->numCidadesComCaminhoPara = rand()* chanceCaminho;*/
    /*cidade->indiceCidadesComCaminhoPara = malloc(sizeof(unsigned)*cidade->numCidadesComCaminhoPara);*/
    /*cidade->indiceCidadesComCaminhoPara = iniFila();        */
    /*for (int i = 0; i < m->numeroCidades; ++i) { */
       /*[>char temCaminho = (char) chanceCaminho; <]*/
       /*if( (unsigned)chanceNaoCaminho((int)chanceCaminho)){*/
        /*enfileira(cidade->indicesCidadesComCaminhoPara,i); */
        /*//acrescentar distancias*/
        /*m->distancias[m->numeroCidades][i] =*/
            /*(double) ModuloDist(cidade->x,m->cidades[i].x,cidade->y,m->cidades[i].y);*/
        /*}*/
    /*}*/
    return cidade;
}

Mapa* geraMapa(unsigned int xTotal, unsigned int yTotal, unsigned int numeroCidades, int chanceCaminho, int coeficienteEstrada){
    Mapa* L = alocaMapa(xTotal,yTotal,numeroCidades);
    L->numeroCidades = numeroCidades;
    L->yTotal = yTotal;
    L->xTotal = xTotal;
    Cidade *cidades = malloc(sizeof(Cidade)*numeroCidades);
    for (int i = 0; i < L->numeroCidades; ++i) {
        cidades[i] = geraCidade(L,chanceCaminho);
    }
    for (int i = 0; i < L->numeroCidades; ++i) {//parte superior ficam as distancias retas, inferior as distancias considerando estradas
        for (int j = 0; j < L->numeroCidades; ++j) {
                /*enfileira(L->cidades[i]->indicesCidadesComCaminhoPara,j); */
            if(i < j){//caminho reto
              //  L->distancias[i][j] = ceil((double) ModuloDist(cidades[i].x,cidades[j].x,cidades[i].y,cidades[j].y));//tirar esse ceil
               L->distancias[i][j] = (double) ModuloDist(cidades[i].x,cidades[j].x,cidades[i].y,cidades[j].y);
            } else {
                if(i==j)
                    L->distancias[i][i] = 0;
                else{ //distancia com estrada
                    if(((int) temEstrada(chanceCaminho))==1)
                    // L->distancias[i][j] = ceil(L->distancias[j][i] + L->distancias[j][i]*(((double)((rand()%coeficienteEstrada))/1000)));
                        L->distancias[i][j] = L->distancias[j][i] + L->distancias[j][i]*(((double)((rand()%coeficienteEstrada))/1000));//sofre uma piora em relacao ao caminho reto
                    else
                        L->distancias[i][j] = -1;
                }
            }
            /*L->distancias[i][j] = (double) ModuloDist(L->cidades[i]->x,L->cidades[j]->x,L->cidades[i]->y,L->cidades[j]->y);*/
        }
    /*char temCaminho = (char) chanceCaminho;*/
    }
    /*limpaCidades(cidades,L->numeroCidades);*/
    free(cidades);
    return L;
}

void printDistancias(Mapa *L){
    printf("imprimindo matriz de distancias\n");
    for (int i = 0; i < L->numeroCidades; ++i) {
        printf("   %6d  ",i);//L->distancias[i][j]) ;
    }
    printf("\n");
    for (int i = 0; i < L->numeroCidades; ++i) {
        /*printf("Cidade %d :",i );*/
        printf("%3d ",i);
        for (int j = 0; j < L->numeroCidades; ++j) {
           printf("(%8.2f) ",distancia(L,i,j));//L->distancias[i][j]) ;
           /*printf("%d->(%.2f) ",j,L->distancias[i][j]) ;*/
        }
        printf("\n");
    }

}

void printHeuristicas(Mapa *L){
    printf("imprimindo matriz de distancias\n");
    for (int i = 0; i < L->numeroCidades; ++i) {
        printf("   %6d  ",i);//L->distancias[i][j]) ;
    }
    printf("\n");
    for (int i = 0; i < L->numeroCidades; ++i) {
        /*printf("Cidade %d :",i );*/
        printf("%3d ",i);
        for (int j = 0; j < L->numeroCidades; ++j) {
           printf("(%8.2f) ",heuristica(L,i,j));//L->distancias[i][j]) ;
           /*printf("%d->(%.2f) ",j,L->distancias[i][j]) ;*/
        }
        printf("\n");
    }

}

double heuristica(Mapa *L,unsigned i, unsigned j){
    if(i < j)
        return L->distancias[i][j];
    else
        return L->distancias[j][i];
}

double distancia(Mapa *L,unsigned i, unsigned j){
    if(i > j)
        return L->distancias[i][j];
    else
        return L->distancias[j][i];
}
