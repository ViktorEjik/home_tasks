#include <iostream>
#include <map>
#include <chrono>

int main() {
    std::map<uint64_t, uint64_t> myMap;
    auto it = myMap.begin();
    std::chrono::duration<double, std::milli> time{};
    std::chrono::duration<double, std::milli> time_hint{};
    // Заполняем map последовательно
    for (uint64_t i = 0; i < 10000000; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        it = myMap.insert(it, {i, i});
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        time_hint += elapsed;

        // Для сравнения, вставка без hint
        start = std::chrono::high_resolution_clock::now();
        myMap.insert({i + 1, i + 1});
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        time += elapsed;
    }
    std::cout << "Hint " << std::fixed << time_hint.count()/10000000 << std::endl;
    std::cout << "No hint " << std::fixed << time.count()/10000000 << std::endl;
    // Hint 0.001779
    // No hint 0.001859
    return 0;
}