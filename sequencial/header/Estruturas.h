#ifndef Estruturas_h
#define Estruturas_h

#include <iostream>
#include <string>

class Elemento
{
protected:
    int id;

public:
    Elemento(int _id);
    virtual ~Elemento();
    int getID() const;// O(1)
    virtual void ImprimirInfo() const = 0; // O(1), só imprime (depende do conteúdo)
};

class Aluno : public Elemento {
private:
    std::string nome;
    double media;

public:
    Aluno(int _id, const std::string& _nome, double _media);
    void ImprimirInfo() const; // O(1)
};

class Livro : public Elemento {
private:
    std::string titulo;
    std::string autor;

public:
    Livro(int _id, const std::string& _titulo, const std::string& _autor);
    void ImprimirInfo() const; // O(1)
};

class ListaNaoOrdenada 
{
protected:
    Elemento** elementos;
    int capacidade;
    int tamanho;

    // O(n) — copia todos elementos para o array maior
    void aumentarCapacidade();

public:
    ListaNaoOrdenada(int cap = 10);
    virtual ~ListaNaoOrdenada(); // O(n) — libera todos elementos
    int getCapacidade() const;   // O(1)

    // O(n) — desloca todos elementos para a direita
    void InserirNoInicio(Elemento* e);

    // O(1) — insere no final (sem contar o aumento)
    void InserirNoFinal(Elemento* e);

    // O(n) — remove o primeiro e desloca para esquerda
    void RemoverInicio();

    // O(1) — remove o último elemento
    void RemoverFinal();

    // O(n) — busca linear pelo id
    int BuscarIndicePeloId(int id) const;

    // O(n) — busca + desloca elementos para remover
    virtual void RemoverPeloId(int id);

    // O(n) — busca + substitui elemento (sem deslocamento)
    virtual void AlterarPeloId(int id, Elemento* novo);

    // O(n) — imprime todos os elementos
    void ImprimirTodos() const;

    // O(1) — acesso direto por índice
    Elemento* getElementoNaPosicao(int pos);

    // O(1) — acesso direto por índice (const version)
    const Elemento* getElementoNaPosicao(int pos) const;

    int getTamanho() const; // O(1)
};

class ListaOrdenada : public ListaNaoOrdenada
{
private:
    // O(log n) — busca binária para posição correta
    int BuscarPosicao(int id);

public:
    ListaOrdenada(int cap = 10);

    // O(n) — busca binária + desloca elementos para abrir espaço
    void InserirOrdenado(Elemento* e);

    // O(n) — busca binária + desloca elementos para remover
    void RemoverPeloId(int id);

    // O(n) — remove + insere (cada um O(n))
    void AlterarPeloId(int id, Elemento* novo);

    // O(n) — busca linear pelo id
    Elemento* BuscarPeloId(int id);
};

class pilha 
{
private:
    ListaNaoOrdenada lista;

public:
    pilha(int capacidade = 10);

    // O(1) — verifica tamanho == 0
    bool pilhaVazia() const;

    // O(1) — verifica tamanho == capacidade
    bool pilhaCheia() const;

    // O(n) — insere no início (desloca elementos)
    void empilhar(Elemento* e);

    // O(1) — remove do final (sem deslocamento)
    void desempilhar();

    // O(1) — acesso ao topo (posição 0)
    Elemento* ConsultarTopo() const;

    // O(n) — imprime todos elementos
    void ImprimirTodos() const;
};

class fila 
{
private:
    ListaNaoOrdenada lista;

public:
    fila(int capacidade = 10);

    // O(1) — verifica tamanho == 0
    bool filaVazia() const;

    // O(1) — verifica tamanho == capacidade
    bool filaCheia() const;

    // O(1) — insere no final (sem deslocamento)
    void enfileirar(Elemento* e);

    // O(n) — remove do início e desloca todos elementos
    void desenfileirar();

    // O(1) — acesso ao início
    Elemento* consultarInicio() const;

    // O(n) — imprime todos elementos
    void imprimirTodos() const;
};

class FilaCircular 
{
private:
    Elemento** elementos;
    int capacidade;
    int tamanho;
    int inicio;
    int fim;

    // O(n) — copia todos elementos para array maior
    void AumentarCapacidade();

public:
    FilaCircular(int cap = 10);
    ~FilaCircular();

    // O(1) — verifica se está vazia
    bool FilaVazia() const;

    // O(1) — verifica se está cheia
    bool FilaCheia() const;

    // O(1) — insere na posição fim, atualiza índice circular
    void Enfileirar(Elemento* e);

    // O(1) — remove na posição inicio, atualiza índice circular
    void Desenfileirar();

    // O(1) — acesso ao índice início
    Elemento* ConsultarInicio() const;

    // O(n) — imprime todos elementos circularmente
    void ImprimirTodos() const;
};

#endif
