#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

long long INF = 1e18;

class grafoPonderado {
private:
    vector<vector<pair<int, int>>> N;

public:
    void init(int cantNodos, const vector<tuple<int, int, int>>& listaAristas) {
        N.resize(cantNodos);

        for (tuple<int, int, int> arista: listaAristas) {
            int v = get<0>(arista);
            int w = get<1>(arista);
            int peso = get<2>(arista);

            N[v].push_back({w, peso});
            N[w].push_back({v, peso});
        }
    }

    bool tieneArista(int v, int w) {
        for (pair<int, int> vecino:N[v]) {
            if (vecino.first == w) {
                return true;
            }
        }
        return false;
    }

    void agregarArista(int v, int w, int peso) {
        N[v].push_back({w, peso});
        N[w].push_back({v, peso});
    }

    long long pesoArista(int v, int w) {
        for (pair<int, int> vecino: N[v]) {
            if (vecino.first == w) {
                return vecino.second;
            }
        }

        return INF;
    }

    int nodos() {
        return N.size();
    }
};

int dijkstra_modificado(grafoPonderado grafo, int v) {
    priority_queue<int> S;
    vector<long long> minDist;
    vector<int> pred;
    int n = grafo.nodos();
    
    S.push(v);
    minDist[v] = 0;
    pred[v] = 0;

    for (int u = 0; u != v; u++) {
        if (grafo.tieneArista(v, u)) {
            minDist[u] = grafo.pesoArista(v, u);
            pred[u] = v;
        }
        else{
            minDist[u] = INF;
            pred[u] = INF;
        }
    }

    while (S.size() < n) {
    }
    return 0;
}