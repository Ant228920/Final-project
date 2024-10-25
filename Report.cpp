#include "Report.h"

#include <utility>
#include <fstream>
// Конструктор за замовчуванням
Report::Report() : name("None"), about("None") {}

// Конструктор з одним параметром
Report::Report(string newname) : name(std::move(newname)), about("None") {}

// Конструктор з двома параметрами
Report::Report(string newname, string newabout) : name(newname), about(newabout) {}

// Геттер для поля name
string Report::getName() const {
    return name;
}

// Геттер для поля about
string Report::getAbout() const {
    return about;
}

// Сеттер для поля name
void Report::setName(const string &newname) {
    name = newname;
}

// Сеттер для поля about
void Report::setAbout(const string &newabout) {
    about = newabout;
}


// Конструктор копіювання
Report::Report(const Report &other) : name(other.name), about(other.about) {}

// Конструктор переміщення
Report::Report(Report &&other) noexcept : name(move(other.name)), about(move(other.about)) {}

// Оператор виводу
ostream& operator << (ostream &os, const Report &obj) {
    os << obj.name << endl << obj.about << endl;
    return os;
}
istream& operator>>(istream& is, Report& report) {
    string name, about;

    // Зчитуємо дані з потоку
    if (is >> name) {
        is.ignore(); // Ігноруємо зайві символи після імені
        getline(is, about); // Зчитуємо весь рядок для about
    }

    // Встановлюємо значення через сетери
    report.setName(name);;

    return is;
}


// Деструктор
Report::~Report() noexcept {
    ofstream fout(R"(D:\oop labs\final project\files\log.txt)", ios_base::app);
    fout << "report destructor" << endl;
    fout.close();
}
