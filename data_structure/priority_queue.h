#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "heap.h"
#include "request.h"
#include <stdexcept>


template<class T>
class priority_queue
{
public:
    priority_queue() = default;

    ~ priority_queue() = default;

    T top() const{
        if(PQ.empty())
            throw runtime_error("PQ is empty");
        return PQ.get_min();
    }
    T pop(){
        if(PQ.empty())
            throw runtime_error("PQ is empty");
        return PQ.remove_min();

    }

    bool empty(){
        return PQ.empty();
    }

    void insert(T new_data){
        PQ.insert(new_data);
    }

private:
    heap<T> PQ;

};

#endif // PRIORITY_QUEUE_H
