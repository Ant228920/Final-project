#include "User.h"
#include "Person.h"
#include "Admin.h"
#include "Report.h"
#include "Banned.h"
#include "WrongChoice.h"
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <fstream>
#include <limits>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

void line(){
    cout << "------------------------" << endl;
}
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
string getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d;%H:%M:%S", std::localtime(&timeNow));

    return string(buffer);
}
void signIn() {

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
                throw WrongChoice();
        }
    } catch (const std::invalid_argument& ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::shared_ptr<int> regisnum{new int{0}};
    std::cout << "Enter your registration number:";
    get_input(*regisnum);

    std::shared_ptr<std::string> about{new std::string{""}};
    std::cout << "Enter something about yourself:";
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
    std::shared_ptr<std::string> status{new string{"Active"}};

    User newAccount(*newpass, *name, *surname, *age, *sex, *regisnum, *registrationDate, *status, *about, *requirements);

    std::ofstream fileOut(R"(D:\oop labs\final project\files\Selected.txt)",
                         ios_base::app);

    fileOut<<newAccount<<endl;
    fileOut.close();

}

bool isEmpty(){
    ifstream fin(R"(D:\oop labs\final project\files\Couples.txt)", ios::binary | ios::ate);
    return fin.tellg() == 0;
}
void adminCreate(){
    cout<<"OK, write down the information"<<endl;
    shared_ptr <string> name {new string {""}};
    cout<<"Enter your new name:";
    cin>>*name;
    shared_ptr <string> surname {new string {""}};
    cout<<"Enter your surname:";
    cin>>*surname;
    shared_ptr <string> pass {new string {""}};
    cout<<"Enter password:";
    cin>>*pass;
    shared_ptr <string> reppass {new string {""}};
    cout<<"Now please repeat your password:";
    do{
        cin>>*reppass;
    }while(*reppass!=*pass);
    Admin adm(*name, *surname, *pass);
    ofstream foutCA (R"(D:\oop labs\final project\files\Admin.txt)",
                     ios_base::app);
    foutCA<<adm<<endl;
    foutCA.close();

}
bool existCheck(){
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
void adminDelete() {
    ifstream fin(R"(D:\oop labs\final project\files\Admin.txt)");
    cout << "Enter password:";
    shared_ptr<string> password {new string{""}};
    cin >> *password;
    Admin admin;
    while(fin >> admin) {
        if (admin.getPassword() == *password) {
            ofstream fout(R"(D:\oop labs\final project\files\Admin.txt)",
                          ios_base::trunc);
            if (fout.is_open()) {
                fout << "";
                cout << "Your account is successfully deleted" << endl;
            }
            fout.close();
        } else {
            cout << "Wrong password!" << endl;
        }
    }
}
void adminEnter(){
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
            cout << "Welcome" <<  endl;
        }
        else{
            cerr << "Wrong password" << endl;
        }
    }
}
void readCouples(){
    int i = 1;
    ifstream fin(R"(D:\oop labs\final project\files\Couples.txt)",ios_base::app);
    shared_ptr<string> name{new string {""}};
    shared_ptr<string> givername{new string {""}};
    while(fin >> *name >> *givername) {
        cout << i << " Couple: " << *name << " and " << *givername << endl;
        i++;
    }
    fin.close();
}
void instruction(){
    User user;
    string filePath = R"(D:\oop labs\final project\files\instruction.txt)";
    user.writeText(filePath);
}
void choice(const string& newname) {
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
void adminRead(){
    ifstream finE(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    else {
        User user;
        int i = 1;
        while (finE >> user) {
            cout <<"----------Profile: " << i << "-----------" << endl;
            user.printAll();
            cout << "Data of registration: " << user.getRegistrationDate() << endl;
            i++;
        }
    }
    finE.close();
}

void sortByAge(){
    ifstream finE(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    User user;
    vector<User> records;
    while(finE >> user){
        records.emplace_back(user.getPass(), user.get_name(), user.get_surname(), user.getAge(), user.getSex(), user.getRegisnum(), user.getRegistrationDate(), user.getStatus(), user.getAbout(), user.getRequirements());
        std::sort(records.begin(), records.end(), [](User &a,User &b) {
            return a.getAge() < b.getAge(); // Сортування за іменем
        });
        ofstream foutdel(R"(D:\oop labs\final project\files\Info.txt)", ios_base::trunc);
        for (const auto &record: records) {
            foutdel << record << endl; // Переконайтеся, що оператор << правильно записує всі поля
        }
        cout << "Sorted by age" << endl;
        adminRead();
        foutdel.close();
    }
    finE.close();
}
void sortByDate(){
    ifstream finE(R"(D:\oop labs\final project\files\Info.txt)",ios_base::app);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    User user;
    vector<User> records;
    while(finE >> user){
        records.emplace_back(user.getPass(), user.get_name(), user.get_surname(), user.getAge(), user.getSex(), user.getRegisnum(), user.getRegistrationDate(), user.getStatus(), user.getAbout(), user.getRequirements());
        std::sort(records.begin(), records.end(), [](User &a,User &b) {
            return a.getRegistrationDate() < b.getRegistrationDate(); // Сортування за іменем
        });
        ofstream foutdel(R"(D:\oop labs\final project\files\Info.txt)", ios_base::trunc);
        for (const auto &record: records) {
            foutdel << record << endl; // Переконайтеся, що оператор << правильно записує всі поля
        }
        cout << "Sorted by date" << endl;
        adminRead();
        foutdel.close();
    }
    finE.close();
}

void sort(){
    int choice;
    cout << "Please enter which sort you would like to have: " << endl;
    cout << "1 - Sort by age" << endl;
    cout << "2 - Sort by date" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            sortByAge();
            break;
        case 2:
            sortByDate();
            break;
        default:
            throw WrongChoice();
    }
}
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
void ban(const string& deletename){
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
    bool found = false;
    User acc;
    vector<User> vec;
    while (fin >> acc){
        if (acc.get_name() == deletename) {
            found = true;
        } else {
            vec.emplace_back(acc.getPass(), acc.get_name(), acc.get_surname(), acc.getAge(), acc.getSex(), acc.getRegisnum(), acc.getRegistrationDate(), acc.getStatus(), acc.getAbout(), acc.getRequirements());
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
void deleteAcc(){
    ifstream finE(R"(D:\oop labs\final project\files\Selected.txt)", ios_base::in);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    }
    else {
        shared_ptr<string> verify{new string{""}};
        cout << "Enter a password, to pass verification:";
        cin >> *verify;
        User user;
        while (finE >> user) {
            if (user.getPass() == *verify)
            {
                cout << "Verification passed" << endl;
                cout << "Account is successfully deleted" << endl;
                ofstream fout(R"(D:\oop labs\final project\files\Selected.txt)", ios_base::trunc);
                fout<<"";
                fout.close();
            }
            else{
                cerr << "Wrong password. Verification is not passed";
            }
        finE.close();
    }
}

}
void reports(string newname) {

    ofstream fout(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::app);
    shared_ptr<string> reporttext{new string{""}};
    cout << "Report" << endl;
    cin.ignore();
    getline(cin, *reporttext);

    Report rep(std::move(newname), *reporttext);
    fout << rep << endl;
    fout.close();

}
void reportRead() {
    ifstream fin(R"(D:\oop labs\final project\files\Reports.txt)", ios_base::app);
    if (!fin.is_open()) {
        cerr << "Error" << endl;
    } else {

        std::shared_ptr<std::string> repname{new std::string{""}};

        std::shared_ptr<std::string> reporttext{new std::string{""}};

        Report rep;
        while (fin >> rep) {
            ifstream finAcc(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
            User user;
            while (finAcc >> user) {
                if (rep.getName() == user.get_name()) {
                    int choice;
                    line();
                    user.printAll();
                    cout << "Reason for report: " << rep.getAbout() << endl;
                    line();
                    cout << "1 - Ban" << endl << "2 - unBan" << endl;
                    cin >> choice;
                    try {
                        switch (choice) {
                            case 1:
                                ban(user.get_name());
                                break;
                            case 2:
                                cout << "Skipped" << endl;
                                unBan(user.get_name());
                                break;
                            default:
                                throw WrongChoice();
                        }
                    }
                    catch (WrongChoice &ex){
                        cerr << ex.what() << endl;
                    }
                }

            }
        }
        fin.close();
    }
}
void show() {
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
        shared_ptr<std::string> registrationDate{new std::string{getCurrentDateTime()}};
        shared_ptr<std::string> status{new std::string{""}};
        User user;
        while (finE >> user) {
            cout << "pass: " << user.getPass() << endl;
            cout << "name: " << user.get_name() << endl;
            cout << "surname: " << user.get_surname() << endl;
            cout << "age: " << user.getAge() << endl;
            cout << "sex: " << user.getSex() << endl;
            cout << "registration number: " << user.getRegisnum() << endl;
            cout << "about: " << user.getAbout() << endl;
            cout << "requirements: " << user.getRequirements() << endl;
            cout << "Status: " << user.getStatus() << endl;
        }
        finE.close();
    }
}

void status() {
    std::ifstream finE(R"(D:\oop labs\final project\files\Selected.txt)", std::ios_base::in);
    if (!finE.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    User user1;
    while (finE >> user1) {
        std::ofstream fout(R"(D:\oop labs\final project\files\Selected.txt)", std::ios_base::trunc);
        int choice;
        cout << "Your current status is:" << user1.getStatus() << endl;
        if(user1.getStatus() == "Active"){
            cout << "1 - Change to status Inactive" << endl;
            cout << "2 - Leave current status" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    user1.setStatus("Inactive");
                    fout << user1 << endl;
                    break;
                case 2:
                    cout << "Your status is:" << user1.getStatus() << endl;
                    fout << user1 << endl;
                    break;
                default:
                    cerr << "No such an option" << endl;
            }
        } else if(user1.getStatus() == "Inactive"){
            cout << "1 - Change to status Active" << endl;
            cout << "2 - Leave current status" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    user1.setStatus("Active");
                    fout << user1 << endl;
                    break;
                case 2:
                    cout << "Your status is:" << user1.getStatus() << endl;
                    fout << user1 << endl;
                    break;
                default:
                    cerr << "No such an option" << endl;
            }
        }
        fout.close();
    }

    finE.close();

}

void edit() {
    std::ifstream finE(R"(D:\oop labs\final project\files\Selected.txt)", std::ios_base::in);
    if (!finE.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    User user1;
    while (finE >> user1) {
        int choice;
        cout << "Please enter your password:";

        shared_ptr<string> pass{new string{""}};
        shared_ptr<string> newname{new string{""}};
        shared_ptr<string> newsurname{new string{""}};
        shared_ptr<int> newage{new int{0}};
        shared_ptr<string> newsex{new string{""}};
        shared_ptr<string> newabout{new string{""}};
        shared_ptr<string> newrequirements{new string{""}};

        cin >> *pass;
        cin.ignore();

        if (user1.getPass() == *pass) {
            std::ofstream fout(R"(D:\oop labs\final project\files\Selected.txt)", std::ios_base::trunc);
            cout << "1 - Change general information(name, surname, age, sex)" << endl;
            cout << "2 - Change description" << endl;
            cin >> choice;

            switch (choice) {
                case 1: {
                    int option;
                    cout << "Current info:" << endl;
                    cout << "Your name: " << user1.get_name() << endl;
                    cout << "Your surname: " << user1.get_surname() << endl;
                    cout << "Your age: " << user1.getAge() << endl;
                    cout << "Your sex: " << user1.getSex() << endl;

                    cout << "1 - Change information" << endl;
                    cout << "2 - Leave current" << endl;
                    cin >> option;

                    if (option == 1) {
                        int option2;
                        do {
                            cout << "Write new name:";
                            cin >> *newname;
                            user1.set_name(*newname);

                            cout << "Write new surname:";
                            cin >> *newsurname;
                            user1.set_surname(*newsurname);

                            cout << "Write new age:";
                            cin >> *newage;
                            user1.setAge(*newage);

                            cout << "Write new sex (Male/Female):";
                            cin >> *newsex;
                            user1.setSex(*newsex);


                            line();
                            user1.printAll();
                            line();
                            cout << "Is it correct? (1 - Yes, 2 - No):" << endl;
                            cin >> option2;

                        } while (option2 == 2);

                        fout << user1 << endl;
                        cout << "Profile is successfully changed!" << endl;
                        fout.close();
                        return;
                    }
                    if (option == 2) {
                        cout << "Left current" << endl;
                        fout << user1;
                    }
                    break;
                }
                case 2: {
                    int option;
                    cout << "Current info:" << endl;
                    cout << "Your about: " << user1.getAbout() << endl;
                    cout << "Your requirements: " << user1.getRequirements() << endl;

                    cout << "1 - Change information" << endl;
                    cout << "2 - Leave current" << endl;
                    cin >> option;
                    if (option == 1) {
                        int option2;
                        do {
                            cout << "Write new description:";
                            cin.ignore();
                            getline(cin, *newabout);
                            user1.setAbout(*newabout);

                            cout << "Write new requirements:";
                            getline(cin, *newrequirements);
                            user1.setRequirements(*newrequirements);

                            line();
                            user1.printAll();
                            line();
                            cout << "Is it correct? (1 - Yes, 2 - No):" << endl;
                            cin >> option2;

                        } while (option2 == 2);

                        fout << user1 << endl;
                        cout << "Profile is successfully changed!" << endl;
                        fout.close();
                        return;
                    }
                    if (option == 2) {
                        cout << "Left current" << endl;
                        fout << user1;
                    }
                    break;
                }
                default:
                    throw WrongChoice();
            }
            fout.close();
        }
        else{
            cout << "Wrong password" << endl;
        }

    }
    finE.close();
}



bool checking(const string& sercname) {
    if (isEmpty()) {
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
                std::shared_ptr<std::string> status{new std::string{""}};
                User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate, *status);
                while (finS >> user) {
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
void read() {
    ifstream finE(R"(D:\oop labs\final project\files\Info.txt)", ios_base::app);
    if (!finE.is_open()) {
        cerr << "Error opening file: " << endl;
    } else {
        int num;
        shared_ptr<string> search{new string{""}};
        User user;
        cout << "Are you looking for man of female?" << endl;
        cout << "1 - Male" << endl << "2 - Female" << endl;
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
                   throw WrongChoice();
        }
        int i=1;
        while (finE >> user) {
            ifstream finSelect(R"(D:\oop labs\final project\files\Selected.txt)", ios_base::in);
            if (!finE.is_open()) {
                cerr << "Error opening file: " << endl;
            }
            User user1;

            while (finSelect >> user1) {
                if (*search == user.getSex() && user.getStatus() == "Active") {
                    if (user1.subtractFromAge() <= user.getAge() <= user1.addToAge()) {
                        if (checking(user.get_name())) {
                            int option;
                            cout <<"----------Profile:" << i << "-----------" << endl;
                            user.printAll();
                            i++;
                            line();
                            cout << endl << "1 - To like" << endl << "2 - To skip" << endl << "3 - To report" << endl;
                            cin >> option;
                            switch (option) {
                                case 1:
                                    cout << "Like received" << endl;
                                    choice(user.get_name());
                                    break;
                                case 2:
                                    cout << "Skipped" << endl;
                                    break;
                                case 3:
                                    reports(user.get_name());
                                    break;
                                default:
                                    throw WrongChoice();
                            }
                        }
                    }
                }
            }
            finSelect.close();
        }
        }
        catch (WrongChoice &ex) {
            cerr << ex.what() << endl;
        }
        finE.close();
    }
}
    void conformation(const string& givename, const string& receivename) {
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

void notifications() {
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
    std::shared_ptr<std::string> status{new std::string{""}};
    User user(*pass, *name, *surname, *age, *sex, *regisnum, *about, *requirements, *registrationDate, *status);
    while (fin >> user) {
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
                }
                finS.close();
                cout << "1 - Like" << endl << "2 - Skip" << endl;
                int choice;
                cin >> choice;
                        switch (choice) {
                            case 1:
                                cout << "Liked received" << endl;
                                conformation(*givename, *receivename);
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
void exit() {
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
    std::shared_ptr<std::string> status{new std::string{""}};
    std::ofstream fout(R"(D:\oop labs\final project\files\Info.txt)", std::ios_base::app);
    if (!fout.is_open()) {
        std::cout << "Error opening file for writing: Info.txt" << std::endl;
        return;
    }
    User user;
    while (fin >> user) {
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

bool logIn() {
    ifstream fin(R"(D:\oop labs\final project\files\Info.txt)");
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
        ifstream reportsFile(R"(D:\oop labs\final project\files\Reports.txt)");
        Report report;
        while (reportsFile >> report) {
            try {
                if (report.getName() == *newname) {
                    throw Banned();
                }
            }
            catch (Banned &ex){
                cerr << ex.what() << endl;
                return false;
            }
        }
        reportsFile.close();
        bool found = false;
        vector<User> records;
        User user;
        while (fin >> user) {
            if (*pass == user.getPass() && *newname == user.get_name()) {
                found = true;
                ofstream foutsel(R"(D:\oop labs\final project\files\Selected.txt)");
                User acc(user.getPass(), user.get_name(), user.get_surname(), user.getAge(), user.getSex(), user.getRegisnum(), user.getRegistrationDate(), user.getStatus(), user.getAbout(), user.getRequirements());
                foutsel << acc << endl;
                foutsel.close();
            } else {
                records.emplace_back(user.getPass(), user.get_name(), user.get_surname(), user.getAge(), user.getSex(), user.getRegisnum(), user.getRegistrationDate(), user.getStatus(), user.getAbout(), user.getRequirements());
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
            cerr << "Wrong password!" << endl;
            return false;
        }

    }
}

