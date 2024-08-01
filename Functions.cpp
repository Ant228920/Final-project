#include "Info.h"
#include "Person.h"
#include "Admin.h"
#include "Report.h"
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <limits>
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
void SignIn(Info) {
    std::cout << "OK, write down the information" << std::endl;

    std::shared_ptr<std::string> newpass{new std::string{""}};
    std::cout << "Enter your new password: ";
    std::cin >> *newpass;

    std::shared_ptr<std::string> name{new std::string{""}};
    std::cout << "Enter your name: ";
    cin >> *name;

    std::shared_ptr<std::string> surname{new std::string{""}};
    std::cout << "Enter your surname: ";
    std::cin >> *surname;

    std::shared_ptr<int> age{new int{0}};
    std::cout << "Enter your age: ";
    std::cin >> *age;

    std::shared_ptr<std::string> sex{new std::string{""}};
    std::cout << "Enter your sex: ";
    std::cin >> *sex;

    std::shared_ptr<int> regisnum{new int{0}};
    std::cout << "Enter your registrational number: ";
    std::cin >> *regisnum;

    std::shared_ptr<std::string> about{new std::string{""}};
    std::cout << "Enter something about yourself: ";
    cin.ignore();
    getline(cin, *about);

    std::shared_ptr<std::string> requirements{new std::string{""}};
    std::cout << "Enter your requirements: ";
    getline(cin, *requirements);

    std::shared_ptr<std::string> reppass{new std::string{""}};
    std::cout << "Now please repeat your password: ";
    do {
        std::cin >> *reppass;
    } while (*reppass != *newpass);

    Info newAccount(*newpass, *name, *surname, *age, *sex, *regisnum, *about, *requirements);

    std::ofstream fileOut(R"(D:\oop labs\final project\files\Selected.txt)",
                         ios_base::app);

    fileOut<<newAccount<<endl;
    cout<<"----------------------";
    fileOut.close();

}


void AdminCreate(Admin) {
    std::cout << "OK, write down the information" << std::endl;

    std::shared_ptr<std::string> name{new std::string{""}};
    std::cout << "Enter your name: ";
    cin >> *name;

    std::shared_ptr<std::string> surname{new std::string{""}};
    std::cout << "Enter your surname: ";
    std::cin >> *surname;

    std::shared_ptr<std::string> newpass{new std::string{""}};
    std::cout << "Enter your new password: ";
    std::cin >> *newpass;

    shared_ptr<int> reports{new int{0}};

    std::shared_ptr<std::string> reppass{new std::string{""}};
    std::cout << "Now please repeat your password: ";
    do {
        std::cin >> *reppass;
    } while (*reppass != *newpass);

    Admin newAccount(*name, *surname, *newpass, *reports);

    std::ofstream fileOut(R"(D:\oop labs\final project\files\Admin.txt)",
                          ios_base::app);

    fileOut<<newAccount<<endl;
    cout<<"----------------------";
    fileOut.close();

}

std::string GetName(Info& account) {
    return account.GetName();
}


bool ExistCheck(Info){
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
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
bool AdminEnter(Admin){
    bool P = false;
    shared_ptr <string> parol{new string {""}};
    cout<<"Enter the password ";
    cin>>*parol;
    ifstream fin(R"(D:\oop labs\ooplab1\files\Admin.txt)",
                 ios_base::app);

    if(fin.is_open()){
        string line;
        while (std::getline(fin, line)) {
            if (line.find(*parol) != std::string::npos) {
                cout<<"Welcome!"<<endl;
                P = true;
                fin.close();
            }
            else{
                cerr<<"Wrong password! Please try later"<<endl;
                P = false;
                fin.close();
            }
        }
    }
    fin.close();
    return P;
}
void Choice(string newname) {
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
vector<Info> Vec(vector<Info>& accounts){
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
    if(!fin.is_open()){
        cerr << "Error" <<endl;
    }
    else{
        std::shared_ptr<std::string> newpass{new std::string{""}};

        std::shared_ptr<std::string> name{new std::string{""}};

        std::shared_ptr<std::string> surname{new std::string{""}};

        std::shared_ptr<int> age{new int{0}};

        std::shared_ptr<std::string> sex{new std::string{""}};

        std::shared_ptr<int> regisnum{new int{0}};

        std::shared_ptr<std::string> about{new std::string{""}};

        std::shared_ptr<std::string> requirements{new std::string{""}};
       while(fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum){
           fin.ignore();

           std::getline(fin, *about);
           std::getline(fin, *requirements);
           Info acc(*newpass,*name,*surname,*age,*sex,*regisnum,*about,*requirements);
           accounts.push_back(acc);
       }

    }
    return accounts;
}
void Reports(string newname) {
    ifstream fin(R"(D:\oop labs\final project\files\Admin.txt)", ios_base::app);
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    } else {

        std::shared_ptr<std::string> name{new std::string{""}};

        std::shared_ptr<std::string> surname{new std::string{""}};

        std::shared_ptr<std::string> newpass{new std::string{""}};

        std::shared_ptr<int> reports{new int{0}};

        while (fin >> *name >> *surname >> *newpass >> *reports) {
            ofstream fout(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::app);
            shared_ptr<string> reporttext{new string{""}};
            cout << "Report" << endl;
            cin.ignore();
            getline(cin, *reporttext);
            fout << newname << endl << *reporttext << endl;
            fout.close();

            (*reports)++;
        }
        fin.close();
    }
}
void ReportRead(){
    ifstream fin(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::app);
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    } else {

        std::shared_ptr<std::string> name{new std::string{""}};

        std::shared_ptr<std::string> reporttext{new std::string{""}};
        while(fin >> *name){
            fin.ignore();
            std::getline(fin, *reporttext);
            cout<<*name<<endl;
            cout<<*reporttext<<endl;
        }
    }
    fin.close();
}
void Show(){
    ifstream finE(R"(D:\oop labs\final project\files\Selected.txt)",ios_base::app);
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
bool IsEmpty(){
    ifstream fin(R"(D:\oop labs\final project\files\Couples.txt)", ios::binary | ios::ate);
    return fin.tellg() == 0;
}
bool Checking(string sercname) {
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
                while (finS >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum) {
                    finS.ignore();

                    std::getline(finS, *about);
                    std::getline(finS, *requirements);
                    if (*receivename == sercname && *givername == *name || *receivename == *name && *givername == sercname) {
                        return false;
                    }
                }
                finS.close();
            }
            fin.close();
            return true;
        }
    }
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
        cout << "Are you looking for man of female?" << endl;
        cout << "1 - Male" << endl << "2 - Female" << endl << "3 - Don't care" << endl;
        cin >> num;
        switch (num) {
            case 1:
                *search = "Male";
                break;
            case 2:
                *search = "Female";
                break;
        }
        cout << "1 - To like" << endl << "2 - To skip" << endl << "3 - To report";
        while (finE >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements) {
            finE.ignore();

            std::getline(finE, *about);
            std::getline(finE, *requirements);
            if (*search == *sex) {
                if (Checking(*name)) {
                    int choice;
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
                    cout << *requirements << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "Like received" << endl;
                            Choice(*name);
                            break;
                        case 2:
                            cout << "Skipped" << endl;
                            break;
                        case 3:
                            Reports(*name);
                            break;
                    }
                }
            }
        }
        finE.close();
    }
}
    void Conformation(string givename, string receivename) {
        ifstream fin(R"(D:\oop labs\final project\files\Match.txt)", ios_base::app);
        shared_ptr<string> name{new string{""}};
        shared_ptr<string> secname{new string{""}};
        bool found = false;
        vector<Person> vec;
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
            ofstream foutdel("D:\\oop labs\\final project\\files\\Match.txt", ios_base::trunc);
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

    while (fin >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum) {
        fin.ignore();

        std::getline(fin, *about);
        std::getline(fin, *requirements);
        ifstream finE(R"(D:\oop labs\final project\files\Match.txt)");
        if (!finE.is_open()) {
            std::cout << "Error opening file for reading: Match.txt" << std::endl;
            return;
        }

        shared_ptr<string> receivename{new string{""}};
        shared_ptr<string> givename{new string{""}};

        while (finE >> *receivename >> *givename) {
            if (*name == *receivename) {
                ifstream finS (R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
                while (finS >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum) {
                    finS.ignore();

                    std::getline(finS, *about);
                    std::getline(finS, *requirements);
                    if(*name == *givename){
                        cout<<"You received a like!"<<endl;
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
                        cout << *requirements << endl;
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
                }
            }
        }
        finE.close();
    }
    fin.close();
}
void Exit() {
    // Открыть файл для чтения
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

    // Открыть файл для записи
    std::ofstream fout(R"(D:\oop labs\final project\files\Info.txt)", std::ios_base::app);
    if (!fout.is_open()) {
        std::cout << "Error opening file for writing: Info.txt" << std::endl;
        return;
    }

    // Чтение и запись данных
    while (fin >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum) {
        fin.ignore();

        std::getline(fin, *about);
        std::getline(fin, *requirements);

        fout << *pass << std::endl;
        fout << *name << std::endl;
        fout << *surname << std::endl;
        fout << *age << std::endl;
        fout << *sex << std::endl;
        fout << *regisnum << std::endl;
        fout << *about << std::endl;
        fout << *requirements << std::endl;
        fout << std::endl;
    }

    fin.close();
    fout.close();

    // Очистить файл Selected.txt
    std::ofstream foutsel(R"(D:\oop labs\final project\files\Selected.txt)", std::ios_base::trunc);
    if (!foutsel.is_open()) {
        std::cout << "Error opening file for clearing: Selected.txt" << std::endl;
        return;
    }
    foutsel.close();
}

//void Delete(){
//    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
//    shared_ptr<string> pass{new string{""}};
//    shared_ptr<string> name{new string{""}};
//    shared_ptr<string> surname{new string{""}};
//    shared_ptr<int> age{new int{0}};
//    shared_ptr<string> sex{new string{""}};
//    shared_ptr<int> regisnum{new int{0}};
//    shared_ptr<string> about{new string{""}};
//    shared_ptr<string> requirements{new string{""}};
//    shared_ptr<string> search{new string{""}};
//    while(fin>>*pass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements){
//        if(*age == 20){
//            ofstream fout(R"(D:\oop labs\final project\files\Info.txt)",ios_base::trunc);
//            fout << "";
//            fout.close();
//        }
//    }
//}
void LogIn() {
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)"); // Видалено ios_base::app
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    } else {
        std::cout << "OK, write down the information" << std::endl;

        shared_ptr<string> pass{new string{""}};
        cout << "Enter password: ";
        cin >> *pass;
        shared_ptr<string> newname{new string{""}};
        cout << "Enter name: ";
        cin >> *newname;

        std::shared_ptr<std::string> newpass{new std::string{""}};
        std::shared_ptr<std::string> name{new std::string{""}};
        std::shared_ptr<std::string> surname{new std::string{""}};
        std::shared_ptr<int> age{new int{0}};
        std::shared_ptr<std::string> sex{new std::string{""}};
        std::shared_ptr<int> regisnum{new int{0}};
        std::shared_ptr<std::string> about{new std::string{""}};
        std::shared_ptr<std::string> requirements{new std::string{""}};

        bool found = false;
        vector<Info> records;
        while (fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum) {
            fin.ignore();

            std::getline(fin, *about);
            std::getline(fin, *requirements);
            if (*pass == *newpass && *newname == *name) {
                found = true;
                ofstream foutsel("D:\\oop labs\\final project\\files\\Selected.txt");
                Info acc(*newpass, *name, *surname, *age, *sex, *regisnum, *about, *requirements);
                foutsel << acc << endl;
                foutsel.close();
            } else {
                records.emplace_back(*newpass, *name, *surname, *age, *sex, *regisnum, *about, *requirements);
            }
        }
        fin.close();

        if (found) {
            ofstream foutdel("D:\\oop labs\\final project\\files\\Info.txt", ios_base::trunc);
            for (const auto &record: records) {
                foutdel << record << endl;
            }
            foutdel.close();
        } else {
            cerr << "Incorrect data" << endl;
        }
    }
}
