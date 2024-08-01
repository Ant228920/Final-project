#include "Admin.h"

Admin::Admin()
        : Person(), password("None"), reports(0){}
Admin::Admin(string newname, string newsurname, string newpassword, int newreports)
        : Person(newname, newsurname), password{newpassword}, reports(newreports){}
ostream &operator << (ostream &os, const Admin &obj){
    os<<static_cast<const Person&>(obj)<<obj.password<<endl<<obj.reports<<endl;
    return os;
}