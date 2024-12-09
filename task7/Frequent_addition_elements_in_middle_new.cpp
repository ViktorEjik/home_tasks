#include <iostream>
#include <map>
#include <chrono>
#include <random>

int main() {

    clock_t start, end;

    {
        std::srand(123);
        std::vector<std::pair<uint32_t, uint32_t>> test2;
        for (uint64_t i = 100000; i < 10000000; ++i){
            test2.emplace_back(100000 + std::rand()%10000000 - 3, i);
        }
        std::map<uint64_t, uint64_t> myMap1{{0,       0},
                                            {10000000, 10000000}};
        for (uint64_t i = 1; i < 100000; ++i) {
            myMap1.insert({i, i});
        }
        auto it = myMap1.begin();
        std::advance(it, 100000 - 1);

        start = clock();
        for (uint64_t i = 100000; i < 10000000; ++i) {
            myMap1.insert(it, test2[i - 100000]);
        }
        end = clock();
        std::cout << "Hint " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;
    }

    return 0;
}