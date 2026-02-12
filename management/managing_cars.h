#ifndef MANAGING_CARS_H
#define MANAGING_CARS_H

#include<iostream>
using namespace std;

#include "doubly_linklist.h"
#include "avl_tree.h"
#include "customer.h"
#include "car.h"

class managing_cars
{
public:
    managing_cars();
    bool insert(car);
    bool is_valid_insert(const car&);
    void deletation(car target);
    car exact_search(car target);


    void searching_base_on_brande(string);
    void searching_base_on_price(int, int);
    void searching_base_on_model(models);


    void update_pq(customer, car, time_t, time_t);
    void update_car(car);


private:
    doubly_linklist<car> cars;


    AVL_TREE avl;


};

#endif // MANAGING_CARS_H
