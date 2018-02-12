
#include <iostream>
#include <cstring>
using namespace std;

class x{

	char title[31];
	int  num;

    public:
	x() { set();
	      cout << "1. " << title << ","
		   << num << endl;
	    }

	x( const char* s ) { set(s, 200);
				         cout << "2. " << title << ","
				              << num  << endl;   }

    void set( const char * s, int k ) { 
	              strcpy(title, s);
				  strcat( title, "-MORE-" );
				  num = k + 5; }

    void set() { set( "*THANK YOU*", 100); }

    void foo( x& a) { a.set( "HELLO!", 300 ); }
	
	x tryit ( x b ) {
	          
		x t;		  
		t = *this;
		*this = b;
		b.set( "SCARRY!", -666 );
			  
		set( "WHAT?", 555 );
			  
		cout << "3:b: " << b.title <<  "," << b.num << endl;
		cout << "3:: " << title << ","
			 << num << endl;
				   
	    return t;
	}
	
	void show() { cout << "title: " << title
	                   << "num: " << num << endl; }
};


int main() {

	x y, z("Acchew!"), m("Monday?");

    y.show(); z.show(); m.show();
	
	cout << "///" << endl;
	
	y.foo( z );
	y.show(); z.show();
	
	cout << "$$$" << endl;
	
	m = y.tryit( z );
	y.show(); z.show(); m.show();
    return 0;
}

