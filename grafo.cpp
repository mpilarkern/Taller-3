#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#include<algorithm>

using namespace std;

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

    bool tieneArista(int v, int w, int peso) {
        pair<int, int> arista = {w, peso};

        return (find(N[v].begin(), N[v].end(), arista) != N[v].end());
    }

    void agregarArista(int v, int w, int peso) {
        N[v].push_back({w, peso});
        N[w].push_back({v, peso});
    }
};