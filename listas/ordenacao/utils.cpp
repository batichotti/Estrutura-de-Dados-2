#include <cstdlib>
#include <cstdio>
#include <vector>

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

std::vector<int> gerar_vetor_aleatorio(int n, int seed, int max){
    std::vector<int> v;
    v.reserve(n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v.push_back(rand() % max);
    }
    return v;
}

void imprimir_vetor(int* v, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
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

std::vector<int> gerar_vetor_aleatorio_sem_reps(int n, int seed){
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


