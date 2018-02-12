#include <iostream>
using namespace std;
#include <string.h>

class foo {
     int number;
     char string[20];

     public:
     foo( ) { set(3, 5);
	      cout << "1." << endl; }

     ~foo( ) { cout << "bye-bye: " << number << ','
		    << string << endl;              }

     foo( const foo & a ) {

			      cout << "...copy constructor...\n";
			      number = a.number * 2;
			      strcpy( string, a.string );
			      strcat( string, "COPY" );
			      cout << "... copying done...\n";
     }

     void operator = ( const foo & z ) {

	     cout << "...operator =...\n";
	     strcpy( string, z.string );
	     strcat( string, "=" );
	     number = z.number * 3;
	     cout << "...operator = done...\n";
     }

     void set(int a, int b){  number = a * b;
			      strcpy( string, "Winter" ); }

     void messagain( char * );
     void output(){ cout << number << ',' << string << endl;     }

     friend void operator + ( foo, char * );
};

void operator + ( foo  a, char * s ) {

     foo t;

     t = a;

     a.messagain( s );

     a.output();
     t.output();

}

int main() {

     foo a, b;

     char z[] = "oop244";

     a.output();
     b.output();
		  // a = b;
     a + z;

     a.output();
     b.output();

     return 0;
}

void foo::messagain( char * x) {

     strcat(string, x);
     number = number * 10;
}






















