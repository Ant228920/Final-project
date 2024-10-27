#include "Person.h"
#include <fstream>

Person::Person() : name("None"), surname("None") {}

Person::Person(string& new_name, string& new_surname)
        : name{new_name}, surname{new_surname}{}
Person::Person(const Person& other)
        : name{other.name}, surname{other.surname} {}

Person::Person(Person&& other) noexcept
        : name{std::move(other.name)}, surname{std::move(other.surname)} {}

Person& Person::operator=(const Person &other) {
    if (this == &other) {
        return *this;
    }

    this->name = other.name;
    this->surname = other.surname;

    return *this;
}

Person& Person::operator=(Person &&other) noexcept {
    if (this == &other) {
        return *this;
    }

    this->name = std::move(other.name);
    this->surname = std::move(other.surname);

    return *this;
}

void Person::set_name(string &new_name) {
    this->name = new_name;
}

void Person::set_surname(string &new_surname) {
    this->surname = new_surname;
}

string Person::get_name() {
    return name;
}

string Person::get_surname() {
    return surname;
}

ostream& operator<<(ostream &os, const Person &obj) {
    os << obj.name << endl << obj.surname;
    return os;
}

istream& operator>>(istream &is, Person &obj) {
    is >> obj.name;
    is >> obj.surname;
    return is;
}

Person::~Person() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\log.txt)", ios_base::app);
    fout << name << "destructor"<<endl;
    fout.close();
}
