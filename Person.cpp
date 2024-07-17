#include "Person.h"
#include <iostream>
using namespace std;
Person::Person()
        : name("None"),surname("None"), age(0), sex("None"){}
Person::Person(string newname)
        : name{newname}, surname{"None"}, age{0},  sex{"None"}{}
Person::Person(string newname, string newsurname)
        : name{newname}, surname{newsurname}, age{0}, sex{"None"}{}
Person::Person(string newname, string newsurname, int newage)
        : name{newname}, surname{newsurname}, age{newage}, sex{"None"}{}
Person::Person(string newname, string newsurname, int newage, string newsex)
        : name{newname}, surname{newsurname}, age{newage}, sex{newsex}{}
ostream &operator << (ostream &os, const Person &obj){
    os<<obj.name<<endl<<obj.surname<<endl<<obj.age<<endl<<obj.sex<<endl;
    return os;
}
istream& operator>>(std::istream& is, Person& obj) {
    is >> obj.name >> obj.surname  >> obj.age >> obj.sex;
    is.ignore(); // Пропускаємо пробіл або новий рядок перед зчитуванням `about`
    return is;
}
 string Person::GetName(){
    return name;
}