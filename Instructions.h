#ifndef FINAL_PROJECT_INSTRUCTIONS_H
#define FINAL_PROJECT_INSTRUCTIONS_H
#include <string>
using namespace std;

class Instructions {
public:
    virtual void writeText(const string &filePath) = 0;

    virtual ~Instructions() = default;
};


#endif //FINAL_PROJECT_INSTRUCTIONS_H
