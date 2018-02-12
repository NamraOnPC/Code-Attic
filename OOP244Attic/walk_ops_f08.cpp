
#include <stdio.h>
#include <string.h>

class x{

	char title[31];
	int  num;

    public:

	x() { set( "*Thanksgiving*", 100);
	      printf( "1.%s, %d created\n", title, num );
	    }

	x( const char s[] ) { set(s, 200);
				printf( "2.%s, %d created\n", title, num );
				  }

    void set( const char * s, int k ) { strcpy(title, s); num = k;
				  printf( "2B.\n" );        }

    void show() { printf( "object: %s, %d\n", title, num ); }

   x operator + ( x b ) {

	  printf( "3.+++%s, %d\n", title, num );

	  strcat( title, b.title );
	  num += b.num;

	  show();

	  return *this;
    }

	void operator !() { printf( "4.!!!!%s, %d\n", title, num );

				x a( "/cn tower/" );

			       *this = a + "seneca";
			      }
};

x operator + ( x b, const char * s );

int main()
{
	x y, z("Acchew!"), m("Monday?"), q("oop244:-)");

	m = y + z;

	!q;

	printf( "bye bye\n");

    y.show();
    z.show();
    m.show();
    q.show();

	return 0;
}

x operator + ( x b, const char * s ) {

  x z(s);

  printf( "5.**********%s\n", s );

  z.show();

  z = z + b;

  return z;
}
