#ifndef DEQUE_H
#define DEQUE_H
#include "ListaDuplamenteEncadeadaCircular.h"

class Deque
{
    private:
        ListaDuplamenteEncadeadaCircular dequ; //"deque" eh palavra reservada
    protected:
    public:
        Deque();
        void InserirFila1(int id, int valor);//O(1) por causa da calda
        int RemoverFila1();//O(1)
        void InserirFila2(int id, int valor);//O(1) por causa da calda
        int RemoverFila2();//O(1)
        void imprimir();//O(n)
};

#endif // PILHA_H
