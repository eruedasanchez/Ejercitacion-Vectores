#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <cctype>
#include <assert.h>

using namespace std;

bool divide(vector<int> v, int n);

int maximo(vector<int> v);

bool pertenece(int elem, vector<int> v);

void mostrarVector(vector<int> v);

void sinImpares(vector<int>& v);

bool estaEnElSubvector(vector<int> v, int elem, int desde, int hasta);

vector<int> limpiarDuplicados(vector<int> v);

vector<int> rotar(vector<int> v, int k);

vector<int> reverso(vector<int> v);

vector<int> reversoRec(vector<int> v);
// vector<int> concatenar(vector<int> a, vector<int> b);

bool esPrimo(int y);
vector<int> factoresPrimos(int n);

bool ordenadoCreciente(vector<int> v);
bool ordenadoDecreciente(vector<int> v);
bool estaOrdenado(vector<int> v);

void mostrarVectorBooleanos(vector<bool> v);
void negar(vector<bool>& booleanos);
void mostrarVectorTupla(vector<pair<int,int>> vt);


int contarApariciones(vector<int> v, int elem);
vector<pair<int, int> > cantidadApariciones(vector<int> v);

void palindromos(string rutaArchivoIn, string rutaArchivoOut);

void promedios(string rutaArchivoIn1, string rutaArchivoIn2, string rutaArchivoOut);

void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut);

void estadisticas(string rutaArchivo);

void interseccion();