#include <stdlib.h>
#include "lePairHeap.h"
#include <stdio.h>
#include <string.h>
/*unsigned TAM;*/
static PairHeap* mergeSubheaps(LePairHeap* L, PairHeap *p, PairHeap *q);
static PairHeap* combinaIrmaos(LePairHeap* L, PairHeap *p);

char lePairHeapVazia(LePairHeap* L){
    if(L->raiz !=NULL){
        return 0;
    }else
        return 1;
}

LePairHeap* iniPairHeap(Mapa* mapa, unsigned tam,double* custos,unsigned fim,Compara compara){//,double* custos){//,RetornaCusto retornaCusto_){
    LePairHeap* L = malloc(sizeof(LePairHeap));
    /*custos = malloc(sizeof(double)*tam);*/
    /*for (int i = 0; i < tam; ++i) {*/
       /*custos[i]=0;*/
    /*}*/
    // L->tam = tam;
    /*mapa = l;  */
    L->comparaCidades = compara;
    L->mapa = mapa;
    L->custos = custos;
    L->objetivoBusca = fim ;

    /*custos = custos1;*/
     /*= retornaCusto1;*/
    /*retornaCusto =  retornaCusto_;*/
    L->numNos = 0;
    L->raiz = NULL;
    return L;
}

void insereLePairHeap(LePairHeap* L, unsigned cidade){
    // L->raiz = PairHeapInsert(L, cidade );
    PairHeap *no;
    no = (PairHeap*)malloc(sizeof(*no));
    no->cidade = cidade;
    no->child = no->sibling = no->prev = NULL;
    if(L->raiz == NULL)
        L->raiz = no;
    else
        L->raiz = mergeSubheaps(L,L->raiz, no);
    L->numNos++;
}

/*static PairHeap* merge_subheaps(LePairHeap* L, PairHeap *p, PairHeap *q);*/

/*static PairHeap* combine_siblings(PairHeap *p);*/

unsigned extraiMin(LePairHeap* L){
    if(L == NULL)
        exit(20);
    unsigned cidade = 0;
    // L->raiz =  PairHeapDeleteMin(L,&cidade);
    PairHeap *novaRaiz = NULL;
    /*if(p == NULL)*/
    if(L->raiz == NULL){
        L->raiz = NULL;
    } else {
        // *key = L->raiz->cidade;
        cidade = L->raiz->cidade;
        if(L->raiz->child != NULL)
            novaRaiz = combinaIrmaos(L,L->raiz->child);
        free(L->raiz);
    }
    // printf("deletando %u, %u elementos\n", cidade, L->numNos);
    // fflush(stdout);
    L->raiz = novaRaiz;
    L->numNos--;
    return cidade;
}

/*recebe um vetor e o seu tamanho e devolve com capacidade dobrada*/
PairHeap **RealocaVetor(PairHeap **v, unsigned *size){//funcao para tornar o vetor realocavel
    PairHeap **temp = NULL;
    // int i;
    // temp = (float *) malloc(*size * 2 * sizeof(float));
    temp = (PairHeap **) malloc(*size * 2 * sizeof(PairHeap*));
    memcpy(temp, v, sizeof *v * *size);// otimizacao do stackOveflow
    // for (i = 0; i < *size; i++) {
    // temp[i] = array[i];
    // }
    *size *= 2;
    free(v);
    return temp;
}

static PairHeap* combinaIrmaos(LePairHeap* L, PairHeap *p){
    if(p->sibling == NULL)
        return p;
    unsigned tamVetor = 100;//numero deliberado, que sera realocado as vezes
    PairHeap **vetorArvores = malloc(sizeof(PairHeap*)*tamVetor);
    int numIrmaos;
    for(numIrmaos = 0; p != NULL; numIrmaos++){
        if( numIrmaos == tamVetor )
            vetorArvores = RealocaVetor(vetorArvores,&tamVetor);
        vetorArvores[numIrmaos] = p;
        p->prev->sibling = NULL;
        p = p->sibling;
    }
    vetorArvores[numIrmaos] = NULL;
    for(int i = 1; i < numIrmaos; i++)
        vetorArvores[i] = mergeSubheaps(L,vetorArvores[i-1], vetorArvores[i]);
    return vetorArvores[numIrmaos-1];
}

static PairHeap* mergeSubheaps(LePairHeap* L, PairHeap *p, PairHeap *q)
{
    if(q == NULL){
        return p;
    }
    /*else if( p->custo <= q->custo )*/
    /*else if( retornaCusto(p->cidade) <= retornaCusto(q->cidade))*/
    // else if( L->custos[p->cidade] <= L->custos[q->cidade])
    else if( L->comparaCidades(L,p->cidade,q->cidade) ){

        q->prev = p;
        p->sibling = q->sibling;
        if(p->sibling != NULL)
            p->sibling->prev = p;

        q->sibling = p->child;
        if(q->sibling != NULL)
            q->sibling->prev = q;

        p->child = q;
        return p;
    }else{

        q->prev = p->prev;
        p->prev = q;
        p->sibling = q->child;
        if(p->sibling != NULL)
            p->sibling->prev = p;

        q->child = p;
        return q;
    }
}

void destroiHeapAux(PairHeap* L) {
    if (!L) return;
    destroiHeapAux(L->sibling);
    destroiHeapAux(L->child);
    L->prev = NULL;
    L->child = NULL;
    L->sibling= NULL;
    free(L);
    L= NULL;
  }

void destroiHeap(LePairHeap* L){
  if (L->raiz!= NULL){
    destroiHeapAux(L->raiz);
  }
}
