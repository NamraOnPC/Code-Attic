
#include <iostream>
using namespace std;

class Bond {

   protected:
	  int  x, y;

   public:
      Bond() { cout << "Bond.1." << endl;
		   x = -15; y = -20;         }

      Bond(int b1, int b2) { cout << "Bond.2.\n";
					 x=b1; y=b2; }

	  ~Bond() { cout << "clean up Bond: " << x << "," << y << endl; }

      int foo() { return x+y; }

      void show() { cout << "***" << x << "***" << y << endl; }
};

class Daisy: public Bond {


	protected:
	   char z;

    public:
	   Daisy() { cout << "Daisy.1." << endl; z = '%'; }

	   Daisy(int i, int j, char t);

	   Daisy(char t) { cout << "Daisy.3.\n";
			   z = t; }

	  ~Daisy() { cout << "clean up Daisy..." << z << "..." << endl; }

	  int hello() { return x-y; }

	  void show() {  Bond::show();
			 cout << z << endl; }
};

class Ethan: public Daisy {

      double s;

    public:
      Ethan(int, int, char, double);

      ~Ethan() { cout << "clean up Ethan!" << endl; }

      double foo() { int m;
		     m = hello() * s;
		     return m;         }

      void show() { cout.setf(ios::fixed);
		    cout.precision(2);
		    cout << s << endl;
		    Daisy::show();         }
};

Daisy::Daisy(int i, int j, char t): Bond(i,j) {

     cout << "Daisy.2." << endl;
     z = t; }

Ethan::Ethan(int a, int b, char c, double d): Daisy(c) {
		     s=d+a+b;
		     cout << "Ethan.1." << endl; }


int main()
{
   Daisy d( 2, 4, '?');

   d.show();

   cout << d.foo() << endl;

   Ethan e( 3, 5, '&', 10.00 );

   e.show();

   cout << e.hello() << endl;

   cout.setf(ios::fixed);
   cout.precision(2);

   cout << e.foo() << endl;

   Daisy x, y('$');

   x.show();
   y.show();

   return 0;
}
