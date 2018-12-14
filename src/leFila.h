#ifndef LEFILA_H
#define LEFILA_H
typedef struct L Fila;
typedef struct l noFila;

struct L{
    noFila *inicio;//ponteiro para o inicio da fila
    noFila *fim;////ponteiro para o fim da fila
    unsigned tam;// numero de elementos na fila
};

struct l{
    noFila *next;//proximo no na fila
    unsigned l;//chave do elemento
};

Fila* iniFila();//inicia uma fila vazia
void enfileira(Fila *l,unsigned k);//coloca um elemento no fim da fila
unsigned desenfileira(Fila* l);//retira o primeiro elemento na fila
void destroiFila(Fila* L);//desaloca a memoria usada na fila
char filaVazia(Fila *L);//retorna 1 se vazia e 0 caso nao

#endif /* ifndef LEFILA_H */
