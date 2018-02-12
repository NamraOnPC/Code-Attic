
#include <iostream>
#include <cstring>
using namespace std;

class x{

	char title[31];
	int  num;

    public:

	x() { set();
	      cout << "1. " << title << ","
		   << num << " stored" << endl;
	    }

	x( const char s[] ) { set(s, 200);
				cout << "2. " << title << ","
				     << num << " stored" << endl;
				  }

	void set( const char * s, int k ) { strcpy(title, s);
					     strcat( title, "-more-" );
					     num = k+5; }

       void set() { set( "*Thank you*", 100); }


	x tryit ( x& b ) {
			  *this = b;
			  strcat( b.title, "/" );
			  strcat( b.title, title );
			  b.num += num;
			 
			  cout << "3. " << title << ","
			       << num << endl;
			  return *this;
	}

	x tryit() { x a( "cn tower/" ), b;

		    b = tryit(a);
		    cout << "4. " << title << ","
			 << num << endl;
		    return *this;
	}

};

int main() {

	x y, z("Acchew!"), m("Monday?"), q("oop244?!");

	cout << "...... main" << endl;

	m = y.tryit( z );
	cout << "...... main" << endl;

	//m.display();

	q.tryit();

	cout << "......bye bye\n";
  
	return 0;
}

