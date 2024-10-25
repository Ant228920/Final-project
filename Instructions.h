#ifndef FINAL_PROJECT_INSTRUCTIONS_H
#define FINAL_PROJECT_INSTRUCTIONS_H
#include <string>
using namespace std;

class Instructions {
public:
    virtual void writeInstructions(const string &text) = 0;

    // Віртуальний деструктор, необхідний для інтерфейсів
    virtual ~Instructions() = default;
};


#endif //FINAL_PROJECT_INSTRUCTIONS_H
