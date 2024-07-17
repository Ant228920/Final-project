#ifndef FINAL_PROJECT_EXCEPTION_H
#define FINAL_PROJECT_EXCEPTION_H
#include <iostream>
class Exception: public std::exception{
public:
    Exception()=default;
    ~Exception()=default;
    const char *what() const noexcept override{
        return "Wrong choice!";
    };
};
#endif //FINAL_PROJECT_EXCEPTION_H
