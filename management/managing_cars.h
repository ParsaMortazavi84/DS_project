#ifndef MANAGING_CARS_H
#define MANAGING_CARS_H

#include<iostream>
using namespace std;

#include "doubly_linklist.h"
#include "car.h"

class managing_cars
{
public:
    managing_cars();
    void insert(car);

private:
    doubly_linklist<car> *cars = NULL;

};

#endif // MANAGING_CARS_H
