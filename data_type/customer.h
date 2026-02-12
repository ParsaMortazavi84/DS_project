#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "doubly_linklist.h"
#include "car.h"
#include "user.h"
// i want to take data of customer in the doubly_link list so we don't want to customer be the child of user or registration
// 1-now the customer should have a doubly link list of for reserve request \
(it can be the doubly_link list of cars or new_type that just keep the brand and model of that car \
2-then we should have the list of rental cars \
3-then we should have a dept paramater in int type \
4-we should have a the sum_of_income from that customer \
and we should have a penalty paramater the being assumed was a number of day of that or what?!


//1-function should be a calculate that penalty paramater \
2-the function that if we have no problem extension the retal \
3-pay the dept and add that to sum_of_income \
4-make a reservation and check the validation of that



class customer:public user
{
public:
    customer();
    customer(string, string);
    customer(customer const &);
    void reserve_request_function(car);
    void rental_request(car);

    bool equal(const customer&);

    car payment();


    int get_debt();
    int set_debt(int);


private:
    doubly_linklist<car> rental_cars;
    doubly_linklist<car> reserve_requests;
    int debt = 0;
    int sum_of_income;
};

#endif // CUSTOMER_H
