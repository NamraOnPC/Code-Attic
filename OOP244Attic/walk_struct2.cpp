
 #include <iostream>
 using namespace std;

 struct xyz {
      int f1;
      char f2[14];
 };

 void set( xyz*, int, char  );

 void display( xyz  );

 int main( ) {

     xyz x, y, z;

     set( &x, 1234, 'F' );
     set( &y, -345, 'M' );
     z = x;
     set( &z, 1, 'R' );

     display( x );
     display( y );
     display( z);

     return 0;
 }

 void set( xyz* y, int m, char c ){

     (*y).f1 = m;
     (*y).f2[0] = c;
     (*y).f2[1] = c+2;
     (*y).f2[2] = c-3;
     (*y).f2[3] = '\0';

     cout << y->f1 << "," << y->f2 << endl;

     y->f1 += m;
	 y->f2[1] += 4;
	 y->f2[2] -= 2;
 }

 void display( xyz z){

     cout << "hello: " << z.f1;
     cout << " : " << z.f2 << endl;
 }
