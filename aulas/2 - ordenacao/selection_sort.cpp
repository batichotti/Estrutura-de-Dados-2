#include "utils.h"
#include <vector>
#include <string>

int pos_maior(int *v, int ini, int fim){
    int m = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] > v[m]){
            m = i;
        }
    }
    return m;
}

void SelectionSort(int* v, int n){
    for(int i = n-1; i > 0; i--){ 
        int m = pos_maior(v, 0, i);
        trocar(v, m, i);
    }
}

int main(int argc, char** argv){
    int n = 10;
    if (argc > 1){
        n = std::stoi(argv[1]);
    } 

    std::vector<int> v;
    v = gerar_vetor_aleatorio(n, 99, n*100);

    imprimir_vetor(v.data(), v.size());

    SelectionSort(v.data(), v.size());

    imprimir_vetor(v.data(), v.size());
}
