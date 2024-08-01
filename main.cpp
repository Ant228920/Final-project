#include "Info.h"
#include "Functions.h"
#include "Admin.h"
#include "Exception.h"
#include <iostream>
#include <memory>
#include <vector>


int main() {
    int choice;
    int func;
    Info acc("","","",0,"",0,"","");
    Admin adm("","","",0);
//    cout << "Welcome! Please press 1 if you are an Admin and 2 if you are a User:" << endl;
//    int initial;
//    cin >> initial;
//
//    if(initial == 2){
//        cout << "Please sign up or log in:" << endl;
//        cout << "1 - sign in" << endl;
//        cout << "2 - log in" << endl;
//        try{
//            cin >> choice;
//            if(choice != 1 && choice != 2)
//                throw Exception();
//            switch (choice){
//                case 1:
//                    SignIn(acc);
//                    break;
//                case 2:
//                    LogIn();
//                    break;
//            }
//        }
//        catch (Exception &ex){
//            cerr << ex.what() << endl;
//        }
//        while (true){
//            cout << "1 - Show your profile" << endl;
//            cout << "2 - View profiles" << endl;
//            cout << "3 - Show notifications" << endl;
//            cout << "4 - Quit" << endl;
//
//            try {
//                cin >> func;
//
//                if (func != 1 && func != 2 && func != 3 && func != 4)
//                    throw Exception();
//                switch (func){
//                    case 1:
//                        Show();
//                        break;
//                    case 2:
//                        Read();
//                        break;
//                    case 3:
//                        Notifications();
//                        break;
//                    case 4:
//                        Exit();
//                        return 0;
//                }
//            }
//            catch (Exception &ex){
//                cerr << ex.what() << endl;
//            }
//        }
//    }
    //Read();
    ReportRead();



    // Демонстрація доступу до збережених акаунтів
   //Read();
   //Exit();
   //Notifications();

    return 0;
}

