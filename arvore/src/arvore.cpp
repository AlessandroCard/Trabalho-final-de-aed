#include "../head/arvore.h"
#include <iostream>

arvore::no::no(int id_novo)  // Construtor do no
{
    id = id_novo;
    esq = nullptr;
    dir = nullptr;
}

arvore::arvore()  // Construtor default da arvore
{
    raiz = nullptr;
}

arvore::arvore(int id_novo) : arvore()  // Construtor parametrizado
{
    inserir(id_novo);
}

bool arvore::buscar_pelo_id(no *atual, int ID)  //Busca de forma recursiva
{
    if(atual == nullptr)  // Para se o no atual for nulo
        return false;
    else if(ID < atual->id)  // Vai para a esquerda caso o id seja menor q o atual
        return buscar_pelo_id(atual->esq, ID);
    else if(ID > atual->id)  // Vai para a direit caso o id seja maior q o atual
        return buscar_pelo_id(atual->dir, ID);
    else if(ID == atual->id)  // Retorna True se encontrar o id
        return true;

    return false;

    /*
    Complexidades da busca:
        Melhor caso: O(log n)
        Pior caso: O(n), na árvore desbalanceada 
    */
}

bool arvore::buscar_pelo_id(int ID)  //Função de busca de acesso publico
{
    return buscar_pelo_id(raiz, ID);

    // Apenas chama a função de busca recursiva
    // Logo a complexidade é a da busca recursiva
}

arvore::no * arvore::inserir(no * atual,int id_novo)  //Inserção de forma recursiva
{
    if(atual == nullptr)  // Verifica se o atual é nulo
        atual = new no(id_novo);
    else 
    {
        if(id_novo < atual->id)  // Verifica de o id novo deve ficar a esquerda
            atual->esq = inserir(atual->esq, id_novo);  //Caso recursivo para a subarvore da esquerda
        else if (id_novo > atual->id)  // Verifica de o id novo deve ficar a direita
            atual->dir = inserir(atual->dir, id_novo);  //Caso recursivo para a subarvore da direita
    }

    return atual;

    /*
    Complexidade da inserção:
        Complexidade da busca + complexidade de criação do nó
        Melhor caso: O(log n) + O(1) = O(log n)
        Pior caso: O(n) + O(1) = O(n)
    */
}

bool arvore::inserir(int id_novo)  //Função de inserção de acesso publico
{
    raiz = inserir(raiz, id_novo);

    return true;

    //Chama a função de inserção recursiva
    //Complexidade da inserção recursiva
}


void arvore::Imprimir_Em_Ordem(no *atual)  //Print em ordem de forma recursiva
{
    if(atual != nullptr)
    {
        Imprimir_Em_Ordem(atual->esq);
        std::cout << atual->id << " ";
        Imprimir_Em_Ordem(atual->dir);
    }

    // Percorre todos os nós para printa-los
    // Complexidade de O(n)
}

void arvore::Imprimir_Em_Ordem()  //Print em ordem de acesso publico
{
    Imprimir_Em_Ordem(raiz);

    std::cout << std::endl;

    //Chama a função recursiva
    //Complexidade da função recursiva
}

void arvore::Imprimir_Pre_Ordem(no *atual) {  //Print em pre ordem de forma recursiva
    if (atual == nullptr) return;

    std::cout << atual->id << " ";
    Imprimir_Pre_Ordem(atual->esq);
    Imprimir_Pre_Ordem(atual->dir);

    // Percorre todos os nós para printa-los
    // Complexidade de O(n)
}

void arvore::Imprimir_Pre_Ordem()  //Print em pre ordem de acesso publico
{
    Imprimir_Pre_Ordem(raiz);

    std::cout << std::endl;

    //Chama a função recursiva
    //Complexidade da função recursiva
}

void arvore::Imprimir_Pos_Ordem(no *atual) {  //Print em pos ordem de forma recursiva
    if (atual == nullptr) return;

    Imprimir_Pos_Ordem(atual->esq);
    Imprimir_Pos_Ordem(atual->dir);
    std::cout << atual->id << " ";

    // Percorre todos os nós para printa-los
    // Complexidade de O(n)
}

void arvore::Imprimir_Pos_Ordem()  //Print em pos ordem de acesso publico
{
    Imprimir_Pos_Ordem(raiz);

    std::cout << std::endl;

    //Chama a função recursiva
    //Complexidade da função recursiva
}

arvore::no* arvore::Remover_pelo_id(no* atual, int ID) {
    if (atual == nullptr) return nullptr;

    if (ID < atual->id) {
        atual->esq = Remover_pelo_id(atual->esq, ID);
    } else if (ID > atual->id) {
        atual->dir = Remover_pelo_id(atual->dir, ID);
    } else {
        
        if (atual->esq == nullptr) {
            no* temp = atual->dir;
            delete atual;
            return temp;
        } else if (atual->dir == nullptr) {
            no* temp = atual->esq;
            delete atual;
            return temp;
        }

        no* sucessor = atual->dir;
        while (sucessor->esq != nullptr)
            sucessor = sucessor->esq;

        atual->id = sucessor->id;
        atual->dir = Remover_pelo_id(atual->dir, sucessor->id);
    }

    return atual;

    /*
    Complexidade da remoção:
        No folha:
            Complexidade da busca + complexidade de remoção do nó
            Melhor caso: O(log n) + O(1) = O(log n)
            Pior caso: O(n) + O(1) = O(n)

        Nó com 1 filho:
            Complexidade da busca + remoção do nó + ligação com o filho
            Melhor caso: O(log n) + O(1) = O(log n)
            Pior caso: O(n) + O(1) = O(n)
        
        Nó com 2 filhos:
            Complexidade da busca + encontrar sucessor + remoção do sucessor
            Melhor caso: O(log n) + O(log n) + O(1) = O(log n)
            Pior caso: O(n) + O(n) + O(1) = O(n)
    */
}

bool arvore::Remover_pelo_id(int ID)
{
    raiz = Remover_pelo_id(raiz, ID);

    return true;

    //Chama a função de inserção recursiva
    //Complexidade da inserção recursiva
}
