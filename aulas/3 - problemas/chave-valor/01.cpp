#include <unordered_map>
#include <vector>
#include <iostream>
/*Retorna: um dicionario com a frequencia de cada inteiro, onde a chave é o inteiro
e o valor é a frequência.*/

template< typename T>
std::unordered_map<T,int> contarFrequencia(std::vector<T>& arr){
    std::unordered_map<T, int> tabela;
    for (T each : arr) {
        if (tabela.find(each) == tabela.end()) tabela[each] = 1;
        else tabela[each]++;   
    }
    return tabela;
}

int main(int argc, char const *argv[]){
    std::vector<int> numeros = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    std::unordered_map<int, int> frequencias = contarFrequencia(numeros);

    for (const auto& par : frequencias) {
        std::cout << "Numero: " << par.first << ", Frequencia: " << par.second << std::endl;
    }
    return 0;
}
