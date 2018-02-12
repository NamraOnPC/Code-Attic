#include <iostream>
using namespace std;
#include <string.h>

class foo {
     int number;
     char string[20];

     public:
     foo( ) { set(3, 5);
	          cout << "1." << endl; }

     ~foo( ) { cout << "...bye-bye: " << number << ','
		            << string << endl;              }

     foo( const foo & a ) {

			      cout << "...copy constructor: watch out...\n";
			      number = a.number * 2;
			      strcpy( string, a.string );
			      strcat( string, "COPY" );
			      cout << "... copying done...\n";
     }

     void operator = ( const foo & a ) {

	     cout << "...operator =: be careful...\n";
	     strcpy( string, a.string );
	     strcat( string, "=" );
	     number = a.number * 3;
	     cout << "...operator = done...\n";
     }

     void set(int a, int b){ number = a * b;
					         strcpy( string, "Winter" ); }

     void messagain( char * );

     void output(){ cout << number << ',' << string << endl;     }

   friend void operator + ( foo, char * );

};

void operator + ( foo a, char * s ) {

     foo t;

     t = a;

     a.messagain( s );

     a.output();
     t.output();
     cout << "+: the end..." << endl;
}

int main() {

     foo a, b;

     char z[] = "BTP200";

     a.output();
     b.output();

     a + z;

     a.output();
     b.output();

     return 0;
}

void foo::messagain( char * x) {

     strcat(string, x);
     number = number * 10;
}






















