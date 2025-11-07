#include <iostream>
#include "utils.cpp"

template <typename T>
void SelectionSort(T* V, int n){
    int i;
    int maior;

    for (int i = n-1; i>0; i--){
        maior = max(v, 0, i);
        troca(v[maior], v[i]);
    }   
}

template <typename T>
void BubbleSort(T* v, int n){
    int trocas = 1;
    int j;
    while(trocas){
        trocas = 0;
        for(j = 0; j < n-1; j++){
            if(v[j] > v[j+1]){
                trocas++;
                troca(v[j], v[j+1]);
            }
        }
    }
}

template <typename T>
void InsertionSort(T* v, int n){
    int j;
    for (j = 0; j < n; j++) insertion(v, j);   
}

void SelectionSortDec(int*v, int n){
    int i;
    int maior;

    for (int i = n-1; i>0; i--){
        maior = min(v, 0, i);
        troca(v[maior], v[i]);
    }   
}

void BubbleSortDec(int* v, int n){
    int trocas = 1;
    int j;
    while(trocas){
        trocas = 0;
        for(j = 0; j < n-1; j++){
            if(v[j] < v[j+1]){
                trocas++;
                troca(v[j], v[j+1]);
            }
        }
    }
}

void InsertionSortDec(int* v, int n){
    int j;
    for (j = 0; j < n; j++) insertion_dec(v, j);   
}

void SelectionSortMenor(int*v, int n){
    int i;
    int maior;

    for (int i = n-1; i>0; i--){
        maior = min(v, 0, i);
        troca(v[maior], v[i]);
    }   
}

void Quicksort(int* v, int p, int r){
    if(p < r){
        int q = partition(v, p, r);
        Quicksort(v, p, q-1);
        Quicksort(v, q+1, r);
    }
}