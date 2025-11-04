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

vector<long long> dijkstra_modificado(grafoPonderado& grafo, vector<vector<long long>> tiemposBloqueados, long long v) {
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

            for (long long t: tiemposBloqueados[vecino.first]) {
                if (minDist[vecino.first] == t) {
                    minDist[vecino.first] = minDist[vecino.first] + 1;
                }
            }
        }
    }
    return minDist;
}

int main() {
    long long n;
    long long m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> N(n + 1);
    for (int i = 0; i < m; i++) {
        long long a;
        long long b;
        long long c;

        cin >> a >> b >> c;

        N[a].push_back({b, c});
        N[b].push_back({a, c});
    }

    vector<vector<long long>> tiemposBloqueados(n);
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        vector<long long> tiempos(k);

        for (int j = 0; j < k; j++) {
            long long t;
            cin >> t;
            tiempos.push_back(t);
        }

        tiemposBloqueados.push_back(tiempos);
    }
    return 0;
}