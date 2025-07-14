#ifndef LISTADUPLAMENTEENCADEADACIRCULAR_H
#define LISTADUPLAMENTEENCADEADACIRCULAR_H
#include "ResultadoBusca.h"
using namespace std;



class ListaDuplamenteEncadeadaCircular {
    private:
        class No {//No como uma classe em private
            public:
                int id;
                int valor;
                No* prox;
                No* ant;

                No(int id, int valor);
            };

        No* cabeca; //cabeca da lista duplamente encadeada circular
        No* calda1; //calda utilizada para insercao na primeira fila do deque
        No* calda2; //calda utilizada para insercao na segunda fila do deque

    public:
        ListaDuplamenteEncadeadaCircular();

        void inserirNoInicio(int id, int valor);//O(1)
        void inserirNoFim(int id, int valor);//O(1)
        int removerNoInicio();// O(1)usado pelo deque
        int removerNoFim();//O(1) usado pelo deque e pela fila
        void inserirNaFila1(int id, int valor);// O(1) usado no deque. Eh O(1) em razao da calda
        void inserirNaFila2(int id, int valor);// O(1) usado no deque. Eh O(1) em razao da calda
        int removerPeloId(int id);//O(n)
        ResultadoBusca buscarPeloId(int id);//O(n)
        int listaVazia();//O(1) usado pela fila
        void imprimir();//O(n)

    protected:




};

#endif
