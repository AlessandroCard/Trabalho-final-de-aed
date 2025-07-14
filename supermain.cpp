#include "arvore/head/arvore.h"
#include "encadeada/include/ListaSimplesmenteEncadeada.h"
#include "encadeada/include/ListaDuplamenteEncadeada.h"
#include "encadeada/include/ListaDuplamenteEncadeadaCircular.h"
#include "encadeada/include/Pilha.h"
#include "encadeada/include/Fila.h"
#include "encadeada/include/Deque.h"
#include "sequencial/header/Estruturas.h"
#include <iostream>

using namespace std;

void menuPrincipal() {
    std::cout << "\n===== MENU PRINCIPAL =====\n";
    std::cout << "1 - Lista Nao Ordenada\n";
    std::cout << "2 - Lista Ordenada\n";
    std::cout << "3 - Pilha\n";
    std::cout << "4 - Fila\n";
    std::cout << "0 - Sair\n";
    std::cout << "Escolha: ";
}

void menuTipoElemento() {
    std::cout << "\n--- Escolha o tipo ---\n";
    std::cout << "1 - Aluno\n";
    std::cout << "2 - Livro\n";
    std::cout << "0 - Voltar\n";
    std::cout << "Escolha: ";
}

void menuListaNaoOrdenada() {
    std::cout << "\n--- Operacoes Lista Nao Ordenada ---\n";
    std::cout << "1 - Inserir no Inicio\n";
    std::cout << "2 - Inserir no Final\n";
    std::cout << "3 - Remover pelo ID\n";
    std::cout << "4 - Alterar pelo ID\n";
    std::cout << "5 - Imprimir Todos\n";
    std::cout << "0 - Voltar\n";
    std::cout << "Escolha: ";
}

void menuListaOrdenada() {
    std::cout << "\n--- Operacoes Lista Ordenada ---\n";
    std::cout << "1 - Inserir Ordenado\n";
    std::cout << "2 - Remover pelo ID\n";
    std::cout << "3 - Alterar pelo ID\n";
    std::cout << "4 - Imprimir Todos\n";
    std::cout << "0 - Voltar\n";
    std::cout << "Escolha: ";
}

void menuPilhaFila(const std::string& tipo) {
    std::cout << "\n--- Operacoes " << tipo << " ---\n";
    std::cout << "1 - Inserir\n";
    std::cout << "2 - Remover\n";
    std::cout << "3 - Consultar topo/inicio\n";
    std::cout << "4 - Imprimir Todos\n";
    std::cout << "0 - Voltar\n";
    std::cout << "Escolha: ";
}

Elemento* criarAluno() {
    int id;
    std::string nome;
    double media;
    std::cout << "ID do aluno: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Nome do aluno: ";
    std::getline(std::cin, nome);
    std::cout << "Media do aluno: ";
    std::cin >> media;
    return new Aluno(id, nome, media);
}

Elemento* criarLivro() {
    int id;
    std::string titulo, autor;
    std::cout << "ID do livro: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Titulo do livro: ";
    std::getline(std::cin, titulo);
    std::cout << "Autor do livro: ";
    std::getline(std::cin, autor);
    return new Livro(id, titulo, autor);
}

int main()
{
    int resp = 0;

    do {
        cout << endl;

        cout << "[1] Lista sequencial" << endl;
        cout << "[2] Lista Encadeada" << endl;
        cout << "[3] Arvore binaria" << endl;
        cout << "[0] Sair" << endl;

        cin >> resp;

        cout << endl;

        switch (resp) {
            case 1:
                {
                    int opcaoPrincipal;

                    ListaNaoOrdenada listaNaoOrdenada(10);
                    ListaOrdenada listaOrdenada(10);
                    pilha pilha(10);
                    fila fila(10);
                    FilaCircular filaCircular(10);

                    do {
                        menuPrincipal();
                        std::cin >> opcaoPrincipal;

                        switch (opcaoPrincipal) {
                            case 1: {
                                bool sairListaNaoOrdenada = false;
                                while (!sairListaNaoOrdenada) {
                                    menuTipoElemento();
                                    int tipoElemento;
                                    std::cin >> tipoElemento;

                                    if (tipoElemento == 0) {
                                        sairListaNaoOrdenada = true;
                                        break;
                                    }

                                    bool sairOperacoes = false;
                                    while (!sairOperacoes) {
                                        menuListaNaoOrdenada();
                                        int op;
                                        std::cin >> op;

                                        if (op == 0) {
                                            sairOperacoes = true;
                                            break;
                                        }

                                        Elemento* e = nullptr;
                                        if (op == 1 || op == 2 || op == 4) {
                                            if (tipoElemento == 1) e = criarAluno();
                                            else if (tipoElemento == 2) e = criarLivro();
                                        }

                                        switch (op) {
                                            case 1:
                                                listaNaoOrdenada.InserirNoInicio(e);
                                                std::cout << "Elemento inserido no inicio da lista nao ordenada.\n";
                                                break;
                                            case 2:
                                                listaNaoOrdenada.InserirNoFinal(e);
                                                std::cout << "Elemento inserido no final da lista nao ordenada.\n";
                                                break;
                                            case 3: {
                                                if (listaNaoOrdenada.getTamanho() == 0) {
                                                    std::cout << "Lista vazia. Nada a remover.\n";
                                                } else {
                                                    int id;
                                                    std::cout << "ID a remover: ";
                                                    std::cin >> id;
                                                    listaNaoOrdenada.RemoverPeloId(id);
                                                }
                                                break;
                                            }
                                            case 4: {
                                                int id;
                                                std::cout << "ID a alterar: ";
                                                std::cin >> id;
                                                listaNaoOrdenada.AlterarPeloId(id, e);
                                                std::cout << "Elemento alterado.\n";
                                                break;
                                            }
                                            case 5:
                                                listaNaoOrdenada.ImprimirTodos();
                                                break;
                                            default:
                                                std::cout << "Opcao invalida.\n";
                                        }
                                    }
                                }
                                break;
                            }
                            case 2: { // Lista Ordenada
                                bool sairListaOrdenada = false;
                                while (!sairListaOrdenada) {
                                    menuTipoElemento();
                                    int tipoElemento;
                                    std::cin >> tipoElemento;

                                    if (tipoElemento == 0) {
                                        sairListaOrdenada = true;
                                        break;
                                    }

                                    bool sairOperacoes = false;
                                    while (!sairOperacoes) {
                                        menuListaOrdenada();
                                        int op;
                                        std::cin >> op;

                                        if (op == 0) {
                                            sairOperacoes = true;
                                            break;
                                        }

                                        Elemento* e = nullptr;
                                        if (op == 1 || op == 3) {
                                            if (tipoElemento == 1) e = criarAluno();
                                            else if (tipoElemento == 2) e = criarLivro();
                                        }

                                        switch (op) {
                                            case 1:
                                                listaOrdenada.InserirOrdenado(e);
                                                std::cout << "Elemento inserido na lista ordenada.\n";
                                                break;
                                            case 2: {
                                                if (listaOrdenada.getTamanho() == 0) {
                                                    std::cout << "Lista vazia. Nada a remover.\n";
                                                } else {
                                                    int id;
                                                    std::cout << "ID a remover: ";
                                                    std::cin >> id;
                                                    listaOrdenada.RemoverPeloId(id);
                                                }
                                                break;
                                            }
                                            case 3: {
                                                int id;
                                                std::cout << "ID a alterar: ";
                                                std::cin >> id;
                                                listaOrdenada.AlterarPeloId(id, e);
                                                std::cout << "Elemento alterado.\n";
                                                break;
                                            }
                                            case 4:
                                                listaOrdenada.ImprimirTodos();
                                                break;
                                            default:
                                                std::cout << "Opcao invalida.\n";
                                        }
                                    }
                                }
                                break;
                            }
                            case 3: { // Pilha
                                bool sairPilha = false;
                                while (!sairPilha) {
                                    menuTipoElemento();
                                    int tipoElemento;
                                    std::cin >> tipoElemento;

                                    if (tipoElemento == 0) {
                                        sairPilha = true;
                                        break;
                                    }

                                    bool sairOperacoes = false;
                                    while (!sairOperacoes) {
                                        menuPilhaFila("Pilha");
                                        int op;
                                        std::cin >> op;

                                        if (op == 0) {
                                            sairOperacoes = true;
                                            break;
                                        }

                                        Elemento* e = nullptr;
                                        if (op == 1) { // Inserir
                                            if (tipoElemento == 1) e = criarAluno();
                                            else if (tipoElemento == 2) e = criarLivro();
                                        }

                                        switch (op) {
                                            case 1:
                                                if (pilha.pilhaCheia()) {
                                                    std::cout << "Pilha cheia!\n";
                                                } else {
                                                    pilha.empilhar(e);
                                                    std::cout << "Elemento empilhado.\n";
                                                }
                                                break;
                                            case 2:
                                                if (pilha.pilhaVazia()) {
                                                    std::cout << "Pilha vazia! Nada a remover.\n";
                                                } else {
                                                    pilha.desempilhar();
                                                    std::cout << "Elemento desempilhado.\n";
                                                }
                                                break;
                                            case 3: {
                                                Elemento* topo = pilha.ConsultarTopo();
                                                if (topo) topo->ImprimirInfo();
                                                else std::cout << "Pilha vazia.\n";
                                                break;
                                            }
                                            case 4:
                                                pilha.ImprimirTodos();
                                                break;
                                            default:
                                                std::cout << "Opcao invalida.\n";
                                        }
                                    }
                                }
                                break;
                            }
                            case 4: { // Fila ('normal' ou circular)
                                bool sairFila = false;
                                while (!sairFila) {
                                    std::cout << "\n--- Escolha o tipo de fila ---\n";
                                    std::cout << "1 - Fila normal\n";
                                    std::cout << "2 - Fila circular\n";
                                    std::cout << "0 - Voltar\n";
                                    std::cout << "Escolha: ";
                                    int tipoFila;
                                    std::cin >> tipoFila;

                                    if (tipoFila == 0) {
                                        sairFila = true;
                                        break;
                                    }

                                    bool sairOperacoes = false;
                                    while (!sairOperacoes) {
                                        menuPilhaFila(tipoFila == 1 ? "Fila normal" : "Fila circular");
                                        int op;
                                        std::cin >> op;

                                        if (op == 0) {
                                            sairOperacoes = true;
                                            break;
                                        }

                                        Elemento* e = nullptr;
                                        if (op == 1) {
                                            std::cout << "Escolha o tipo de elemento para inserir:\n";
                                            std::cout << "1 - Aluno\n2 - Livro\nEscolha: ";
                                            int tipoElemento;
                                            std::cin >> tipoElemento;
                                            if (tipoElemento == 1) e = criarAluno();
                                            else if (tipoElemento == 2) e = criarLivro();
                                            else {
                                                std::cout << "Tipo invalido.\n";
                                                continue;
                                            }
                                        }

                                        if (tipoFila == 1) {
                                            // Fila normal
                                            switch (op) {
                                                case 1:
                                                    if (fila.filaCheia()) {
                                                        std::cout << "Fila cheia!\n";
                                                    } else {
                                                        fila.enfileirar(e);
                                                        std::cout << "Elemento enfileirado na fila normal.\n";
                                                    }
                                                    break;
                                                case 2:
                                                    if (fila.filaVazia()) {
                                                        std::cout << "Fila vazia! Nada a remover.\n";
                                                    } else {
                                                        fila.desenfileirar();
                                                        std::cout << "Elemento desenfileirado da fila normal.\n";
                                                    }
                                                    break;
                                                case 3: {
                                                    Elemento* inicio = fila.consultarInicio();
                                                    if (inicio) inicio->ImprimirInfo();
                                                    else std::cout << "Fila vazia.\n";
                                                    break;
                                                }
                                                case 4:
                                                    fila.imprimirTodos();
                                                    break;
                                                default:
                                                    std::cout << "Opcao invalida.\n";
                                            }
                                        } else if (tipoFila == 2) {
                                            // Fila circular
                                            switch (op) {
                                                case 1:
                                                    if (filaCircular.FilaCheia()) {
                                                        std::cout << "Fila circular cheia!\n";
                                                    } else {
                                                        filaCircular.Enfileirar(e);
                                                        std::cout << "Elemento enfileirado na fila circular.\n";
                                                    }
                                                    break;
                                                case 2:
                                                    if (filaCircular.FilaVazia()) {
                                                        std::cout << "Fila circular vazia! Nada a remover.\n";
                                                    } else {
                                                        filaCircular.Desenfileirar();
                                                        std::cout << "Elemento desenfileirado da fila circular.\n";
                                                    }
                                                    break;
                                                case 3: {
                                                    Elemento* inicio = filaCircular.ConsultarInicio();
                                                    if (inicio) inicio->ImprimirInfo();
                                                    else std::cout << "Fila circular vazia.\n";
                                                    break;
                                                }
                                                case 4:
                                                    filaCircular.ImprimirTodos();
                                                    break;
                                                default:
                                                    std::cout << "Opcao invalida.\n";
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                            case 0:
                                std::cout << "Saindo...\n";
                                break;
                            default:
                                std::cout << "Opcao invalida.\n";
                        }

                    } while (opcaoPrincipal != 0);

                break;
                }

            case 2:
            {
                                    //inicializacao das estruturas
                    ListaSimplesmenteEncadeada LS;
                    ListaDuplamenteEncadeada LD;
                    ListaDuplamenteEncadeadaCircular LDC;
                    Pilha P;
                    Fila F;
                    Deque D;

                    int opcao = 38; //opcao fora do escopo para inicializacao do menu

                    while(opcao!=0 && opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5 && opcao!=6){
                        cout<<"Escolha dentre uma das opcoes:\n"<<endl;
                        cout<<"0 - Sair\n"<<endl;
                        cout<<"1 - Lista Simplesmente Encadeada\n"<<endl;
                        cout<<"2 - Lista Duplamente Encadeada\n"<<endl;
                        cout<<"3 - Lista Duplamente Encadeada Circular\n"<<endl;
                        cout<<"4 - Pilha\n"<<endl;
                        cout<<"5 - Fila\n"<<endl;
                        cout<<"6 - Deque\n"<<endl;
                        cin>>opcao;
                    }
                    switch (opcao){
                        case 1:{
                            int opcao2 = 38, id = 0; // opcao fora do escopo para inicializacao do menu 2, e declaracao do id como uma contadora
                            while(opcao2!=0 && opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5){
                                cout<<"Escolha dentre uma das opcoes:\n"<<endl;
                                cout<<"0 - Sair\n"<<endl;
                                cout<<"1 - Inserir no Inicio\n"<<endl;
                                cout<<"2 - Inserir no Fim\n"<<endl;
                                cout<<"3 - Remover\n"<<endl;
                                cout<<"4 - Buscar\n"<<endl;
                                cout<<"5 - Imprimir\n"<<endl;
                                cin>>opcao2;
                                if(opcao2==1){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    LS.inserirNoInicio(id, valor);
                                    cout<<"\n"<<endl;
                                    LS.imprimir();
                                    id++;
                                }
                                if(opcao2==2){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    LS.inserirNoFim(id, valor);
                                    cout<<"\n"<<endl;
                                    LS.imprimir();
                                    id++;
                                }
                                if(opcao2==3){
                                    int id_remocao, res;
                                    cout<<"\nQual id do valor que voce quer remover? "<<endl;
                                    cin>>id_remocao;
                                    res = LS.removerPeloId(id_remocao);
                                    if(res == 0){
                                        cout<<"\nRemovido com sucesso\n"<<endl;
                                    }
                                    if(res == 1){
                                        cout<<"\nO id digitado nao pertence a nenhum item da lista\n"<<endl;
                                    }
                                    LS.imprimir();
                                }
                                if(opcao2 == 4){
                                    int id_busca;
                                    ResultadoBusca res;
                                    cout<<"\nQual id do valor que voce quer buscar? "<<endl;
                                    cin>>id_busca;
                                    res = LS.buscarPeloId(id_busca);
                                    if(res.sucesso==0){
                                        cout<<"O valor que voce esta procurando eh: "<<res.valor<<endl;
                                    }
                                    else{
                                        cout<<"Nao ha nenhum elemento na lista com este id"<<endl;
                                    }
                                }
                                if(opcao2 == 5){
                                    cout<<"\n"<<endl;
                                    LS.imprimir();
                                }
                                if(opcao2!=0){ // se opcao2 for igual a zero, o programa acaba
                                    if(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5){
                                        cout<<"\nValor Invalido. Tente novamente\n"<<endl;
                                    }
                                    opcao2 = 38;
                                }

                            }
                            break;
                        }
                        case 2:{
                            int opcao2 = 38, id = 0;// opcao fora do escopo para inicializacao do menu 2, e declaracao do id como uma contadora
                            while(opcao2!=0 && opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5){
                                cout<<"Escolha dentre uma das opcoes:\n"<<endl;
                                cout<<"0 - Sair\n"<<endl;
                                cout<<"1 - Inserir no Inicio\n"<<endl;
                                cout<<"2 - Inserir no Fim\n"<<endl;
                                cout<<"3 - Remover\n"<<endl;
                                cout<<"4 - Buscar\n"<<endl;
                                cout<<"5 - Imprimir\n"<<endl;
                                cin>>opcao2;
                                if(opcao2==1){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    LD.inserirNoInicio(id, valor);
                                    cout<<"\n"<<endl;
                                    LD.imprimir();
                                    id++;
                                }
                                if(opcao2==2){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    LD.inserirNoFim(id, valor);
                                    cout<<"\n"<<endl;
                                    LD.imprimir();
                                    id++;
                                }
                                if(opcao2==3){
                                    int id_remocao, res;
                                    cout<<"\nQual id do valor que voce quer remover? "<<endl;
                                    cin>>id_remocao;
                                    res = LD.removerPeloId(id_remocao);
                                    if(res == 0){
                                        cout<<"\nRemovido com sucesso\n"<<endl;
                                    }
                                    if(res == 1){
                                        cout<<"\nO id digitado nao pertence a nenhum item da lista\n"<<endl;
                                    }
                                    LD.imprimir();
                                }
                                if(opcao2 == 4){
                                    int id_busca;
                                    ResultadoBusca res;
                                    cout<<"\nQual id do valor que voce quer buscar? "<<endl;
                                    cin>>id_busca;
                                    res = LD.buscarPeloId(id_busca);
                                    if(res.sucesso == 0){
                                        cout<<"O valor que voce esta procurando eh: "<<res.valor<<endl;
                                    }
                                    else{
                                        cout<<"Nao ha nenhum elemento na lista com este id"<<endl;
                                    }
                                }
                                if(opcao2 == 5){
                                    cout<<"\n"<<endl;
                                    LD.imprimir();
                                }
                                if(opcao2!=0){ // se opcao2 for igual a zero, o programa acaba
                                    if(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5){
                                        cout<<"\nValor Invalido. Tente novamente\n"<<endl;
                                    }
                                    opcao2 = 38;
                                }
                            }
                            break;
                        }
                        case 3:{
                            int opcao2 = 38, id = 0;// opcao fora do escopo para inicializacao do menu 2, e declaracao do id como uma contadora
                            while(opcao2!=0 && opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5){
                                cout<<"Escolha dentre uma das opcoes:\n"<<endl;
                                cout<<"0 - Sair\n"<<endl;
                                cout<<"1 - Inserir no Inicio\n"<<endl;
                                cout<<"2 - Inserir no Fim\n"<<endl;
                                cout<<"3 - Remover\n"<<endl;
                                cout<<"4 - Buscar\n"<<endl;
                                cout<<"5 - Imprimir\n"<<endl;
                                cin>>opcao2;
                                if(opcao2==1){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    LDC.inserirNoInicio(id, valor);
                                    cout<<"\n"<<endl;
                                    LDC.imprimir();
                                    id++;
                                }
                                if(opcao2==2){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    LDC.inserirNoFim(id, valor);
                                    cout<<"\n"<<endl;
                                    LDC.imprimir();
                                    id++;
                                }
                                if(opcao2==3){
                                    int id_remocao, res;
                                    cout<<"\nQual id do valor que voce quer remover? "<<endl;
                                    cin>>id_remocao;
                                    res = LDC.removerPeloId(id_remocao);
                                    if(res == 0){
                                        cout<<"\nRemovido com sucesso\n"<<endl;
                                    }
                                    if(res == 1){
                                        cout<<"\nO id digitado nao pertence a nenhum item da lista\n"<<endl;
                                    }
                                    LDC.imprimir();
                                }
                                if(opcao2 == 4){
                                    int id_busca;
                                    ResultadoBusca res;
                                    cout<<"\nQual id do valor que voce quer buscar? "<<endl;
                                    cin>>id_busca;
                                    res = LDC.buscarPeloId(id_busca);
                                    if(res.sucesso == 0){
                                        cout<<"O valor que voce esta procurando eh: "<<res.valor<<endl;
                                    }
                                    else{
                                        cout<<"Nao ha nenhum elemento na lista com este id"<<endl;
                                    }

                                }
                                if(opcao2 == 5){
                                    cout<<"\n"<<endl;
                                    LDC.imprimir();
                                }
                                if(opcao2!=0){ // se opcao2 for igual a zero, o programa acaba
                                    if(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5){
                                        cout<<"\nValor Invalido. Tente novamente\n"<<endl;
                                    }
                                    opcao2 = 38;
                                }
                            }
                            break;
                        }
                        case 4:{
                            int opcao2 = 38, id = 0;// opcao fora do escopo para inicializacao do menu 2, e declaracao do id como uma contadora
                            while(opcao2!=0 && opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4){
                                cout<<"Escolha dentre uma das opcoes:\n"<<endl;
                                cout<<"0 - Sair\n"<<endl;
                                cout<<"1 - Empilhar\n"<<endl;
                                cout<<"2 - Desempilhar\n"<<endl;
                                cout<<"3 - Verificar se a pilha esta vazia\n"<<endl;
                                cout<<"4 - Imprimir\n"<<endl;
                                cin>>opcao2;
                                if(opcao2==1){
                                    int valor;
                                    cout<<"\nQual valor voce quer empilhar? "<<endl;
                                    cin>>valor;
                                    P.empilhar(id, valor);
                                    cout<<"\n"<<endl;
                                    P.imprimir();
                                    id++;
                                }
                                if(opcao2==2){
                                    int res;
                                    res = P.desempilhar();
                                    if(res == 0){
                                        cout<<"\nRemovido com sucesso\n"<<endl;
                                    }
                                    if(res == 1){
                                        cout<<"\nO Pilha vazia\n"<<endl;
                                    }
                                    P.imprimir();
                                }
                                if(opcao2 == 3){
                                    if(P.pilhaVazia() == 0){
                                        cout<<"\nA pilha nao esta vazia\n"<<endl;
                                    }
                                    else if(P.pilhaVazia() == 1){
                                        cout<<"\nA pilha esta vazia\n"<<endl;
                                    }
                                }
                                if(opcao2 == 4){
                                    cout<<"\n"<<endl;
                                    P.imprimir();
                                }
                                if(opcao2!=0){ // se opcao2 for igual a zero, o programa acaba
                                    if(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4){
                                        cout<<"\nValor Invalido. Tente novamente\n"<<endl;
                                    }
                                    opcao2 = 38;
                                }
                            }
                            break;
                        }
                        case 5:{
                            int opcao2 = 38, id = 0;// opcao fora do escopo para inicializacao do menu 2, e declaracao do id como uma contadora
                            while(opcao2!=0 && opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4){
                                cout<<"Escolha dentre uma das opcoes:\n"<<endl;
                                cout<<"0 - Sair\n"<<endl;
                                cout<<"1 - Enfileirar\n"<<endl;
                                cout<<"2 - Desenfileirar\n"<<endl;
                                cout<<"3 - Verificar se a fila esta vazia\n"<<endl;
                                cout<<"4 - Imprimir\n"<<endl;
                                cin>>opcao2;
                                if(opcao2==1){
                                    int valor;
                                    cout<<"\nQual valor voce quer enfileirar? "<<endl;
                                    cin>>valor;
                                    F.enfileirar(id, valor);
                                    cout<<"\n"<<endl;
                                    F.imprimir();
                                    id++;
                                }
                                if(opcao2==2){
                                    int res;
                                    res = F.desenfileirar();
                                    if(res == 0){
                                        cout<<"\nRemovido com sucesso\n"<<endl;
                                    }
                                    if(res == 1){
                                        cout<<"\nO Fila vazia\n"<<endl;
                                    }
                                    F.imprimir();
                                }
                                if(opcao2 == 3){
                                    if(F.filaVazia() == 0){
                                        cout<<"\nA fila nao esta vazia\n"<<endl;
                                    }
                                    else if(P.pilhaVazia() == 1){
                                        cout<<"\nA fila esta vazia\n"<<endl;
                                    }
                                }
                                if(opcao2 == 4){
                                    cout<<"\n"<<endl;
                                    F.imprimir();
                                }
                                if(opcao2!=0){ // se opcao2 for igual a zero, o programa acaba
                                    if(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4){
                                        cout<<"\nValor Invalido. Tente novamente\n"<<endl;
                                    }
                                    opcao2 = 38;
                                }
                            }
                            break;
                        }
                        case 6:{
                            int opcao2 = 38, id = 0;// opcao fora do escopo para inicializacao do menu 2, e declaracao do id como uma contadora
                            while(opcao2!=0 && opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4){
                                cout<<"Escolha dentre uma das opcoes:\n"<<endl;
                                cout<<"0 - Sair\n"<<endl;
                                cout<<"1 - Inserir na primeira fila\n"<<endl;
                                cout<<"2 - Remover da primeira fila\n"<<endl;
                                cout<<"3 - Inserir na segunda fila\n"<<endl;
                                cout<<"4 - Remover da segunda fila\n"<<endl;
                                cin>>opcao2;
                                if(opcao2==1){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    D.InserirFila1(id, valor);
                                    cout<<"\n"<<endl;
                                    D.imprimir();
                                    id++;
                                }
                                if(opcao2==2){
                                    int res;
                                    res = D.RemoverFila1();
                                    if(res == 0){
                                        cout<<"\nRemovido com sucesso\n"<<endl;
                                    }
                                    if(res == 1){
                                        cout<<"\nO Fila vazia\n"<<endl;
                                    }
                                    D.imprimir();
                                }
                                if(opcao2 == 3){
                                    int valor;
                                    cout<<"\nQual valor voce quer inserir? "<<endl;
                                    cin>>valor;
                                    D.InserirFila2(id, valor);
                                    cout<<"\n"<<endl;
                                    D.imprimir();
                                    id++;
                                }
                                if(opcao2 == 4){
                                    int res;
                                    res = D.RemoverFila2();
                                    if(res == 0){
                                        cout<<"\nRemovido com sucesso\n"<<endl;
                                    }
                                    if(res == 1){
                                        cout<<"\nO Fila vazia\n"<<endl;
                                    }
                                    D.imprimir();
                                }
                                if(opcao2!=0){ // se opcao2 for igual a zero, o programa acaba
                                    if(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4){
                                        cout<<"\nValor Invalido. Tente novamente\n"<<endl;
                                    }
                                    opcao2 = 38;
                                }
                            }
                            break;
                        }
                    }

                break;
            }


            case 3:
            {
                arvore abb;
                int r = 0, id;

                do
                {
                    cout << "[1] Inserir um id." << endl;
                    cout << "[2] Remover um id." << endl;
                    cout << "[3] Buscar um id." << endl;
                    cout << "[4] Imprimir em ordem." << endl;
                    cout << "[5] Imprimir em pre ordem." << endl;
                    cout << "[6] Imprimir em pos ordem." << endl;
                    cout << "[0] Sair" << endl;

                    cin >> r;

                    switch (r) {
                        case 1:
                            cout << "Digite o id a inserir: ";
                            cin >> id;
                            
                            if(abb.inserir(id))
                                cout << "insercao bem sucedida" << endl << endl;
                            else
                                cout << "Erro ao inserir" << endl << endl;

                            break;
                        case 2:
                            cout << "Digite um id a remover: ";
                            cin >> id;

                            if(abb.buscar_pelo_id(id))
                            {
                                abb.Remover_pelo_id(id);
                                cout << "Remocao bem sucedida." << endl << endl;
                            }
                            else
                                cout << "Erro ao remover." << endl << endl;

                            break;

                        case 3:
                            cout << "Digite o id a buscar: ";
                            cin >> id;

                            if(abb.buscar_pelo_id(id))
                                cout << "id encontrado" << endl << endl;
                            else
                                cout << "id não encontrado" << endl << endl;

                            break;

                        case 4:
                            cout << endl;
                            abb.Imprimir_Em_Ordem();
                            cout << endl;

                            break;
                        
                        case 5:
                            cout << endl;
                            abb.Imprimir_Pre_Ordem();
                            cout << endl;

                            break;

                        case 6:
                            cout << endl;
                            abb.Imprimir_Pos_Ordem();
                            cout << endl;

                            break;
                    }
                }while(r != 0);
                break;
            }
        }
    }while(resp != 0);

    return 0;
}
