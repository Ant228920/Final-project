#include "User.h"
#include <fstream>
#include <utility>

User::User() : Person(), age(0), sex(""), pass(""), regisnum(0), about(""), requirements("") {}

User::User(string newname, string newsurname)
        : Person(newname, newsurname){}
User::User(string newpass, string newname, string newsurname, int newage, string newsex, int newregisnum, string newregistrationdate, string newstatus, string newabout, string newrequirements)
        : Person(newname, newsurname), age(newage), sex(std::move(newsex)), pass(std::move(newpass)), regisnum(newregisnum), registrationDate(std::move(newregistrationdate)), status(std::move(newstatus)), about(std::move(newabout)), requirements(std::move(newrequirements)) {}

User::User(const User &other)
        : Person(other), age(other.age), sex(other.sex), pass(other.pass), regisnum(other.regisnum), registrationDate(other.registrationDate), status(other.status), about(other.about), requirements(other.requirements) {
}

User::User(User &&other) noexcept
        : Person(std::move(other)), age(other.age), sex(std::move(other.sex)), pass(std::move(other.pass)), regisnum(other.regisnum),  registrationDate(std::move(other.registrationDate)),  status(std::move(other.status)), about(std::move(other.about)), requirements(std::move(other.requirements)) {
    other.age = 0;
    other.regisnum = 0;
}

User& User::operator=(const User &other) {
    if (this == &other) {
        return *this;
    }

    this->age = other.age;
    this->sex = other.sex;
    this->pass = other.pass;
    this->regisnum = other.regisnum;
    this->about = other.about;
    this->requirements = other.requirements;
    this->registrationDate = other.registrationDate;
    this->status = other.status;

    Person::operator=(other);
    return *this;
}

User& User::operator=(User &&other) noexcept {
    if (this == &other) {
        return *this;
    }

    this->age = other.age;
    this->sex = std::move(other.sex);
    this->pass = std::move(other.pass);
    this->regisnum = other.regisnum;
    this->about = std::move(other.about);
    this->requirements = std::move(other.requirements);
    this->registrationDate = std::move(other.registrationDate);
    this->status = std::move(other.status);

    Person::operator=(std::move(other));

    return *this;
}

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

string User::getStatus() const{
    return status;
}

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
void User::setStatus(const string &newstatus) {
    status = newstatus;
}

ostream& operator<<(ostream &os, const User &obj) {
        os << obj.pass << endl
       << static_cast<const Person&>(obj) << endl
       << obj.age << endl
       << obj.sex << endl
       << obj.regisnum << endl
       << obj.registrationDate << endl
       << obj.status << endl
       << obj.about << endl
       << obj.requirements << endl;
    return os;
}
void User::printAll(){
    cout << "Name: " << get_name() << endl;
    cout << "Surname: " << get_surname() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Sex: " << getSex() << endl;
    cout << "Registration number: " << getRegisnum() << endl;
    cout << "About: " << getAbout() << endl;
    cout << "Requirements: " << getRequirements() << endl;
}
int User::subtractFromAge() const {
    int substract;
    substract = age - 3;
    if (substract < 0) substract = 0;
    return substract;
}

int User::addToAge() const {
    int add;
     add = age+3;
    return add;
}

istream& operator>>(std::istream& is, User& user) {
    is >> user.pass >> static_cast<Person &>((Person &) user) >> user.age >> user.sex >> user.regisnum >> user.registrationDate >> user.status;
    is.ignore();
    std::getline(is, user.about);
    std::getline(is, user.requirements);
    return is;
}

User::~User() noexcept {
    ofstream fout("files\\log.txt", ios_base::app);
    fout << "user destructor" << endl;
    fout.close();
}
