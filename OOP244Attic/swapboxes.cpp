#include <iostream>
using namespace std;
#include "Boxes2.cpp"

// pointers
void swap( Box*  b1, Box  * b2 );

// C++ reference parameters
void swapagain( Box& c, Box & d );

int  main()
{
   Box Bluebox('B',10,5), Greenbox('G',15,3);

   Bluebox.showBox(2);  cout << "\n";
   Greenbox.showBox(4);
 
   cout << "\n... swap...\n";
 
   swap( &Bluebox, &Greenbox); // pass by address
 
   Bluebox.showBox(2); cout << "\n";
   Greenbox.showBox(4);

   cout << "\n... swap again...\n\n...Enter a  character: ";
   char junk;
   cin >> junk;

   swapagain( Bluebox, Greenbox );  // pass by reference
 
   Bluebox.showBox(2); cout << "\n";
   Greenbox.showBox(4);

  return 0;
}

void swap( Box *b1, Box *b2 )
{
   Box t;

   t = *b1;

   *b1 = *b2;
   *b2 = t;
}

void swapagain( Box&  c, Box& d ) // the value of c: an address 
{
   Box t;

   t = c;       
   c = d;
   d = t;
}











