#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "doubly_linklist.h"
#include "request.h"


class priority_queue
{
public:
    priority_queue();
    request top();
    request pop();
    void insert();

private:
    doubly_linklist<request> *requests;



};

#endif // PRIORITY_QUEUE_H
