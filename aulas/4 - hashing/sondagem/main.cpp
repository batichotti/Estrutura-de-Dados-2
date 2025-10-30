#include <iostream>
#include "thea.h"
#include <cstdlib>
#include "sondagem.h"

void test(int argc, char** argv, FSondagem* fsondagem){
    int m;
    int n;
    float limiar;
    if(argc < 4){
        m = 7;
        n = 100;
        limiar = 0.4;
    } else {   
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        limiar = atof(argv[3]);
    }

    TabHashEndAberto tab(m, limiar, fsondagem);

    srand(1);
    for(int i = 0; i < n; i++){
        tab.inserir(rand() % (n*100), rand() % (n*100));
    }

    tab.imprimir_info();

    // for(int i = 0; i < n; i++){
    //     tab.buscar(rand() % (n*100));
    // }

    //tab.imprimir();

}

int main(int argc, char** argv){
    
    test(argc, argv, new SondagemLinear());

    return 0;
}