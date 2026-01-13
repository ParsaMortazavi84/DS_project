#ifndef USER_H
#define USER_H


#include <iostream>
using namespace std;
hash<string> h;

class user
{
public:
    user(string , string);// and in this function we should hash the password
    int comparison(user, user);
    int valid_password(string);
    int valid_user(string, string);
private:
    string name;
    string password;
};

#endif // USER_H
