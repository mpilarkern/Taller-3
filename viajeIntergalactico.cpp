#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

//idea general del ejercicio: corro dijkstra sobre el grafo (nodos: planetas, aristas: portales con peso determinado por el tiempo de la transferencia) 
//y me guardo un arreglo de tamaño n que en la i-ésima posición diga el tiempo que tardo en llegar desde el planeta 1 al i por el camino mínimo (-1 si no se puede llegar de 1 a i).
//Si el tiempo que tardo en llegar de 1 a i coincide con algún tiempo en el que llega otro viajero al planeta i, sumo 1.

long long INF = 1e18;

int dijkstra_modificado(vector<vector<int>> G, vector<vector<int>> costos){ //quiero calcular el camino mínimo entre 1 y n
    int n = G.size();
    vector<int> V(n);
    vector<int> S = {0};
    vector<int> pi(n);
    vector<int> pred(n);
    int w = 0;
    pred[0] = 0;

    for (int i = 1; i < n; i++){
        if (find(G[0].begin(), G[0].end(), i) != G[0].end()){
            pi[i] = costos[0][i];
            pred[i] = 0;
        }
        else {
            pi[i] = INF;
            pred[i] = INF;
        }
    }

    while (S.size() < n){
        for (int v = 0; v < n; v++) {
            if (!(find(S.begin(), S.end(), v) != S.end()) && pi[v] <= pi[w]) {
                w = v;
            }
        }
        S.push_back(w);
    }
}