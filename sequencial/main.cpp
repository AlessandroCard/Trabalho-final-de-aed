#include "header/Estruturas.h"

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

int main() {
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

    return 0;
}
