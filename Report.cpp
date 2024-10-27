#include "Report.h"
#include <utility>
#include <fstream>
Report::Report() : name("None"), about("None") {}

Report::Report(string newname) : name(std::move(newname)), about("None") {}

Report::Report(string newname, string newabout) : name(std::move(newname)), about(std::move(newabout)) {}

string Report::getName() const {
    return name;
}

string Report::getAbout() const {
    return about;
}

void Report::setName(const string &newname) {
    name = newname;
}

void Report::setAbout(const string &newabout) {
    about = newabout;
}

Report::Report(const Report &other) : name(other.name), about(other.about) {}

Report::Report(Report &&other) noexcept : name(std::move(other.name)), about(std::move(other.about)) {}

ostream& operator << (ostream &os, const Report &obj) {
    os << obj.name << endl << obj.about << endl;
    return os;
}
istream& operator>>(std::istream& is, Report& user) {
    is >> user.name;
    is.ignore();
    std::getline(is, user.about);
    return is;
}

Report::~Report() noexcept {
    ofstream fout(R"(D:\oop labs\final project\files\log.txt)", ios_base::app);
    fout << "report destructor" << endl;
    fout.close();
}
