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
        avl->insert(avl, new_car);
        return true;
    }
    else{
        current_ptr = cars->insert(current_ptr, new_car);
        avl->insert(avl, new_car);
        return true;
    }


}

void managing_cars::deletation(car target)
{
    cars->deletation(cars, target);
    avl->deletation(avl, target);
}

void managing_cars::exact_search(car target)// in this function we should do the finding job in the avl tree
{
    doubly_linklist<car>* temp = cars;
    while(temp != NULL){
        if(temp->data.brande == target.brande && temp->data.model == target.model){
            cout << "brand: " << target.brande << "\t model: " << target.model;
            if(temp->data.current_situation == available){
                cout << "situation: " << "available";
            }
            else{
                cout << "return time: " << temp->data.return_time;
            }

        }
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

void managing_cars::searching_base_on_brande(string brande)// we should change that and serach for that in the avl
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

void managing_cars::searching_base_on_model(models model)
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
