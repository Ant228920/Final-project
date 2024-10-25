#ifndef FINAL_PROJECT_WRONGCHOICE_H
#define FINAL_PROJECT_WRONGCHOICE_H
#include <iostream>
class WrongChoice: public std::exception{
public:
    WrongChoice()=default;
    ~WrongChoice() override =default;
    [[nodiscard]] const char *what() const noexcept override{
        return "Wrong choice!";
    };
};
#endif //FINAL_PROJECT_WRONGCHOICE_H
