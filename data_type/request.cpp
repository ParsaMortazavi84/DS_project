#include "request.h"
#include "customer.h"  // NOW we include the FULL customer definition
using namespace std;


request::request(const customer& client, time_t start_time, time_t end_time)
    : start_time(start_time),
    end_time(end_time),
    client(&client)
{}

// For MIN-HEAP based on EARLIEST END TIME (common for scheduling)
bool request::operator<(const request& other) const {
    return this->end_time < other.end_time;
}

bool request::operator>(const request& other) const {
    return other < *this;
}

bool request::operator==(const request& other) const{
    return this->start_time == other.start_time &&
           this->end_time == other.end_time &&
           this->client == other.client;
}

// Check if two requests overlap in time
bool request::conflicts_with(const request& other) const {
    return !(this->end_time <= other.start_time || other.end_time <= this->start_time);
}

// Getters
time_t request::get_start_time() const {
    return start_time;
}

time_t request::get_end_time() const {
    return end_time;
}

const customer* request::get_client() const {
    return client;
}

// Setters
void request::set_start_time(time_t newStart_time) {
    start_time = newStart_time;
}

void request::set_end_time(time_t newEnd_time) {
    end_time = newEnd_time;
}

void request::set_client(const customer *newClient) {
    client = newClient;
}
