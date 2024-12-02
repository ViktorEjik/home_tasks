//
// Created by viktor on 02.12.2024.
//
#include <exception>
#include <string>
#include <sstream>
#include <iostream>

class TMyException: std::exception{
public:
    TMyException& operator<<(const std::string& alert){
        alert_ += alert;
        return *this;
    }

    [[nodiscard]] const char * what() const noexcept override{
        return alert_.c_str();
    }
protected:
    std::string alert_;
};

class MyExcept1: public TMyException{
public:

    MyExcept1& operator<<(const std::string& alert){
        alert_ += alert + " alert1";
        return *this;
    }
};

class MyExcept2: public TMyException{
public:
    MyExcept2& operator<<(const std::string& alert){
        alert_ += alert + " alert2 what";
        return *this;
    }
};

int main(){
    try {
        throw TMyException();
    }
    catch (TMyException &e){
        std::cout << "what: " << e.what() << '\n';
    }

    try {
        throw TMyException() << "ALARM" << " l";
    }
    catch (TMyException &e){
        std::cout <<  "what: " << e.what() << '\n';
    }
    try {
        throw MyExcept1() << "abc";
    } catch (MyExcept1 &e) {
        std::cout <<  "what: " << e.what() << '\n';
    }
    try {
        throw MyExcept2() << "abc";
    } catch (TMyException &e) {
        std::cout <<  "what: " << e.what() << '\n';
    }
    return 0;
}