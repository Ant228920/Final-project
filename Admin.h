#include <iostream>
#include "Person.h"

#ifndef FINAL_PROJECT_ADMIN_H
#define FINAL_PROJECT_ADMIN_H

using namespace std;

class Admin : public Person {
private:
    string password;
public:
    // Конструктори
    Admin();
    Admin(string newname, string newsurname, string newpassword);

    // Конструктор копіювання
    Admin(const Admin &other);

    // Конструктор переміщення
    Admin(Admin &&other) noexcept;

    // Сетери
    void setPassword(const string &newpassword);

    // Гетери
    string get_name() override;
    string get_surname() override;
    [[nodiscard]] string getPassword() const;

    // Оператор виводу
    friend ostream& operator<<(ostream &os, const Admin &obj);
    friend istream& operator>>(istream &is, Admin &obj);

    // Деструктор
    ~Admin() override;
};

#endif // FINAL_PROJECT_ADMIN_H
