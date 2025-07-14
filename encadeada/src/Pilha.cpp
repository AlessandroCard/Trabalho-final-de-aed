#include <iostream>
#include "../include/Pilha.h"
using namespace std;

Pilha::Pilha()
{

}
//Todos os metodos aproveitam a lista simplesmente encadeada
void Pilha::empilhar(int ID, int VALOR) {
    pilha.inserirNoInicio(ID, VALOR);
}
int Pilha::desempilhar() {
    return pilha.removerNoInicio();
}
int Pilha::pilhaVazia() {
    return pilha.listaVazia();
}
void Pilha::imprimir() {
    pilha.imprimir();
}

