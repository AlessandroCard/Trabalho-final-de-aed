#include <iostream>
#include "../include/ListaSimplesmenteEncadeada.h"
using namespace std;

ListaSimplesmenteEncadeada::No::No(int ID, int VALOR) { //construtor do no

    id = ID;
    valor = VALOR;
    prox = nullptr;

}


ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada(){ //construtor da lista simplesmente encadeada
    cabeca = new No(-1, -1);
    cabeca->prox = nullptr;
}

void ListaSimplesmenteEncadeada::inserirNoInicio(int ID, int VALOR) {
    No* novo = new No(ID, VALOR);
    novo->prox = cabeca->prox;
    cabeca->prox = novo;
}

void ListaSimplesmenteEncadeada::inserirNoFim(int ID, int VALOR) {

    No* aux = cabeca;
    while (aux->prox != nullptr){
        aux = aux->prox;
    }

    No* novo = new No(ID, VALOR);
    novo->prox = nullptr;
    aux->prox = novo;
}

int ListaSimplesmenteEncadeada::removerNoInicio() { //retorna 1 se a lista estiver vazia (impossivel de remover) e 0 se nao estiver
    if(cabeca->prox == nullptr){
        return(1);
    }
    No* aux = cabeca->prox;
    cabeca->prox = aux->prox;
    delete aux;
    return 0;
}


int ListaSimplesmenteEncadeada::removerPeloId(int ID) { //retorna 0 se o id pertencer a lista (remocao bem sucedida) e 0 se nao pertencer

    No* ant = cabeca;
    No* aux = cabeca->prox;

    while (aux != nullptr && aux->id != ID)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux != nullptr)
    {
        ant->prox = aux->prox;
        delete aux;
        return 0;
    }
    return 1;

}

ResultadoBusca ListaSimplesmenteEncadeada::buscarPeloId(int ID) { //o sucesso eh 0 se o elemento foi encontrado, e 1 se nao foi. Isto serve, na main, para saber se deve ou nao imprimir o valor para o usuario
    ResultadoBusca res;
    res.sucesso=0;
    No* aux = cabeca->prox;
    while (aux->prox != nullptr && aux->id != ID){
        aux = aux->prox;
    }
    if(aux->id!=ID){
        res.sucesso = 1;
    }
    res.valor = aux->valor;
    return res;
}

int ListaSimplesmenteEncadeada::listaVazia() { //retorna 1 se a lista estiver vazia e 0 se nao estiver
    if (cabeca->prox == nullptr){
        return(1);
    }
    return(0);
}



void ListaSimplesmenteEncadeada::imprimir() {

    No* aux = cabeca->prox;
    while (aux != nullptr)
    {
        cout << "(" << aux->id << ": " << aux->valor << ") -> ";
        aux = aux->prox;
    }

}
