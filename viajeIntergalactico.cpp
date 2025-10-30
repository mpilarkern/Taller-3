#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

long long INF = 1e18;

int dijkstra_modificado(vector<vector<int>> grafo, vector<vector<int>> longitud, int v) {
    int n = grafo.size();
    vector<int> S = {v};
    vector<int> V(n);
    vector<int> minDist(n);
    vector<int> pred(n);

    for (int i = 0; i < n; i++) {
        V[i] = i+1;
    }

    minDist[v] = 0;
    pred[v] = 0;

    for (int u=1; u < n;  u++) {
        if (find(grafo[v].begin(), grafo[v].end(), u) != grafo[v].end()) {
            minDist[u] = longitud[v][u];
            pred[u] = v;
        }
        else {
            minDist[u] = INF;
            pred[u] = INF;
        }
    }

    while (S.size() < n) {

    }
    return minDist[n-1];
}