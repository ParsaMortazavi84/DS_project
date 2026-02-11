#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
using namespace std;

#include "customer.h"
#include "car.h"
#include "request.h"
struct keys{
    keys(){

    }
    void set(string new_brand, models new_model){
        brand = new_brand;
        model = new_model;
    }
    bool operator<(const keys& key) const{
        if(brand < key.brand){
            return 1;
        }
        else if(brand == key.brand && model < key.model){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool operator==(const keys& key){
        if(brand == key.brand && model == key.model)
            return 1;
        return 0;
    }


    string brand;
    models model;
};
struct values{

    void set(int new_price, situation new_situation, time_t return_time, condition new_condition){
        price = new_price;
        current_situation = new_situation;
        this->return_time = return_time;
        current_condition = new_condition;
    }


    int price;
    situation current_situation;
    time_t return_time;
    condition current_condition;
};

// we should add some search thing in this class

class AVL_TREE{
private:
    keys key;
    values value;
    AVL_TREE* right;
    AVL_TREE* left;

    int height;




public:

    friend ostream& operator<<(ostream &out, const AVL_TREE& current);


    AVL_TREE(){
        right = nullptr;
        left = nullptr;
        height = 1;
    }
    ~AVL_TREE(){
        height = 0;

    }



    int get_height(AVL_TREE* node) {
        return node ? node->height : 0;
    }




    AVL_TREE *insert(AVL_TREE* current , car new_data)
    {
        keys new_key;
        new_key.set(new_data.brande, new_data.model);


        if(current == NULL){
            current = new AVL_TREE();
            current->set_attributes(new_data);
            current->height = 1;
            return current;
        }
        else if(current->key < new_key){
            current->right = insert(current->right, new_data);
        }
        else if(current->key == new_key){
            cout << "invalid insertion";
            return current;
        }
        else{
            current->left = insert(current->left, new_data);
        }

        current->height = 1 + max_height(get_height(current->left), get_height(current->right));

        //check the balancing
        int balance = get_height(current->left) - get_height(current->right);


        //if not balanced in the left side
        if(balance > 1){
            //left right case
            if(current->left->key < new_key){
                current->left = leftrotation(current->left);
                return rightrotation(current);
            }

            // left left case

            else{
                return rightrotation(current);
            }
        }
        // if not balance in the right side
        else if(balance < -1){
            //right left case

            if(new_key < current->right->key){
                current->right = rightrotation(current->right);
                return leftrotation(current);
            }

            // right right case
            else{
                return leftrotation(current);
            }

        }
        return current;


    }
    AVL_TREE* deletation(AVL_TREE* current, car value)
    {
        keys new_key;
        new_key.set(value.brande, value.model);
        if(current == NULL){
            cout << "Tree is empty";
            return NULL;
        }
        if(new_key < current->key){
            current->left = deletation(current->left, value);
        }
        else if(current->key < new_key){
            current->right = deletation(current->right, value);
        }
        else{
            if(current->left == NULL && current->right == NULL){
                delete current;
                current = NULL;
            }
            //if it has two childs
            else if(current->left != NULL && current->right != NULL){
                AVL_TREE* max = max_utility(current->left);
                current->key = max->key;
                current->value = max->value;
                car target_car;
                target_car.brande = max->key.brand;
                target_car.model = max->key.model;
                deletation(current->left, target_car);
            }
            // if it has only one child
            else{
                AVL_TREE* child = current;
                if(current->right != NULL){
                    current = current->right;
                }
                else{
                    current = current->left;
                }
                child->left = NULL;
                child->right = NULL;
                delete child;
                child = NULL;
            }
        }
        current->height = 1 + max_height(get_height(current->left), get_height(current->right));
        int balance = get_height(current->left) - get_height(current->right);

        //if not balanced in the left side
        if(balance > 1){
            //left right case
            if(current->left->key < new_key){
                current->left = leftrotation(current->left);
                return rightrotation(current);
            }

            // left left case

            else{
                return rightrotation(current);
            }
        }
        // if not balance in the right side
        else if(balance < -1){
            //right left case

            if(new_key < current->right->key){
                current->right = rightrotation(current->right);
                return leftrotation(current);
            }

            // right right case
            else{
                return leftrotation(current);
            }

        }
        return current;
    }

    AVL_TREE *search(AVL_TREE *current, car target)
    {
        if(!current) return current;

        keys new_key;
        new_key.set(target.brande, target.model);
        if(new_key < current->key){
            return search(current->left, target);
        }
        else if(current->key < new_key){
            return search(current->right, target);
        }
        else{
            return current;
        }
    }


    void set_attributes(car new_data){
        key.set(new_data.brande, new_data.model);
        value.set(new_data.price, new_data.current_situation, new_data.return_time, new_data.current_condition);
    }
    void update_reservation_list(AVL_TREE* current, customer client, time_t start_time, time_t end_time)
    {
        request new_request(client, start_time, end_time);
        // add the new_request to current->data.PQ.insert(new_request)
    }

    // balancing
    int max_height(int left_height, int right_height)
    {
        if(left_height < right_height)
            return right_height;
        return left_height;
    }
    AVL_TREE* leftrotation(AVL_TREE* current)
    {
        if(!current || !current->right) return current;

        AVL_TREE* new_data = current->right;
        current->right = new_data->left;
        new_data->left = current;
        current->height = 1 + max_height(get_height(current->left), get_height(current->right));
        new_data->height = 1 + max_height(get_height(new_data->left), get_height(new_data->right));
        return new_data;
    }
    AVL_TREE* rightrotation(AVL_TREE* current)
    {
        if(!current || !current->left) return current;

        AVL_TREE* new_data = current->left;
        current->left = new_data->right;
        new_data->right = current;
        current->height = 1 + max_height(get_height(current->left), get_height(current->right));
        new_data->height = 1 + max_height(get_height(new_data->left), get_height(new_data->right));
        return new_data;
    }

    //display
    void inorder_utility(AVL_TREE* current)
    {
        if(current == NULL){
            return;
        }
        inorder_utility(current->left);
        cout << *current;
        inorder_utility(current->right);
    }
    void preorder_utility(AVL_TREE* current)
    {
        if(current == NULL){
            return;
        }
        cout << *current;
        preorder_utility(current->left);
        preorder_utility(current->right);
    }
    void postorder_utility(AVL_TREE* current){
        if(current == NULL){
            return;
        }
        postorder_utility(current->left);
        postorder_utility(current->right);
        cout << *current;
    }


    AVL_TREE *max_utility(AVL_TREE* current)
    {
        if(!current || current->right == NULL)
            return current;
        else return max_utility(current->right);
    }



private:
    keys key;
    values value;
    AVL_TREE* right;
    AVL_TREE* left;

    int height;

};

ostream& operator<<(ostream& out, const AVL_TREE& current){
    out << "brand: " << current.key.brand << "\t model: " << current.key.model;
    return out;

}


#endif // AVL_TREE_H
