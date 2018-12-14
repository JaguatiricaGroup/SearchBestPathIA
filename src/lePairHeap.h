#ifndef PAIRINGHEAPPROGPRAXIS_H
#define PAIRINGHEAPPROGPRAXIS_H
#include "buscas.h"
typedef struct PairingHeap LePairHeap;

typedef int (*Compara) (LePairHeap* L,unsigned cidade, unsigned cidade1);//tipo da funcao de comparacao

typedef struct PairingHeapNode{
    unsigned                    cidade;//indica cidade que representa
    struct  PairingHeapNode*    child;//ponteiro para o no no nivel abaixo, menos prioridade
    struct  PairingHeapNode*    sibling;// ponteiro para o no ao lado, igual prioridade
    struct  PairingHeapNode*    prev;// ponteiro para o pai
}PairHeap;


//Compara comparaCidades;
//double* custos;
//Mapa *mapa;

 struct PairingHeap {
   PairHeap* raiz;//ponteiro para a raiz da heap
   unsigned numNos;//numero de elementos na heap
   Mapa *mapa;//mapa usado no problema de ia, otimizando memoria
   double* custos;//ponteiro para vetor de custos
   Compara comparaCidades;//ponteiro para funcao que compara prioridade
   unsigned objetivoBusca;//chegada para o problema
   //double* custos;
};

//LePairHeap* iniPairHeap(unsigned tam);
//LePairHeap* iniPairHeap(unsigned tam, Compara compara);//,double* custos);////,RetornaCusto retornaCusto_);
//LePairHeap* iniPairHeap(unsigned tam,double* custos,Mapa* mapa, Compara compara);//,double* custos){//,RetornaCusto retornaCusto_){

LePairHeap* iniPairHeap(Mapa* mapa, unsigned tam,double* custos,unsigned fim,Compara compara);//inicia um estrutura de heap vazia
unsigned extraiMin(LePairHeap* L);//retorna e deleta o elemento mais prioritario da heap
void insereLePairHeap(LePairHeap* L, unsigned cidade);//insere um elemento na heap
char lePairHeapVazia(LePairHeap* L);//retorna 1 se vazia, 0 caso nao
void destroiHeap(LePairHeap* L);//desaloca memoria usada na heap



//static PairHeap* merge_subheaps(LePairHeap* L, PairHeap *p, PairHeap *q);
//static PairHeap* combine_siblings(LePairHeap* L, PairHeap *p);
//PairHeap* PairHeap_insert(PairHeap *p, double key);
//PairHeap* PairHeap_insert(PairHeap *p, double key,unsigned cidade);
//PairHeap* PairHeap_insert(PairHeap *p, unsigned cidade, double custo);
// PairHeap* PairHeap_insert(LePairHeap* L, unsigned cidade,double custo);
//PairHeap* PairHeap_DecreaseKey(PairHeap *p, PairHeap *pos, int d);
//PairHeap* PairHeap_DeleteMin(double *key, PairHeap *p);
// PairHeap* PairHeap_DeleteMin(LePairHeap* L,unsigned *key);
#endif /* ifndef PAIRINGHEAPPROGPRAXIS_H */
