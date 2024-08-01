#include "User.h"

ostream &operator<<(ostream &os, const User &obj){
    obj.Print(os);
    return os;
}