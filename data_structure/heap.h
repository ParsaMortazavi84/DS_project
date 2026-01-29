#ifndef HEAP_H
#define HEAP_H

#include "queue.h"

template<class T>

class heap
{

public:
    heap();
    heap<T> *insert(heap<T>*, T);
    int bubble_up(heap<T>*, T);// that is check if the parent (if min heap) lower than it's child them we should change the data of that two
    void bubble_down(heap<T> *current);
    heap<T> *remove_root(heap<T>*);
    heap<T>* last_node(heap<T>*);
    heap<T>* get_parent(heap<T>*, heap<T>*);

private:
    T data;
    heap<T>* right_child;
    heap<T>* left_child;
};

#endif // HEAP_H
