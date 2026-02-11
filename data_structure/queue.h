#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
#include "linklist.h"

template <class T>

class queue
{
public:
    queue() {
        list = NULL;
    }
    ~queue() {
        clear();
    }

    bool empty(){
        return list.empty();
    }

    void insert(T new_data){
        list.insert(new_data);
    }
    T top(){
        if(empty()){
            throw runtime_error("Queue is empty");
        }
        return list.get_first_element();
    }
    T pop(){
        if(empty()){
            throw runtime_error("Queue is empty");
        }
        T value = top();
        bool success = list.remove(value);  // Uses value-based removal

        if (!success) {
            throw runtime_error("Queue pop failed");
        }
        return value;
    }

    bool empty() const{
        return list.empty();
    }

    void clear(){
        list.clear();
    }


private:
    linklist<T> list;
};

#endif // QUEUE_H
