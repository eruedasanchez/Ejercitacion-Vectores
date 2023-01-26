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

bool esPalindromo(string s){
    bool res = true;
    for(int i = 0; i < (s.size() / 2); i++){
        if(s[i] != s[(s.size()-1) - i]){
            res = false;
            break;
        }
    }
    return res;
}

void palindromos(string rutaArchivoIn, string rutaArchivoOut){

    vector<string> palabras;

    /* Lectura de las palabras */
    ifstream archivoIn;
    archivoIn.open(rutaArchivoIn, ios::in);
    while(!archivoIn.eof()){
        string palabra;
        archivoIn >> palabra;
        palabras.push_back(palabra);
    }
    archivoIn.close();

    /* Escritura de los palindromos en rutaArchivoOut */
    ofstream archivoOut;
    archivoOut.open(rutaArchivoOut);
    for(int i = 0; i < palabras.size(); i++){
        if(esPalindromo(palabras[i])){
            archivoOut << palabras[i] << " , ";
        }
    }
    archivoOut.close();
}

void promedios(string rutaArchivoIn1, string rutaArchivoIn2, string rutaArchivoOut){
    vector<float> numerosPrimerArchivo;
    vector<float> numerosSegundoArchivo;

    /* Lectura de los numeros del primer archivo */
    ifstream archivoIn1;
    archivoIn1.open(rutaArchivoIn1, ios::in);
    while(!archivoIn1.eof()){
        float r1;
        archivoIn1 >> r1;
        numerosPrimerArchivo.push_back(r1);
    }
    archivoIn1.close();

    /* Lectura de los numeros del segundo archivo */
    ifstream archivoIn2;
    archivoIn2.open(rutaArchivoIn2, ios::in);
    while(!archivoIn2.eof()){
        float r2;
        archivoIn2 >> r2;
        numerosSegundoArchivo.push_back(r2);
    }
    archivoIn2.close();

    /* Escritura de los promedios en rutaArchivoOut */

    ofstream archivoOut;
    archivoOut.open(rutaArchivoOut);
    for(int i = 0; i < numerosPrimerArchivo.size(); i++){
        archivoOut << (numerosPrimerArchivo[i] + numerosSegundoArchivo[i]) / 2 << " , ";
    }
    archivoOut.close();
}

void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut){
    vector<int> numeros;

    /* Lectura de los numeros */
    ifstream archivoIn;
    archivoIn.open(rutaArchivoIn, ios::in);
    while(!archivoIn.eof()){
        int num;
        archivoIn >> num;
        numeros.push_back(num);
    }
    archivoIn.close();

    /* Escritura de los palindromos en rutaArchivoOut */
    ofstream archivoOut;
    archivoOut.open(rutaArchivoOut);
    for(int i = 0; i < numeros.size(); i++){
        if(!estaEnElSubvector(numeros, numeros[i], 0, i)){
            archivoOut << " ' " << numeros[i] << " " << contarApariciones(numeros, numeros[i]) << " ' " << " ";
        }
    }
    archivoOut.close();
}

void estadisticas(string rutaArchivo){
    vector<string> palabrasDelArchivo;

    /* Lectura de las palabras del archivo */
    ifstream archivoIn;
    archivoIn.open(rutaArchivo, ios::in);
    while(!archivoIn.eof()){
        string palabra;
        archivoIn >> palabra;
        palabrasDelArchivo.push_back(palabra);
    }
    archivoIn.close();

    /* Calculo de la palabra con maxima longitud */

    int maximaLongitudPalabra = palabrasDelArchivo[0].size();
    for(int i = 1; i < palabrasDelArchivo.size(); i++){
        if(maximaLongitudPalabra < palabrasDelArchivo[i].size()){
            maximaLongitudPalabra = palabrasDelArchivo[i].size();
        }
    }

    /* Agrupacion de las palabras de acuerdo a su longitud */
    vector<vector<string>> palabrasAgrupadasPorLong(maximaLongitudPalabra);
    for(int j = 0; j < palabrasDelArchivo.size(); j++){
        (palabrasAgrupadasPorLong[palabrasDelArchivo[j].size() - 1]).push_back(palabrasDelArchivo[j]);
    }

    /* Impresion por pantalla de la cantidad de palabras de acuerdo a su longitud */
    for(int k = 0; k < maximaLongitudPalabra; k++){
        cout << "Palabras de longitud " << k+1 << ": " << (palabrasAgrupadasPorLong[k]).size() << endl;
    }
}

void interseccion(string rutaArchivoIn1, string rutaArchivoIn2){
    vector<int> numerosPrimerArchivo;
    vector<int> numerosSegundoArchivo;

    /* Lectura de los numeros del primer archivo */
    ifstream archivoIn1;
    archivoIn1.open(rutaArchivoIn1, ios::in);
    while(!archivoIn1.eof()){
        float r1;
        archivoIn1 >> r1;
        numerosPrimerArchivo.push_back(r1);
    }
    archivoIn1.close();

    /* Lectura de los numeros del segundo archivo */
    ifstream archivoIn2;
    archivoIn2.open(rutaArchivoIn2, ios::in);
    while(!archivoIn2.eof()){
        float r2;
        archivoIn2 >> r2;
        numerosSegundoArchivo.push_back(r2);
    }
    archivoIn2.close();

    /* Escritura de la interseccion por pantalla */
    for(int i = 0; i < numerosPrimerArchivo.size(); i++){
        if(!estaEnElSubvector(numerosPrimerArchivo, numerosPrimerArchivo[i], 0, i) && estaEnElSubvector(numerosSegundoArchivo, numerosPrimerArchivo[i], 0, numerosSegundoArchivo.size())){
            cout << numerosPrimerArchivo[i] << " , ";
        }
    }
}

