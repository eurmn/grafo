# Graph Operations

Este programa fornece uma implementação de um grafo e permite a execução de várias operações, incluindo a impressão da lista de adjacências, a impressão da matriz de adjacências, a busca em largura (BFS) e a busca em profundidade (DFS).

## Compilação

Para compilar o programa, use o seguinte comando:

```bash
make
```

## Uso

Para executar o programa, use o seguinte comando:

```bash
make run ARGS="[comando]"
```

ou:
```bash
g++ main.cpp -o main.exe && ./main.exe [comando]
```

Substitua `[comando]` por um dos seguintes comandos:

- `printAdjList`: Imprime a lista de adjacências do grafo.
- `printAdjMatrix`: Imprime a matriz de adjacências do grafo.
- `BFS s t`: Executa a busca em largura (BFS) do vértice `s` ao vértice `t`.
- `DFS s`: Executa a busca em profundidade (DFS) a partir do vértice `s`.

Por exemplo, para executar a busca em largura do vértice 0 ao vértice 4, use o seguinte comando:

```bash
make run ARGS="BFS 0 4"
```

## Limpeza

Para limpar os arquivos compilados, use o seguinte comando:

```bash
make clean
```

## Notas

- O programa lê as arestas do grafo a partir de um arquivo chamado `grafo.txt` no mesmo diretório do executável. Cada linha do arquivo deve conter dois números inteiros que representam uma aresta entre dois vértices.
- O número de vértices `V` é definido no código-fonte. Certifique-se de que este número é maior ou igual ao maior vértice no arquivo `grafo.txt`.
