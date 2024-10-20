#include "User.h"
#include "Functions.h"
#include "Admin.h"
#include "Exception.h"
#include <iostream>
#include <memory>
#include <vector>


int main() {
    int choice;
    int func;
    //User acc("", "", "", 0, "", 0, "", "");
    //Admin adm("","","");
    cout << "Welcome! Please press 1 if you are an Admin and 2 if you are a User:" << endl;
    int initial;
    cin >> initial;

    if (initial == 1) {
        cout << "Please sign up or log in:" << endl;
        cout << "1 - sign in" << endl;
        cout << "2 - log in" << endl;
        cout << "3 - delete and create new account" << endl;
        bool T = ExistCheck();
        cout<<T<<endl;
        try {
            cin >> choice;
            switch (choice) {
                case 1:
                    if (T) {
                        cout << "You already have some info" << endl;
                        AdminEnter();
                    } else {
                        AdminCreate();
                    }
                    break;
                case 2:
                    if (!T) {
                        cout << "Sorry you don't have an account, please create one" << endl;
                        AdminCreate();
                    } else {
                        AdminEnter();
                    }
                    break;
                case 3:
                    if (!T) {
                        cout << "You don't have any accounts" << endl;
                        AdminCreate();
                    } else {
                        AdminDelete();
                        AdminCreate();
                    }
                    break;
                default:
                    throw Exception();
            }
        }
        catch (Exception &ex) {
            cerr << ex.what() << endl;
        }

        while (true) {
            cout << "Please choose an action:" << endl;
            cout << "1 - See reports" << endl;
            cout << "2 - See couples" << endl;
            cout << "3 - See all users" << endl;
            cout << "4 - Quit" << endl;

            try {
                cin >> func;

                switch (func) {
                    case 1:
                        ReportRead();
                        break;
                    case 2:
                        ReadCouples();
                        break;
                    case 3:
                        AdminRead();
                        break;
                    case 4:
                        return 0;
                    default:
                        throw Exception();
                }
            } catch (Exception &ex) {
                cerr << ex.what() << endl;
            }
        }
    }

    if (initial == 2) {
            while (true) {
                cout << "Please sign up or log in:" << endl;
                cout << "1 - sign in" << endl;
                cout << "2 - log in" << endl;
                try {
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            SignIn();
                            break;
                        case 2:
                            if( LogIn()){
                                cout<<"Welcome"<<endl;
                            } else {
                                cerr << "Incorrect Data";
                                return 0;
                            }
                            break;
                        default:
                            throw Exception();
                    }
                    break;
                }
                catch (Exception &ex) {
                    cerr << ex.what() << endl;
                }
            }

            // Друга частина меню (Дії з профілем)
            while (true) {
                cout << "1 - Show your profile" << endl;
                cout << "2 - View profiles" << endl;
                cout << "3 - Show notifications" << endl;
                cout << "4 - Delete account" << endl;
                cout << "5 - Quit" << endl;

                try {
                    cin >> func;

                    switch (func) {
                        case 1:
                            Show();
                            break;
                        case 2:
                            Read();
                            break;
                        case 3:
                            Notifications();
                            break;
                        case 4:
                            DeleteAcc();
                            return 0;
                        case 5:
                            Exit();
                            return 0;
                        default:
                            throw Exception();
                    }
                }
                catch (Exception &ex) {
                    cerr << ex.what() << endl;
                }
            }
         }
   //Read();
    //ReportRead();
    //LogIn();



    // Демонстрація доступу до збережених акаунтів
   //Read();
   //Exit();
   //Notifications();

    return 0;
}

