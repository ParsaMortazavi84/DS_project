#include "user.h"

user::user(string username, string pass)
    :name(username)
{
    password = h(pass);
}

int user::comparison(user data, user new_user)
{
    if(data.name == new_user.name)
        return 1;
    return 0;
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
