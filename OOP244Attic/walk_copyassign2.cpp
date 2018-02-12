#include <iostream>
using namespace std;
#include <string.h>

class foo {
     int number;
     char string[30];

     public:
     foo( ) { set(3, 5);
	          cout << "1." << endl; }

     ~foo( ) { cout << "bye-bye: " << number << ','
		           << string << endl;              }

     foo( const foo & a ) {
			      cout << "...copy constructor...\n";
			      number = a.number * 2;
			      strcpy( string, a.string );
			      strcat( string, "#COPY" );
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
			                  strcpy( string, "OLYMPICS 2014" ); }

     void messagain( char * );
     void output(){ cout << number << ',' << string << endl;     }
};

void hello( foo  a, char * s ) {
     foo t;
     t = a;
     a.messagain( s );
	 
	 cout << "...hello" << endl;
     a.output();
     t.output();
	 
	 cout << "...hello done" << endl;
}

int main() {
     foo a, b;
     char z[] = "BTP200";

     a.output();
     b.output();
     a = b;
     hello(a, z);
     a.output();
     b.output();
     return 0;
}

void foo::messagain( char * x) {
     strcat(string, x);
     number = number * 10;
}