#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
#include <ctime>

enum situation{
    available,
    rented,
    reserved
};

class car
{
public:
    car(string , string, int);// for price ,brande and model we should get that from pc
    //but for time and current we can set the defualt value for time don't matter for current -> available


private:
    int price;
    string brande;
    string model;
    enum situation current;
    time_t return_time;

};

#endif // CAR_H
