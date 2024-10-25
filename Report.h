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

    [[nodiscard]] string getName() const;
    [[nodiscard]] string getAbout() const;

    void setName(const string &newname);
    void setAbout(const string &newabout);

    Report(const Report &other);

    Report(Report &&other) noexcept;

    friend ostream& operator << (ostream &os, const Report &obj);
    friend istream& operator>>(istream &is, Report &obj);

    virtual ~Report();
};


#endif //FINAL_PROJECT_REPORT_H
