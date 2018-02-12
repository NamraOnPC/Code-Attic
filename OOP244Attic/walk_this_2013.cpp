
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

    void operator!() { cout << "object: "
			    << title << "," << num << endl;}

	x tryit ( x b ) {
		      *this = b;
			  strcat( b.title, "/" );
			  strcat( b.title, title );
			  b.num += num;
			  !b;
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

	friend void tryit( x a, x b);
};

void tryit( x a, x b){

	a.set( "hello", -999 );
	b.set( "what?", -777 );
	cout << "+++++" << endl;
	!a;
	!b;
}

int main() {

	x y, z("Acchew!"), m("Monday?"), q("oop244?!");

    tryit(m, q);
    cout << "...... main" << endl;
    !m;
    !q;

	m = y.tryit( z );
	cout << "...... main" << endl;

	q.tryit();

	cout << "......bye bye\n";
    !y;
    !z;
    m.operator!();
    q.operator!();
    return 0;
}

