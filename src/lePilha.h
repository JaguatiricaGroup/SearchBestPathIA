#ifndef LEPILHA_H
#define LEPILHA_H
typedef struct elem elementos;
struct elem{
    elementos* elemento;//ponteiro para proximo elemento
    unsigned chave;//chave do elemento
};

typedef struct{
  int numElementos;//numero de elementos na pilha
  elementos *pilha;//ponteiro para o inicio da lista
} lePilha;

  lePilha* iniPilha();//inicia uma pilha vazia
  void empilha(lePilha* Pilha,unsigned elem);//coloca elemento no inicio da pilha
  unsigned desempilha(lePilha* Pilha);//retira o ultimo elemento acrescentado
void destroiPilha(lePilha *l);//desaloca a memoria usada na pilha
    char pilhaVazia(lePilha *L);//retorna 1 se vazia e 0 caso nao


#endif
