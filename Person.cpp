#include "Person.h"
#include <iostream>
using namespace std;
Person::Person()
        : name("None"),surname("None"){}
Person::Person(string newname)
        : name{newname}, surname{"None"}{}
Person::Person(string newname, string newsurname)
        : name{newname}, surname{newsurname}{}
ostream &operator << (ostream &os, const Person &obj){
    os<<obj.name<<endl<<obj.surname<<endl;
    return os;
}
istream& operator>>(std::istream& is, Person& obj) {
    is >> obj.name >> obj.surname ;
    is.ignore(); // Пропускаємо пробіл або новий рядок перед зчитуванням `about`
    return is;
}
 string Person::GetName(){
    return name;
}