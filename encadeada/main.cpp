#include <iostream>
#include "include/ListaSimplesmenteEncadeada.h"
#include "include/ListaDuplamenteEncadeada.h"
#include "include/ListaDuplamenteEncadeadaCircular.h"
#include "include/Pilha.h"
#include "include/Fila.h"
#include "include/Deque.h"

using namespace std;

int main() {
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

    return 0;
}
