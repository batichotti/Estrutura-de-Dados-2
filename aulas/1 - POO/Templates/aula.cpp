#include <iostream>

template <typename T>
T max(T a, T b){
    return (a >= b)?(a):(b);
}

template <typename T>
void troca(T& a, T& b){
    T aux = b;
    b = a;
    a = aux;
}

template <typename T>
T soma_array(T* arr, int n){
    T answer = 0;
    for (int i = 0; i < n; i++){
        answer += arr[i];
    }
    return answer;
}

int main(int argc, char const *argv[]){
    
    int a = 9;
    int b = 25;

    std::cout << "Max_int: " << max(a, b) << std::endl;
    
    float af = 0.9;
    float bf = 2.5;

    std::cout << "Max_float: " << max<float>(af, bf) << std::endl;

    troca(a, b);

    std::cout << "Troca: " << b << std::endl;

    int v[] = {3, 4, 1, 6, 2, 0};
    float u[] = {1.5, 2.4, 1.3};
    double w[] = {3.1, 5.0, 2.3};
    unsigned char y[] = {0, 244, 152};

    auto soma_v = soma_array(v, 6);
    float soma_u = soma_array(u, 3);
    double soma_w = soma_array<double>(w, 3);
    int soma_y = soma_array(y, 3);

    std::cout << "soma_v: " << soma_v << "\n";
    std::cout << "soma_u: " << soma_u << "\n";
    std::cout << "soma_w: " << soma_w << "\n";
    std::cout << "soma_y: " << soma_y << "\n";

    return 0;
}
