#include <iostream>
#include <cstring>
using namespace std;

class foo {

     int number;
     char string[20];

public:
     foo( ) { set(3, 5); }

     foo( int m, const char * s) { set(m, m+1);
				   strcpy(string, s);       }

     foo(  const foo & c ) { cout << "... hello ...\n";
			    number = c.number + 2;
			    strcpy( string, c.string );
			    strcat( string, ".1.2.3" );
			    cout << "... bye bye ..." << endl;  }

     ~foo( ) { cout << number << "," << string << " - out of scope\n"; }

     void set(int a, int b){ number = a + b;
			     strcpy( string, "summer" ); }
     void messagain();

     void output(){ cout << number << ',' << string << endl;  }
};

void showyanothing( foo );

void showyasomething( foo & );

int main() {

     /* 1 */
     foo a, b;

     /* 2 */
     showyanothing( a );

     /* 3 */
     a.output();

     cout << "#####" << endl;

     showyasomething( b );

     a.output();
     b.output();

     cout << "/////" << endl;

     foo x(7, "c++");
     
     foo y=x;   // 3. copy constructor

     cout << "...don't forget about the destructor..." 
	  << "\n4 objects will go out of scope" << endl;

     return 0;
}

void foo::messagain() { strcat(string,".0.1.0");
			number = number * 2;     }

void showyanothing( foo z ) { cout << "... how are you?\n";
			      z.messagain(); 
			      z.output(); 
			      cout << "...something\n"; }


void showyasomething(foo & z) {  cout << "... wow!" << endl;
				foo a; // foo a=z;
				a = z;
				
				z.messagain();
				cout << "wow.1" << '\n';  
				z.output();
				a.output();
				cout << "...nothing\n";
				//return a; // 2. copy constructor
			     }





















