#include<utility>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int bfs(const vector<vector<int>>& G, int n, int m) {
    int nodos = G.size();
    vector<int> pred(nodos);
    vector<int> orden(nodos);
    queue<int> lista;

    int sig = 1;
    int raiz = n;
    pred[raiz] = 0;
    orden[raiz] = sig;
    lista.push(raiz);

    while (!lista.empty()) {
        int actual = lista.front();
        for (int vecino: G[actual]) { //no sé qué tan bien está esto
            if (orden[vecino] == 0) {
                pred[vecino] = actual;
                sig = sig + 1;
                orden[vecino] = sig;
                lista.push(vecino);
            }
        }
        lista.pop();
    }
    //cómo hago para que devuelva la distancia entre n y m?
}

vector<vector<int>> misteryMachine(int n, int m) {
    vector<vector<int>> grafo(2*m + 1);
    for (int v = 1; v <= 2*m; v++) {
        grafo[v].push_back(2*v);
        grafo[v].push_back(v - 1);
    }

    return grafo;
}