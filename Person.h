#include <iostream>
#include "Instructions.h"
#include <fstream>
#ifndef FINAL_PROJECT_PERSON_H
#define FINAL_PROJECT_PERSON_H


using namespace std;
class Person : public Instructions {
private:
    string name;
    string surname;
public:
    Person();
    Person(string& newname, string& newsurname);

    Person(const Person &other);

    Person(Person &&other) noexcept;

    Person& operator=(const Person &other);

    Person& operator=(Person &&other) noexcept;

    virtual string get_name()=0;
    virtual string get_surname()=0;

    virtual void set_name(string& new_name);
    virtual void set_surname(string& new_surname);

    friend ostream& operator<<(ostream &os, const Person &obj);

    friend istream& operator>>(istream &is, Person &obj);

    void writeText(const string &filePath) override {}

    virtual ~Person();
};

#endif //FINAL_PROJECT_PERSON_H
