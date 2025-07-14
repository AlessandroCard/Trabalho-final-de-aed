#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H
#include "ResultadoBusca.h"


using namespace std;



class ListaDuplamenteEncadeada {
    private:
        class No {//No como uma classe em private
            public:
                int id;
                int valor;
                No* prox;
                No* ant;

                No(int id, int valor);
            };

        No* cabeca;// cabeca da lista duplamente encadeada

    public:
        ListaDuplamenteEncadeada();

        void inserirNoInicio(int id, int valor);//O(1)
        void inserirNoFim(int id, int valor);//O(n)
        int removerPeloId(int id);//O(n)
        ResultadoBusca buscarPeloId(int id);//O(n)
        void imprimir();//O(n)

    protected:




};

#endif
