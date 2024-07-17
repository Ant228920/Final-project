#include "Info.h"
#include "Person.h"
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
        while (fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements) {
            ofstream fout(R"(D:\oop labs\final project\files\Match.txt)", ios_base::app);
            fout << newname << " Got liked by " << *name<<endl;
            fout.close();
        }
        fin.close();
    }
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
       while(fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements){
           Info acc(*newpass,*name,*surname,*age,*sex,*regisnum,*about,*requirements);
           accounts.push_back(acc);
       }

    }
    return accounts;
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
        while (finE >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements) {
            cout << "pass: ";
            cout << *pass<<endl;
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

void Read(){
    ifstream finE(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    else {
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
        cout<<"Are you looking for man of female?"<<endl;
        cout<<"1 - Male"<<endl<<"2 - Female"<<endl<<"Don't care"<<endl;
        cin>>num;
        switch (num) {
            case 1:
                *search = "Male";
                break;
            case 2:
                *search = "Female";
                break;
        }
        cout<<"1 - To like"<<endl<<"2 - To skip";
            while (finE >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements) {
                if (*search == *sex) {
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
                    }
                }
            }
    }
    finE.close();
}

void Exit() {
        // Відкрити файл для читання
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
        while (fin >> *pass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements){
            std::ofstream fout(R"(D:\oop labs\final project\files\Info.txt)", std::ios_base::app);
            if (!fout.is_open()) {
                std::cout << "Error opening file for writing: Info.txt" << std::endl;
                return;
            }

            fout << *pass << endl;
            fout << *name << endl;
            fout << *surname << endl;
            fout << *age << endl;
            fout << *sex << endl;
            fout << *regisnum << endl;
            fout << *about << endl;
            fout << *requirements << endl;
            cout << endl;
            fout.close();
        }

        // Очистити файл Selected.txt
        std::ofstream foutsel(R"(D:\oop labs\final project\files\Selected.txt)", std::ios_base::trunc);
        if (!foutsel.is_open()) {
            std::cout << "Error opening file for clearing: Selected.txt" << std::endl;
            return;
        }
        foutsel.close();

        // Записати дані до файлу Info.txt
}

    void Delete(){
    ofstream fout(R"(D:\oop labs\final project\files\Selected.txt)",ios_base::trunc);
    if(fout.is_open()){
        fout << "";
        fout.close();
    }
}
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
        while (fin >> *newpass >> *name >> *surname >> *age >> *sex >> *regisnum >> *about >> *requirements) {
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
