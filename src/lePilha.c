#include "lePilha.h"
#include <stdlib.h>
#include <stdio.h>

lePilha* iniPilha(){
  lePilha* pilha = malloc(sizeof(lePilha));
  pilha->numElementos=0;
  pilha->pilha=NULL;
  return pilha;
}

void empilha(lePilha* Pilha,unsigned elem){
  Pilha->numElementos++;
  elementos *aux;
  aux = Pilha->pilha;
  Pilha->pilha = malloc(sizeof(elementos));
  Pilha->pilha->elemento = aux;
  Pilha->pilha->chave = elem;
}

char pilhaVazia(lePilha *L){
    if(L->pilha == NULL)
        return 1;
    else
        return 0;
}

unsigned desempilha(lePilha* Pilha){
  // Pilha->numElementos--;
  if (Pilha->pilha == NULL) {
    printf("Pilha descarregada :(  \n");
    return -1;
  }else{
      unsigned l = Pilha->pilha->chave;
      elementos *aux;
      aux = Pilha->pilha;
      Pilha->pilha = aux->elemento;
      free(aux);
      aux = NULL;
      return l;
    }
}

void destroiPilha(lePilha *l){
   if (l->pilha != NULL) {

   while(!l->pilha->elemento){
        elementos *aux = l->pilha->elemento;
        l->pilha->elemento = l->pilha->elemento->elemento;
        free(aux);
        aux = NULL;
   }
 }

}
