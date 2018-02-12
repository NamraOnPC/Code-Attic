#include <iostream>
using namespace std;
#include <string.h>

class foo {
     int  number;
     char string[20];

     public:
     foo( ) { set(3, 5);
		  cout << "1." << endl; }

     ~foo( ) { cout << "bye-bye: " << number << ','
			    << string << endl;              }

     foo( const foo & a ) {

			      cout << "...2. copy constructor...\n";
			      number = a.number * 2;
			      strcpy( string, a.string );
			      strcat( string, "+COPY" );
			      cout << "... copying done...\n";
     }

     void operator = ( const foo & z ) {

	     cout << "...3. assignment operator...\n";
	     strcpy( string, z.string );
	     strcat( string, "+=" );
	     number = z.number * 3;
	     cout << "... operator = done...\n";
     }

     void set(int a, int b){  number = a * b;
			      strcpy( string, "Winter" ); }

     void messagain( foo );
     void output(){ cout << number << ',' << string << endl;     }
};

void foo::messagain( foo x ) {
     
	 cout << "...4. messagain..." << endl;
	 x.output();
	 (*this).output();
     cout << "... done with messagain" << endl;
}

int main() {

     foo a, b;

     a.messagain(b);
	 
     a = b;
	 
     a.output();
     b.output();

     return 0;
}
























