#include "priority_queue.h"

priority_queue::priority_queue() {
    requests = NULL;
}

request priority_queue::top()
{
    return requests->data;
}

request priority_queue::pop()
{
    request temp = requests->data;
    requests = requests->deletation(requests, requests->data);

}

void priority_queue::insert()
{

}


