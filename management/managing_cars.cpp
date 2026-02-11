#include "managing_cars.h"

managing_cars::managing_cars() {}

bool managing_cars::insert(car new_car)
{
    cars.insert(new_car);
    avl = avl->insert(avl, new_car);

}

void managing_cars::deletation(car target)
{
    cars.deletation(target);
    avl = avl->deletation(avl, target);
}

car managing_cars::exact_search(car target)// in this function we should do the finding job in the avl tree
{
    AVL_TREE* current = avl->search(avl, target);
    car return_car;
    return_car.return_time = current->value.return_time;
    return_car.current_condition = current->value.current_condition;
    return_car.current_situation = current->value.current_situation;
    return_car.brande = current->key.brand;
    return_car.model = current->key.model;
    return_car.price = current->value.price;
    return return_car;
}

bool managing_cars::is_valid_insert(const car& new_car) // if we have a same car (same in the brand and model) the insertation was invalid
{
    return cars.is_valid(new_car);
}

void managing_cars::searching_base_on_brande(string brande)// we should change that and searching in the avl
{// we can have an array of brand because in the other site we can choose more that one of that for example brande list
    int id = 0;
    doubly_linklist<car>::Node* temp = cars.get_head();
    while(temp != NULL){
        if(temp->data.brande ==  brande){
            cout << id++ << " : " << brande << "/" << temp->data.model;
        }
        temp = temp->next;
    }

}

void managing_cars::searching_base_on_price(int low_bounder, int high_bounder)
{
    int id = 0;
    doubly_linklist<car>::Node* temp = cars.get_head();
    while(temp != NULL){
        if(low_bounder <= temp->data.price && temp->data.price <= high_bounder){
            cout << id++ << temp->data.brande << "/" << temp->data.model;
        }
        temp = temp->next;
    }

}

void managing_cars::searching_base_on_model(models model)
{
    int id = 0;
    doubly_linklist<car>::Node* temp = cars.get_head();
    while(temp != NULL){
        if(temp->data.model ==  model){
            cout << id++ << " : " << temp->data.brande << "/" << model;
        }
        temp = temp->next;
    }

}

void managing_cars::update(customer current_customer, car target, time_t start_time, time_t end_time)
{
    // we should add that request to the car that be in cars \
    so first of all we should find the car
    // in the avl
    AVL_TREE* current = avl->search(avl, target);
    current->update_reservation_list(current, current_customer, start_time, end_time);

    // doubly_linklist
    doubly_linklist<car>::Node* root = cars.get_head();
    while(root != NULL){
        if(root->data.model == target.model && root->data.brande == target.brande){
            break;
        }
    }
    // we find our target in the doubly_linklist
    request new_request(current_customer, start_time, end_time);
    // add that in the PQ root->data.PQ.insert(new_request)
}
