#ifndef HEAP_H
#define HEAP_H

#include "queue.h"

template<class T>

class heap
{
private:
    struct Node{
        T data;
        Node* right_child;
        Node* left_child;
        Node* parent;

        Node(T value)
            :data(value)
            ,right_child(nullptr)
            ,left_child(nullptr)
            ,parent(nullptr)
        {}

    };

    Node* root;

    void bubble_up(Node* current){
        if(!current || !current->parent) return;



        if(current->data < current->parent->data){
            // swap
            T temp = current->data;
            current->data = current->parent->data;
            current->parent->data = temp;


            bubble_up(current->parent);
        }
        return;
    }

    Node* get_last_node(){
        queue<Node*> queue_of_node;
        queue_of_node.insert(root);
        Node* last_node;
        while(!queue_of_node.empty()){
            last_node = queue_of_node.pop();
            if(!last_node->left_child)
                queue_of_node.insert(last_node->left_child);
            if(!last_node->right_child)
                queue_of_node.insert(last_node->right_child);
        }
        return last_node;
    }


    void bubble_down(Node* current){

        if(!current) return;

        Node* smallest = current;

        // Find smallest among current and its children
        if(current->left_child && current->left_child->data < smallest->data)
            smallest = current->left_child;

        if(current->right_child && current->right_child->data < smallest->data)
            smallest = current->right_child;

        // If current is not the smallest, swap and continue
        if(smallest != current){
            T temp = current->data;
            current->data = smallest->data;
            smallest->data = temp;

            bubble_down(smallest);
        }


        return;
    }


    void clear(Node* node){
        if(!node) return;

        clear(node->left_child);
        clear(node->right_child);
        delete node;
    }


public:
    heap()
        :root(nullptr)
    {}
    ~heap(){
        clear(root);
    }
    bool empty() const{
        return root == nullptr;
    }

    void insert(T new_data){
        Node* new_node = new Node(new_data);
        if(!root){
            root = new_node;
            return;
        }

        queue<Node*>node_queue;
        node_queue.insert(root);

        while(!node_queue.empty()){
            Node* current = node_queue.pop();

            if(!current->left_child){
                current->left_child = new_node;
                new_node->parent = current;
                break;
            }
            else if(!current->right_child){
                current->right_child = new_node;
                new_node->parent = current;
                break;
            }
            else{
                node_queue.insert(current->left_child);
                node_queue.insert(current->right_child);
            }
        }
        bubble_up(new_node);

    }

    T get_min(){
        return root->data;
    }

    T remove_min(){
        if(empty())
            throw runtime_error("Heap is empty");
        T temp = get_min();

        Node* last_node = get_last_node();

        if(last_node->parent->left_child == last_node){
            last_node->parent->left_child = nullptr;
        }
        else if(last_node->parent->right_child == last_node){
            last_node->parent->right_child = nullptr;
        }
        T last_data = last_node->data;
        last_node->data = root->data;
        root->data = last_data;

        bubble_down(root);

        return temp;

    }



};

#endif // HEAP_H
