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
    doubly_linklist<car> cars09;
    cars09.insert(new_data1);
    cars09.insert(new_data2);
    cout << cars09.get_head()->data.get_price();

}
