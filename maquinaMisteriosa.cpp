#include<utility>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

vector<vector<int>> grafo;

int bfs(const vector<vector<int>>& G, int v) {
    int n = G.size();
    vector<int> pred(n);
    vector<int> orden(n);
    queue<int> lista;

    int sig = 1;
    int raiz = v;
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
}