#include <iostream>

void swap(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int pos_maior(int* v, int ini, int fim){
    int maior = ini;
    for (int i = ini+1; i <= fim; i++){
        if(v[maior] < v[i]) maior = i;
    }
    return maior;
}

void selectionSort(int* v, int n){
    for (int i = n-1; i > 0; i--){
        int m = pos_maior(v, 0, i);
        swap(v, m, i);
    }
}

int main(int argc, char const *argv[]){
    int v[] = {3, 5, 6, 2, 5, 1, 8};
    int n = 7;
    selectionSort(v, n);
    for (int elem : v){
        std::cout << elem << std::endl;
    }
    return 0;
}
