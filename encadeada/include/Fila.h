#ifndef FILA_H
#define FILA_H
#include "ListaDuplamenteEncadeadaCircular.h"

class Fila
{
    private:
        ListaDuplamenteEncadeadaCircular fila;
    protected:
    public:
        Fila();
        void enfileirar(int id, int valor);//O(1)
        int desenfileirar();//O(1)
        int filaVazia();//O(1)
        void imprimir();//O(n)
};

#endif // PILHA_H
