#include <stdlib.h>
#include "leFila.h"
#include <stdio.h>
//implementacao de um fila
Fila* iniFila(){//Gera uma fila totalmente zerada
    Fila* l = malloc(sizeof(Fila));
    l->tam = 0;
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

void enfileira(Fila* l,unsigned k){//acrescenta um elemento a fila
    noFila *L = malloc(sizeof(noFila));//aloca no
    L->l = k; // coloca valor no no
    if (l->inicio == NULL) {
       l->fim = l->inicio = L;
    }else {
        /*noFila* aux = l->fim;*/
        l->fim->next = L;
        l->fim = l->fim->next;
    }
}

unsigned desenfileira(Fila* l){
    if(l == NULL)
        exit(21);
    if(l->inicio == NULL){
        exit(21);
    }else{
        unsigned L = l->inicio->l;
        if(l->fim == l->inicio){
            free(l->inicio);
            l->fim = l->inicio = NULL;
        }else{
            noFila *aux = l->inicio;
            l->inicio = l->inicio->next;
            free(aux);
            aux = NULL;
        }
        return L;
    }
}

char filaVazia(Fila *L){
    if(L->inicio == NULL)
        return 1;
    else
        return 0;
}

void destroiFila(Fila* L){
    while (!filaVazia(L)) {
      desenfileira(L);
    }
    return;
    //
    // if(L==NULL)
    //     return;
    // noFila* l = L->inicio;
    //
    // while (l!=NULL) {
    //   noFila *aux = l;
    //   l = l->next;
    //   free(aux);
    //   aux = NULL;
    // }
    // // L->fim = l->inicio = NULL
    // free(L);
    // L = NULL;
}
