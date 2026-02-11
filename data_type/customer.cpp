#include "customer.h"

customer::customer()
    :user()
{}

customer::customer(string name, string password)
    :user(name, password)
{}

void customer::reserve_request_function(car requested_car)
{
    reserve_requests.insert(requested_car);
}

void customer::rental_request(car requested_car)
{
    rental_cars.insert(requested_car);
    dept += requested_car.price;
}

car customer::payment()
{
    dept = 0;


}
