#include "User.h"
#include <fstream>
#include <utility>

// Конструктор за замовчуванням
User::User() : Person(), age(0), sex(""), pass(""), regisnum(0), about(""), requirements("") {}

// Параметризований конструктор
User::User(string newname, string newsurname)
        : Person(newname, newsurname) {};
User::User(string newpass, string newname, string newsurname, int newage, string newsex, int newregisnum, string newabout, string newrequirements, string newregistrationdate)
        : Person(newname, newsurname), age(newage), sex(std::move(newsex)), pass(std::move(newpass)), regisnum(newregisnum), about(std::move(newabout)), requirements(std::move(newrequirements)), registrationDate(std::move(newregistrationdate)) {}

// Конструктор копіювання
User::User(const User &other)
        : Person(other), age(other.age), sex(other.sex), pass(other.pass), regisnum(other.regisnum), about(other.about), requirements(other.requirements) {
}

// Конструктор переміщення
User::User(User &&other) noexcept
        : Person(std::move(other)), age(other.age), sex(std::move(other.sex)), pass(std::move(other.pass)), regisnum(other.regisnum), about(std::move(other.about)), requirements(std::move(other.requirements)) {
    other.age = 0;
    other.regisnum = 0;
}

// Гетери
string User::get_name() {
    return Person::get_name();
}

string User::get_surname() {
    return Person::get_surname();
}
int User::getAge() const {
    return age;
}

string User::getSex() const {
    return sex;
}

string User::getPass() const {
    return pass;
}

int User::getRegisnum() const {
    return regisnum;
}

string User::getAbout() const {
    return about;
}

string User::getRequirements() const {
    return requirements;
}
string User::getRegistrationDate() const {
    return registrationDate;
}
// Сетери
void User::set_name(string &newname) {
    Person::set_name(newname);
}

void User::set_surname(string &newsurname) {
    Person::set_surname(newsurname);
}
void User::setAge(int newage) {
    age = newage;
}

void User::setSex(const string &newsex) {
    sex = newsex;
}

void User::setPass(const string &newpass) {
    pass = newpass;
}

void User::setRegisnum(int newregisnum) {
    regisnum = newregisnum;
}

void User::setAbout(const string &newabout) {
    about = newabout;
}

void User::setRequirements(const string &newrequirements) {
    requirements = newrequirements;
}

void User::setRegistrationDate(const string &newregistrationDate) {
    registrationDate = newregistrationDate;
}
// Оператор виводу
ostream& operator<<(ostream &os, const User &obj) {
    os <<obj.pass << endl << static_cast<const Person&>(obj) << endl << obj.age << endl << obj.sex << endl
        << obj.regisnum << endl << obj.about << endl
        << obj.requirements << endl
        <<obj.registrationDate << endl;
    return os;
}

// Оператор вводу
istream& operator>>(std::istream& is, User& user) {
    is >> user.pass >> static_cast<Person &>((Person &) user) >> user.age >> user.sex >> user.regisnum;
    is.ignore(); // Ігноруємо символ нової строки після регіснума
    std::getline(is, user.about);
    std::getline(is, user.requirements);
    is >> user.registrationDate;
    return is;
}



// Деструктор
User::~User() noexcept {
    ofstream fout(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
    fout << "car destructor" << endl;
    fout.close();
}
