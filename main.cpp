#include <iostream>

using namespace std;

#include <avl_tree.h>
#include <car.h>

int main()
{
    car new_data1("benze_c300", sedan, 50000);
    car new_data2("benze_c200", sedan, 100000);
    car new_data3("benze_c100", sedan, 10000);
    car new_data4("benze_c100", sedan, 20000);
    car new_data5("benze_jak", sedan, 1000000);
    AVL_TREE* cars = NULL;
    cars = new AVL_TREE;
    cars = cars->insert(cars, new_data1);
    cars->insert(cars, new_data2);
    cars->insert(cars, new_data3);
    cars->insert(cars, new_data4);
    cars->insert(cars, new_data5);
    cout << cars->right->value.price;

}
