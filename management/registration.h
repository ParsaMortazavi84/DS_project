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
    int login(string, string);
    int is_valid_name(user);

private:
    doubly_linklist<user> *users = NULL;
    doubly_linklist<user> *current_ptr = NULL;
};

#endif // REGISTERATION
