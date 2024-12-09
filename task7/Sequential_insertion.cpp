#include <iostream>
#include <map>
#include <chrono>
#include <ctime>

int main() {
    std::map<uint64_t, uint64_t> myMap1;
    std::map<uint64_t, uint64_t> myMap2;
    auto it = myMap1.begin();
    // Заполняем map последовательно
    auto start = clock();
    for (uint64_t i = 0; i < 10000000; ++i) {

        myMap2.insert({i, i});
    }
    auto end = clock();
    std::cout << "No hint " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    start = clock();
    for(uint64_t i = 0; i < 10000000; ++i){
        it = myMap1.insert(it, {i, i});
    }
    end = clock();
    std::cout << "Hint " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    // No hint 2.64896
    // Hint 0.541984
    return 0;
}