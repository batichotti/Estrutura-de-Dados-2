#include <iostream>
#include <unordered_set> //conjunto implementado com hashing
#include <vector>
#include <string>

using namespace std;

template <typename T>
vector<T> dedup(const vector<int>& v){
    unordered_set<T> d; // Cria um conjunto (dicionário) vazio
    for (T each : v) d.insert(each);
    vector<T> saida;
    for (T each : d) saida.push_back(each);
    return saida;
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


int main(int argc, char const *argv[]){
    vector<int> entrada = (argc < 2)?(gerar_vetor_aleatorio(100, 13, 1000)):(gerar_vetor_aleatorio(stoi(argv[1]), 13, 1000));
    vector<int> resultado = dedup<int>(entrada);
    for (int x : resultado) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
