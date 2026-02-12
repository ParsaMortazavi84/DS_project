#include "registration.h"

registration::registration() {}

bool registration::sign_in(string name, string password)// it's for guest
{

    user new_user(name, password);
    if(is_valid_name(new_user) == false){
        return false;
    }
    users.insert(new_user);
    return true;

}

bool registration::login(string username, string password)
{
    user new_user(username, password);
    doubly_linklist<user>::Node* head = users.get_head();
    while(head != nullptr){
        if(head->data.valid_user(username, password)){
            return true;
        }
        head = head->next;
    }
    return false;
}


bool registration::is_valid_name(user new_user)
{
    return users.is_valid(new_user);
}

void registration::set_users(doubly_linklist<user> data)
{
    users = data;
}


