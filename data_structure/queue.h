#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
#include "linklist.h"

template <class T>

class queue
{
public:
    queue();
    void insert(T);
    T top();
    T pop();

    bool empty();


private:
    linklist<T>* root;
    linklist<T> current_ptr;
};

#endif // QUEUE_H
