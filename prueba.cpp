#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int consecutivos(vector<long long>& lista, long long posInicial){
    int contador = 1;
    for (int i = posInicial; i < lista.size() - 1; i++){
        if (lista[i] + 1 != lista[i + 1]) {
            break;
        }
        contador ++;
    }
    return contador;
}

int main() {
    vector<long long> lista = {3, 4, 6, 7, 8, 9};
    long long posicion = 0;

    cout << consecutivos(lista, posicion);
    return 0;
}