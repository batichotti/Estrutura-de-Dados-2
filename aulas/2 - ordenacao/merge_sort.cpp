#include <iostream>

void merge(int* v, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r - q;
    int* e = new int[n1];
    int* d = new int[n2];
    int k = 0;
    int i = 0;
    int j = 0;

    for(int i = p; i <= q; i++){
        e[k++] = v[i];
    }
    k = 0;
    for(int j = q+1; j <= r; j++){
        d[k++] = v[j];
    }
    k = p;
    i = 0;
    j = 0;

    while ((i < n1) && (j < n2)){
        if (e[i] <= d[j]){
            v[k] = e[i++];
        } else {
            v[k] = d[j++];
        }
        k++;
    }
    while( i < n1 ){
        v[k++] = e[i++];
    }
    while( j < n2 ){
        v[k++] = d[j++];
    }

    delete e;
    delete d;
}

int main(int argc, char const *argv[]){
    int v[] = {1, 7, 9, 0, 5, 8};
    int n = sizeof(v) / sizeof(v[0]);
    int p = 0;
    int q = (n - 1) / 2;
    int r = n - 1;

    merge(v, p, q, r);

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
