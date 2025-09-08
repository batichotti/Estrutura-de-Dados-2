// Dado um vetor V com n inteiros positivos e um inteiro k, retorne os valores de dois elementos de V que somados são iguais a K
// Use std::make_pair(x, y) - std::pair<int, int> -> pair.first, pair.second

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

std::pair<int, int> twosum(std::vector<int>& v, int k){
    for (int first : v) {
        if (first > k) break;
        for (int second : v){
            if (first + second == k) return std::make_pair(first, second);
        }
    }

    return std::make_pair(-1, -1);
}

std::pair<int, int> twosum_optimized(std::vector<int>& v, int k){
    int e = 0;
    int d = v.size() - 1;

    std::sort(v.begin(), v.end());

    while (e < d){
        if(v[e] + v[d] == k) return std::make_pair(v[e], v[d]);
        else if (v[e] + v[d] > k) d--;
        else if (v[e] + v[d] < k) e++;
    }

    return std::make_pair(-1, -1);
}

void embaralhar(int *array, size_t n, int seed)
{
    srand(seed);
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

std::vector<int> gerar_vetor_aleatorio_sem_reps(int n, int seed)
{
    int *saida = new int[n];

    for (int i = 0; i < n; i++)
        saida[i] = i;

    embaralhar(saida, n, seed);

    std::vector<int> v;
    v.reserve(n);

    for (int i = 0; i < n; i++)
        v.push_back(saida[i]);

    delete[] saida;

    return v;
}

int main()
{
    std::vector<int> v = {9, 14, 2, 1, 17, 10};
    int k = 27;
    std::pair<int, int> p = twosum_optimized(v, k);
    std::cout << p.first << " e " << p.second << "\n";
}
