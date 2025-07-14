// Arquivo: Estruturas.cpp - Implementação com uso consistente de busca binária na ListaOrdenada

#include "../header/Estruturas.h"

// ----- Elemento -----
Elemento::Elemento(int _id) : id(_id) {}
Elemento::~Elemento() {}
int Elemento::getID() const { return id; }

// ----- Aluno -----
Aluno::Aluno(int _id, const std::string& _nome, double _media)
    : Elemento(_id), nome(_nome), media(_media) {}
void Aluno::ImprimirInfo() const {
    std::cout << "Aluno ID: " << id << ", Nome: " << nome << ", Média: " << media << std::endl;
}

// ----- Livro -----
Livro::Livro(int _id, const std::string& _titulo, const std::string& _autor)
    : Elemento(_id), titulo(_titulo), autor(_autor) {}
void Livro::ImprimirInfo() const {
    std::cout << "Livro ID: " << id << ", Título: " << titulo << ", Autor: " << autor << std::endl;
}

// ----- ListaNaoOrdenada -----
ListaNaoOrdenada::ListaNaoOrdenada(int cap) : capacidade(cap), tamanho(0) {
    elementos = new Elemento*[capacidade];
}
ListaNaoOrdenada::~ListaNaoOrdenada() {
    for (int i = 0; i < tamanho; i++) delete elementos[i];
    delete[] elementos;
}
int ListaNaoOrdenada::getCapacidade() const { return capacidade; }
void ListaNaoOrdenada::aumentarCapacidade() {
    int novaCapacidade = capacidade * 2;
    Elemento** novoArray = new Elemento*[novaCapacidade];
    for (int i = 0; i < tamanho; i++) novoArray[i] = elementos[i];
    delete[] elementos;
    elementos = novoArray;
    capacidade = novaCapacidade;
}
void ListaNaoOrdenada::InserirNoInicio(Elemento* e) {
    if (tamanho == capacidade) aumentarCapacidade();
    for (int i = tamanho; i > 0; i--) elementos[i] = elementos[i - 1];
    elementos[0] = e;
    tamanho++;
}
void ListaNaoOrdenada::InserirNoFinal(Elemento* e) {
    if (tamanho == capacidade) aumentarCapacidade();
    elementos[tamanho++] = e;
}
void ListaNaoOrdenada::RemoverInicio() {
    if (tamanho == 0) return;
    delete elementos[0];
    for (int i = 0; i < tamanho - 1; i++) elementos[i] = elementos[i + 1];
    tamanho--;
}
void ListaNaoOrdenada::RemoverFinal() {
    if (tamanho == 0) return;
    delete elementos[--tamanho];
}
int ListaNaoOrdenada::BuscarIndicePeloId(int id) const {
    for (int i = 0; i < tamanho; i++) {
        if (elementos[i]->getID() == id) return i;
    }
    return -1;
}
void ListaNaoOrdenada::RemoverPeloId(int id) {
    int pos = BuscarIndicePeloId(id);
    if (pos != -1) {
        delete elementos[pos];
        for (int j = pos; j < tamanho - 1; j++) elementos[j] = elementos[j + 1];
        tamanho--;
    }
}
void ListaNaoOrdenada::AlterarPeloId(int id, Elemento* novo) {
    int pos = BuscarIndicePeloId(id);
    if (pos != -1) {
        delete elementos[pos];
        elementos[pos] = novo;
    }
}
void ListaNaoOrdenada::ImprimirTodos() const {
    for (int i = 0; i < tamanho; i++) elementos[i]->ImprimirInfo();
}
Elemento* ListaNaoOrdenada::getElementoNaPosicao(int pos) {
    return (pos >= 0 && pos < tamanho) ? elementos[pos] : nullptr;
}
const Elemento* ListaNaoOrdenada::getElementoNaPosicao(int pos) const {
    return (pos >= 0 && pos < tamanho) ? elementos[pos] : nullptr;
}
int ListaNaoOrdenada::getTamanho() const { return tamanho; }

// ----- ListaOrdenada com Busca Binária -----
ListaOrdenada::ListaOrdenada(int cap) : ListaNaoOrdenada(cap) {}

int ListaOrdenada::BuscarPosicao(int id) {
    int esq = 0, dir = getTamanho() - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        int meioId = elementos[meio]->getID();
        if (meioId == id) return meio;
        if (meioId < id) esq = meio + 1;
        else dir = meio - 1;
    }
    return esq;
}

void ListaOrdenada::InserirOrdenado(Elemento* e) {
    if (getTamanho() == getCapacidade()) aumentarCapacidade();
    int pos = BuscarPosicao(e->getID());
    for (int i = getTamanho(); i > pos; i--) elementos[i] = elementos[i - 1];
    elementos[pos] = e;
    tamanho++;
}

void ListaOrdenada::RemoverPeloId(int id) {
    int pos = BuscarPosicao(id);
    if (pos < tamanho && elementos[pos]->getID() == id) {
        delete elementos[pos];
        for (int i = pos; i < tamanho - 1; i++) elementos[i] = elementos[i + 1];
        tamanho--;
    }
}

void ListaOrdenada::AlterarPeloId(int id, Elemento* novo) {
    RemoverPeloId(id);
    InserirOrdenado(novo);
}

Elemento* ListaOrdenada::BuscarPeloId(int id) {
    int pos = BuscarPosicao(id);
    if (pos < tamanho && elementos[pos]->getID() == id) return elementos[pos];
    return nullptr;
}

// ----- Pilha -----
pilha::pilha(int capacidade) : lista(capacidade) {}
bool pilha::pilhaVazia() const { return lista.getTamanho() == 0; }
bool pilha::pilhaCheia() const { return lista.getTamanho() == lista.getCapacidade(); }
void pilha::empilhar(Elemento* e) { lista.InserirNoInicio(e); }
void pilha::desempilhar() {
    if (!pilhaVazia()) lista.RemoverFinal();
}
Elemento* pilha::ConsultarTopo() const {
    return pilhaVazia() ? nullptr : const_cast<Elemento*>(lista.getElementoNaPosicao(0));
}
void pilha::ImprimirTodos() const { lista.ImprimirTodos(); }

// ----- Fila -----
fila::fila(int capacidade) : lista(capacidade) {}
bool fila::filaVazia() const { return lista.getTamanho() == 0; }
bool fila::filaCheia() const { return lista.getTamanho() == lista.getCapacidade(); }
void fila::enfileirar(Elemento* e) { lista.InserirNoFinal(e); }
void fila::desenfileirar() {
    if (!filaVazia()) lista.RemoverInicio();
}
Elemento* fila::consultarInicio() const {
    return filaVazia() ? nullptr : const_cast<Elemento*>(lista.getElementoNaPosicao(0));
}
void fila::imprimirTodos() const { lista.ImprimirTodos(); }

// ----- FilaCircular -----
FilaCircular::FilaCircular(int cap)
    : capacidade(cap), tamanho(0), inicio(0), fim(0) {
    elementos = new Elemento*[capacidade];
}
FilaCircular::~FilaCircular() {
    for (int i = 0; i < tamanho; i++) delete elementos[(inicio + i) % capacidade];
    delete[] elementos;
}
void FilaCircular::AumentarCapacidade() {
    int novaCapacidade = capacidade * 2;
    Elemento** novoArray = new Elemento*[novaCapacidade];
    for (int i = 0; i < tamanho; i++) {
        novoArray[i] = elementos[(inicio + i) % capacidade];
    }
    delete[] elementos;
    elementos = novoArray;
    capacidade = novaCapacidade;
    inicio = 0;
    fim = tamanho;
}
bool FilaCircular::FilaVazia() const { return tamanho == 0; }
bool FilaCircular::FilaCheia() const { return tamanho == capacidade; }
void FilaCircular::Enfileirar(Elemento* e) {
    if (tamanho == capacidade) AumentarCapacidade();
    elementos[fim] = e;
    fim = (fim + 1) % capacidade;
    tamanho++;
}
void FilaCircular::Desenfileirar() {
    if (FilaVazia()) return;
    delete elementos[inicio];
    inicio = (inicio + 1) % capacidade;
    tamanho--;
}
Elemento* FilaCircular::ConsultarInicio() const {
    return FilaVazia() ? nullptr : elementos[inicio];
}
void FilaCircular::ImprimirTodos() const {
    if (FilaVazia()) {
        std::cout << "Fila circular vazia.\n";
        return;
    }
    std::cout << "Fila circular:\n";
    for (int i = 0; i < tamanho; i++) {
        elementos[(inicio + i) % capacidade]->ImprimirInfo();
    }
}
