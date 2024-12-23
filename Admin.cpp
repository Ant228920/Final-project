#include "Admin.h"
#include <fstream>
Admin::Admin() : Person(), password("None") {}

Admin::Admin(string newname, string newsurname, string newpassword)
        : Person(newname, newsurname), password(newpassword){}

Admin::Admin(const Admin &other)
        : Person(other), password(other.password) {
}

Admin::Admin(Admin &&other) noexcept
        : Person(std::move(other)), password(std::move(other.password)) {
    other.password = "";
}

void Admin::setPassword(string &newpassword) {
    password = newpassword;
}

string Admin::get_name() {
    return Person::get_name();
}

string Admin::get_surname() {
    return Person::get_surname();
}
string Admin::getPassword() const {
    return password;
}

ostream& operator<<(ostream &os, const Admin &obj) {
    os << static_cast<Person &>((Person &) obj) << endl << obj.password;
    return os;
}

istream& operator>>(istream& is, Admin& admin) {
    is >> static_cast<Person &>((Person &) admin) >> admin.password;
    return is;
}

Admin::~Admin() noexcept {
    ofstream fout("files\\log.txt", ios_base::app);
    fout << "admin destructor" << endl;
    fout.close();
}
