#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
pair<T, T> twosum (const vector<T>& v, T k){
    unordered_set<T> d;
    for (T a : v) {
        d.insert(a);
        if(d.count(k-a)) return make_pair(a, k-a);
    }
    return make_pair(T(), T());
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
    vector<int> v = (argc < 2)?(gerar_vetor_aleatorio(10, 13, 1000)):(gerar_vetor_aleatorio(stoi(argv[1]), 13, 1000));
    int k = (argc < 3)?(rand()%1000):(stoi(argv[2]));
    auto result = twosum(v, k);
    if (result.first != result.second) {
        printf("Pair found: %d, %d\n", result.first, result.second);
    } else {
        printf("No pair found\n");
    }
    return 0;
}
