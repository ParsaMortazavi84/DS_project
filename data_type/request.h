#ifndef REQUEST_H
#define REQUEST_H


#include <ctime>

class customer;

class request
{
public:
    request(const customer&, time_t, time_t);

    // Comparison operators - ALL should be const and take const reference
    bool operator<(const request& other) const;
    bool operator>(const request& other) const;
    bool operator==(const request& other) const;

    // Check if this request conflicts with another
    bool conflicts_with(const request& other) const;

    // Check if this request is valid (no conflict)
    bool is_valid() const;  // Maybe check if start_time < end_time

    // Getters - all const
    time_t get_start_time() const;
    time_t get_end_time() const;
    const customer* get_client() const;

    // Setters
    void set_start_time(time_t newStart_time);
    void set_end_time(time_t newEnd_time);
    void set_client(const customer *newClient);

private:
    time_t start_time;
    time_t end_time;
    const customer* client;

};

#endif // REQUEST_H
