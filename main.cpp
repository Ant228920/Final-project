#include "User.h"
#include "Functions.h"
#include "Admin.h"
#include "WrongChoice.h"
#include <iostream>


int main() {
    int choice;
    int func;
    int initial;
        cout << "Welcome" << endl;
        while (true) {
            try{
                line();
                cout << "Please press:" << endl;
                cout << "1 - If you are Admin" << endl;
                cout << "2 - If you are User" << endl;
                cout << "3 - To see instruction" << endl;
                line();
                get_input(initial);


            if (initial != 1 && initial != 2 && initial !=3)
                throw WrongChoice();
            if (initial == 1) {
                line();
                cout << "Please sign up or log in:" << endl;
                cout << "1 - Sign in" << endl;
                cout << "2 - Log in" << endl;
                line();
                bool T = existCheck();

                try {
                    get_input(choice);
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
                    cout << "5 - Delete and create account" << endl;
                    cout << "6 - Quit" << endl;
                    line();
                    try {
                        get_input(func);

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
                                adminDelete();
                                adminCreate();
                                break;
                            case 6:
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
                        get_input(choice);
                        switch (choice) {
                            case 1:
                                signIn();
                                break;
                            case 2:
                                if (logIn()) {
                                    cout << "Welcome" << endl;
                                } else {
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

                while (true) {
                    line();
                    cout << "1 - Show your profile" << endl;
                    cout << "2 - View profiles" << endl;
                    cout << "3 - Show notifications" << endl;
                    cout << "4 - Delete account" << endl;
                    cout << "5 - Set status" << endl;
                    cout << "6 - Edit profile" << endl;
                    cout << "7 - Quit" << endl;
                    line();

                    try {
                        get_input(func);

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
                                edit();
                                break;
                            case 7:
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
            if(initial == 3){
                line();
                instruction();
            }
        }
            catch (WrongChoice &ex){
                cerr << ex.what() << endl;
            }
        }
    }