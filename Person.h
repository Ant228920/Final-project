#include <iostream>
#ifndef FINAL_PROJECT_PERSON_H
#define FINAL_PROJECT_PERSON_H


using namespace std;
class Person {
private:
    string name;
    string surname;
public:
    Person();
    Person(string newname);
    Person(string newname, string newsurname);
    friend ostream& operator << (ostream &os, const Person &obj);
    friend istream& operator >> (istream &is, Person &obj);
    virtual ~Person(){};
    string GetName();
    void Print();
};




#endif //FINAL_PROJECT_PERSON_H
