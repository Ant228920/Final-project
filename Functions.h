#include "Person.h"
#include "Info.h"
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
bool ExistCheck(Info);
void Show();
void Read();
void Exit();
void Delete();
void LogIn();

#endif //FINAL_PROJECT_FUNCTIONS_H
