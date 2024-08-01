#include "Report.h"

Report::Report()
        : name("None"),about("None"){}
Report::Report(string newname, string newabout)
        : name{newname}, about{newabout}{}
ostream &operator << (ostream &os, const Report &obj){
    os<<obj.name<<endl<<obj.about<<endl;
    return os;
}
