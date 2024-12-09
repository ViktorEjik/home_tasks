#include <iostream>
#include <map>
#include <chrono>
#include <random>

int main() {

    clock_t start, end;

    std::vector<std::pair<uint32_t, uint32_t>> test;
    for (uint64_t i = 100000; i < 1000000; ++i){
        test.emplace_back(100000 + std::rand()%1000000 - 3, i);
    }

    {
        std::map<uint64_t, uint64_t> myMap1{{0,       0},
                                            {1000000, 1000000}};
        for (uint64_t i = 1; i < 100000; ++i) {
            myMap1.insert({i, i});
        }
        auto it = myMap1.begin();
        std::advance(it, 100000 - 1);

        start = clock();
        for (uint64_t i = 100000; i < 1000000; ++i) {
            myMap1.insert(it, test[i - 100000]);
        }
        end = clock();
        std::cout << "Hint " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;
    }
    {
        std::map<uint64_t, uint64_t> myMap2{{0, 0}, {1000000, 1000000}};
        for (uint64_t i = 1; i < 100000; ++i) {
            myMap2.insert({i, i});
        }
        start = clock();
        for (uint64_t i = 100000; i < 1000000; ++i) {
            myMap2.insert(test[i - 100000]);
        }
        end = clock();
        std::cout << "No hint " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;
    }

//    Hint 0.603019
//    No hint 0.683811
    return 0;
}