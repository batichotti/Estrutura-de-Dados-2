#include <vector>
#include "utils.cpp"
#include "sorts.cpp"

main(int argc, char const *argv[]){
    std::vector<int> v = gerar_vetor_aleatorio(5, 314, 10);
    imprimir_vetor(v.data(), v.size());
    SelectionSort(v.data(),v.size());
    imprimir_vetor(v.data(), v.size());
    return 0;
}
