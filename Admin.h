#include <iostream>
#include "Person.h"
#ifndef FINAL_PROJECT_ADMIN_H
#define FINAL_PROJECT_ADMIN_H

using namespace std;
class Admin : public Person{
private:
    string password;
    int reports;
public:
    Admin();
    Admin(string newname, string newsurname, string newpassword, int newreports);
    friend ostream& operator << (ostream &os,const Admin &obj);
    ~Admin(){}
};


#endif //FINAL_PROJECT_ADMIN_H
