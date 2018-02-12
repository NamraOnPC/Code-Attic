
#include <stdio.h>
#include <string.h>

class x{

	char title[31];
	int  num;

    public:

	x() { set( "*Thank you*", 100);
	      printf( "1.%s, %d created\n", title, num );
	    }

	x( char s[] ) { set(s, 200);
			printf( "2.%s, %d created\n", title, num );
				  }

        void set( char * s, int k ) { strcpy(title, s);
                                      strcat( title, "-more-" );
                                      num = k+5; }

        void show() { printf( "object: %s, %d\n", title, num ); }

	x tryit ( x b ) { *this = b;

			  strcat( b.title, "/" );
			  strcat( b.title, title );

			  b.num += num;

			  b.show();

			  printf( "3.%s, %d...\n", title, num );

			  return *this;
			 }


	x tryit() { x a( "cn tower/" ), b;

	            b = tryit(a);

	            printf( "4.%s, %d...\n", title, num );

	            return *this;
	          }
};

int main()
{
	x y, z("Acchew!"), m("Monday?"), q("oop244?!");

	m = y.tryit( z  );

	q.tryit();

	printf( "......bye bye\n");

       y.show();
       z.show();
       m.show();
       q.show();

       return 0;
}

