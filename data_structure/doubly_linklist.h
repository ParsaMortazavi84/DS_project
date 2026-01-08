#ifndef DOUBLY_LINKLIST_H
#define DOUBLY_LINKLIST_H

#include<iostream>
using namespace std;

template <class T>
class doubly_linklist
{
public:
    doubly_linklist();
    void insert(T);//if next == null insert here
    void deletation(T);//if data == T delete and next-> before = before and before->next = next
    void set_time();

private:
    T data;
    T* next;
    T* prev;

};

#endif // DOUBLY_LINKLIST_H
