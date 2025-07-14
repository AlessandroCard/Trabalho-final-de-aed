#ifndef LISTA_SIMPLESMENTE_ENCADEADA_H
#define LISTA_SIMPLESMENTE_ENCADEADA_H
#include "ResultadoBusca.h"
using namespace std;


class ListaSimplesmenteEncadeada {

    public:
        ListaSimplesmenteEncadeada();

        void inserirNoInicio(int id, int valor);//O(1)
        void inserirNoFim(int id, int valor);//O(n)
        int removerNoInicio(); // O(1)usado pela pilha
        int removerPeloId(int id);//O(n)
        ResultadoBusca buscarPeloId(int id);//O(n)
        int listaVazia(); //O(1) usado pela pilha
        void imprimir();//O(n)

    protected:

    private:
        class No { //No como uma classe em private
            public:
                int id;
                int valor;
                No* prox;

                No(int id, int valor);
            };

        No* cabeca; // cabeca da lista simplesmente encadeada


};

#endif
