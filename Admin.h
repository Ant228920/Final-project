#include <iostream>
#include "Person.h"

#ifndef FINAL_PROJECT_ADMIN_H
#define FINAL_PROJECT_ADMIN_H

using namespace std;

class Admin : public Person {
private:
    string password;
public:
    Admin();
    Admin(string newname, string newsurname, string newpassword);

    Admin(const Admin &other);
    Admin(Admin &&other) noexcept;

    void setPassword(string &newpassword);

    string get_name() override;
    string get_surname() override;
    [[nodiscard]] string getPassword() const;

    friend ostream& operator<<(ostream &os, const Admin &obj);
    friend istream& operator>>(istream &is, Admin &obj);

    ~Admin() override;
};

#endif // FINAL_PROJECT_ADMIN_H
