
#include <cstring>
#include <iostream>
using namespace std;

struct xyz {

   char x[21];
   int  y;
   char z;

};

void show( char [], int, char );

int main(){

    struct xyz x;

    strcpy( x.x, "hello" );
    x.y = 100;
    x.z = '?';
    
    show( x.x, x.y, x.z );

    struct xyz y = { {"BTP200"}, -999, 'B' };

    struct xyz z;

    --(x.y);
    strcat( y.x, "56789" );
    (y.z)++;
    
    z = x;

    show( y.x, y.y, y.z );

    show (z.x, z.y, z.z);    
    return 0;
}

void show( char a[], int b, char c ){

     cout << a << ", " << b << ", " << c << endl;
}