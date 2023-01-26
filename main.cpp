#include <iostream>
#include "ejercicios.h"

using namespace std;

int main() {

    cout << "A probar se ha dicho!" << endl;
    cout << "FUNCION CANTIDAD DE APARICIONES" << endl;


    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    cout << " " << endl;

    cout << "El vector original es ";
    mostrarVector(v);

    cout << " " << endl;
    vector<pair<int,int>> res = cantidadApariciones(v);
    cout << "El vector resultante es ";
    mostrarVectorTupla(res);
    cout << " " << endl;
    return 0;
}