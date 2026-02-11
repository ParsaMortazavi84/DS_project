#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
using namespace std;

#include "customer.h"
#include "car.h"
#include "request.h"
#include "priority_queue.h"

class AVL_TREE;

class AVL_node {
    friend class AVL_TREE;

private:
    car data;  // Store car object directly
    AVL_node* left;
    AVL_node* right;
    int height;

public:
    AVL_node(const car& car_data)
        : data(car_data), left(nullptr), right(nullptr), height(1) {}

    const car& get_data() const { return data; }
};


// we should add some search thing in this class

class AVL_TREE{

private:
    AVL_node* root;


    int get_height(AVL_node* node){
        return node ? node->height : 0;
    }

    int get_balance(AVL_node* node){
        return node ? get_height(node->left) - get_height(node->right) : 0;
    }

    void update_height(AVL_node* node){
        if(node)
            node->height = 1 + maximum(get_height(node->left), get_height(node->right));
    }

    int maximum(int height1, int height2){
        if(height1 < height2)
            return height2;
        return height1;
    }

    AVL_node* right_rotation(AVL_node* y){
        AVL_node* x = y->left;
        AVL_node* T2 = x->right;

        x->right = y;
        y->left = T2;

        update_height(y);
        update_height(x);

        return x;
    }

    AVL_node* left_rotation(AVL_node* x){
        AVL_node* y = x->right;
        AVL_node* T1 = y->left;

        y->left = x;
        x->right = T1;

        update_height(x);
        update_height(y);

        return y;
    }
    AVL_node* insert(AVL_node* node, car new_car) {
        // 1. Perform normal BST insertion
        if (!node) {
            return new AVL_node(new_car);
        }

        if (new_car < node->data) {
            node->left = insert(node->left, new_car);
        }
        else if (node->data < new_car) {  // This uses operator<
            node->right = insert(node->right, new_car);
        }
        else {
            throw runtime_error("Car already exists in inventory");
        }

        // 2. Update height
        update_height(node);

        // 3. Get balance factor
        int balance = get_balance(node);

        // 4. Balance the tree
        // Left Left Case
        if (balance > 1 && new_car < node->left->data) {
            return right_rotation(node);
        }

        // Left Right Case
        if (balance > 1 && new_car > node->left->data) {
            node->left = left_rotation(node->left);
            return right_rotation(node);
        }

        // Right Right Case - FIXED: new_car > node->right->data
        if (balance < -1 && new_car > node->right->data) {
            return left_rotation(node);
        }

        // Right Left Case
        if (balance < -1 && new_car < node->right->data) {
            node->right = right_rotation(node->right);
            return left_rotation(node);
        }

        return node;
    }


    AVL_node* find_min(AVL_node* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    AVL_node* remove(AVL_node* node, car& target) {
        if (!node) {
            return nullptr;
        }

        // 1. Perform BST deletion
        if (target < node->data) {
            node->left = remove(node->left, target);
        }
        else if (node->data < target) {
            node->right = remove(node->right, target);
        }
        else {
            // Node to delete found
            if (!node->left || !node->right) {
                AVL_node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;  // Copy the non-null child
                }
                delete temp;
            }
            else {
                // Node with two children
                AVL_node* temp = find_min(node->right);
                node->data = temp->data;  // Copy data
                node->right = remove(node->right, temp->data);
            }
        }

        if (!node) {
            return nullptr;
        }

        // 2. Update height
        update_height(node);

        // 3. Balance the tree
        int balance = get_balance(node);

        // Left Left Case
        if (balance > 1 && get_balance(node->left) >= 0) {
            return right_rotation(node);
        }

        // Left Right Case
        if (balance > 1 && get_balance(node->left) < 0) {
            node->left = left_rotation(node->left);
            return right_rotation(node);
        }

        // Right Right Case
        if (balance < -1 && get_balance(node->right) <= 0) {
            return left_rotation(node);
        }

        // Right Left Case
        if (balance < -1 && get_balance(node->right) > 0) {
            node->right = right_rotation(node->right);
            return left_rotation(node);
        }

        return node;
    }

    // Search helper
    AVL_node* search(AVL_node* node, car target) const {
        if (!node || node->data == target) {
            return node;
        }

        if (target < node->data) {
            return search(node->left, target);
        }
        else {
            return search(node->right, target);
        }
    }

    // Clear helper
    void clear(AVL_node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // Traversal helpers
    void inorder(AVL_node* node, ostream& out) const {
        if (node) {
            inorder(node->left, out);
            node->data.print();
            inorder(node->right, out);
        }
    }

    void preorder(AVL_node* node, ostream& out) const {
        if (node) {
            node->data.print();
            preorder(node->left, out);
            preorder(node->right, out);
        }
    }

    void postorder(AVL_node* node, ostream& out) const {
        if (node) {
            postorder(node->left, out);
            postorder(node->right, out);
            node->data.print();
        }
    }
public:
    AVL_TREE() : root(nullptr) {}

    ~AVL_TREE() {
        clear();
    }

    // Disable copy constructor and assignment operator
    AVL_TREE(const AVL_TREE&) = delete;
    AVL_TREE& operator=(const AVL_TREE&) = delete;

    void insert(const car& new_car) {
        root = insert(root, new_car);
    }

    void remove(const car& target) {
        root = remove(root, target);
    }

    bool search(const car& target) const {
        return search(root, target) != nullptr;
    }

    car* find(const car& target) {
        AVL_node* node = search(root, target);
        return node ? &(node->data) : nullptr;
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    bool empty() const {
        return root == nullptr;
    }

    void inorder(ostream& out = cout) const {
        inorder(root, out);
    }

    void preorder(ostream& out = cout) const {
        preorder(root, out);
    }

    void postorder(ostream& out = cout) const {
        postorder(root, out);
    }

    // Add reservation to a car
    // void add_reservation(const car& target,request new_request) {
    //     AVL_node* node = search(root, target);
    //     if (node) {
    //         node->reservation_queue.insert(new_request);
    //     }
    //     else {
    //         throw runtime_error("Car not found");
    //     }
    // }


};


#endif // AVL_TREE_H
