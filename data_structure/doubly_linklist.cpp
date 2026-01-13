#include "../data_structure/doubly_linklist.h"

template<class T>
int doubly_linklist<T>::id = 0;

template<class T>
doubly_linklist<T>::doubly_linklist() {
    id++;
}

template<class T>
doubly_linklist<T>* doubly_linklist<T>::insert(doubly_linklist *current, T new_data)
{
    doubly_linklist *return_ptr;
    if(current->next == NULL){
        doubly_linklist* temp = new doubly_linklist;
        temp->data = new_data;
        temp->prev = current;
        temp->next = NULL;
        current->next = temp;

        return current -> next;
    }
    else if(current == NULL){
        doubly_linklist* temp = new doubly_linklist*;
        temp->data = new_data;
        temp->prev = NULL;
        temp->next = NULL;
        current = temp;
        return current;
    }
    else{
        return_ptr = insert(current->next, new_data);
    }
    return current->next;
}

template<class T>
int doubly_linklist<T>::deletation(doubly_linklist *current, T target)
{
    if(current->data == target){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        return 1;
    }
    else if(current == NULL){
        return 0;
    }
    else{
        deletation(current->next, target);
    }

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


