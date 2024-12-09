#include <iostream>
#include <map>
#include <chrono>

int main() {
    std::map<uint64_t, uint64_t> myMap1{{0, 0}, {1000000, 1000000}};
    std::map<uint64_t, uint64_t> myMap2{{0, 0}, {1000000, 1000000}};
    for (uint64_t i = 1; i < 100000; ++i) {
        myMap1.insert({i, i});
        myMap2.insert({i, i});
    }
    auto it = myMap1.begin();
    std::advance(it, 100000-1);

    auto start = clock();
    for (uint64_t i = 100000; i < 1000000; ++i) {
        myMap1.insert(it, {i, i});
    }
    auto end = clock();
    std::cout << "Hint " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    start = clock();
    for (uint64_t i = 1000; i < 1000000; ++i) {
        myMap2.insert({i, i});
    }
    end = clock();

    std::cout << "No hint " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
//    Hint 0.193043
//    No hint 0.225971
    return 0;
}