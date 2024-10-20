#include <iostream>
#ifndef FINAL_PROJECT_BANNED_H
#define FINAL_PROJECT_BANNED_H


class Banned : public std::exception{
public:
    Banned()=default;
    ~Banned()=default;
    const char *what() const noexcept override{
        return "You are banned from this app!";
    };
};


#endif //FINAL_PROJECT_BANNED_H
