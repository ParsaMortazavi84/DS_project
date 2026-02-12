#include "managing_customer.h"

managing_customer::managing_customer() {
    current_customer = NULL;
}


bool managing_customer::sign_in(string name, string password)// it's for guest
{

    customer new_customer(name, password);
    if(is_valid_name(new_customer) == 0){
        return false;
    }
    customers.insert(new_customer);

    return true;

}

bool managing_customer::login(string username, string password)
{
    customer new_client(username, password);
    if(customers.is_valid(new_client)){
        doubly_linklist<customer>::Node* temp = customers.get_head();
        while(temp != nullptr){
            if(temp->data == new_client){
                current_customer = temp;
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}


int managing_customer::is_valid_name(customer new_customer)
{
    doubly_linklist<customer>::Node* root = customers.get_head();
    while(root != nullptr){
        if(root->data.getName() == new_customer.getName()){
            return false;
        }
        root = root->next;
    }
    return true;
}

void managing_customer::set_customers(doubly_linklist<customer> data)
{
    customers = data;
}

bool managing_customer::valid_reserve_request(managing_cars *managing_cars_pointer, car target, time_t start_time, time_t end_time)
{
    if(target.current_situation == available && target.current_condition != maintenance){
        return true;
    }

    car resualt = managing_cars_pointer->exact_search(target);
    if(start_time <= resualt.return_time){
        return false;
    }

    request temp(current_customer->data, start_time, end_time);

    while(!target.reservation_list.empty()){
        auto x = target.reservation_list.pop();
        if(x.conflicts_with(temp))
            return false;
    }

    return true;
}

void managing_customer::reservation(managing_cars *managing_cars_pointer, car target, time_t start_time, time_t end_time)
{
    // managing_cars_pointer -> update(current_customer->data, target, start_time, end_time)
    managing_cars_pointer->update_pq(current_customer->data, target, start_time, end_time);
    current_customer->data.reserve_request_function(target);
    cout << "request is registered" << endl;
    // we should add a function that update the attribute in the some \
    the function should get the start_time and, end_time, car target, current_customer \
    then should add them in the priority queue
    ///////////////////////////////   PQ   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

}

car managing_customer::payement_function(car )
{
    // we should take the car of current_customer and then pass that to the return car
}


