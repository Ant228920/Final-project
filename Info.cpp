#include "Info.h"
#include <vector>
#include <iostream>

Info::Info()
        : pass("None"),Person(), regisnum(0), about("None"), requirements("None"){}
Info::Info(string newpass, string newname, string newsurname, int newage, string newsex, int newregisnum, string newabout, string newrequirements)
        : pass{newpass},Person(newname, newsurname, newage, newsex), regisnum{newregisnum}, about{newabout}, requirements{newrequirements}{}
ostream &operator << (ostream &os, const Info &obj){
    os<<obj.pass<<endl<<static_cast<const Person&>(obj)<<obj.regisnum<<endl<<obj.about<<endl<<obj.requirements<<endl;
    return os;
}
std::istream& operator>>(std::istream& is, Info& obj) {
    is >> obj.pass >> static_cast<Person&>(obj) >> obj.regisnum;
    is.ignore(); // Пропускаємо пробіл або новий рядок перед зчитуванням `about`
    std::getline(is, obj.about, ';');
    std::getline(is, obj.requirements, ';');
    return is;
}
