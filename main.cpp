#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

class Graph {
    int V;
    list<int> *adjList;
    vector<vector<int>> adjMatrix;
public:
    Graph(int V);
    void addEdgeList(int v, int w);
    void addEdgeMatrix(int v, int w);
    void printAdjList();
    void printAdjMatrix();
    bool BFS(int s, int t);
    void DFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adjList = new list<int>[V];
    adjMatrix.resize(V, vector<int>(V, 0));
}

void Graph::addEdgeList(int v, int w) {
    adjList[v].push_back(w);
}

void Graph::addEdgeMatrix(int v, int w) {
    adjMatrix[v][w] = 1;
    adjMatrix[w][v] = 1;
}

void Graph::printAdjList() {
    for (int v = 0; v < V; ++v) {
        cout << "\n Lista de adjacência do vértice " << v << "\n cabeça ";
        for (auto x : adjList[v])
            cout << "-> " << x;
        printf("\n");
    }
}

void Graph::printAdjMatrix() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool Graph::BFS(int s, int t) {
    if (s == t) {
        cout << s;
        return true;
    }

    bool *visited = new bool[V];
    int *parent = new int[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    queue<int> queue;
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (!visited[*i]) {
                parent[*i] = v;
                visited[*i] = true;
                queue.push(*i);

                if (*i == t) {
                    stack<int> stack;
                    int node = t;
                    while (node != -1) {
                        stack.push(node);
                        node = parent[node];
                    }

                    while (!stack.empty()) {
                        cout << stack.top() << " ";
                        stack.pop();
                    }

                    return true;
                }
            }
        }
    }

    cout << "Não há caminho entre os vértices";
    return false;
}

void Graph::DFS(int s) {
    vector<bool> visited(V, false);
    stack<int> stack;
    stack.push(s);

    while (!stack.empty()) {
        s = stack.top();
        stack.pop();

        if (!visited[s]) {
            cout << s << " ";
            visited[s] = true;
        }

        for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Por favor, forneça um comando.";
        return 1;
    }

    string command = argv[1];
    ifstream file("grafo.txt");
    string line;
    int V = 5; // Number of vertices
    Graph g(V);

    while (getline(file, line)) {
        istringstream iss(line);
        int v, w;
        if (!(iss >> v >> w)) { break; } // error
        g.addEdgeList(v, w);
        g.addEdgeMatrix(v, w);
    }

    if (command == "printAdjList") {
        g.printAdjList();
    } else if (command == "printAdjMatrix") {
        g.printAdjMatrix();
    } else if (command == "BFS") {
        if (argc < 4) {
            cout << "Por favor, forneça dois vértices.";
            return 1;
        }
        int s = atoi(argv[2]);
        int t = atoi(argv[3]);
        g.BFS(s, t);
    } else if (command == "DFS") {
        if (argc < 3) {
            cout << "Por favor, forneça um vértice.";
            return 1;
        }
        int s = atoi(argv[2]);
        g.DFS(s);
    } else {
        cout << "Comando desconhecido.";
        return 1;
    }

    return 0;
}