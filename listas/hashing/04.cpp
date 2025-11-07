#include <unordered_set>
#include <iostream>
#include <vector>

template <typename T>
bool temDuplicatas(std::vector<T>& arr){
    std::unordered_set<T> tabela;
    for (T each : arr){
        if (tabela.find(each) != tabela.end()) return true;
        tabela.insert(each);
    }
    return false;
}

int main(int argc, char const *argv[]){
    std::vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (temDuplicatas(numeros)) {
        std::cout << "Ha duplicatas no vetor." << std::endl;
    } else {
        std::cout << "Nao ha duplicatas no vetor." << std::endl;
    }
    return 0;
}
