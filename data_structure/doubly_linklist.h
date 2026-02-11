#ifndef DOUBLY_LINKLIST_H
#define DOUBLY_LINKLIST_H

#include<iostream>
using namespace std;

template <class T>
class doubly_linklist
{
public:
    doubly_linklist()
        : head(nullptr),
        tail(nullptr),
        size(0)
    {}
    void insert(const T& new_data)
    {
        Node* new_node = new Node(new_data);
        if(tail == nullptr){
            head = tail = new_node;
        }
        else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;

    }
    void insertFront(const T& new_data) {
        Node* newNode = new Node(new_data);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    bool deletation(const T& target)
    {
        Node* current = head;
        while(current != nullptr){
            if(current->data == target){
                if(current -> prev != nullptr){
                    current->prev->next = current->next;
                }
                else{
                    head = current->next;
                }
                if(current->next != nullptr){
                    if(current->data == target){
                        current->next->prev = current->prev;
                    }
                    else{
                        tail = current->prev;
                    }
                }
                delete current;
                size--;
                return true;
            }
            current = current->next;

        }
        return false;



    }//if data == T delete and next-> before = before and before->next = next


    bool is_valid(T new_data)
    {
        Node* current = head;
        while (current != nullptr) {
            if(current->data == new_data){
                return true;
            }
        }
        return false;
    }
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }
    bool is_empty(){
        return head == nullptr;
    }

    int get_size() const{
        return size;
    }



    struct Node{
    public:
        T data;
        Node* next;
        Node* prev;

        Node(const T& val)
            : data(val),
            next(nullptr),
            prev(nullptr)
        {}
    };

    Node* get_head() const { return head;}

    Node* get_tail() const { return tail;}


private:
// properties   

    Node *tail;
    Node *head;
    int size;

};

#endif // DOUBLY_LINKLIST_H
