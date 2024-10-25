#include <iostream>
#include "Person.h"
#ifndef FINAL_PROJECT_INFO_H
#define FINAL_PROJECT_INFO_H

using namespace std;
class User: public Person {
private:
    int age;
    string sex;
    string pass;
    int regisnum;
    string about;
    string requirements;
    std::string registrationDate;
    string status;
public:
    User();
    User(string newname, string newsurname);
    User(string newpass, string newname, string newsurname, int newage, string newsex, int newregisnum, string newregistrationdate, string newstatus, string newabout, string newrequirements);

    // Конструктор копіювання
    User(const User &other);

    // Конструктор переміщення
    User(User &&other) noexcept;

    User& operator=(const User &other);

// Оператор присвоєння переміщенням
    User& operator=(User &&other) noexcept;
    // Гетери
    string get_name() override;
    string get_surname() override;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] string getSex() const;
    [[nodiscard]] string getPass() const;
    [[nodiscard]] int getRegisnum() const;
    [[nodiscard]] string getAbout() const;
    [[nodiscard]] string getRequirements() const;
    [[nodiscard]] string getRegistrationDate() const;
    [[nodiscard]] string getStatus() const;

    void writeInstructions(const string &text) override {
        cout << "Something good" << endl;
    }
    // Сетери
    void set_name(string& new_name) override;
    void set_surname(string& new_surname) override;
    void setAge(int newage);
    void setSex(const string &newsex);
    void setPass(const string &newpass);
    void setRegisnum(int newregisnum);
    void setAbout(const string &newabout);
    void setRequirements(const string &newrequirements);
    void setRegistrationDate(const string &newrequirements);
    void setStatus(const string &newstatus);

    void printAll();
    int subtractFromAge();
    int addToAge();
    // Оператор виводу
    friend ostream& operator<<(ostream &os, const User &obj);

    // Оператор вводу
    friend istream& operator>>(istream &is, User &user);

    // Деструктор
    ~User() override;
};


#endif //FINAL_PROJECT_INFO_H
