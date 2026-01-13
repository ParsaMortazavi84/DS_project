#include "managing_cars.h"

managing_cars::managing_cars() {}

bool managing_cars::insert(car new_car)
{
    if(is_valid_insert(new_car) == 0){
        return 0;
    }
    if(cars == NULL){
        cars = cars->insert(cars, new_car);
        current_ptr = cars;
        return true;
    }
    else{
        current_ptr = cars->insert(current_ptr, new_car);
        return true;
    }

}

bool managing_cars::is_valid_insert(car new_car) // if we have a same car (same in the brand and model) the insertation was invalid
{
    doubly_linklist<car>* temp = cars;
    while(temp != NULL){
        if(temp->data.is_valid(new_car) == 0){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

void managing_cars::searching_base_on_brande(string brande)
{
    int id = 0;
    doubly_linklist<car>* temp = cars;
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
    doubly_linklist<car>* temp = cars;
    while(temp != NULL){
        if(low_bounder <= temp->data.price && temp->data.price <= high_bounder){
            cout << id++ << temp->data.brande << "/" << temp->data.model;
        }
        temp = temp->next;
    }

}

void managing_cars::searching_base_on_model(string model)
{
    int id = 0;
    doubly_linklist<car>* temp = cars;
    while(temp != NULL){
        if(temp->data.model ==  model){
            cout << id++ << " : " << temp->data.brande << "/" << model;
        }
        temp = temp->next;
    }

}
