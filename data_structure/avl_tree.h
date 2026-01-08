#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<car.h>

class AVL_TREE
{
public:
    AVL_TREE();
    void insert(car);
    void balance();
private:
    car data;
    AVL_TREE* right;
    AVL_TREE* left;
};

#endif // AVL_TREE_H
