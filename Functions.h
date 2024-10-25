#include "Person.h"
#include "User.h"
#include "Admin.h"
#include "Report.h"
#include <vector>
#ifndef FINAL_PROJECT_FUNCTIONS_H
#define FINAL_PROJECT_FUNCTIONS_H
void signIn();
std::string GetName(User& account);
vector<User> Vec(vector<User>& accounts);
bool existCheck();
void show();
void notifications();
bool adminCreate();
void status();
void sort();
void instraction();
void line();
bool adminEnter();
void deleteAcc();
void adminDelete();
void readCouples();
void adminRead();
void read();
void exit();
void edit();
void reportRead();
void reports(string newname);
bool logIn();

#endif //FINAL_PROJECT_FUNCTIONS_H
