#include "buscas.h"
#include "lePairHeap.h"
#include <time.h>
/*#include "lePilha.h"*/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*#include "lePilha.h"*/
static InformacoesDaBusca* buscaIdaEstrela(Mapa *L, unsigned inicio, unsigned fim);
static InformacoesDaBusca* buscaAestrela(Mapa * L, unsigned inicio, unsigned fim);
static InformacoesDaBusca* buscaGulosa(Mapa * L, unsigned inicio, unsigned fim);
static InformacoesDaBusca* buscaProfundidade(Mapa * L, unsigned inicio, unsigned fim);
static InformacoesDaBusca* buscaLargura(Mapa * L, unsigned inicio, unsigned fim);
static InformacoesDaBusca* buscaOrdenada(Mapa * L, unsigned inicio, unsigned fim);
static InformacoesDaBusca* backTrack(Mapa* L,unsigned inicio, unsigned objetivo);

static unsigned* iniPai(unsigned tam,int valorInicial){
    unsigned *pais = malloc(sizeof(unsigned)*tam);
    for(int i=0 ;i < tam;i++){
        pais[i]=valorInicial;
        /*printf("%u\n", pais[i]);            */
    }
    /*printf("Gerei os pais");*/
    /*fflush(stdout);*/
    return pais;
}

static double* iniCustos(unsigned tam,int valorInicial){
    double *custos = malloc(sizeof(double)*tam);
    for(int i=0 ;i < tam;i++){
        custos[i]=valorInicial;
        /*printf("%u\n", pais[i]);            */
    }
    /*printf("Gerei os pais");*/
    /*fflush(stdout);*/
    return custos;
}

static char* iniVisitados(unsigned tam){
    char *visitados = malloc(sizeof(char)*tam);
    for(int i = 0; i<tam; i++)
        visitados[i] = 0;
    return visitados;
}

static InformacoesDaBusca* iniBusca(){
    InformacoesDaBusca* l = malloc(sizeof(InformacoesDaBusca));
    l->tempoExecucao = 0;
    l->nosVisitados = 0;
    l->custoSolucao = 0;
    l->nosExpandidos = 0;
    l->profundidade = 0;
    l->caminho = iniPilha();
    return l;
}

static void printInfos(InformacoesDaBusca* infos,Mapa *L){
    fflush(stdout);
    printf("\nresultados da busca:\n");
    if (pilhaVazia(infos->caminho)) {
        printf("Busca Fracassada, Resultado não existe\n");
    }else {
        printf("Nos visitados: %u \n",infos->nosVisitados);
        printf("Nos expandidos: %u \n",infos->nosExpandidos);
        printf("Fator de Ramificacao Medio: %.2lf \n", (double)infos->nosExpandidos/(double)infos->nosVisitados );
        printf("profundidade Solucao: %u \n",infos->caminho->numElementos);
        printf("caminho: inicio");
        double custoSolucao = 0;
        unsigned pai = desempilha(infos->caminho);
        printf(" -> %u",pai );
       while(!pilhaVazia(infos->caminho)){
            unsigned atual = desempilha(infos->caminho);
            custoSolucao+= distancia(L,pai,atual);
            printf(" -> %u",atual );
            pai = atual;
        }
        printf("\n");
        printf("custo Solucao: %lf \n",custoSolucao);
        printf("Tempo execucao: %lf seconds \n", infos->tempoExecucao);
        fflush(stdout);
  }
}

void busca(Mapa* L,unsigned inicio,unsigned fim,char busca){
    InformacoesDaBusca *infos=NULL;
    if( fim >= L->numeroCidades){
      printf("cidade não está no mapa, busca fracassada\n");
      return ;
    }
    switch(busca){
        case 'i' :{
            clock_t start = clock();
            infos = buscaIdaEstrela(L,inicio,fim);
            clock_t diff = clock() - start;
            double msec =  (double) diff / CLOCKS_PER_SEC;
            infos->tempoExecucao = msec;
            printInfos(infos,L);
            // clock_t start = clock();
            // /*infos = buscaIdaestrela(L,inicio,fim);*/
            // printInfos(buscaIdaEstrela(L, inicio, fim),L);
            // diff = clock() - start;
            break;
        }
        case 'b':{
            /*infos = backTrack(L,inicio,fim);*/
            clock_t start = clock();// *100.0f testar depois
            infos = backTrack(L,inicio,fim);
            clock_t diff = clock() - start;
            double msec =  (double) diff / CLOCKS_PER_SEC;
            infos->tempoExecucao = msec;
            printInfos(infos,L);
            break;
        }
        case 'l':{
            clock_t start = clock();
            infos = buscaLargura(L,inicio,fim);
            clock_t diff = clock() - start;
            double msec =  (double) diff / CLOCKS_PER_SEC;
            infos->tempoExecucao = msec;
            printInfos(infos,L);
            break;
        }
        case 'p':{
            clock_t start = clock();
            infos = buscaProfundidade(L,inicio,fim);
            clock_t diff = clock() - start;
            double msec =  (double) diff / CLOCKS_PER_SEC;
            infos->tempoExecucao = msec;
            printInfos(infos,L);

            // clock_t start = clock();
            // printInfos(buscaProfundidade(L,inicio,fim),L);
            // /*infos = buscaProfundidade(L,inicio,fim);*/
            // diff = clock() - start;
            break;
        }
        case 'o':{
            clock_t start = clock();
            infos = buscaOrdenada(L,inicio,fim);
            clock_t diff = clock() - start;
            double msec =  (double) diff / CLOCKS_PER_SEC;
            infos->tempoExecucao = msec;
            printInfos(infos,L);

            // clock_t start = clock();
            // printInfos(buscaOrdenada(L,inicio,fim),L);
            // /*infos = buscaOrdenada(L,inicio,fim);*/
            // diff = clock() - start;
            break;
        }
        case 'g' :{
            clock_t start = clock();
            infos = buscaGulosa(L,inicio,fim);
            clock_t diff = clock() - start;
            double msec =  (double) diff / CLOCKS_PER_SEC;
            infos->tempoExecucao = msec;
            printInfos(infos,L);

            // clock_t start = clock();
            // printInfos(buscaGulosa(L,inicio,fim),L);
            // /*infos = buscaGulosa(L,inicio,fim);*/
            // diff = clock() - start;
            break;
        }
        case 'a' :{
            clock_t start = clock();
            infos = buscaAestrela(L,inicio,fim);
            clock_t diff = clock() - start;
            double msec =  (double) diff / CLOCKS_PER_SEC;
            infos->tempoExecucao = msec;
            printInfos(infos,L);

            // clock_t start = clock();
            // printInfos(buscaAestrela(L,inicio,fim),L);
            // /*infos = buscaAestrela(L,inicio,fim);*/
            // diff = clock() - start;
         break;
        }
        
        default:{

            printInfos(backTrack(L,inicio,fim),L);
            printInfos(buscaLargura(L,inicio,fim),L);
            printInfos(buscaProfundidade(L,inicio,fim),L);
            printInfos(buscaOrdenada(L,inicio,fim),L);
            printInfos(buscaGulosa(L,inicio,fim),L);
            printInfos(buscaAestrela(L,inicio,fim),L);
            printInfos(buscaIdaEstrela(L, inicio, fim),L);
            printf("Voce digitou uma chave invalida, imprimi todos os resultados sem capturar o tempo\n");
            }
        
    }
    /*printInfos(infos,L);*/
}


int auxBackTrack(Mapa* L, unsigned cidadeAtual, unsigned objetivo,InformacoesDaBusca *infos,unsigned *pais){
    /*printf("-> %u ", cidadeAtual );*/
    infos->nosVisitados++;
    /*visitados[pai][cidadeAtual] = 1 ;*/
    /*L->distancias[cidadeAtual][cidadeAtual] = 1;*/
    if(cidadeAtual == objetivo){
        empilha(infos->caminho,cidadeAtual);
        return 1;
        /*printf("cheguei ao objetivo \n");*/
    } else {
        for(unsigned i= 0 ; i < L->numeroCidades ; i++){
            infos->nosExpandidos++;
            if(distancia(L,cidadeAtual,i) > 0 && pais[i]==L->numeroCidades){//!L->distancias[i][i])
            // if(distancia(L,cidadeAtual,i) != -1.0 && distancia(L,cidadeAtual,i)!= 0.0 && pais[i]==L->numeroCidades){//!L->distancias[i][i])
                pais[i] = cidadeAtual;
                if(auxBackTrack(L,i,objetivo,infos,pais)){
                    empilha(infos->caminho,cidadeAtual);
                    return 1;
                }
            }
        }
    }
    /*printf("backTrack (%u)\n",cidadeAtual);*/
    /*infos->profundidade--;*/
    /*L->distancias[cidadeAtual][cidadeAtual] = 0;*/
    pais[cidadeAtual] = L->numeroCidades;
    return 0;
}

static InformacoesDaBusca* backTrack(Mapa* L,unsigned inicio, unsigned objetivo){
    printf("Iniciando Busca Backtrack \n ");
    InformacoesDaBusca* infos = iniBusca();
    unsigned *pais = iniPai(L->numeroCidades,L->numeroCidades);
    /*printf("iniciando no %u e indo ate %u:\n", inicio, objetivo );    */
    /*char** visitados = malloc(sizeof(char*)*L->numeroCidades);*/
    /*for (int i = 0; i < L->numeroCidades; ++i) {*/
        /*visitados [i] = malloc(sizeof(char)*L->numeroCidades);*/
        /*for (int j = 0; j < L->numeroCidades; ++j) {*/
            /*visitados[i][j]= 0;            */
        /*}        */
    /*} */
    printf("inicio ");
    pais[inicio] = inicio;
    if(auxBackTrack(L,inicio,objetivo,infos,pais))
        printf("sucesso\n");
    else
        printf("falha\n");
    /*limpaDiagonal(L);*/
    free(pais);
    pais = NULL;
    return infos;
}

static InformacoesDaBusca* buscaLargura(Mapa * L, unsigned inicio, unsigned fim){
    printf("Iniciando Busca em Largura \n ");
    InformacoesDaBusca* infos = iniBusca();
    Fila *fila = iniFila();
    enfileira(fila,inicio);
    unsigned atual;
    printf("inicio ");
    unsigned *pais = iniPai(L->numeroCidades,L->numeroCidades);
    pais[inicio] = inicio;
    while(!filaVazia(fila)){
        infos->nosVisitados++;
        atual = desenfileira(fila);
        // printf("-> %u ", atual );
        if(atual == fim){
            printf("sucesso\n");
            int k;
            for(k = atual;pais[k]!= k; k= pais[k] )
                empilha(infos->caminho,k);
            empilha(infos->caminho,k);
            break;
        }else{
            for(int i =0 ; i< L->numeroCidades; i++)
                if( distancia(L,atual,i) > 0 && pais[i] == L->numeroCidades){// !L->distancias[i][i]){
                    pais[i] = atual;
                    infos->nosExpandidos++;
                    enfileira(fila,i);
                    /*printf("%d\n", i);*/
                }
        }
        /*L->distancias[atual][atual] = 1;*/
        /*pais[atual] = L->numeroCidades;*/
    }
    /*limpaDiagonal(L);*/
    destroiFila(fila);
    free(pais);
    pais = NULL;
    return infos;
}

static InformacoesDaBusca* buscaProfundidade(Mapa * L, unsigned inicio, unsigned fim){
    printf("Iniciando Busca em profundidade \n ");
    InformacoesDaBusca* infos = iniBusca();
    lePilha *pilha = iniPilha();
    empilha(pilha,inicio);
    unsigned atual;
    printf("inicio ");
    unsigned *pais = iniPai(L->numeroCidades,L->numeroCidades);
    pais[inicio] = inicio;
    char* visitados = iniVisitados(L->numeroCidades);
    while(!pilhaVazia(pilha)){
        atual = desempilha(pilha);
        infos->nosVisitados++;
        // printf("-> %u ", atual );
        if(atual == fim){
            // printf("sucesso\n");
            int k;
            for(k = atual;pais[k]!= k; k= pais[k] )
                empilha(infos->caminho,k);
            empilha(infos->caminho,k);
            break;
        }else{
            for(int i = L->numeroCidades-1 ; i>=0; i--){
                if( distancia(L,atual,i) > 0 && !visitados[i]){// !L->distancias[i][i]){
                /*printf("%u\n", i);*/
                    pais[i] = atual;//if( distancia(L,atual,i) > 0 && !L->distancias[i][i]){
                    infos->nosExpandidos++;
                    empilha(pilha,i);
                    /*printf("%d\n", i);*/
                }
            }
        }
        /*L->distancias[atual][atual] = 1;*/
                visitados[atual] = 1;
    }
    /*limpaDiagonal(L);*/
            free(pais);
            pais = NULL;
            free(visitados);
            visitados = NULL;
    destroiPilha(pilha);
    return infos;
}

static int comparaHeapOrdenada(LePairHeap* L,unsigned cidade1, unsigned cidade2){
  // printf("%.2lf\n",L->custos[L->pais[cidade1]] + distancia(L->mapa,L->pais[cidade1],cidade1) );
  // return L->custos[L->pais[cidade1]] + distancia(L->mapa,L->pais[cidade1],cidade1) <= L->custos[L->pais[cidade2]] + distancia(L->mapa,L->pais[cidade2],cidade2);
  return L->custos[cidade1]  <= L->custos[cidade2];//+ distancia(L->mapa,L->pais[cidade2],cidade2);
}

static int comparaHeapGulosa(LePairHeap* L,unsigned cidade1, unsigned cidade2){
  // return heuristica(L->mapa,cidade1,L->pais[cidade1]) <= heuristica(L->mapa,cidade2,L->pais[cidade2]);
  return heuristica(L->mapa,cidade1,L->objetivoBusca) <= heuristica(L->mapa,cidade2,L->objetivoBusca);
  // return heuristica(L->mapa,cidade1,L->mapa->numeroCidades-1) <= heuristica(L->mapa,cidade2,);
}

static int comparaHeapAestrela(LePairHeap* L,unsigned cidade1, unsigned cidade2){
  // return L->custos[L->pais[cidade1]] + distancia(L->mapa,L->pais[cidade1],cidade1) + heuristica(L->mapa,cidade1,L->pais[cidade1])
  //     <= L->custos[L->pais[cidade2]] + distancia(L->mapa,L->pais[cidade2],cidade2) + heuristica(L->mapa,cidade2,L->pais[cidade2]);
  // return L->custos[cidade1] + heuristica(L->mapa,cidade1,L->pais[cidade1])  <= L->custos[cidade2] + heuristica(L->mapa,cidade2,L->pais[cidade2]);
  return L->custos[cidade1] + heuristica(L->mapa,cidade1,L->objetivoBusca)  <= L->custos[cidade2] + heuristica(L->mapa,cidade2,L->objetivoBusca);
  /*return heuristica(L->mapa,cidade1,L->pais[cidade1]) <= */
}

static InformacoesDaBusca* buscaOrdenada(Mapa * L, unsigned inicio, unsigned fim){
    printf("Iniciando Busca Ordenada \n ");
    unsigned *pais = iniPai(L->numeroCidades,L->numeroCidades);
    InformacoesDaBusca* infos = iniBusca();
    double* custos = iniCustos(L->numeroCidades,0);//malloc(sizeof(double)*L->numeroCidades);
    LePairHeap* heap = iniPairHeap(L,L->numeroCidades,custos,fim,comparaHeapOrdenada);
    /*enfileira(fila,inicio);*/
    insereLePairHeap(heap,inicio);
    unsigned atual;
    printf("inicio ");
    fflush(stdout);
    pais[inicio] = inicio;
    while(!lePairHeapVazia(heap)){
        infos->nosVisitados++;
        atual = extraiMin(heap);
        //  printf("-> _%u_ ", atual );
        if(atual == fim){
            printf("sucesso\n");
            int k;
            for(k = atual;pais[k]!= k; k= pais[k] )
                empilha(infos->caminho,k);
            empilha(infos->caminho,k);
            break;
        }else{
            for(int i =0 ; i< L->numeroCidades; i++)
                if( distancia(L,atual,i) > 0 ){// !L->distancias[i][i]){
                  if( pais[i] == L->numeroCidades || custos[i] > custos[atual] + distancia(L,atual,i) ){//caso em que já existe mas é melhor*/
                    // if( pais[i] == L->numeroCidades || custos[i] > custos[atual] + distancia(L,atual,i) ){//caso em que já existe mas é melhor*/
                      custos[i] = custos[atual] + distancia(L,atual,i);
                      pais[i] = atual;
                      infos->nosExpandidos++;
                      insereLePairHeap(heap,i);
                        // /*;//descreaseKey();*/printf("(%d,%0.2lf)", i, custos[i]);
                      }
                    // if(pais[i]==L->numeroCidades){//Nao foi aberto ainda
                    //     custos[i] = custos[atual] + distancia(L,atual,i);
                    //     pais[i] = atual;
                    //     infos->nosExpandidos++;
                    //     insereLePairHeap(heap,i,custos[atual] + distancia(L,atual,i));
                    //     //insereHeap()
                    //     printf("(%d,%0.2lf)", i, custos[i]);
                    // }
                }
        }
        // L->distancias[atual][atual] = 1;
    }
    /*limpaDiagonal(L);*/
    /*destroiFila(fila);*/
    free(pais);
    pais = NULL;
    destroiHeap(heap);

    return infos;
}



static InformacoesDaBusca* buscaGulosa(Mapa * L, unsigned inicio, unsigned fim){
    printf("Iniciando Busca Gulosa \n ");
    unsigned *pais = iniPai(L->numeroCidades,L->numeroCidades);
    InformacoesDaBusca* infos = iniBusca();
    // double* custos = malloc(sizeof(double)*L->numeroCidades);
    LePairHeap* heap = iniPairHeap(L,L->numeroCidades,NULL,fim,comparaHeapGulosa);
    /*enfileira(fila,inicio);*/
    insereLePairHeap(heap,inicio);
    unsigned atual;
    /*printf("inicio ");*/
    /*fflush(stdout);*/

    pais[inicio] = inicio;
    while(!lePairHeapVazia(heap)){
        infos->nosVisitados++;
        atual = extraiMin(heap);
        // printf("-> %u ", atual );
        if(atual == fim){
            // printf("sucesso\n");
            int k;
            for(k = atual;pais[k]!= k; k= pais[k] )
                empilha(infos->caminho,k);
            empilha(infos->caminho,k);
            break;
        }else{
            for(int i =0 ; i< L->numeroCidades; i++)
                if( distancia(L,atual,i) > 0 ){// !L->distancias[i][i]){
                    /*if( pais[i] != L->numeroCidades && custos[i] > custos[pais[i]]+distancia(L,atual,i) )//caso em que já existe mas é melhor*/
                        /*;//descreaseKey();*/
                        if( pais[i] == L->numeroCidades ){//caso em que já existe mas é melhor*/
                          // if( pais[i] == L->numeroCidades || custos[i] > custos[atual] + distancia(L,atual,i) ){//caso em que já existe mas é melhor*/
                            // custos[i] = custos[atual] + distancia(L,atual,i);
                            pais[i] = atual;
                            infos->nosExpandidos++;
                            insereLePairHeap(heap,i);
                              // /*;//descreaseKey();*/printf("(%d,%0.2lf)", i, heuristica( L, i, fim));
                              // /*;//descreaseKey();*/printf("(%d,%0.2lf)", i, custos[i]);
                            }
//                     if(pais[i]==L->numeroCidades){
//                         /*custos[i] = custos[atual] + distancia(L,atual,i);*/
//                         pais[i] = atual;
//                         infos->nosExpandidos++;
//                         insereLePairHeap(heap,i);
// //insereHeap()
//                         /*printf("%d\n", i);*/
//                     }
                }
        }
        // L->distancias[atual][atual] = 1;
    }
    /*limpaDiagonal(L);*/
    /*destroiFila(fila);*/
    free(pais);
    pais = NULL;
    destroiHeap(heap);
    return infos;
}



InformacoesDaBusca* buscaAestrela(Mapa * L, unsigned inicio, unsigned fim){
  printf("Iniciando Busca A* \n ");
  unsigned *pais = iniPai(L->numeroCidades,L->numeroCidades);
  InformacoesDaBusca* infos = iniBusca();
  double* custos = iniCustos(L->numeroCidades,0);//malloc(sizeof(double)*L->numeroCidades);
  LePairHeap* heap = iniPairHeap(L,L->numeroCidades,custos,fim,comparaHeapAestrela);
  /*enfileira(fila,inicio);*/
  insereLePairHeap(heap,inicio);
  unsigned atual;
  // printf("inicio ");
  fflush(stdout);
  pais[inicio] = inicio;
  while(!lePairHeapVazia(heap)){
      infos->nosVisitados++;
      atual = extraiMin(heap);
      //  printf("-> _%u_ ", atual );
      if(atual == fim){
          // printf("sucesso\n");
          int k;
          for(k = atual;pais[k]!= k; k= pais[k] )
              empilha(infos->caminho,k);
          empilha(infos->caminho,k);
          break;
      }else{
          for(int i =0 ; i< L->numeroCidades; i++)
              if( distancia(L,atual,i) > 0 ){// !L->distancias[i][i]){
                if( pais[i] == L->numeroCidades || custos[i] > custos[atual] + distancia(L,atual,i) ){//caso em que já existe mas é melhor*/
                  // if( pais[i] == L->numeroCidades || custos[i] > custos[atual] + distancia(L,atual,i) ){//caso em que já existe mas é melhor*/
                    custos[i] = custos[atual] + distancia(L,atual,i);
                    pais[i] = atual;
                    infos->nosExpandidos++;
                    insereLePairHeap(heap,i);

                    }
                  // if(pais[i]==L->numeroCidades){//Nao foi aberto ainda
                  //     custos[i] = custos[atual] + distancia(L,atual,i);
                  //     pais[i] = atual;
                  //     infos->nosExpandidos++;
                  //     insereLePairHeap(heap,i,custos[atual] + distancia(L,atual,i));
                  //     //insereHeap()
                  //     printf("(%d,%0.2lf)", i, custos[i]);
                  // }
              }
      }
      // L->distancias[atual][atual] = 1;
  }
  /*limpaDiagonal(L);*/
  /*destroiFila(fila);*/
  free(pais);
  pais = NULL;
  destroiHeap(heap);
  return infos;
}

static double idaEstrelaAux(Mapa *L,unsigned cidadeAtual,double custoCaminho,
  double limiteCusto,unsigned fim,unsigned *pais, InformacoesDaBusca* infos){
    double f = custoCaminho + heuristica(L,cidadeAtual,fim);
    // printf("-> %u ", cidadeAtual);
    infos->nosVisitados++;
    if(f > limiteCusto){
        pais[cidadeAtual] = L->numeroCidades;
        return f;
      }
    if(cidadeAtual == fim){
        empilha(infos->caminho,cidadeAtual);
        return -1;
    }
    double custoMin = DBL_MAX;
    for(unsigned i= 0 ; i < L->numeroCidades ; i++){
        if(distancia(L,cidadeAtual,i) > 0 && pais[i] == L->numeroCidades){//!L->distancias[i][i])
          // printf("(%u)", i);
            infos->nosExpandidos++;
            pais[i] = cidadeAtual;
            double custoAux = idaEstrelaAux(L,i,custoCaminho + distancia(L,cidadeAtual,i),limiteCusto,fim,pais,infos);
            if(custoAux == -1){
                empilha(infos->caminho, cidadeAtual);
                return -1;
              }
            if( custoAux < custoMin )
                custoMin = custoAux;
        }
    }
    pais[cidadeAtual] = L->numeroCidades;
    return custoMin;
}

static InformacoesDaBusca* buscaIdaEstrela(Mapa *L, unsigned inicio, unsigned fim){
    printf("Iniciando Busca IDA* \n ");
    unsigned *pais =iniPai(L->numeroCidades,L->numeroCidades);
    double limiteCusto = heuristica(L,inicio,fim);
    InformacoesDaBusca* infos = iniBusca();
    pais[inicio] = inicio;
    while(1){
        double custoEncontrado = idaEstrelaAux(L,inicio, 0, limiteCusto, fim, pais, infos);
        if(custoEncontrado == -1){
            // printf("Sucesso\n");
            return infos;
        }
        if(custoEncontrado == DBL_MAX){
            // printf("fracasso\n");
            return infos;
        }
        /*if(custoEncontrado == -1)*/

        // if(noEncontrado == ∞)
            //  return;
        limiteCusto = custoEncontrado;
        // printf("\niterei limite:  %lf\n",limiteCusto);
    }
    return infos;
}
