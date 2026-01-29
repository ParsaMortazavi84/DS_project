#include "linklist.h"

template<class T>
linklist<T>::linklist() {}

template<class T>
linklist<T> *linklist<T>::insert(linklist<T>* current, T data)
{
    if(current == NULL){
        current = new linklist();
        current->data = data;
        current->next = NULL;
        return current;
    }
    else if(current -> next == NULL){
        current->next = new linklist();
        current->next->data = data;
        current->next->next = NULL;
        return current->next;
    }
    else{
        return insert(current->next, data);
    }
}

template<class T>
T linklist<T>::get_data()
{
    return data;
}
