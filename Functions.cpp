#include "User.h"
#include "Person.h"
#include "Admin.h"
#include "Report.h"
#include "Banned.h"
#include "Exception.h"
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <fstream>
#include <limits>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
using namespace std;

//struct AccountsResult {
//    std::vector<Info> accounts;
//    size_t size;
//};
//std::vector<Info> LoadAccounts() {
//    std::vector<Info> accounts;
//    std::ifstream fileIn(R"(D:\oop labs\final project\files\Info.txt)",
//                         std::ios_base::in);
//    if (!fileIn.is_open()) {
//        std::cerr << "Error opening file: "  << std::endl;
//        return accounts;
//    }
//
//    Info account;
//    while (fileIn >> account) {
//        accounts.push_back(account);
//        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропускаємо розділову лінію
//    }
//
//    fileIn.close();
//    return accounts;
//}
template <typename T>
static T get_input(T& value) {
    while (true) {
        cin>>value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter a value of the correct type." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}
std::string getCurrentDateTime() {
    // Отримуємо поточний час
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

    // Створюємо буфер для форматування часу
    char buffer[80];
    // Форматуємо час у вигляді "YYYY-MM-DD HH:MM:SS"
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&timeNow));

    // Повертаємо форматовану строку
    return std::string(buffer);
}
void SignIn() {

    std::cout << "OK, write down the information" << std::endl;
    int choice;
    std::shared_ptr<std::string> newpass{new std::string{""}};
    std::cout << "Enter your new password:";
    std::cin >> *newpass;

    std::shared_ptr<std::string> name{new std::string{""}};
    std::cout << "Enter your name:";
    cin >> *name;


    std::shared_ptr<std::string> surname{new std::string{""}};
    std::cout << "Enter your surname:";
    std::cin >> *surname;

    std::shared_ptr<int> age{new int{0}};
    std::cout << "Enter your age:";
    get_input(*age);

    std::shared_ptr<std::string> sex{new std::string{""}};
    std::cout << "Choose your sex:" << endl << "1 - Male" << endl << "2 - Female" << endl;
    std::cin >> choice;
    try {
        switch (choice) {
            case 1:
                *sex = "Male";
                break;
            case 2:
                *sex = "Female";
                break;
            default:
                throw Exception();
        }
    } catch (const std::invalid_argument& ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::shared_ptr<int> regisnum{new int{0}};
    std::cout << "Enter your registrational number:";
    std::cin >> *regisnum;
    get_input(*regisnum);

    std::shared_ptr<std::string> about{new std::string{""}};
    std::cout << "Enter something about yourself:";
    cin.ignore();
    getline(cin, *about);

    std::shared_ptr<std::string> requirements{new std::string{""}};
    std::cout << "Enter your requirements:";
    getline(cin, *requirements);

    std::shared_ptr<std::string> reppass{new std::string{""}};
    std::cout << "Now please repeat your password:";
    do {
        std::cin >> *reppass;
    } while (*reppass != *newpass);
    std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
    // Передаємо дату реєстрації в об'єкт User (припустимо, що його конструктор підтримує це поле)
    User newAccount(*newpass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);

    std::ofstream fileOut(R"(D:\oop labs\final project\files\Selected.txt)",
                         ios_base::app);

    fileOut<<newAccount<<endl;
    cout<<"----------------------" << endl;
    fileOut.close();

}

bool IsEmpty(){
    ifstream fin(R"(D:\oop labs\final project\files\Couples.txt)", ios::binary | ios::ate);
    return fin.tellg() == 0;
}
void AdminCreate(){
    cout<<"OK, write down the information"<<endl;
    shared_ptr <string> name {new string {""}};
    cout<<"Enter your new name: ";
    cin>>*name;
    shared_ptr <string> surname {new string {""}};
    cout<<"Enter your surname: ";
    cin>>*surname;
    shared_ptr <string> pass {new string {""}};
    cout<<"Enter password: ";
    cin>>*pass;
    shared_ptr <string> reppass {new string {""}};
    cout<<"Now please repeat your password: ";
    do{
        cin>>*reppass;
    }while(*reppass!=*pass);
    Admin adm(*name, *surname, *pass);
    ofstream foutCA (R"(D:\oop labs\final project\files\Admin.txt)",
                     ios_base::app);
    foutCA<<adm<<endl;
    foutCA.close();

}
bool ExistCheck(){
    ifstream fin(R"(D:\oop labs\final project\files\Admin.txt)",ios_base::app);
    bool T=false;
    if(fin.is_open()){
        string line;
        while(getline(fin, line)) {
            T=true;
        }
        fin.close();
    }
    else{
        cerr << "Error during the opening of the file";
    }
    return T;
}
void AdminDelete() {
    ofstream fin(R"(D:\oop labs\final project\files\Admin.txt)",
                 ios_base::trunc);

    if (fin.is_open()) {
        fin << "";

        fin.close();
        cout << "Your account is successfully deleted"<<endl;
    }
}
void AdminEnter(){
    ifstream fin (R"(D:\oop labs\final project\files\Admin.txt)",ios_base::app);
    shared_ptr<string> name {new string{""}};
    shared_ptr<string> surname {new string{""}};
    shared_ptr<string> pass {new string{""}};
    shared_ptr<string> parol{new string{""}};
    cout<<"Enter your password: ";
    cin>>*parol;
    Admin admin(*name, *surname, *pass);
    while(fin >> admin){
        if(admin.getPassword() == *parol){
            cout<<"Welcome"<<endl;
        }
        else{
            cerr << "Wrong password";
        }
    }
}
void ReadCouples(){
    int i = 1;
    ifstream fin(R"(D:\oop labs\ooplab1\files\Couples.txt)",ios_base::app);
    shared_ptr<string> name{new string {""}};
    shared_ptr<string> givername{new string {""}};
    while(fin >> *name >> *givername) {
        cout << i << "Couple" << *name << "and" << *givername;
        i++;
    }
    fin.close();
}

void Choice(const string& newname) {
    ifstream fin(R"(D:\oop labs\final project\files\Selected.txt)", ios_base::app);
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    } else {
        std::shared_ptr<std::string> newpass{new std::string{""}};

        std::shared_ptr<std::string> name{new std::string{""}};


        std::shared_ptr<std::string> surname{new std::string{""}};


        std::shared_ptr<int> age{new int{0}};


        std::shared_ptr<std::string> sex{new std::string{""}};


        std::shared_ptr<int> regisnum{new int{0}};


        std::shared_ptr<std::string> about{new std::string{""}};

        std::shared_ptr<std::string> requirements{new std::string{""}};
        while (fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum) {
            fin.ignore();

            std::getline(fin, *about);
            std::getline(fin, *requirements);
            ofstream fout(R"(D:\oop labs\final project\files\Match.txt)", ios_base::app);
            fout << newname << " " << *name<<endl;
            fout.close();
        }
        fin.close();
    }
}
void AdminRead(){
    ifstream finE(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    else {
        shared_ptr<string> pass{new string{""}};
        shared_ptr<string> name{new string{""}};
        shared_ptr<string> surname{new string{""}};
        shared_ptr<int> age{new int{0}};
        shared_ptr<string> sex{new string{""}};
        shared_ptr<int> regisnum{new int{0}};
        shared_ptr<string> about{new string{""}};
        shared_ptr<string> requirements{new string{""}};
        while (finE >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum) {
            finE.ignore();

            std::getline(finE, *about);
            std::getline(finE, *requirements);
            cout << "pass: ";
            cout << *pass << endl;
            cout << "name: ";
            cout << *name << endl;
            cout << "surname: ";
            cout << *surname << endl;
            cout << "age: ";
            cout << *age << endl;
            cout << "sex: ";
            cout << *sex << endl;
            cout << "regisnum: ";
            cout << *regisnum << endl;
            cout << "about: ";
            cout << *about << endl;
            cout << "requirements: ";
            cout << *requirements<<endl;
        }
    }
    finE.close();
}
//vector<Info> Vec(vector<Info>& accounts){
//    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
//    if(!fin.is_open()){
//        cerr << "Error" <<endl;
//    }
//    else{
//        std::shared_ptr<std::string> newpass{new std::string{""}};
//
//        std::shared_ptr<std::string> name{new std::string{""}};
//
//        std::shared_ptr<std::string> surname{new std::string{""}};
//
//        std::shared_ptr<int> age{new int{0}};
//
//        std::shared_ptr<std::string> sex{new std::string{""}};
//
//        std::shared_ptr<int> regisnum{new int{0}};
//
//        std::shared_ptr<std::string> about{new std::string{""}};
//
//        std::shared_ptr<std::string> requirements{new std::string{""}};
//       while(fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum){
//           fin.ignore();
//
//           std::getline(fin, *about);
//           std::getline(fin, *requirements);
//           Info acc(*newpass,*name,*surname,*age,*sex,*regisnum,*about,*requirements);
//           accounts.push_back(acc);
//       }
//
//    }
//    return accounts;
//}
void unBan(const string& deletename){
    ifstream fin(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::app);
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    }
    std::shared_ptr<std::string> repname{new std::string{""}};

    std::shared_ptr<std::string> reporttext{new std::string{""}};

    bool found = false;
    vector<pair<string, string >> vec;
    Report rep(*repname, *reporttext);
    while(fin >> rep) {
//        fin.ignore();
//        std::getline(fin, *reporttext);
        if (rep.getName() == deletename) {
            found = true;
        } else {
            vec.emplace_back(rep.getName(), rep.getAbout());
        }
    }
    fin.close();

    if (found) {
        ofstream foutdel(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::trunc);
        for (const auto &record: vec) {
            foutdel << record.first << endl << record.second;
        }
        foutdel.close();
    } else {
        cerr << "Incorrect data" << endl;
    }
}
void Ban(const string& deletename){
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
    shared_ptr<string> pass{new string{""}};
    shared_ptr<string> name{new string{""}};
    shared_ptr<string> surname{new string{""}};
    shared_ptr<int> age{new int{0}};
    shared_ptr<string> sex{new string{""}};
    shared_ptr<int> regisnum{new int{0}};
    shared_ptr<string> about{new string{""}};
    shared_ptr<string> requirements{new string{""}};
    std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
    bool found = false;
    User acc(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
    vector<User> vec;
    while (fin >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum >> *registrationDate) {
        fin.ignore();

        std::getline(fin, *about);
        std::getline(fin, *requirements);
        if (*name == deletename) {
            found = true;
        } else {
            vec.emplace_back(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
        }
    }
    fin.close();

    if (found) {
        ofstream foutdel(R"(D:\oop labs\final project\files\Info.txt)", ios_base::trunc);
        for (const auto &record: vec) {
            foutdel << record << endl;
        }
        foutdel.close();
    } else {
        cerr << "Incorrect data" << endl;
    }
}
void DeleteAcc(){
    ofstream fout(R"(D:\oop labs\final project\files\Selected.txt)", ios_base::trunc);
    fout<<"";
    fout.close();
}
void Reports(string newname) {

            ofstream fout(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::app);
            shared_ptr<string> reporttext{new string{""}};
            cout << "Report" << endl;
            cin.ignore();
            getline(cin, *reporttext);

            Report rep(std::move(newname), *reporttext);
            fout << rep << endl;
            fout.close();

}
void ReportRead() {
    ifstream fin(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::app);
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    } else {

        std::shared_ptr<std::string> repname{new std::string{""}};

        std::shared_ptr<std::string> reporttext{new std::string{""}};

        Report rep(*repname, *reporttext);
        while (fin >> rep) {
//            fin.ignore();
//            std::getline(fin, *reporttext);
            ifstream finAcc(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
            shared_ptr<string> pass{new string{""}};
            shared_ptr<string> name{new string{""}};
            shared_ptr<string> surname{new string{""}};
            shared_ptr<int> age{new int{0}};
            shared_ptr<string> sex{new string{""}};
            shared_ptr<int> regisnum{new int{0}};
            shared_ptr<string> about{new string{""}};
            shared_ptr<string> requirements{new string{""}};
            std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
            User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
            while (finAcc >> user) {
//                finAcc.ignore();
//
//                std::getline(finAcc, *about);
//                std::getline(finAcc, *requirements);

                if (rep.getName() == user.get_name()) {
                    int choice;
                    cout << user;
                    cout << "1 - Ban" << endl << "2 - unBan" << endl;
                    cin >> choice;
                    try {
                        switch (choice) {
                            case 1:
                                Ban(user.get_name());
                                break;
                            case 2:
                                cout << "Skipped" << endl;
                                unBan(user.get_name());
                                break;
                            default:
                                throw Exception();
                        }
                    }
                    catch (Exception &ex){
                        cerr << ex.what() << endl;
                    }
                }

            }
        }
        fin.close();
    }
}
void Show() {
    ifstream finE(R"(D:\oop labs\final project\files\Selected.txt)", ios_base::in);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    else {
        shared_ptr<string> pass{new string{""}};
        shared_ptr<string> name{new string{""}};
        shared_ptr<string> surname{new string{""}};
        shared_ptr<int> age{new int{0}};
        shared_ptr<string> sex{new string{""}};
        shared_ptr<int> regisnum{new int{0}};
        shared_ptr<string> about{new string{""}};
        shared_ptr<string> requirements{new string{""}};
        std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
        User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, * registrationDate);
        while (finE >> user) {
            cout << "pass: " << user.getPass() << endl;
            cout << "name: " << user.get_name() << endl;
            cout << "surname: " << user.get_surname() << endl;
            cout << "age: " << user.getAge() << endl;
            cout << "sex: " << user.getSex() << endl;
            cout << "registration number: " << user.getRegisnum() << endl;
            cout << "about: " << user.getAbout() << endl;
            cout << "requirements: " << user.getRequirements() << endl;
        }
        finE.close();
    }
}

bool Checking(const string& sercname) {
    if (IsEmpty()) {
        return true;
    } else {
        ifstream fin(R"(D:\oop labs\final project\files\Couples.txt)", ios_base::app);
        if (!fin.is_open()) {
            cerr << "Error opening file: " << endl;
        } else {
            shared_ptr<string> receivename{new string{""}};
            shared_ptr<string> givername{new string{""}};
            while (fin >> *receivename >> *givername) {
                ifstream finS(R"(D:\oop labs\final project\files\Selected.txt)", ios_base::app);
                shared_ptr<string> pass{new string{""}};
                shared_ptr<string> name{new string{""}};
                shared_ptr<string> surname{new string{""}};
                shared_ptr<int> age{new int{0}};
                shared_ptr<string> sex{new string{""}};
                shared_ptr<int> regisnum{new int{0}};
                shared_ptr<string> about{new string{""}};
                shared_ptr<string> requirements{new string{""}};
                std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
                User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
                while (finS >> user) {
//                    finS.ignore();
//
//                    std::getline(finS, *about);
//                    std::getline(finS, *requirements);
                    if (*receivename == sercname && *givername == user.get_name() || *receivename == user.get_name() && *givername == sercname) {
                        return false;
                    }
                }
                finS.close();
            }
            fin.close();
        }
    }
    return true;
}
void Read() {
    ifstream finE(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    } else {
        int num;
        shared_ptr<string> pass{new string{""}};
        shared_ptr<string> name{new string{""}};
        shared_ptr<string> surname{new string{""}};
        shared_ptr<int> age{new int{0}};
        shared_ptr<string> sex{new string{""}};
        shared_ptr<int> regisnum{new int{0}};
        shared_ptr<string> about{new string{""}};
        shared_ptr<string> requirements{new string{""}};
        shared_ptr<string> search{new string{""}};
        std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
        User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
        cout << "Are you looking for man of female?" << endl;
        cout << "1 - Male" << endl << "2 - Female" << endl << "3 - Don't care" << endl;
        cin >> num;
        try{
            switch (num) {
                case 1:
                    *search = "Male";
                    break;
                case 2:
                    *search = "Female";
                    break;
                default:
                   throw Exception();
        }
        cout << "1 - To like" << endl << "2 - To skip" << endl << "3 - To report" << endl;
        while (finE >> user) {
//            finE.ignore();
//
//            std::getline(finE, *about);
//            std::getline(finE, *requirements);
            if (*search == user.getSex()) {
                if (Checking(user.get_name())) {
                    int choice;
                    cout << user << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "Like received" << endl;
                            Choice(user.get_name());
                            break;
                        case 2:
                            cout << "Skipped" << endl;
                            break;
                        case 3:
                            Reports(user.get_name());
                            break;
                        default:
                            throw Exception();
                    }
                }
            }
          }
        }
        catch (Exception &ex) {
            cerr << ex.what() << endl;
        }
        finE.close();
    }
}
    void Conformation(const string& givename, const string& receivename) {
        ifstream fin(R"(D:\oop labs\final project\files\Match.txt)", ios_base::app);
        shared_ptr<string> name{new string{""}};
        shared_ptr<string> secname{new string{""}};
        bool found = false;
        vector<User> vec;
        while (fin >> *name >> *secname) {
            if (*name == receivename && *secname == givename) {
                found = true;
                ofstream fout(R"(D:\oop labs\final project\files\Couples.txt)", ios_base::app);
                fout << receivename << endl << givename << endl;
                fout.close();
            } else {
                vec.emplace_back(*name, *secname);
            }
        }
        fin.close();

        if (found) {
            ofstream foutdel(R"(D:\oop labs\final project\files\Match.txt)", ios_base::trunc);
            for (const auto &record: vec) {
                foutdel << record << endl;
            }
            foutdel.close();
        } else {
            cerr << "Incorrect data" << endl;
        }
    }

void Notifications() {
    ifstream fin(R"(D:\oop labs\final project\files\Selected.txt)");
    if (!fin.is_open()) {
        std::cout << "Error opening file for reading: Selected.txt" << std::endl;
        return;
    }

    shared_ptr<string> pass{new string{""}};
    shared_ptr<string> name{new string{""}};
    shared_ptr<string> surname{new string{""}};
    shared_ptr<int> age{new int{0}};
    shared_ptr<string> sex{new string{""}};
    shared_ptr<int> regisnum{new int{0}};
    shared_ptr<string> about{new string{""}};
    shared_ptr<string> requirements{new string{""}};
    std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
    User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
    while (fin >> user) {
//        fin.ignore();
//
//        std::getline(fin, *about);
//        std::getline(fin, *requirements);
        ifstream finE(R"(D:\oop labs\final project\files\Match.txt)");
        if (!finE.is_open()) {
            std::cout << "Error opening file for reading: Match.txt" << std::endl;
            return;
        }

        shared_ptr<string> receivename{new string{""}};
        shared_ptr<string> givename{new string{""}};

        while (finE >> *receivename >> *givename) {
            if (user.get_name() == *receivename) {
                ifstream finS(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
                while (finS >> user) {
//                    finS.ignore();
//
//                    std::getline(finS, *about);
//                    std::getline(finS, *requirements);
                    if (user.get_name() == *givename) {
                        cout << "You received a like!" << endl;
                        cout << "name: ";
                        cout << user.get_name() << endl;
                        cout << "surname: ";
                        cout << user.get_surname() << endl;
                        cout << "age: ";
                        cout << user.getAge() << endl;
                        cout << "sex: ";
                        cout << user.getSex() << endl;
                        cout << "registration number: ";
                        cout << user.getRegisnum() << endl;
                        cout << "about: ";
                        cout << user.getAbout() << endl;
                        cout << "requirements: ";
                        cout << user.getRequirements() << endl;
                    }
                    else{
                        cout<<"No notifications";
                    }
                }
                finS.close();
                cout << "1 - Like" << endl << "2 - Skip" << endl;
                int choice;
                cin >> choice;
                        switch (choice) {
                            case 1:
                                cout << "Liked received" << endl;
                                Conformation(*givename, *receivename);
                                break;
                            case 2:
                                cout << "Skipped" << endl;
                                break;
                            default:
                                cerr << "Wrong choice" << endl;
                        }
                }
            }
            finE.close();
        }
        fin.close();
}
void Exit() {
    std::ifstream fin(R"(D:\oop labs\final project\files\Selected.txt)");
    if (!fin.is_open()) {
        std::cout << "Error opening file for reading: Selected.txt" << std::endl;
        return;
    }

    shared_ptr<string> pass{new string{""}};
    shared_ptr<string> name{new string{""}};
    shared_ptr<string> surname{new string{""}};
    shared_ptr<int> age{new int{0}};
    shared_ptr<string> sex{new string{""}};
    shared_ptr<int> regisnum{new int{0}};
    shared_ptr<string> about{new string{""}};
    shared_ptr<string> requirements{new string{""}};
    std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
    std::ofstream fout(R"(D:\oop labs\final project\files\Info.txt)", std::ios_base::app);
    if (!fout.is_open()) {
        std::cout << "Error opening file for writing: Info.txt" << std::endl;
        return;
    }
    User user(*pass,*name,*surname,*age,*sex,*regisnum,*about, *requirements, *registrationDate);
    while (fin >> user) {
//        fin.ignore();
//
//        std::getline(fin, *about);
//        std::getline(fin, *requirements);

        fout << user << endl;
    }

    fin.close();
    fout.close();

    std::ofstream foutsel(R"(D:\oop labs\final project\files\Selected.txt)", std::ios_base::trunc);
    if (!foutsel.is_open()) {
        std::cout << "Error opening file for clearing: Selected.txt" << std::endl;
        return;
    }
    foutsel.close();
}

bool LogIn() {
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)"); // Видалено ios_base::app
    if (!fin.is_open()) {
        cerr << "Error" << endl;
        return false;
    } else {
        std::cout << "OK, write down the information" << std::endl;

        shared_ptr<string> pass{new string{""}};
        cout << "Enter password:";
        cin >> *pass;
        shared_ptr<string> newname{new string{""}};
        cout << "Enter name:";
        cin >> *newname;

        std::shared_ptr<std::string> newpass{new std::string{""}};
        std::shared_ptr<std::string> name{new std::string{""}};
        std::shared_ptr<std::string> surname{new std::string{""}};
        std::shared_ptr<int> age{new int{0}};
        std::shared_ptr<std::string> sex{new std::string{""}};
        std::shared_ptr<int> regisnum{new int{0}};
        std::shared_ptr<std::string> about{new std::string{""}};
        std::shared_ptr<std::string> requirements{new std::string{""}};
        std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
        bool found = false;
        vector<User> records;
        User user(*newpass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
        while (fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum >> *registrationDate) {
            fin.ignore();

            std::getline(fin, *about);
            std::getline(fin, *requirements);
            if (*pass == *newpass && *newname == *name) {
                found = true;
                ofstream foutsel(R"(D:\oop labs\final project\files\Selected.txt)");
                User acc(*newpass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
                foutsel << acc << endl;
                foutsel.close();
            } else {
                records.emplace_back(*newpass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
            }
        }
        fin.close();

        if (found) {
            ofstream foutdel(R"(D:\oop labs\final project\files\Info.txt)", ios_base::trunc);
            for (const auto &record: records) {
                foutdel << record << endl;
            }
            foutdel.close();
            return true;
        } else {
            return false;
        }
    }
}
void sort(){
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)"); // Видалено ios_base::app
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    } else {
        shared_ptr<string> pass{new string{""}};
        shared_ptr<string> name{new string{""}};
        shared_ptr<string> surname{new string{""}};
        shared_ptr<int> age{new int{0}};
        shared_ptr<string> sex{new string{""}};
        shared_ptr<int> regisnum{new int{0}};
        shared_ptr<string> about{new string{""}};
        shared_ptr<string> requirements{new string{""}};
        std::shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
        User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate);
        while (fin >> user){

        }
    }
}
