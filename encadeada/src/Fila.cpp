#include <iostream>
#include "../include/Fila.h"
using namespace std;

Fila::Fila()
{

}
//Todos os metodos aproveitam a lista duplamente encadeada circular
void Fila::enfileirar(int ID, int VALOR) {
    fila.inserirNoInicio(ID, VALOR);
}
int Fila::desenfileirar() {
    return fila.removerNoFim();
}
int Fila::filaVazia() {
    return fila.listaVazia();
}
void Fila::imprimir() {
    fila.imprimir();
}

