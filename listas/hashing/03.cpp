#include <unordered_set>
#include <vector>
#include <utility>
#include <iostream>


std::pair<int, int> twosum(std::vector<int>& arr, int k) {
    std::unordered_set<int> tabela;
    for (int num : arr) {
        int complement = k - num;
        if (tabela.find(complement) != tabela.end()) {
            return std::make_pair(complement, num);
        }
        tabela.insert(num);
    }
    return std::make_pair(-1, -1);
}

int main(int argc, char const *argv[]) {
    std::vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    std::pair<int, int> result = twosum(arr, target);

    if (result.first != -1 && result.second != -1) {
        std::cout << "Pair found: (" << result.first << ", " << result.second << ")\n";
    } else {
        std::cout << "No pair found.\n";
    }

    return 0;
}
