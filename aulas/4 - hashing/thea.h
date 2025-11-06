#pragma once

#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class TabHashEndAberto {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEndAberto(int tamanho, float limiar = 0.5){
        this->m = tamanho;
        this->n = 0;
        this->tabela = new Elemento[this->m];
        for(int i = 0; i < this-> m; i++){
            this->tabela[i].estado = Estado::LIVRE;
        }
    }

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEndAberto(){
        delete[] this->tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, T valor){
        int pos = buscar_pos(chave);
        if (pos >= 0){
            this->tabela[pos].valor = valor;
            return;
        }

        if (((float)this->n / this->m)>=0.5) redimensionar(m*2+1);

        int h = hash(chave);
        while (this->tabela[h].estado == Estado::OCUPADO){
            h++;
            h %= this->m;
        }
        this->tabela[h].chave = chave;
        this->tabela[h].valor = valor;
        this->tabela[h].estado = Estado::OCUPADO;
        this->n++;
    }
    
    //Remove o par com a chave da tabela
    void remover(int chave) {
        int pos = buscar_pos(chave);
        if (pos >= 0) {
            this->tabela[pos].estado = Estado::APAGADO;
            this->n--;
        }
    }

    //Busca o valor associado a chave na tabela
    std::pair<int,T> buscar(int chave){
        int pos = buscar_pos(chave);
        if (pos >= 0){
            return std::make_pair(this->tabela[pos].chave, this->tabela[pos].valor);
        }
        return this->invalido;
    }
    
    //Imprime a tabela
    void imprimir(){
        for (int i = 0; i < this->m; i++) {
            std::cout << i << ": ";
            const auto& el = this->tabela[i];
            std::cout << "(" << el.chave << "," << el.valor << ") ";
            char estado = el.estado == Estado::APAGADO ? 'A' :
                        (el.estado == Estado::LIVRE ? 'L' : 'O');
            std::cout << "[" << estado << "]";
            std::cout << std::endl;
        }    
    }

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info()
    {
        std::cout << "m: " << this->m << std::endl;
        std::cout << "n: " << this->n << std::endl;
        std::cout << "fator de carga: " << (float)this->n/this->m << std::endl;
        std::cout << "redimensionamentos: " << this->redims << std::endl;
    }

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,T> invalido = {-1, -1};

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,T>> itens();

private:

    enum class Estado {
        LIVRE,
        OCUPADO,
        APAGADO
    };

    struct Elemento {
    public:
        int chave;
        T valor;
        Estado estado;
    };

    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    float limiar; 
    int redims; // número de redimensionamentos realizados

    Elemento *tabela; // tabela hash

    int hash(int chave){ //função hash
        return chave % this->m;
    }
    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m){
        this->redims++;
        Elemento* nova_tabela = new Elemento[novo_m];
        for (int i = 0; i < novo_m; i++){
            nova_tabela[i].estado = Estado::LIVRE;
        }
        Elemento* tabela_antiga = this->tabela;
        this->tabela = nova_tabela;
        int m_antigo = this->m;
        this->n = 0;
        this->m = novo_m;
        for(int i = 0; i < m_antigo; i++) if (tabela_antiga[i].estado == Estado::OCUPADO) inserir(tabela_antiga[i].chave, tabela_antiga[i].valor);
        delete[] tabela_antiga;
    }

    //retorna a posição que a chave ocupa na tabela. 
    //(ou -1 se a chave não estiver na tabela)
    int buscar_pos(int chave){
        int h = this->hash(chave);
        while (this->tabela[h].estado != Estado::LIVRE){
            if((this->tabela[h].estado == Estado::OCUPADO) && (this->tabela[h].chave == chave)){
                return h;
            }
            h++;
            h %= this->m;
        }
        return -1;
    }
    
};