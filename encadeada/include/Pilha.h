#ifndef PILHA_H
#define PILHA_H
#include "ListaSimplesmenteEncadeada.h"

class Pilha
{
    private:
        ListaSimplesmenteEncadeada pilha;
    protected:
    public:
        Pilha();
        void empilhar(int id, int valor); //O(1)
        int desempilhar(); //O(1)
        int pilhaVazia(); //O(1)
        void imprimir(); //O(n)
};

#endif // PILHA_H
