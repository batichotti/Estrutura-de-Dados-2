#include <unordered_map>
#include <iostream>
#include <vector>

template <typename T>
int primeiroUnico(std::vector<T>& arr) {
    // Encontre o primeiro elemento que aparece apenas uma vez no vetor (caso não exista, retorne -1)
    std::unordered_map<T, int> th;
    for (T each : arr) {
        th[each]++;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (th[arr[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    std::vector<int> arr = {4, 5, 1, 2, 0, 4, 1, 2};
    int index = primeiroUnico(arr);
    if (index != -1) {
        std::cout << "Primeiro elemento unico: " << arr[index] << " no indice " << index << std::endl;
    } else {
        std::cout << "Nenhum elemento unico encontrado." << std::endl;
    }
    return 0;
}
