#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

long long INF = 1e18;

class grafoPonderado {
private:
    vector<vector<pair<long long, long long>>> N;

public:
    void init(long long cantNodos, vector<tuple<long long, long long, long long>>& listaAristas) {
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

int consecutivos(const vector<long long>& lista, long long posInicial){
    int contador = 1;
    for (int i = posInicial; i < lista.size() - 1; i++){
        if (lista[i] + 1 != lista[i + 1]) {
            break;
        }
        contador ++;
    }
    return contador;
}

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
        if (S[w] == 1) continue; //cambiar por if S[w] == 0
        S[w] = 1;
        if (w != n) {
            long long t = minDist[w];
            if (!tiemposBloqueados[w].empty()) {
                auto lb = lower_bound(tiemposBloqueados[w].begin(), tiemposBloqueados[w].end(), t);
                if (lb != tiemposBloqueados[w].end() && *lb == t) {
                    long long posInicial = lb - tiemposBloqueados[w].begin();
                    long long tAdicional = consecutivos(tiemposBloqueados[w], posInicial);
                    t += tAdicional;
                }
            }

            for (pair<long long, long long> vecino: grafo.vecindad(w)) {   
                if (S[vecino.first] == 0 && vecino.second + t < minDist[vecino.first]) {
                    minDist[vecino.first] = vecino.second + t;
                    long long distancia = -minDist[vecino.first];
                    candidatos.push({distancia, vecino.first});
                }
            }
        }
    }
    return minDist;
}

int main() {
    long long n;
    cin >> n ;
    long long m;
    cin >> m;

    vector<tuple<long long, long long, long long>> listaAristas;
    for (long long i = 0; i < m; i++) {
        long long a;
        long long b;
        long long c;

        cin >> a >> b >> c;
        a--; b--;
        listaAristas.push_back({a, b, c});
    }

    grafoPonderado grafo;
    grafo.init(n, listaAristas);

    vector<vector<long long>> tiemposBloqueados(n);
    for (long long i = 0; i < n; i++) {
        long long k;
        cin >> k;
        vector<long long> tiempos(k);

        for (long long j = 0; j < k; j++) {
            cin >> tiempos[j];
        }
        tiemposBloqueados[i] = tiempos;
    }
    
    vector<long long> caminosMinimos = dijkstra_modificado(grafo, tiemposBloqueados, 0);
    int res;
    if (caminosMinimos[n-1] == INF){
        res= -1;
    } 
    else {
        res = caminosMinimos[n-1];
    }
    cout << res;    
    return 0;
}