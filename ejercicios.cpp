#include "ejercicios.h"

bool divide(vector<int> v, int n){
    assert(v.size() > 0);           // PRE: El vector debe tener al menos un elemento

    bool divideATodos = true;
    for(int i = 0; i < v.size(); i++){
        if(v[i] % n != 0){
            divideATodos = false;
            break;
        }
    }
    return divideATodos;
}

int maximo(vector<int> v){
    assert(v.size() > 0);     // PRE: El vector debe tener al menos un elemento

    int i = 0;
    int max = v[i];
    for(int j = 1; j < v.size(); j++){
        if(v[j] > max){
            max = v[j];
        }
    }
    return max;
}

bool pertenece(int elem, vector<int> v){
    bool encontreElemento = false;

    for(int i = 0; i < v.size(); i++){
        if(v[i] == elem){
            encontreElemento = true;
            break;
        }
    }
    return encontreElemento;
}

void mostrarVectorBooleanos(vector<bool> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        if(i != v.size()-1){
            string s = v[i] ? "true" : "false";
            cout << s  << ",";
        } else {
            string j = v[i] ? "true" : "false";
            cout << j << "]";
        }
    }
}

void mostrarVector(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        if(i != v.size()-1){
            cout << v[i] << ",";
        } else {
            cout << v[i] << "]";
        }
    }
}

void mostrarVectorTupla(vector<pair<int,int>> vt){
    cout << "[";
    for(int i = 0; i < vt.size(); i++){
        if(i != vt.size()-1){
            cout << "(" << vt[i].first << "," << vt[i].second << ")" << ",";
        } else {
            cout << "(" << vt[i].first << "," << vt[i].second << ")" << "]";
        }
    }
}

void sinImpares(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 == 1){
            v[i] = 0;
        }
    }
}

bool estaEnElSubvector(vector<int> v, int elem, int desde, int hasta){
    bool encontre = false;

    for(int i = desde; i < hasta; i++){
        if(v[i] == elem){
            encontre = true;
            break;
        }
    }
    return encontre;
}

vector<int> limpiarDuplicados(vector<int> v){
    vector<int> sinDuplicados;
    for(int i = 0; i < v.size(); i++){
        if(!(estaEnElSubvector(v,v[i],0,i))){
            sinDuplicados.push_back(v[i]);
        }
    }
    return sinDuplicados;
}

vector<int> rotar(vector<int> v, int k){
    vector<int> vectorRotado;

    for(int i = 0; i < v.size(); i++){
        vectorRotado.push_back(v[(k+i) % v.size()]);
    }
    return vectorRotado;
}

vector<int> reverso(vector<int> v){
    vector<int> rev;

    for(int i = 0; i < v.size(); i++){
        rev.push_back(v[(v.size()-1) - i]);
    }
    return rev;
}

/* vector<int> concatenar(vector<int> a, vector<int> b){
    vector<int> concat;
    for(int i = 0; i < a.size() + b.size(); i++){
        if(i < a.size()){
            concat[i] = a[i];
        } else {
            concat[i] = b[i-a.size()];
        }
    }
    return concat;
}

 vector<int> reversoRec(vector<int> v){
    vector<int> reversoRecursivo;
    if(v.size() == 0){
        return reversoRecursivo;
    } else {
        return concatenar(reversoRecursivo.push_back(v[v.size()-1]), reversoRec(v.pop_back()));
    }
}

*/

//[1] ->   1 . []
// [1,2] -> 2 . revrecursivo[1]
// [1,2,3] -> 3 .revRecursivo[1,2]

bool esPrimo(int y){
    assert(y > 0);

    bool primo;
    int sumardiv = 0;
    for (int i = 1; i < y; i++) {
        if (y % i == 0){
            sumardiv++;
        }
    }

    if (sumardiv == 1){
        primo = true;
    } else {
        primo = false;
    }
    return primo;
}

vector<int> factoresPrimos(int n){
    vector<int> factPrimos;
    for(int i = 1; i < n; i++){
        if((n % i == 0) && esPrimo(i)){
            factPrimos.push_back(i);
        }
    }
    return factPrimos;
}

bool ordenadoCreciente(vector<int> v){
    bool res = true;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            res = false;
            break;
        }
    }
    return res;
}

bool ordenadoDecreciente(vector<int> v){
    bool res = true;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] < v[i+1]){
            res = false;
            break;
        }
    }
    return res;
}

bool estaOrdenado(vector<int> v){
    return ordenadoCreciente(v) || ordenadoDecreciente(v);
}

void negar(vector<bool>& v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == true){
            v[i] = false;
        } else {
            v[i] = true;
        }
    }
}

int contarApariciones(vector<int> v, int elem){
    int contadorApariciones = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == elem){
            contadorApariciones++;
        }
    }
    return contadorApariciones;
}

vector<pair<int,int>> cantidadApariciones(vector<int> v){
    vector<pair<int,int>> elemYApariciones;

    for(int i = 0; i < v.size(); i++){
        if(!(estaEnElSubvector(v,v[i],0,i))){
            /* Hay que agregarlo al vector */
            int elemento = v[i];
            int apariciones = contarApariciones(v, v[i]);
            pair<int,int> tupla = make_pair(elemento, apariciones);
            elemYApariciones.push_back(tupla);
        }
    }
    return elemYApariciones;
}

void palindromos(string rutaArchivoIn, string rutaArchivoOut)
{
    cout << "Implementame!" << endl;
}

void promedios(string rutaArchivoIn1, string rutaArchivoIn2, string rutaArchivoOut)
{
    cout << "Implementame!" << endl;
}

void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut)
{
    cout << "Implementame!" << endl;
}

void estadisticas(string rutaArchivo)
{
    cout << "Implementame!" << endl;
}

void interseccion()
{
    cout << "Implementame!" << endl;
}

