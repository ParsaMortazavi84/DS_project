#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

template <class T>

class linklist
{
public:
    linklist()
        :head(nullptr)
        ,tail(nullptr)
        ,size(0)
    {}
    ~linklist(){
        clear();
    }

    void insert(T data)
    {
        Node* new_node = new Node(data);
        if(tail == nullptr){
            head = tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    bool remove(T target) {
        if (!head) {
            return false;
        }

        if (head->data == target) {
            Node* temp = head;
            head = head->next;

            // If list becomes empty
            if (head == nullptr) {
                tail = nullptr;
            }

            delete temp;
            size--;
            return true;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != target) {
            prev = current;
            current = current->next;
        }

        // Target not found
        if (current == nullptr) {
            return false;
        }

        // Found the node to remove
        prev->next = current->next;

        // If removing tail
        if (current == tail) {
            tail = prev;
        }

        delete current;
        size--;
        return true;
    }

    bool remove_root(){
        if(!head) return false;
        head = head->next;
        return true;
    }

    T get_first_element(){
        return head->data;
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

    bool empty() const {
        return head == nullptr;
    }

    int get_size() const {
        return size;
    }



    struct Node{
        T data;
        Node* next;

        Node(T new_data)
            :next(nullptr)
            ,data(new_data)
        {}
    };

    Node* get_head(){
        return head;
    }
    Node* get_tail(){
        return tail;
    }


private:
    Node* head;
    Node* tail;
    int size;
};

#endif // LINKLIST_H
