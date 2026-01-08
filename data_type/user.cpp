#include "user.h"

user::user(string username, string pass)
    :name(username)
{
    password = h(pass);
}
