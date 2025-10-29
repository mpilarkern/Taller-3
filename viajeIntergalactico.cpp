#include<utility>
#include<vector>
#include<iostream>

using namespace std;

//idea general del ejercicio: corro dijkstra sobre el grafo (nodos: planetas, aristas: portales con peso determinado por el tiempo de la transferencia) 
//y me guardo un arreglo de tamaño n que en la i-ésima posición diga el tiempo que tardo en llegar desde el planeta 1 al i por el camino mínimo (-1 si no se puede llegar de 1 a i).
//Si el tiempo que tardo en llegar de 1 a i coincide con algún tiempo en el que llega otro viajero al planeta i, sumo 1.