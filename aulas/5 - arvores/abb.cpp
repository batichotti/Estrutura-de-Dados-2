#include <iostream>

class NoABB{
public:
    NoABB(int chave, int valor){
        this->chave = chave;
        this->valor = valor;
    }

    NoABB* esq;
    NoABB* dir;
    int chave;
    int valor;
};

class ABB {
public:
    NoABB* raiz;
    void inserir(int chave, int valor){
        this->raiz = inserir(this->raiz, chave, valor);
    }
    NoABB* buscar(int chave){
        return buscar(this->raiz, chave);
    }
    void remover (int chave);

private:
    NoABB* buscar(NoABB* n, int chave){
        if(n->chave == chave) return n;
        if(n == nullptr) return nullptr;
        if(chave < n->chave) return buscar(n->esq, chave);
        return buscar(n->dir, chave);
    }
    NoABB* inserir(NoABB* n, int chave, int valor){
        if(n == nullptr) return new NoABB(chave, valor);
        if(n->chave == chave) n->valor = valor;
        else{
            if(chave < n->chave) n->esq = inserir(n->esq, chave, valor);
            else n->dir = inserir(n->dir, chave, valor);
        }
        return n;
    }
};

int main(int argc, char const *argv[]){
    
    return 0;
}
