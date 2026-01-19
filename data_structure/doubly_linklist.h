#ifndef DOUBLY_LINKLIST_H
#define DOUBLY_LINKLIST_H

#include<iostream>
using namespace std;

template <class T>
class doubly_linklist
{
public:
    doubly_linklist();
    doubly_linklist* insert(doubly_linklist*, T);//if next == null insert here
    int deletation(doubly_linklist* ,T);//if data == T delete and next-> before = before and before->next = next
    int is_valid(doubly_linklist *, T);




// properties
    T data;
    doubly_linklist* next;
    doubly_linklist* prev;

};

#endif // DOUBLY_LINKLIST_H
