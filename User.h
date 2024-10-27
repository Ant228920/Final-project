#include <iostream>
#include "Person.h"
#include "Instructions.h"
#include <fstream>
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

    User(const User &other);

    User(User &&other) noexcept;

    User& operator=(const User &other);
    User& operator=(User &&other) noexcept;

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

    void writeText(const string &filePath) override {
        ifstream file(filePath);

        if (!file.is_open()) {
            cerr << "Error: could not open the file." << endl;
            return;
        }

        string line;
        while (getline(file, line)) {  // Зчитуємо кожен рядок
            cout << line << endl;      // Виводимо рядок на екран
        }

        file.close();
    }

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

    friend ostream& operator<<(ostream &os, const User &obj);

    friend istream& operator>>(istream &is, User &user);

    ~User() override;
};


#endif //FINAL_PROJECT_INFO_H
