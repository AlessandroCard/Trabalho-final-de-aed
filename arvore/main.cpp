#include "head/arvore.h"
#include <iostream>

using namespace std;

int main()
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
        cout << "[7] Sair" << endl;

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
    }while(r != 7);

    return 0;
}
