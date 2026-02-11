#include "car.h"

car::car()
{}

car::car(string name, models model, int price)
    :price(price),
    brande(name),
    model(model)
{
    current_situation = available;
    current_condition = healthy;
}



int car::get_price()
{
    return price;
}


bool car::is_valid(car new_car)
{
    if(brande == new_car.brande && model == new_car.model){
        return 0;
    }
    return 1;
}

bool car::operator==(const car &new_car)
{
    if(this->price == new_car.price && this->brande == new_car.brande && this->model == new_car.model){
        return 1;
    }
    return 0;
}

bool car::operator<(const car& target)
{
    if(brande < target.brande){
        return true;
    }
    else if(brande == target.brande && model < target.model){
        return true;
    }
    else{
        return false;
    }
}

bool car::operator>(const car& target)
{
    if(brande > target.brande) {  // Changed to >
        return true;
    }
    else if(brande == target.brande && model > target.model) {  // Changed to >
        return true;
    }
    else {
        return false;
    }
}

void car::print()
{
    cout << "brand: " << brande << "\tmodel: " << model << endl;
    cout << "price: " << price << endl;
    cout << "current_situation: " << current_situation << endl;
    cout << "current_condition: " <<  current_condition << endl;

    cout << "return_time: " << return_time << endl;

}



