// Dado um vetor v com n elementos veririfque se há elementos repetidos
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

template<typename T>
bool haRepetidos(vector<T> &v, int n){ // Eficiente
    sort(v.begin(), v.end()); // Supondo o vetor ordenado
    for (int i = 0; i < n-1; i++){
        if (v[i] == v[i+1]) return true;
    }
    return false;
}

template<typename T>
bool haRepetidosOn2(vector<T> &v, int n){ // O(n^2)
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < v.size(); j++){
            if(v[i] == v[j]) return true;
        }   
    }
    return false;
}

void embaralhar(int *array, size_t n, int seed){
    srand(seed);
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

vector<int> gerar_vetor_aleatorio_sem_reps(int n, int seed){
    int* saida = new int[n];
    
    for(int i = 0; i < n; i++)
        saida[i] = i;
    
    embaralhar(saida, n, seed);
    
    std::vector<int> v;
    v.reserve(n);

    for(int i = 0; i < n; i++)
        v.push_back(saida[i]);
    
    delete[] saida;

    return v;
}

int main(int argc, char const *argv[]){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> u = {1, 2, 3, 7, 2, 5, 6, 7, 2, 2, 7};
    vector<string> s = {"Rossi", "Viña", "Léo", "Léo", "Varela", "Saúl", "Jorginho", "Lino", "Arrascaeta", "Plata", "Pedro"};

    cout << "Sem Ordenacao" << endl;
    cout << "v: " << (haRepetidosOn2(v, v.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;
    cout << "u: " << (haRepetidosOn2(u, u.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;
    cout << "s: " << (haRepetidosOn2(s, s.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;

    cout << endl << "Com Ordenacao" << endl;
    cout << "v: " << (haRepetidos(v, v.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;
    cout << "u: " << (haRepetidos(u, u.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;
    cout << "s: " << (haRepetidos(s, s.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;

    cout << endl << "Com Gerador" << endl;

    vector<int> grandao = gerar_vetor_aleatorio_sem_reps(10000, 99);
    cout << "g: " << (haRepetidos(grandao, grandao.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;
    cout << "g: " << (haRepetidosOn2(grandao, grandao.size()) ? "Ha elementos repetidos" : "Nao ha elementos repetidos") << endl;

    return 0;
}
