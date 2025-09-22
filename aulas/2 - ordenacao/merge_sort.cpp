#include <iostream>
#include "utils.h"
#include <vector>
#include <string>

void merge(int* v, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r - q;
    int* e = new int[n1];
    int* d = new int[n2];
    int k = p;
    int i = 0;
    int j = 0;

    for(int i = 0; i < n1; i++){
        e[i] = v[p+i];
    }
    for(int j = 0; j < n2; j++){
        d[j] = v[q+j+1];
    }

    while ((i < n1) && (j < n2)){
        if (e[i] <= d[j]){
            v[k] = e[i++];
        } else {
            v[k] = d[j++];
        }
        k++;
    }
    while( i < n1 ){
        v[k++] = e[i++];
    }
    while( j < n2 ){
        v[k++] = d[j++];
    }

    delete[] e;
    delete[] d;
}

void MergeSort(int* v, int e, int d){
    if (e < d){
        int M = (e + d)/2;
        MergeSort(v, e, M);
        MergeSort(v, M+1, d);
        merge(v, e, M, d);
    } 
}

int main(int argc, char const *argv[]){
    int n = (argc >= 2)?(std::stoi(argv[1])):(10);

    std::vector<int> v = gerar_vetor_aleatorio(n, 99, n*100);
    
    MergeSort(v.data(), 0, n-1);

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
