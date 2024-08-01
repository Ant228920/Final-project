#include <iostream>
#include "Person.h"
#ifndef FINAL_PROJECT_INFO_H
#define FINAL_PROJECT_INFO_H

using namespace std;
class Info: public Person {
private:
    int age;
    string sex;
    string pass;
    int regisnum;
    string about;
    string requirements;
public:
    Info();
    Info(string newpass, string newname, string newsurname, int newage, string newsex, int newregisnum, string newabout, string newrequirements);
    friend ostream& operator << (ostream &os, const Info &obj);
    friend istream& operator >> (istream &is, Info &obj);
    virtual ~Info(){
    };
};


#endif //FINAL_PROJECT_INFO_H
