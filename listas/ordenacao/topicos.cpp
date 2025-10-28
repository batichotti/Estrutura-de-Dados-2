#include "utils.h"

void SelectionSort(int*v, int n){
    int i;
    int maior;
    for (int i = n-1; i>0; i--){
        maior = max(v, 0, i);
        troca(maior, i);
    }   
}

int main(int argc, char const *argv[]){
    
    return 0;
}
