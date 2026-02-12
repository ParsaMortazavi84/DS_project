#ifndef MANAGING_CUSTOMER_H
#define MANAGING_CUSTOMER_H

#include "customer.h"
#include "managing_cars.h"


class managing_customer
{
public:
    //sign_in or login part
    managing_customer();
    bool sign_in(string, string);
    bool login(string, string);
    int is_valid_name(customer);
    void set_customers(doubly_linklist<customer> data);

    void find_customer();

    // reserve part
    bool valid_reserve_request(managing_cars*, car, time_t start_time, time_t end_time);// we use that in the main
    void reservation(managing_cars *, car, time_t start_time, time_t end_time);// it's for make a request in this function and then add that in the current_customer

    void renewal(car);// of that car find out the return_time of car and we know that the start time of next time and add that some day and we have the end time
    car payement_function(car);// that call the payment function of current_customer


    doubly_linklist<customer> get_customers();
private:
    doubly_linklist<customer> customers;

    doubly_linklist<customer>::Node *current_customer;// if some one login we set the current_customer

};

#endif // MANAGING_CUSTOMER_H
