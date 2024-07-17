#include <iostream>
#ifndef FINAL_PROJECT_PERSON_H
#define FINAL_PROJECT_PERSON_H


using namespace std;
class Person {
private:
    string name;
    string surname;
    int age;
    string sex;
public:
    Person();
    Person(string newname);
    Person(string newname, string newsurname);
    Person(string newname, string newsurname, int newage);
    Person(string newname, string newsurname, int newage, string newsex);
    friend std::ostream& operator<<(std::ostream &os, const Person &obj);
    friend istream& operator >>(istream &is, Person &obj);
    ~Person(){};
    string GetName();
};




#endif //FINAL_PROJECT_PERSON_H
