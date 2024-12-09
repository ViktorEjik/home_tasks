#include <iostream>
#include <map>
#include <chrono>
#include <random>

int main() {

    clock_t start, end;

    {
        std::srand(123);
        std::vector<std::pair<uint32_t, uint32_t>> test1;
        for (uint64_t i = 100000; i < 10000000; ++i){
            test1.emplace_back(100000 + std::rand()%10000000 - 3, i);
        }
        std::map<uint64_t, uint64_t> myMap2{{0, 0}, {10000000, 10000000}};
        for (uint64_t i = 1; i < 100000; ++i) {
            myMap2.insert({i, i});
        }
        start = clock();
        for (uint64_t i = 100000; i < 10000000; ++i) {
            myMap2.insert(test1[i - 100000]);
        }
        end = clock();
        std::cout << "No hint " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;
    }

    return 0;
}