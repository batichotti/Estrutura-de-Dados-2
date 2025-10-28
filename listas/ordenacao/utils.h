#pragma once

#include <vector>

template <typename T>
void troca(T& a, T& b);
int max(int* v, int ini, int fim);
std::vector<int> gerar_vetor_aleatorio(int n, int seed, int max);
void imprimir_vetor(int* v, int n);
std::vector<int> gerar_vetor_aleatorio_sem_reps(int n, int seed);