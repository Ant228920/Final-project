#include <iostream>
#ifndef FINAL_PROJECT_REPORT_H
#define FINAL_PROJECT_REPORT_H

using namespace std;
class Report {
private:
    string name;
    string about;
public:
    Report();
    Report(string newname);
    Report(string newname, string newabout);
    friend ostream& operator << (ostream &os, const Report &obj);
    ~Report(){};
};


#endif //FINAL_PROJECT_REPORT_H
