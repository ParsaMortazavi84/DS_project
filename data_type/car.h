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
enum models{
    sedan,
    hatchback,
    hybrid,
    suv
};

enum condition{
    healthy,
    maintenance
};

class car
{
public:
    car();
    car(string , models, int);// for price ,brande and model we should get that from pc
    //but for time and current we can set the defualt value for time don't matter for current -> available
    void set_price(int);

    int get_price();
    bool is_valid(car);
    bool operator==(const car&);
    bool operator<(const car &);
    bool operator>(const car &);

    void print();
// attribute

    int price;
    string brande;
    models model;
    situation current_situation;
    time_t return_time;

    condition current_condition;

    // attribute for reserve PQ


};

#endif // CAR_H
