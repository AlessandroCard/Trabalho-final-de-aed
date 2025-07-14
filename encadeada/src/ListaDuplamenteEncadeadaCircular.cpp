#include <iostream>
#include "../include/ListaDuplamenteEncadeadaCircular.h"

using namespace std;

ListaDuplamenteEncadeadaCircular::No::No(int ID, int VALOR) {//construtor do no

    id = ID;
    valor = VALOR;
    prox = nullptr;
    ant = nullptr;

}


ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular(){//construtor da lista duplamente encadeada circular
    cabeca = new No(-1, -1);
    cabeca->prox = cabeca;


    calda1 = new No(-1, -1);
    calda1->prox = cabeca;
    calda1->ant = cabeca;

    calda2 = new No(-1, -1);
    calda2->prox = cabeca;

}

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(int ID, int VALOR) {

    No* novo = new No(ID, VALOR);
    novo->prox = cabeca->prox;
    novo->ant = cabeca;
    cabeca->prox->ant = novo;
    cabeca->prox = novo;
}

void ListaDuplamenteEncadeadaCircular::inserirNoFim(int ID, int VALOR) {

    No* novo = new No(ID, VALOR);
    novo->prox = cabeca;
    novo->ant = cabeca->ant;
    cabeca->ant->prox= novo;
    cabeca->ant = novo;
}
void ListaDuplamenteEncadeadaCircular::inserirNaFila1(int ID, int VALOR) {
    //a calda1 eh usada para saber o fim da fila 1 do deque
    No* novo = new No(ID, VALOR);
    novo->prox = calda1->prox->prox;
    novo->ant = calda1->prox;
    novo->prox->ant = novo;
    novo->ant->prox = novo;
    calda1->prox = novo;
}
void ListaDuplamenteEncadeadaCircular::inserirNaFila2(int ID, int VALOR) {
    //a calda2 eh usada para saber o fim da fila 2 do deque
    No* novo = new No(ID, VALOR);
    novo->prox = calda2->prox;
    novo->ant = calda2->prox->ant;
    novo->prox->ant = novo;
    novo->ant->prox = novo;
    calda2->prox = novo;
}

int ListaDuplamenteEncadeadaCircular::removerNoInicio() {// retorna 1 se a lista estiver vazia e 0 se a remocao for bem sucedida
    if(cabeca->prox == cabeca && cabeca->ant == cabeca){
        return(1);
    }
    No* aux = cabeca->prox;
    if(calda1->prox == aux){ //se for remover o ultimo item de uma lista de um deque, calda1 volta a apontar pra cabeca
        calda1->prox = cabeca;
    }
    if(calda2->prox == aux){ //impede que remova da fila errada em um deque
        return(1);
    }
    aux->prox->ant = cabeca;
    cabeca->prox = aux->prox;
    delete aux;
    return 0;
}

int ListaDuplamenteEncadeadaCircular::removerNoFim() {// retorna 1 se a lista estiver vazia e 0 se a remocao for bem sucedida

    if(cabeca->prox == cabeca && cabeca->ant == cabeca){
        return(1);
    }

    No* aux = cabeca->ant;

    if(calda1->prox == aux){//impede que remova da fila errada em um deque
        return(1);
    }
    if(calda2->prox == aux){//se for remover o ultimo item de uma lista de um deque, calda1 volta a apontar pra cabeca
        calda2->prox = cabeca;
    }

    aux->ant->prox = cabeca;
    cabeca->ant = aux->ant;
    delete aux;
    return (0);
}

ResultadoBusca ListaDuplamenteEncadeadaCircular::buscarPeloId(int ID) { //o sucesso eh 0 se o elemento foi encontrado, e 1 se nao foi. Isto serve, na main, para saber se deve ou nao imprimir o valor para o usuario
    ResultadoBusca res;
    res.sucesso = 0;

    No* aux = cabeca->prox;
    while (aux != cabeca && aux->id != ID){
        aux = aux->prox;
    }

    if(aux->id!=ID){
        res.sucesso = 1;
    }
    res.valor = aux->valor;
    return res;
}

int ListaDuplamenteEncadeadaCircular::removerPeloId(int ID) {//retorna 0 se o id pertencer a lista (remocao bem sucedida) e 0 se nao pertencer

    No* aux = cabeca->prox;

    while (aux != cabeca && aux->id != ID){
        aux = aux->prox;
    }

    if (aux != cabeca && aux->id == ID)
    {

        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        delete aux;
        return 0;
    }
    return 1;

}

int ListaDuplamenteEncadeadaCircular::listaVazia() {//retorna 1 se a lista estiver vazia e 0 se nao estiver
    if (cabeca->prox == cabeca && cabeca->ant == cabeca){
        return(1);
    }
    return(0);
}


void ListaDuplamenteEncadeadaCircular::imprimir() {

    No* aux = cabeca->prox;
    while (aux != cabeca)
    {
        cout << "(" << aux->id << ": " << aux->valor << ") <-> ";
        aux = aux->prox;
    }

}
