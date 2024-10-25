#include "Person.h"
#include <fstream>
// Конструктор за замовчуванням
Person::Person() : name("None"), surname("None") {}

// Параметризований конструктор (ім'я та прізвище)
Person::Person(string& new_name, string& new_surname)
        : name{new_name}, surname{new_surname}{}
Person::Person(const Person& other)
        : name{other.name}, surname{other.surname} {}

Person::Person(Person&& other) noexcept
        : name{std::move(other.name)}, surname{std::move(other.surname)} {}

// Оператор присвоєння копіюванням
Person& Person::operator=(const Person &other) {
    if (this == &other) {
        return *this; // Перевірка на самоприсвоєння
    }

    // Присвоєння полів
    this->name = other.name;
    this->surname = other.surname;

    return *this;
}

// Оператор присвоєння переміщенням
Person& Person::operator=(Person &&other) noexcept {
    if (this == &other) {
        return *this; // Перевірка на самоприсвоєння
    }

    // Переміщення полів
    this->name = std::move(other.name);
    this->surname = std::move(other.surname);

    return *this;
}

// Сетери
void Person::set_name(string &new_name) {
    this->name = new_name;
}

void Person::set_surname(string &new_surname) {
    this->surname = new_surname;
}
// Гетери
string Person::get_name() {
    return name;
}

string Person::get_surname() {
    return surname;
}

// Оператор виводу
ostream& operator<<(ostream &os, const Person &obj) {
    os << obj.name << endl << obj.surname;
    return os;
}

// Оператор вводу
istream& operator>>(istream &is, Person &obj) {
    is >> obj.name;
    is >> obj.surname;
    return is;
}

// Метод друку

// Деструктор
Person::~Person() {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\log.txt)", ios_base::app);
    fout << name << "destructor"<<endl;
    fout.close();
}
