void troque(int* v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(int* v, int p, int r){
    int x = v[r];
    int i = p - 1; // azul
    for (int j = p; j < r; j++){
        if(v[j] <= x){
            troque(v, ++i, j);
        }
    }
    troque(v, ++i, r);
    return i;
}

void Quicksort(int* v, int p, int r){
    if(p < r){
        int q = partition(v, p, r);
        Quicksort(v, p, q-1);
        Quicksort(v, q+1, r);
    }
}