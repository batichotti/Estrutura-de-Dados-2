#include <iostream>
#include <vector>
#include <map>

template <typename T>
T most_common(std::vector<T> v){
    std::map<T, unsigned int> M;
    for (T x : v){
        if (M.count(x)){
            M[x]++;
            // M.insert_or_assign(x, M.at(x) + 1); // -std=c++17
            // M.insert_or_assign(x, ++M.at(x)); // -std=c++17
            // int count = M.at(x);
            // count++;
            // M.insert_or_assign(x, count); // -std=c++17
        } else {
            M.insert({x, 1});
        }
    }

    T maior_chave;
    unsigned int maior_valor = 0;
    for(auto& x : M){
        // x.first é a chave e x.second é o valor
        if (x.second > maior_valor){
            maior_valor = x.second;
            maior_chave = x.first;
        }
    }

    return maior_chave;
}

int main(int argc, char const *argv[]){
    std::vector<int> v = {3, 1, 4, 2, 3, 1, 3, 2, 3, 4};

    int mais_comum = most_common(v);
    std::cout << "O elemento mais comum foi " << mais_comum << std::endl;
    return 0;
}
