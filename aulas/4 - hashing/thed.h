#pragma once

#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class TabHashEncadeamento {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEncadeamento(int tamanho, int limiar = 5){
        this->invalido = std::make_pair(-1, -1);
        this->limiar = limiar;
        this->m = tamanho;
        this->n = 0;
        this->redims = 0;
        this->colisoes = 0;
        this->tabela = new std::vector<std::pair<int, T>>[tamanho];
    }

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEncadeamento(){
        delete[] this->tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, T valor){
        // std::cout << "Inserindo chave: " << chave << std::endl;
        auto& el = this->buscar(chave);
        if(el != this->invalido){
            // chave já está na tabela
            el.second = valor;
            return;
        }

        int fator_carga = this->n / this->m;
        if (fator_carga >= this->limiar) this->redimensionar(this->m*2+3);

        int h = hash(chave);
        this->tabela[h].push_back(std::make_pair(chave, valor));
        this->n++;
    }
    
    //Remove o par com a chave da tabela
    void remover(int chave) {
        int h = hash(chave);
        for (auto it = this->tabela[h].begin(); it != this->tabela[h].end(); ++it) {
            if (it->first == chave) {
                this->tabela[h].erase(it);
                this->n--;
                return;
            }
        }
    }
    //Busca o valor associado a chave na tabela
    std::pair<int,T>& buscar(int chave){
        int h = hash(chave);
        for (auto& el : this->tabela[h]){
            this->colisoes++;
            if (el.first == chave) return el;
        }
        return this->invalido;
    }
    
    //Imprime a tabela
    void imprimir(){
        for(int i = 0; i < this->m; i++){
            std::cout << "Hash " << i << ":";
            for(auto& el : this->tabela[i]){
                std::cout << "("<< el.first<<")," << "(" << el.second << ")";
            }
            std::cout << std::endl;
        }
    }

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info(){
        std::cout << "M:" << this->m << std::endl;
        std::cout << "N:" << this->n << std::endl;
        std::cout << "Fator de carga:" << (float) this->n / this->m << std::endl;
        std::cout << "Colisões: " << this->colisoes << std::endl;
        std::cout << "Redimensionamentos:" << this->redims << std::endl;
    }

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,T> invalido;

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,T>> itens();

private:
    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    int limiar; 
    int redims; // número de redimensionamentos realizados
    int colisoes;

    std::vector<std::pair<int,T>> *tabela; // tabela hash
    int hash(int chave){ // função hash
        return chave % this->m;
    }

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m){
        this->redims++;
        auto* antiga = this->tabela;
        int m_antigo = this->m;
        this->m = novo_m;
        this->n = 0;
        this->tabela = new std::vector<std::pair<int, int>>[novo_m];
        for(int i = 0; i < m_antigo; i++){
            if(antiga[i].size()>0){
                for(auto& el : antiga[i]) this->inserir(el.first, el.second);
            }
        }
        delete[] antiga;
    }
    
};