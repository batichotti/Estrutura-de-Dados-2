// Dado um vetor v com n posições retorne o k-ésimo maior elemento deste vetor
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
T kesimoMaior(std::vector<T> &v, int k){
    sort(v.begin(), v.end());
    return v[v.size()-k];
}

int main(int argc, char const *argv[]){
    std::vector<int> v = {7, 2, 9, 4, 5};
    int k = 2;
    std::cout << "O " << k << "th maior elemento: " << kesimoMaior(v, k) << std::endl;
    return 0;
}
