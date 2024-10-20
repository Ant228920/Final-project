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
    Person(string& newname, string& newsurname);

    // Конструктор копіювання
    Person(const Person &other);

    // Конструктор переміщення
    Person(Person &&other) noexcept;

    // Сетери
    virtual string get_name()=0;
    virtual string get_surname()=0;

    // Гетери
    virtual void set_name(string& new_name);
    virtual void set_surname(string& new_surname);

    // Оператор виводу
    friend ostream& operator<<(ostream &os, const Person &obj);

    // Оператор вводу
    friend istream& operator>>(istream &is, Person &obj);

    // Інші методи
    void Print();

    // Деструктор
    virtual ~Person();
};




#endif //FINAL_PROJECT_PERSON_H
