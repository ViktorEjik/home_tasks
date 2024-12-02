//
// Created by viktor on 02.12.2024.
//
#include <exception>
#include <string>
#include <iostream>

class TMyException: std::exception{
public:
    TMyException operator<<(std::basic_string<char> alert){
        alert__ = alert;
        return *this;
    }

    const char * what() const noexcept override{
        return alert__.c_str();
    }
protected:
    std::basic_string<char> alert__;
};

class MyExcept1: public TMyException{
public:
    MyExcept1 operator<<(std::basic_string<char> alert){
        alert__ = alert + " alert1";
        return *this;
    }
};

class MyExcept2: public TMyException{
public:
    MyExcept2 operator<<(std::basic_string<char> alert){
        alert__ = alert + " alert2 what";
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
        throw TMyException() << "ALARM";
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