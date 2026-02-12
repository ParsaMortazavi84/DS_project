#include "customer.h"

customer::customer()
    :user()
{}

customer::customer(string name, string password)
    :user(name, password)
{}

customer::customer(const customer & data)
{
    this->debt = data.debt;
    this->sum_of_income = data.sum_of_income;
    this->rental_cars = this->rental_cars;
    this->reserve_requests = this->reserve_requests;
}

void customer::reserve_request_function(car requested_car)
{
    reserve_requests.insert(requested_car);
}

void customer::rental_request(car requested_car)
{
    rental_cars.insert(requested_car);
    debt += requested_car.price;
}

bool customer::equal(const customer &target)
{
    if(this->getName() == target.getName() && this->getPassword() == target.getPassword()){
        return true;
    }
    return false;
}

car customer::payment()
{
    debt = 0;

}

int customer::get_debt()
{
    return debt;
}

int customer::set_debt(int data)
{
    debt += data;
}
