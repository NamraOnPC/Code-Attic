#include <iostream>
using namespace std;

#include <string.h>

class foo {

     int number;
     char string[20];

public:
     foo( ) { set(3, 5); }

     foo( int m, const char * s) { set(m, m+1);
				   strcpy(string, s);       }

     foo( const foo & c ) { cout << "...hello...\n";
			    number = c.number + 2;
			    strcpy( string, c.string );
			    strcat( string, ".1.2.3" );
			    cout << "...bye bye..." << endl;  }

     ~foo( ) { cout << number << "," << string << " - out of scope\n"; }

     void set(int a, int b){ number = a + b;
			     strcpy( string, "summer" ); }
     void messagain();

     void output(){ cout << number << ',' << string << endl;  }
};

void showyanothing( foo );

void showyasomething( foo & );

int main() {

     foo a, b;

     showyanothing( a );

     a.output();

     cout << "#####" << endl;

     showyasomething( b );

     b.output();

     cout << "/////" << endl;

     foo x(7, "c++");
     
     foo y=x;   // copy constructor

     cout << "...don't forget about the destructor..." << endl;

     return 0;
}

void foo::messagain() { strcat(string,".0.1.0");
			number = number * 2;     }

void showyanothing( foo z ) { z.messagain(); 
			      z.output(); 
			      cout << "...something\n"; }


void showyasomething(foo & z) { z.messagain();  
				z.output();
				cout << "...nothing\n"; }





















