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

    int nodos() {
        return N.size();
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

    vector<pair<int, int>> vecindad(int v) {
        return N[v];
    }
};

int dijkstra_modificado(grafoPonderado grafo, int v) {
    int n = grafo.nodos();
    priority_queue<pair<long long, int>> candidatos;
    vector<int> S(n, 0);
    vector<long long> minDist(n, INF);
    
    candidatos.push({0, v});
    minDist[v] = 0;

    while (!candidatos.empty()) {
        pair<long long, int> candidato = candidatos.top();
        long long distancia = -candidato.first;
        int w = candidato.second;
        candidatos.pop();
        
        for (pair<int, int> arista: grafo.vecindad(w)) { 
            int u = arista.first;
            int c = arista.second;
            if (minDist[u] > distancia + c) {
                minDist[u] = minDist[w] + c;
            }
        }
    }
    return 0;
}