#ifndef USER_H
#define USER_H


#include <iostream>
using namespace std;
hash<string> h;

class user
{
public:
    user();
    user(string , string);// and in this function we should hash the password
    int valid_password(string);
    int valid_user(string, string);
    string getName() const;
    string getPassword() const;
    void setName(const string &newName);

    void setPassword(const string &newPassword);

    bool operator==(const user&);

private:
    string name;
    string password;
};

#endif // USER_H
