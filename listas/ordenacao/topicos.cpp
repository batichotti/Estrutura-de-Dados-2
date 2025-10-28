template <typename T>
void troca(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int max(int* v, int ini, int fim){
    int maior = v[ini];
    for (int i = ini; i < fim; i++){
        if (maior < v[i]) maior = v[i];
    }
    return maior;
}

void SelectionSort(int*v, int n){
    int i;
    int maior;
    for (int i = n-1; i>0; i--){
        maior = max(v, 0, i);
        troca(maior, i);
    }   
}