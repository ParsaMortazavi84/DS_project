#include "queue.h"
template<class T>
queue<T>::queue() {
    root = NULL;
    current_ptr;
}

template<class T>
void queue<T>::insert(T new_data)
{
    if(root == NULL){
        root = root->insert(root, new_data);
        current_ptr = root;
    }
    else
        current_ptr = current_ptr.insert(current_ptr, new_data);
}

template<class T>
T queue<T>::top()
{
    return root->get_data();
}

template<class T>
T queue<T>::pop()
{
    linklist<T>* temp = root;
    root = root->next;
    T tmp_data = temp->get_data();
    temp->next = NULL;
    delete temp;
    temp = NULL;
    return tmp_data;
}

template<class T>
bool queue<T>::empty()
{
    if(root == NULL)
        return true;
    return false;
}

