# Trabalho de Estrutura de dados 
## Grupo formado por: Alessandro Cardinot, Gabriel Gonçalves, Lucas Thurler, Guilherme Munhooz, Paulo Emanuel, Eduardo Woyames

* ### Alocação Sequencial
Lucas e Eduardo
### Lista Sequencial Não Ordenada
Foi feita uma função aumentarCapacidade() para copiar os valores da lista para um array maior, dobrando seu tamanho, com complexidade O(n).

|     Operação      | Complexidade |                Explicação                |
| :---------------: | :----------: | :--------------------------------------: |
| Inserir no início |     O(n)     | Inicialmente O(1) + Aumentar capacidade  |
| Inserir no final  |     O(n)     | Inicialmente O(1) + Aumentar capacidade  |
| Remover primeiro  |     O(n)     | Remove e desloca dando um passo à frente |
|  Remover último   |     O(1)     |           Remove, sem reajuste           |
|  Remover pelo ID  |     O(n)     |             Busca + Remoção              |
|  Buscar pelo ID   |     O(n)     |             Busca exaustiva              |
|  Alterar pelo ID  |     O(n)     | Busca + Operações de troca de informação |

### Lista Sequencial Ordenada

|    Operação     | Complexidade |                Explicação                |
| :-------------: | :----------: | :--------------------------------------: |
| Buscar pelo ID  |   O(log n)   |              Busca binária               |
| Inserir pelo ID |     O(n)     |           Busca + Abrir espaço           |
| Remover pelo ID |     O(n)     |          Busca + Fechar espaço           |
| Alterar pelo ID |     O(n)     | Busca + Operações de troca de informação |

### Pilha

|    Operação    | Complexidade |            Explicação             |
| :------------: | :----------: | :-------------------------------: |
|    Empilhar    |     O(1)     |          Insere no topo           |
|  Desempilhar   |     O(1)     |          Remove no topo           |
| Consultar topo |     O(1)     |          Verifica o topo          |
|  Pilha cheia   |     O(1)     | Verifica se topo atingiu o limite |
|  Pilha vazia   |     O(1)     |  Verifica se topo está no início  |

### Fila

|     Operação     | Complexidade |                Explicação                |
| :--------------: | :----------: | :--------------------------------------: |
|    Enfileirar    |     O(n)     |    Insere no início + Passo à frente     |
|  Desenfileirar   |     O(1)     |            Remove o primeiro             |
| Consultar início |     O(1)     |           Verifica o primeiro            |
|    Fila cheia    |     O(1)     | Verifica se elementos estouram o tamanho |
|    Fila vazia    |     O(1)     |        Verifica se tem elementos         |

### Fila Circular

|     Operação     | Complexidade |                Explicação                |
| :--------------: | :----------: | :--------------------------------------: |
|    Enfileirar    |     O(1)     |    Insere + Atualiza índice circular     |
|  Desenfileirar   |     O(1)     |    Remove + Atualiza índice circular     |
| Consultar início |     O(1)     |           Verifica o primeiro            |
|    Fila cheia    |     O(1)     | Verifica se elementos estouram o tamanho |
|    Fila vazia    |     O(1)     |        Verifica se tem elementos         |

* ### Alocação Dinâmica
Gabriel e Paulo
### Lista Simplesmente Encadeada

|     Operação      | Complexidade |                    Explicação                    |
| :---------------: | :----------: | :----------------------------------------------: |
| Inserir no início |     O(1)     | Insere na frente do cabeça + Ajustes de ponteiro |
| Inserir no final  |     O(n)     |            Percorre a lista e insere             |
| Remover primeiro  |     O(1)     |  Remove próximo do cabeça + Ajustes de ponteiro  |
|  Remover pelo ID  |     O(n)     |                 Busca + Remoção                  |
|  Buscar pelo ID   |     O(n)     |                 Busca exaustiva                  |

### Lista Duplamente Encadeada

|     Operação      | Complexidade |                    Explicação                    |
| :---------------: | :----------: | :----------------------------------------------: |
| Inserir no início |     O(1)     | Insere na frente do cabeça + Ajustes de ponteiro |
| Inserir no final  |     O(n)     |            Percorre a lista e insere             |
|  Remover pelo ID  |     O(n)     |                 Busca + Remoção                  |
|  Buscar pelo ID   |     O(n)     |                 Busca exaustiva                  |

### Lista Duplamente Encadeada Circular

|     Operação      | Complexidade |                    Explicação                    |
| :---------------: | :----------: | :----------------------------------------------: |
| Inserir no início |     O(1)     | Insere na frente do cabeça + Ajustes de ponteiro |
| Inserir no final  |     O(1)     |   Insere atrás do cabeça + Ajustes de ponteiro   |
| Remover primeiro  |     O(1)     |  Remove próximo do cabeça + Ajustes de ponteiro  |
|  Remover último   |     O(1)     | Remove anterior do cabeça + Ajustes de ponteiro  |
|  Remover pelo ID  |     O(n)     |                 Busca + Remoção                  |
|  Buscar pelo ID   |     O(n)     |                 Busca exaustiva                  |

### Pilha

|  Operação   | Complexidade |           Explicação            |
| :---------: | :----------: | :-----------------------------: |
|  Empilhar   |     O(1)     |         Insere no topo          |
| Desempilhar |     O(1)     |         Remove no topo          |
| Pilha vazia |     O(1)     | Verifica se topo está no início |

### Fila

|   Operação    | Complexidade |        Explicação         |
| :-----------: | :----------: | :-----------------------: |
|  Enfileirar   |     O(1)     |     Insere no início      |
| Desenfileirar |     O(1)     |       Remove no fim       |
|  Fila vazia   |     O(1)     | Verifica se tem elementos |

### Deque

|        Operação         | Complexidade |                Explicação                |
| :---------------------: | :----------: | :--------------------------------------: |
|  Enfileirar na fila 1   |     O(1)     | Insere no final, usando uma cauda para 1 |
|  Enfileirar na fila 2   |     O(1)     | Insere no final, usando uma cauda para 2 |
| Desenfileirar na fila 1 |     O(1)     |       Remove no fim, usando cauda        |
| Desenfileirar na fila 2 |     O(1)     |       Remove no fim, usando cauda        |

### Árvore Binária de Busca
Alessandro e Guilherme
|    Operação     |     Complexidade      |           Explicação            |
| :-------------: | :-------------------: | :-----------------------------: |
| Buscar pelo ID  | O(h), *log n < h < n* |          Busca binária          |
| Inserir pelo ID |         O(h)          |        Busca + Inserção         |
| Remover pelo ID |         O(h)          |         Busca + Remoção         |
|    Percursos    |         O(n)          | Percorre todos os nós da árvore |
