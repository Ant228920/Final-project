#include "Person.h"
#include "Info.h"
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
void SignIn(Info);
std::string GetName(Info& account);
vector<Info> Vec(vector<Info>& accounts);
bool ExistCheck(Admin);
void Show();
void Notifications();
void AdminCreate(Admin);
bool AdminEnter(Admin);
void AdminRead();
void Read();
void Exit();
void ReportRead();
void Reports(string newname);
void Delete();
void LogIn();

#endif //FINAL_PROJECT_FUNCTIONS_H
