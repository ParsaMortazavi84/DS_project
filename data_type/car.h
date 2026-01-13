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
    car();
    car(string , string, int);// for price ,brande and model we should get that from pc
    //but for time and current we can set the defualt value for time don't matter for current -> available
    void set_price(int);

    int get_price();
    int comparison(car , car);
    bool is_valid(car);

    int price;
    string brande;
    string model;
    enum situation current_situation;
    time_t return_time;

};

#endif // CAR_H
