#include <iostream>
using namespace std;

// free function: operator+(int,Box)

class Box {
   char symbol;
   int length;
   int width;

   public:
      Box();
      Box(char, int, int);

      void set(char, int, int);
      void set(int, int);
      void set(char, int);
      void set(char);

      void setLength(int);
      void setWidth(int);
      void setSymbol(char);

      char getSymbol();       // access functions
      int  getLength();
      int  getWidth();
				  // BINARY operator functions
      Box  operator+(int delta);
      Box  operator+(Box b2);

      Box  enlarge(int deltaL, int deltaW);

      void showBox(int);
};

// free function!
Box operator+(int delta, Box b1)

{
   Box t;

   // use ACCESS FUNCTIONS

   t.setSymbol(b1.getSymbol());
   t.setLength(b1.getLength() + delta);
   t.setWidth(b1.getWidth() + delta);

   return t;
}



// ***** IMPLEMENTATION OF THE CLASS *****

Box::Box()
{ set(1,1); }

Box::Box(char c, int lg, int wd)
{ set(c, lg, wd); }

// access functions
char Box::getSymbol()
{
	return symbol;
}

int Box::getLength()
{
	return length;
}

int Box::getWidth()
{
	return width;
}

void Box::setSymbol(char c)
{
	symbol = c;
}

void Box::setLength(int j)
{
	length = j;
}

void Box::setWidth(int w)
{
	width = w;
}

void Box::showBox(int m)
{
	for(int i=0; i<width; i++) {
	   for (int k=0; k<m; k++) 
		    cout << " ";

	   for(int j=0; j<length; j++) 
		   cout << symbol;
	   cout << "\n";
	}
}

void Box::set(char c, int lg, int w)
{
   symbol = c;
   length = lg;
   width = w;
}

void Box::set(int lg, int w)
{
   symbol = '*';   // default

   length = lg;
   width = w;

   // set( '*', lg, w );
}

void Box::set(char c)
{
   symbol = c;

   // default values
   length = 1;
   width = 1;

  // set( c, 1, 1 );
}

// implementation of the operator functions as MEMBER functions

Box  Box::operator+(int delta) // the current object is NOT changed!
{
   Box local;

   // data members of the CURRENT OBJECT: symbol, length, width
   local.symbol = symbol;
   local.length = length + delta;
   local.width  = width + delta;

   return local;

}

Box  Box::operator+(Box b2) // the current object is NOT changed!
{
   Box local;

   // data members of the CURRENT OBJECT: symbol, length, width
   local.symbol = symbol;   // or b2.symbol!
   local.length = length + b2.length;
   local.width  = width + b2.width;
   return local;
}

Box  Box::enlarge(int deltaL, int deltaW) // the current object is NOT changed!
{
   Box local;

   local.symbol = symbol;
   local.length = length + deltaL;
   local.width  = width + deltaW;
   return local;
}
