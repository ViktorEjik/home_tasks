#include <iostream>
#include <array>
#include <algorithm>

template <char... bits>
struct to_binary;

template <char high_bit, char... bits>
struct to_binary<high_bit, bits...>
{
    static_assert(high_bit == '0' || high_bit == '1', "Not a binary value!");
    static const unsigned long long value =
            (high_bit - '0') << (sizeof...(bits)) | to_binary<bits...>::value;
};

template <char high_bit>
struct to_binary<high_bit>
{
    static_assert(high_bit == '0' || high_bit == '1', "Not a binary value!");
    static const unsigned long long value = (high_bit - '0');
};

template <const char... bits>
constexpr unsigned long long operator "" _b()
{
    return to_binary<bits...>::value;
}

class TString {
public:
    TString(const char* c, size_t s):c(c), len(s){}
    TString(std::basic_string<char> c):c(c){}
    explicit operator std::basic_string<char> (){
        return {c, len};
    }
private:
    const char* c;
    size_t len;
};

TString operator + (TString r, TString l){
    return TString()
}

auto operator""_b(std::basic_string<char>){
    return (std::basic_string<char>)TString{c, len};
}

// ...
int main()
{
    int arr[1010_b]; // значение вычисляется во время компиляции
    std::cout << "h"_b <<
    std::endl; // выведет 44
}