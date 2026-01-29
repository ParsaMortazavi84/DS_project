#include "heap.h"
#include <cstddef>
template<class T>
heap<T>::heap() {}

template<class T>
heap<T>* heap<T>::insert(heap<T>* root ,T new_data)
{
    if(root == NULL){
        root = new heap<T>;
        root->data = new_data;
        root->left_child = NULL;
        root->right_child;
        return root;
    }
    else{
        heap<T>* last_node, temp = root;
        queue<heap<T>*> BFS_traversal;
        BFS_traversal.insert(root);
        while(BFS_traversal.empty() != true){
            heap<T>* data = BFS_traversal.pop();
            if(data->left_child != NULL){
                BFS_traversal.insert(data->left_child);
            }
            else{
                last_node = data->left_child;
                break;
            }
            if(data->right_child != NULL){
                BFS_traversal.insert(data->right_child);
            }
            else{
                last_node = data->right_child;
                break;
            }

        }
        last_node = new heap<T>;
        last_node->data = new_data;
        last_node->left_child = NULL;
        last_node->right_child = NULL;
    }
    //balacing
    bubble_up(root, root->data);
    return root;

}

template<class T>
int heap<T>::bubble_up(heap<T> *current, T parent_value)/// we want a Min heap
{
    if(current == NULL){
        return -1;
    }
    int resualt = bubble_up(current->left_child, current->data);
    if(resualt == 1){// bubble_up
        T temp = current->data;
        current = current->left_child->data;
        current->left_child->data = temp;
    }
    resualt = bubble_up(current->right_child, current->data);
    if(resualt == 1){// bubble_up
        T temp = current->data;
        current = current->right_child->data;
        current->right_child->data = temp;
    }

    if(parent_value <= current->data){
        return 0;
    }
    else{// this mean that the child is lower that it's parent so becuase we want to impliment a Min_heap we switch them data
        return 1;
    }
}

template<class T>
void heap<T>::bubble_down(heap<T> *current)
{
    if(current == NULL){
        return;
    }

    if(current->left_child != NULL && current->left_child->data < current->data){
        T temp = current->data;
        current->data = current->left_child->data;
        current->left_child->data = temp;
    }
    if(current->right_child != NULL && current->right_child->data < current->data){
        T temp = current->data;
        current->data = current->right_child->data;
        current->right_child->data = temp;
    }

    bubble_down(current->left_child);
    bubble_down(current->right_child);



}

template<class T>
heap<T>* heap<T>::remove_root(heap<T>* root)
{
    T deleted_value = root->data;
    heap<T>* last_node = root->last_node(root);
    heap<T>* parent_of_last_node = root->get_parent(root, last_node);

    if(root->left_child == NULL && root->right_child == NULL){
        delete root;
        return NULL;
    }

    root->data = last_node->data;
    if(parent_of_last_node -> left_child == last_node){
        delete parent_of_last_node->left_child;
        parent_of_last_node->left_child = NULL;
    }
    else{
        delete parent_of_last_node->right_child;
        parent_of_last_node->right_child = NULL;
    }

    bubble_down(root);
    return root;

}

template<class T>
heap<T> *heap<T>::last_node(heap<T> *root)
{
    if(root == NULL){
        return root;
    }
    else{
        heap<T>* last_node, temp = root;
        queue<heap<T>*> BFS_traversal;
        BFS_traversal.insert(root);
        while(BFS_traversal.empty() != true){
            heap<T>* data = BFS_traversal.pop();
            if(data->left_child != NULL){
                BFS_traversal.insert(data->left_child);
            }
            else{
                last_node = data->left_child;
                break;
            }
            if(data->right_child != NULL){
                BFS_traversal.insert(data->right_child);
            }
            else{
                last_node = data->right_child;
                break;
            }

        }
    }
    return last_node;
}

template<class T>
heap<T> *heap<T>::get_parent(heap<T> *root, heap<T> *target)
{
    if(root == NULL || target == NULL || root == target) return NULL;

    queue<heap<T>*> q;
    q.push(root);

    while(!q.empty()){
        heap<T>* current = q.pop();

        if((current->left_child == target) || (current->right_child == target)){
            return current;
        }

        if(current->left_child != NULL){
            q.push(current->left_child);
        }
        if(current->right_child != NULL){
            q.push(current->right_child);
        }
    }

    return NULL;
}
