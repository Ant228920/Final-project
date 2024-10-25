#include "User.h"
#include "Functions.h"
#include "Admin.h"
#include "WrongChoice.h"
#include <iostream>


int main() {
    int choice;
    int func;
    cout << "Welcome! Please press 1 if you are an Admin and 2 if you are a User:" << endl;
    int initial;
    cin >> initial;

    if (initial == 1) {
        line();
        cout << "Please sign up or log in:" << endl;
        cout << "1 - sign in" << endl;
        cout << "2 - log in" << endl;
        cout << "3 - delete and create new account" << endl;
        line();
        bool T = existCheck();
        try {
            cin >> choice;
            switch (choice) {
                case 1:
                    if (T) {
                        line();
                        cout << "You already have some info" << endl;
                        adminEnter();
                        line();
                    } else {
                        adminCreate();
                    }
                    break;
                case 2:
                    if (!T) {
                        cout << "Sorry you don't have an account, please create one" << endl;
                        adminCreate();
                    } else {
                        adminEnter();
                    }
                    break;
                case 3:
                    if (!T) {
                        cout << "You don't have any accounts" << endl;
                        adminCreate();
                    } else {
                        adminDelete();
                        adminCreate();
                    }
                    break;
                case 4:

                default:
                    throw WrongChoice();
            }
        }
        catch (WrongChoice &ex) {
            cerr << ex.what() << endl;
        }

        while (true) {
            line();
            cout << "Please choose an action:" << endl;
            cout << "1 - See reports" << endl;
            cout << "2 - See couples" << endl;
            cout << "3 - See all users" << endl;
            cout << "4 - Sort users" << endl;
            cout << "5 - Quit" << endl;
            line();
            try {
                cin >> func;

                switch (func) {
                    case 1:
                        reportRead();
                        break;
                    case 2:
                        readCouples();
                        break;
                    case 3:
                        adminRead();
                        break;
                    case 4:
                        sort();
                        break;
                    case 5:
                        return 0;
                    default:
                        throw WrongChoice();
                }
            } catch (WrongChoice &ex) {
                cerr << ex.what() << endl;
            }
        }
    }

    if (initial == 2) {
            while (true) {
                line();
                cout << "Please sign up or log in:" << endl;
                cout << "1 - sign in" << endl;
                cout << "2 - log in" << endl;
                line();
                try {
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            signIn();
                            break;
                        case 2:
                            if(logIn()){
                                cout<<"Welcome"<<endl;
                            } else {
                                cerr << "Incorrect Data";
                                return 0;
                            }
                            break;
                        default:
                            throw WrongChoice();
                    }
                    break;
                }
                catch (WrongChoice &ex) {
                    cerr << ex.what() << endl;
                }
            }

            // Друга частина меню (Дії з профілем)
            while (true) {
                line();
                cout << "1 - Show your profile" << endl;
                cout << "2 - View profiles" << endl;
                cout << "3 - Show notifications" << endl;
                cout << "4 - Delete account" << endl;
                cout << "5 - Set status" << endl;
                cout << "6 - Instruction" << endl;
                cout << "7 - Edit profile" << endl;
                cout << "8 - Quit" << endl;
                line();

                try {
                    cin >> func;

                    switch (func) {
                        case 1:
                            show();
                            break;
                        case 2:
                            read();
                            break;
                        case 3:
                            notifications();
                            break;
                        case 4:
                            deleteAcc();
                            return 0;
                        case 5:
                            status();
                            break;
                        case 6:
                            userInstraction();
                            break;
                        case 7:
                            edit();
                            break;
                        case 8:
                            exit();
                            return 0;
                        default:
                            throw WrongChoice();
                    }
                }
                catch (WrongChoice &ex) {
                    cerr << ex.what() << endl;
                }
            }
         }
    return 0;
}

