#include "registration.h"

registration::registration() {}

bool registration::sign_in(string name, string password)// it's for guest
{

    user new_user(name, password);
    if(is_valid_name(new_user) == 0){
        return false;
    }
    if(users == NULL){
        users = users->insert(users, new_user);
        current_ptr = users;
    }
    else{
        current_ptr = users->insert(current_ptr, new_user);
    }
    return true;

}

int registration::login(string username, string password)
{
    doubly_linklist *root = users;
    while(root != NULL){
        if(root->data.valid_user(username, password)){
            return 1;
        }
        root = root->next;
    }
    return 0;
}


int registration::is_valid_name(user new_user)
{
    if(users->is_valid(users, new_user)){
        return 0;
    }
    return 1;
}


