#include "managing_cars.h"
#include "managing_customer.h"
#include "registration.h"
#include "car.h"
#include <iostream>

using namespace std;

#include <avl_tree.h>
#include <car.h>

int main()
{
    // car new_data1("benze_c300", sedan, 50000);
    // car new_data2("benze_c200", sedan, 100000);
    // car new_data3("benze_c100", sedan, 10000);
    // car new_data4("benze_c100", sedan, 20000);
    // car new_data5("benze_jak", sedan, 1000000);
    // doubly_linklist<car> cars09;
    // cars09.insert(new_data1);
    // cars09.insert(new_data2);
    // cout << cars09.get_head()->data.get_price();
    managing_cars management_cars;
    managing_customer management_customer;
    registration registeration_guests;


    int choosen = 0;

    while(choosen != 4){
        cout << "if you want ...." << endl;
        cout << "to login or sign_up as ordinary user press 0" << endl;
        cout << "to login or sign_up as customer press 1" << endl;
        if(choosen == 0){// that's mean she / he choose ordinary user
            while(1){


                int a;
                cout << "if you want to ...." << endl;
                cout << "login press 0" << endl;
                cout << "sign_up press 1" << endl;
                cout << "exit press 2";
                cin >> a;
                string name, pass;
                switch (a){
                case 0:

                    while(1){
                        cout << "enter the name and password" << endl;
                        cout << "name: "; cin >> name;
                        cout << "password: "; cin >> pass;
                        if(registeration_guests.sign_in(name , pass)){
                            break;
                        }
                        else{
                            cout << "your username is invalid" << endl;
                        }
                    }
                    cout << "now you can login...\n";
                    break;

                case 1:
                    // for valid login
                    while(1){
                        cout << "name: "; cin >> name;
                        cout << "password: "; cin >> pass;
                        if(registeration_guests.login(name , pass)){
                            break;
                        }
                        else{
                            cout << "the password or username is wrong please try again" << endl;
                        }
                    }
                    // for valid guest feature
                    while(1){
                        int b;
                        cout << "if you want to ...." << endl;
                        cout << "see the list of cars press 0" << endl;
                        cout << "see the list of cars by brand filter press 1" << endl;
                        cout << "see the list of cars by model filter press 2" << endl;
                        cout << "see the list of cars by price filter press 3" << endl;
                        cout << "if you want to see the exact detail of a car press 4\n";
                        cin >> b;
                        if(b == 0){
                            management_cars.print();
                        }
                        else if(b == 1){
                            string brand;
                            cout << "brand: ";
                            cin >> brand;
                            management_cars.searching_base_on_brande(brand);
                        }
                        else if(b == 2){
                            string current_situation;
                            models model;
                            cout << "model: sedan/hatchback/hybrid/suv";
                            while(1){
                                cin >> current_situation;
                                if(current_situation != "sedan" && current_situation!= "hatchback" && current_situation != "hybrid" && current_situation != "suv"){
                                    cout  << "invalid input";
                                }
                                else  if(current_situation == "sedan"){
                                    management_cars.searching_base_on_model(sedan);
                                    break;
                                }
                                else  if(current_situation == "sedan"){
                                    management_cars.searching_base_on_model(hatchback);
                                    break;
                                }
                                else  if(current_situation == "hybrid"){
                                    management_cars.searching_base_on_model(hybrid);
                                    break;
                                }
                                else  if(current_situation == "suv"){
                                    management_cars.searching_base_on_model(suv);
                                    break;
                                }
                            }
                        }
                        else if(b == 3){

                        }
                        else if(b > 3){
                            cout << "invalid input";
                        }
                    }
                    break;
                case 2:

                }
            }
        }
        else if(choosen == 1){

        }
        else if(choosen == 2){

        }
        else if(choosen == 3){

        }
        else if(choosen == 4){
            break;
        }
        else{
            cout << "please try again invalind input" << endl;
        }
    }






}
