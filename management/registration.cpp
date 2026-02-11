#include "registration.h"

registration::registration() {}

bool registration::sign_in(string name, string password)// it's for guest
{

    user new_user(name, password);
    if(is_valid_name(new_user) == 0){
        return false;
    }
    users.insert(new_user);
    return true;

}

bool registration::login(string username, string password)
{
    user new_user(username, password);
    return users.is_valid(new_user);
}


int registration::is_valid_name(user new_user)
{
    return users.is_valid(new_user);
}

void registration::set_users(doubly_linklist<user> data)
{
    users = data;
}


