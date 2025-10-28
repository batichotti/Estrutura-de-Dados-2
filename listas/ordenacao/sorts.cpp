#include <iostream>
#include "utils.cpp"

void SelectionSort(int*v, int n){
    int i;
    int maior;

    for (int i = n-1; i>0; i--){
        maior = max(v, 0, i);
        troca(v[maior], v[i]);
    }   
}