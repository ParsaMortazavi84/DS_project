#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <car.h>

struct keys{
    keys();
    void set(string new_brand, models new_model){
        brand = new_brand;
        model = new_model;
    }
    bool operator<(const keys key){
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
    bool operator==(const keys key){
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


    friend ostream& operator<<(ostream out, AVL_TREE*);

public:
    AVL_TREE();
    AVL_TREE *insert(AVL_TREE* , car);
    AVL_TREE* deletation(AVL_TREE*, car);
    AVL_TREE* search(AVL_TREE *current, car);
    void set_attributes(car);


    // balancing
    void balance();
    int max_height(int, int);
    AVL_TREE* leftrotation(AVL_TREE*);
    AVL_TREE* rightrotation(AVL_TREE*);

    //display
    void inorder_utility(AVL_TREE*);
    void preorder_utility(AVL_TREE*);
    void postorder_utility(AVL_TREE*);


    AVL_TREE *max_utility(AVL_TREE*);



// attribute
    keys key;
    values value;
    AVL_TREE* right;
    AVL_TREE* left;

    int height;

};

ostream& operator<<(ostream &out, const AVL_TREE &current){
    out << "brand: " << current.key.brand << "\t model: " << current.key.model;
    return out;
}


#endif // AVL_TREE_H
