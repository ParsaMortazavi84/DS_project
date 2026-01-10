#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
using namespace std;
#include "user.h"
#include "doubly_linklist.h"

class registration: public doubly_linklist<user>
{
public:
    registration();
    bool sign_in(string, string);
    int is_valid_name(string);
private:
    doubly_linklist<user> users;
};

#endif // REGISTERATION
