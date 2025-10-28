#include<utility>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int bfs_modificado(const vector<vector<int>>& G, int n, int m) {
    int cant_nodos = G.size();
    vector<int> distancias(cant_nodos, -1);
    queue<int> lista;

    int raiz = n;
    lista.push(raiz);
    distancias[raiz] = 0;

    while (!lista.empty()) {
        int actual = lista.front();
        for (int vecino: G[actual]) { 
            if (vecino >= 0 && vecino < cant_nodos && distancias[vecino] == -1) {
                distancias[vecino] = distancias[actual] + 1;
                lista.push(vecino);
            }
        }
        lista.pop();
    }
    return distancias[m];
}

vector<vector<int>> misteryMachine(int n, int m) {
    int cant_max = max(2*m, n);
    vector<vector<int>> grafo(cant_max + 1);
    
    for (int i = 0; i <= cant_max; i++) {
        if (i - 1 >= 0) {
            grafo[i].push_back(i - 1);
        }
        if (i*2 <= cant_max) {
            grafo[i].push_back(i*2);
        }
    }

    return grafo;
}

int main() {
    int n;
    int m;

    cin >> n;
    cin >> m;

    vector<vector<int>> grafo = misteryMachine(n, m);
    cout << bfs_modificado(grafo, n, m);
}