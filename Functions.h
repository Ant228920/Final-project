#include "Person.h"
#include "User.h"
#include "Admin.h"
#include "Report.h"
#include <vector>
#ifndef FINAL_PROJECT_FUNCTIONS_H
#define FINAL_PROJECT_FUNCTIONS_H
//struct AccountsResult {
//    std::vector<Info> accounts;
//    size_t size;
//};
//std::vector<Info> LoadAccounts();
void SignIn();
std::string GetName(User& account);
vector<User> Vec(vector<User>& accounts);
bool ExistCheck();
void Show();
void Notifications();
bool AdminCreate();
bool AdminEnter();
void DeleteAcc();
void AdminDelete();
void ReadCouples();
void AdminRead();
void Read();
void Exit();
void ReportRead();
void Reports(string newname);
bool LogIn();

#endif //FINAL_PROJECT_FUNCTIONS_H
