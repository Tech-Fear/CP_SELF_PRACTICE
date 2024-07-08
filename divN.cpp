#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

std::vector<int> findDivisors(int n) {
    std::vector<int> divisors;
    int sqrtN = std::sqrt(n);
    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

std::unordered_map<int, std::vector<int>> findAllDivisors(const std::vector<int>& array) {
    std::unordered_map<int, std::vector<int>> divisorsMap;
    for (int num : array) {
        if (divisorsMap.find(num) == divisorsMap.end()) {
            divisorsMap[num] = findDivisors(num);
        }
    }
    return divisorsMap;
}

int main() {
    std::vector<int> array = {12, 15, 20, 12}; // Example array
    std::unordered_map<int, std::vector<int>> divisorsMap = findAllDivisors(array);

    for (const auto& pair : divisorsMap) {
        std::cout << "Divisors of " << pair.first << ": ";
        for (int divisor : pair.second) {
            std::cout << divisor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
