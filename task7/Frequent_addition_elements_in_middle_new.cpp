#include <iostream>
#include <map>
#include <chrono>
#include <random>

int main() {

    clock_t start, end;

    {
        std::srand(123);
        std::vector<std::pair<uint32_t, uint32_t>> test1;
        for (uint64_t i = 1; i < 10000000; ++i){
            test1.emplace_back(1000000 + i, i);
        }
        std::map<uint64_t, uint64_t> myMap1{{0,       0},
                                            {10000000, 10000000}};
        for (uint64_t i = 1; i < 10000000; ++i) {
            myMap1.insert({std::rand()%10000000, i});
        }
        auto it = myMap1.begin();
        for (auto &[key, value]: myMap1) {
            if (key >= 1000000) {
                it--;
                break;
            }
            it++;
        }
        start = clock();
        for (auto& elem: test1) {
            it = myMap1.insert(it,elem);
        }
        end = clock();
        std::cout << "Hint " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;
    }

    //No hint 1.39082
    //Hint 1.26475
    return 0;
}