#include <iostream>

#ifndef FINAL_PROJECT_USER_H
#define FINAL_PROJECT_USER_H

using namespace std;
class User {
    friend ostream &operator<<(ostream &os, const User &obj);
public:
    virtual void Print(ostream &os) const = 0;
    virtual ~User(){};
};




#endif //FINAL_PROJECT_USER_H
