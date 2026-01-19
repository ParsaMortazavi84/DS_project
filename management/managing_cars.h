#ifndef MANAGING_CARS_H
#define MANAGING_CARS_H

#include<iostream>
using namespace std;

#include "doubly_linklist.h"
#include "avl_tree.h"

#include "car.h"

class managing_cars
{
public:
    managing_cars();
    bool insert(car);
    bool is_valid_insert(car);
    void deletation(car target);
    void exact_search(car target);


    void searching_base_on_brande(string);
    void searching_base_on_price(int, int);
    void searching_base_on_model(models);



private:
    doubly_linklist<car> *cars = NULL;
    doubly_linklist<car> *current_ptr;

    AVL_TREE* avl;


};

#endif // MANAGING_CARS_H
