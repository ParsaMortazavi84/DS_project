#include "customer.h"

customer::customer(string name, string password)
    :user(name, password)
{}

void customer::reserve_request_function(car requested_car)
{
    reserve_requests->insert(reserve_requests, requested_car);
}

void customer::rental_request(car requested_car)
{
    rental_cars->insert(rental_cars, requested_car);
    dept += requested_car.price;
}

bool customer::valid_reservation(car, time_t)
{
    //that should be in the managing customer
}

int customer::calculate_penalty()
{
    // that should be in the managing customer too
}

void customer::payment()
{
    dept = 0;
}
