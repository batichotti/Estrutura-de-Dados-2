#include <iostream>
#include <string>
#include <vector>
#include <map>

void imprimir_por_tamanho(std::vector<std::string> v){
    std::map<unsigned int, std::vector<std::string>> M;
    for (std::string x : v){
        M[x.size()].push_back(x);
    }

    for(auto& pair : M){
        std::cout << "Grupo de tamanho " << pair.first << std::endl;
        for (std::string s : pair.second){
            std::cout << "   " << s << std::endl;
        }
    }
}

int main(int argc, char const *argv[]){
    std::vector<std::string> animais = {"macaco", "cachorro", "gato", "vaca", "girafa", "anta", "cavalo", "porco"};
    imprimir_por_tamanho(animais);
    return 0;
}
