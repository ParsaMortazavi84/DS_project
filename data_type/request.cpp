#include "request.h"

request::request() {}

request::request(customer client, time_t start_time, time_t end_time)
    :start_time(start_time),
    end_time(end_time),
    client(client)
{}

int request::operator<(request another_request)
{
    if(this->end_time < another_request.start_time){
        return 1;
    }
    return 0;
}

int request::comparison(request data, request new_request)
{
    if(data.start_time <= new_request.start_time && new_request.start_time < data.end_time){
        return 1; // that mean isvalid
    }
    else if(data.start_time < new_request.end_time && new_request.end_time <= data.end_time){
        return 1;
    }
    return 0;

}


time_t request::get_end_time() const
{
    return end_time;
}

time_t request::get_start_time() const
{
    return start_time;
}

void request::set_end_time(time_t newEnd_time)
{
    end_time = newEnd_time;
}

customer request::get_client() const
{
    return client;
}

void request::set_client(const customer &newClient)
{
    client = newClient;
}

void request::set_start_time(time_t newStart_time)
{
    start_time = newStart_time;
}
