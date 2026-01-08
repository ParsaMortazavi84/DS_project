#include "doubly_linklist.h"

template<class T>
doubly_linklist<T>::doubly_linklist() {
}

template<class T>
void doubly_linklist<T>::insert(T new_data)
{
    current_ptr->data = new_data;
    doubly_linklist* temp = current_ptr;
    current_ptr = current_ptr->next;
    current_ptr->prev = temp;
    // delete temp;
}

template<class T>
void doubly_linklist<T>::deletation(T target)
{
    doubly_linklist* temp = this;
    while (temp->data != target && temp != NULL)
        temp = temp->next;
    if(temp == NULL){
        cout << "we can't find your car";
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;


}
