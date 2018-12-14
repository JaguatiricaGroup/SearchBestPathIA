 /*Gera grafos para o trabalho de Ia*/
#include "leFila.h"
typedef struct {
    double x,y;//coordenadas da cidade    
    //unsigned *indiceCidadesComCaminhoPara;
    //Fila *indicesCidadesComCaminhoPara;
}Cidade;

typedef struct {
    // Cidade **cidades;
    double **distancias;//melhorar essa matriz na diagonal principal
    unsigned numeroCidades;//numero de Cidades presentes no problema Gerado
    unsigned xTotal,yTotal;// coordenada maxima possivel em x e y
}Mapa;


/*recebe mapa e imprime a matriz de heuristica de distancias*/
void printHeuristicas(Mapa *L);
/*recebe limite em c e y, um numero de cidades, a chance de ter caminho,
coeficiente da Estrada ser ruim e devolve um mapa*/
Mapa* geraMapa(unsigned int xTotal,unsigned int yTotal, unsigned int numeroCidades,int chanceCaminho, int coeficienteEstrada);
/*recebe mapa e imprime a matriz de distancias*/
void printDistancias(Mapa *L);
/*recebe cidades e mapa e devolve distancia*/
double distancia(Mapa *L,unsigned i, unsigned j);
/*recebe cidades e mapa e devolve heuristica da distancia reta*/
double heuristica(Mapa *L,unsigned i, unsigned j);


// Cidade geraCidade(Mapa* m,double ChanceCaminho);
// Mapa* alocaMapa(unsigned xTotal, unsigned yTotal,unsigned numeroCidades);
// Cidade* alocaCidade();
//Mapa* geraMapa(unsigned xTotal, unsigned yTotal,unsigned numeroCidades);
// void limpaDiagonal(Mapa* L);
//void limpaCidades(Mapa *L);
