#ifndef ARVORE_H
#define ARVORE_H

class arvore
{
    private:
        class no  //Declaração da classe no
        {
            public:
                int id;
                no *esq, *dir;

                no(int id_novo);  //Construtor parametrizado

        };

        no *raiz;

        no *inserir(no *atual, int id_novo);  //Inserção de forma recursiva
        bool buscar_pelo_id(no *atual, int ID);  //Busca de forma recursiva
        void Imprimir_Em_Ordem(no *atual);  //Print em ordem de forma recursiva
        void Imprimir_Pre_Ordem(no *atual);  //Print em pre ordem de forma recursiva
        void Imprimir_Pos_Ordem(no *atual);  //Print em pos ordem de forma recursiva
        no *Remover_pelo_id(no *atual, int ID);

    public:
        arvore();
        arvore(int id_novo);

        bool inserir(int id_novo);  //Função de inserção de acesso publico
        bool buscar_pelo_id(int ID);  //Função de busca de acesso publico
        bool Remover_pelo_id(int ID);  //Função de remoção de acesso publico

        void Imprimir_Em_Ordem();  //Print em ordem de acesso publico
        void Imprimir_Pre_Ordem();  //Print em pre ordem de acesso publico
        void Imprimir_Pos_Ordem();  //Print em pos ordem de acesso publico

};

#endif