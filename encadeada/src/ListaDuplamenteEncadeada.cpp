#include <iostream>
#include "../include/ListaDuplamenteEncadeada.h"
using namespace std;



ListaDuplamenteEncadeada::No::No(int ID, int VALOR) {//construtor do no

    id = ID;
    valor = VALOR;
    prox = nullptr;
    ant = nullptr;

}


ListaDuplamenteEncadeada::ListaDuplamenteEncadeada(){//construtor da lista duplamente encadeada
    cabeca = new No(-1, -1);
    cabeca->prox = nullptr;
    cabeca->ant = nullptr;
}

void ListaDuplamenteEncadeada::inserirNoInicio(int ID, int VALOR) {

    No* novo = new No(ID, VALOR);
    novo->prox = cabeca->prox;
    novo->ant = cabeca;
    if (cabeca->prox != nullptr){
        cabeca->prox->ant = novo;
    }
    cabeca->prox = novo;
}

void ListaDuplamenteEncadeada::inserirNoFim(int ID, int VALOR) {


    No* aux = cabeca;

    while (aux->prox != nullptr){
        aux = aux->prox;
    }

    No* novo = new No(ID, VALOR);
    novo->prox = nullptr;
    novo->ant = aux;
    aux->prox = novo;
}

ResultadoBusca ListaDuplamenteEncadeada::buscarPeloId(int ID) { //o sucesso eh 0 se o elemento foi encontrado, e 1 se nao foi. Isto serve, na main, para saber se deve ou nao imprimir o valor para o usuario
    ResultadoBusca res;
    res.sucesso = 0;
    No* aux = cabeca->prox;
    while (aux != nullptr && aux->id != ID){
        aux = aux->prox;
    }
    if(aux == nullptr){
        res.sucesso = 1;
        res.valor = 0;
    }
    else{
        res.valor = aux->valor;
    }
    return res;
}

int ListaDuplamenteEncadeada::removerPeloId(int ID) {//retorna 0 se o id pertencer a lista (remocao bem sucedida) e 0 se nao pertencer

    if (cabeca->prox == nullptr){
        return 1;
    }

    No* aux = cabeca->prox;

    while (aux != nullptr && aux->id != ID){
        aux = aux->prox;
    }

    if (aux != nullptr && aux->id == ID)
    {
        if (aux->prox != nullptr){
            aux->prox->ant = aux->ant;
        }
        aux->ant->prox = aux->prox;
        delete aux;
        return 0;
    }
    return 1;

}

void ListaDuplamenteEncadeada::imprimir() {

    No* aux = cabeca->prox;
    while (aux != nullptr)
    {
        cout << "(" << aux->id << ": " << aux->valor << ") <-> ";
        aux = aux->prox;
    }

}
