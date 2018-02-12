
#include <iostream.h>

class B {

   protected:
	  int  x, y;
   public:
      B() { cout << "B.1." << endl;
		x=-20; y=-30; }

      B(int b1, int b2) { cout << "B.2\n";
				      x=b1; y=b2; }

      int foo() { return x+y; }

      void show() { cout << "..." << x << "..." << y << endl; }
};

class D: public B {

	char z;

    public:
	   D() {cout << "D.1." << endl; z = '?'; }

	   D(int i, int j, char t);

	   D(char t) { cout << "D.3.\n";
			   z = t; }

       int minus() { return x-y; }

       void show() { B::show();  // call a shadowed function
		      cout << "..." << z << endl; }
};


class E: public D {

	double t;

	public:

       E( int, int , char, double );

       void show() { cout << minus() << ',' << foo() << endl; }
};

D::D(int i, int j, char t): B(i,j) {

     cout << "D.2.\n";
     z = t; }

E::E(int a, int b, char c, double d): D(c) { t = a+b+d;
					     cout << "E.1." << endl; }

int main()
{
   D d( 1, 2, '$');

   E e( 3, 5, '@', 9.9 );

   d.show();
   e.show();

   return 0;
}
