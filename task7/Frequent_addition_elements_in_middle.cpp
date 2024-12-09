#include <iostream>
#include <map>
#include <chrono>

int main() {
    std::map<uint64_t, uint64_t> myMap1{{0, 0}, {1000000, 1000000}};
    std::map<uint64_t, uint64_t> myMap2{{0, 0}, {1000000, 1000000}};
    for (uint64_t i = 1; i < 1000; ++i) {
        myMap1.insert({i, i});
        myMap2.insert({i, i});
    }
    auto it = myMap1.begin();
    std::advance(it, 999);

    std::chrono::duration<double, std::milli> time{};
    std::chrono::duration<double, std::milli> time_hint{};
    // Заполняем map последовательно
    for (uint64_t i = 1000; i < 1000000; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        it = myMap1.insert(it, {i, i});
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        time_hint += elapsed;

        // Для сравнения, вставка без hint
        start = std::chrono::high_resolution_clock::now();
        myMap2.insert({i, i});
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        time += elapsed;
    }
    std::cout << "Hint " << std::fixed << time_hint.count()/1000000 << std::endl;
    std::cout << "No hint " << std::fixed << time.count()/1000000 << std::endl;
//    Hint 0.001383
//    No hint 0.001828
    return 0;
}