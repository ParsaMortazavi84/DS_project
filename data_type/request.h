#ifndef REQUEST_H
#define REQUEST_H

#include <ctime>
#include "customer.h"

class request
{
public:
    request();
    request(customer, time_t, time_t);

    int operator<(request);
    int comparison(request data, request new_request);

    // getter and setter
    void set_start_time(time_t newStart_time);

    time_t get_end_time() const;

    time_t get_start_time() const;

    void set_end_time(time_t newEnd_time);

    customer get_client() const;
    void set_client(const customer &newClient);

private:
    time_t start_time;
    time_t end_time;
    customer client;

};

#endif // REQUEST_H
