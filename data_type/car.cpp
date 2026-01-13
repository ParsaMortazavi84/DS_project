#include "car.h"

car::car()
{}

car::car(string name, string model, int price)
    :price(price),
    brande(name),
    model(model)
{
    current_situation = available;
}



int car::get_price()
{
    return price;
}

int car::comparison(car data, car new_car)
{

    if(data.price == new_car.price && data.brande == new_car.brande && data.model == new_car.model){
        return 1;
    }
    return 0;
}

bool car::is_valid(car new_car)
{
    if(brande == new_car.brande && model == new_car.model){
        return 0;
    }
    return 1;
}



