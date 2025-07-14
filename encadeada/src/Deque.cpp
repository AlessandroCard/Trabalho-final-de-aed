#include <iostream>
#include "../include/Deque.h"
using namespace std;

Deque::Deque()
{

}
//Todos os metodos aproveitam a lista duplamente encadeada circular
void Deque::InserirFila1(int ID, int VALOR) {
    dequ.inserirNaFila1(ID, VALOR);
}
void Deque::InserirFila2(int ID, int VALOR) {
    dequ.inserirNaFila2(ID, VALOR);
}
int Deque::RemoverFila1() {
    return dequ.removerNoInicio();
}
int Deque::RemoverFila2() {
    return dequ.removerNoFim();
}
void Deque::imprimir() {
    dequ.imprimir();
}
