#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

long long INF = 1e18;

class grafoPonderado {
private:
    vector<vector<pair<long long, long long>>> N;

public:
    void init(long long cantNodos, const vector<tuple<long long, long long, long long>>& listaAristas) {
        N.resize(cantNodos);

        for (tuple<long long, long long, long long> arista: listaAristas) {
            long long v = get<0>(arista);
            long long w = get<1>(arista);
            long long peso = get<2>(arista);

            N[v].push_back({w, peso});
            N[w].push_back({v, peso});
        }
    }

    long long nodos() {
        return N.size();
    }

    bool tieneArista(long long v, long long w) {
        for (pair<long long, long long> vecino:N[v]) {
            if (vecino.first == w) {
                return true;
            }
        }
        return false;
    }

    void agregarArista(long long v, long long w, long long peso) {
        N[v].push_back({w, peso});
        N[w].push_back({v, peso});
    }

    long long pesoArista(long long v, long long w) {
        for (pair<long long, long long> vecino: N[v]) {
            if (vecino.first == w) {
                return vecino.second;
            }
        }

        return INF;
    }

    vector<pair<long long, long long>> vecindad(long long v) {
        return N[v];
    }
};

vector<long long> dijkstra_modificado(grafoPonderado& grafo, long long v) {
    long long n = grafo.nodos();
    priority_queue<pair<long long, long long>> candidatos;
    vector<long long> S(n, 0);
    vector<long long> minDist(n, INF);
    
    candidatos.push({0, v});
    minDist[v] = 0;

    while (!candidatos.empty()){
        pair<long long, long long> candidato = candidatos.top();
        long long distancia = -candidato.first;
        long long w = candidato.second;
        candidatos.pop();
        if (S[w] == 1) continue;
        S[w] = 1;

        for (pair<long long, long long> vecino: grafo.vecindad(w)) {            
            if (S[vecino.first] == 0 && vecino.second + minDist[w] < minDist[vecino.first]) {
                minDist[vecino.first] = vecino.second + minDist[w];
                long long distancia = -minDist[vecino.first];
                candidatos.push({distancia, vecino.first});
            }
        }
    }
    return minDist;
}

int main() {
    
    return 0;
}