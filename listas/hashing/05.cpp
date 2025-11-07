#include <unordered_set>
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> semDuplicatas(std::vector<T>& arr){
    std::unordered_set<T> th;
    for (T each : arr) th.insert(each);
    std::vector<T> vecna;
    for (T v : th) vecna.push_back(v);
    return vecna;
}

int main(int argc, char const *argv[]){
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> result = semDuplicatas(arr);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
