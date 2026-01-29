#include "../data_structure/doubly_linklist.h"


template<class T>
doubly_linklist<T>::doubly_linklist() {
}

template<class T>
doubly_linklist<T>* doubly_linklist<T>::insert(doubly_linklist *current, T new_data)
{

    if(current->next == NULL){
        current->next = new doubly_linklist();
        current->next->data = new_data;
        current->next->prev = current;
        current->next->next = NULL;
        return current->next;
    }
    else if(current == NULL){
        current = new doubly_linklist();
        current->data = new_data;
        current->prev = NULL;
        current->next = NULL;
        return current;
    }
    else{
        return insert(current->next, new_data);
    }// the changing that happend in the insert function in the current->next list their saved in the original current \
    soo we return the other insert function beacuse we want to save the current_ptr in the class that we use the doubly_linklist in.
}

template<class T>
doubly_linklist<T>* doubly_linklist<T>::deletation(doubly_linklist *current, T target)
{
    if(current->data == target){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        return current;
    }
    else if(current == NULL){
        return NULL;
    }
    else{
        current->next = deletation(current->next, target);
    }
    return current;


}

template<class T>
int doubly_linklist<T>::is_valid(doubly_linklist* root, T new_data)
{
    while(root != NULL){
        if(new_data.comparison(new_data, root->data)){
            return 1;
        }
        root = root->next;
    }
    return 0;
}


