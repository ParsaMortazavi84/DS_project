#include "customer.h"
#include "car.h"
#include "request.h"

customer::customer()
    :user()
{}

customer::customer(string name, string password)
    :user(name, password)
{}

customer::customer(const customer & data)
    : user(data),
    rental_cars(data.rental_cars),
    reserve_requests(data.reserve_requests),
    debt(data.debt),
    sum_of_income(data.sum_of_income)
{}

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
    car temp(rental_cars.get_head()->data);
    rental_cars.deletation(temp);
    return temp;
}

int customer::get_debt()
{
    return debt;
}

void customer::set_debt(int data)
{
    debt += data;
}

doubly_linklist<car> customer::getRental_cars() const
{
    return rental_cars;
}

doubly_linklist<car> customer::get_reserve_requests() const
{
    return reserve_requests;
}
