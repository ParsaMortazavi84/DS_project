#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

template <class T>

class linklist
{
public:
    linklist();
    linklist<T>* insert(linklist<T>* current, T);
    T get_data();

private:
    T data;
    linklist<T>* next;
};

#endif // LINKLIST_H
