#ifndef BUSCAS_H
#define BUSCAS_H
#include "mapa.h"
#include "lePilha.h"

typedef struct {
    lePilha *caminho;// pilha com o caminho percorrido
    unsigned profundidade,nosExpandidos,nosVisitados;// profundidade da solucao, nos Expandidos na solucao, nos Visitados na solucao
    double custoSolucao,tempoExecucao;//custo na solucao e tempo de execucao
}InformacoesDaBusca;

/*
b = backtrack
l = Largura
p = profundidade
o = Ordenada
g = Gulosa
a = a*
i = ida*
*/
/*recebe um mapa, um inicio fim e um char com a inicial do problema, e imprime solucao*/
void busca(Mapa* L,unsigned inicio,unsigned fim,char busca);//funcao para chamar as buscas

//int backtrack(Mapa* L,unsigned inicio, unsigned fim);
// InformacoesDaBusca *backTrack(Mapa* L,unsigned inicio, unsigned objetivo);
// InformacoesDaBusca *buscaLargura(Mapa * L, unsigned inicio, unsigned fim);
// InformacoesDaBusca *buscaProfundidade(Mapa * L, unsigned inicio, unsigned fim);
//void imprimeInformacoesBusca(InformacoesDaBusca* L);
// void printInfos(InformacoesDaBusca* infos,Mapa *L);
// InformacoesDaBusca* buscaOrdenada(Mapa * L, unsigned inicio, unsigned fim);
//int  auxBackTrack(Mapa* L, unsigned cidadeAtual, unsigned objetivo);
// InformacoesDaBusca* buscaGulosa(Mapa * L, unsigned inicio, unsigned fim);

// InformacoesDaBusca* buscaAestrela(Mapa * L, unsigned inicio, unsigned fim);
// InformacoesDaBusca* buscaIdaEstrela(Mapa *L, unsigned inicio, unsigned fim);
#endif /* ifndef BUSCAS_H */
