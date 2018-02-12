/* 1. C++ reference parameters
   2. function overloading (many different functions with the SAME NAME)
   3. parameter: an unmodifiable address of an array (const)
      a) array synatx
      b) pointer syntax
 */

#include <iostream>
using namespace std;

struct Item{
   int   qty;
   float price;
};

/* function overloading */

void foo(Item, int );

void foo(Item &); // a C++ reference parameter

float foo(const Item [], int );

int main(void){

    Item one = { 100, 4.56 };

    foo(one, 9999);
	
    foo(one);

    cout << one.qty << "," << one.price << endl;


    // Part 2
    Item goods[4] = { {123, 4.56}, {456, 2.66}, {789, 9.55}, {809, 6.75} };
    
    int size = 4;

    cout << "the highest price: $" << foo(goods, size) << endl;
}

void foo(Item haha, int m){
     cout << m << endl;
     cout << haha.qty << "," << haha.price << endl;
}

void foo(Item& item){
   cout << item.qty << "," << item.price << endl;
   item.qty = -11999;
}


// list: an UNMODIFIABLE address of an array (const)
float foo( const Item list [], int num ){

    int k;
    float highest = 0.0;

    for (k=0; k < num; k++)
	 if ( list[k].price > highest )
	     highest = list[k].price;

    // list[0] = -9999;

    return highest;
}
