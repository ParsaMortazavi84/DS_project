#include "user.h"

user::user()
{

}

user::user(string username, string pass)
    :name(username)
{
    password = h(pass);
}

int user::valid_password(string pass)
{
    pass = h(pass);
    if(pass == password){
        return 1;
    }
    return 0;
}

int user::valid_user(string username, string pass)
{
    pass = h(pass);
    if(username == name && pass == password)
        return 1;
    return 0;
}

string user::getName() const
{
    return name;
}

string user::getPassword() const
{
    return password;
}

void user::setName(const string &newName)
{
    name = newName;
}

void user::setPassword(const string &newPassword)
{
    password = h(newPassword);
}

bool user::operator==(const user &new_user)
{
    if(this->name == new_user.name)
        return 1;
    return 0;
}
