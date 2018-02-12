
#include <iostream>
#include <cstring>
using namespace std;

class x{

	char title[41];
	int  num;

    public:

	x() { set( "*Thanksgiving*", 100);
	      cout << "1." << title << "," << num << " created\n";
	    }

	x( const char s[] ) {  set(s, 200);
			       cout << "2." << title << "," 
				    << num << " created\n";
			    }

       void set( const char * s, int k ) { strcpy(title, s); num = k;
					   cout << "2B.\n";        }

       void show() { cout << "object: " << title 
			  << "," << num << "\n"; }

       x operator + ( x b ) {

	  cout << "3.+++" << title << "," << num << endl;

	  strcat( title, b.title );
	  num += b.num;

	  show();

	  return *this;
       }

       void operator !() { cout << "4.!!!!" << title 
				<< num << endl;

			   x a( "/cn tower/" );

			   *this = a + "seneca";
			  }
};  // end class

x operator + ( x b, const char * s );

int main()
{
	x y, z("Acchew!"), m("Monday?"), q("oop244:-)");

	m = y + z;

	cout << "..." << endl;

	!q;

	cout << "bye bye" << endl;

	y.show();
	z.show();
	m.show();
	q.show();

	return 0;
}

x operator + ( x b, const char * s ) {

  x z(s);

  cout << "5.**********" << s << endl;

  z.show();

  z = z + b;

  return z;
}
