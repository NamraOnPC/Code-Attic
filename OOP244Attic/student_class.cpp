
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

 // declaration of a C++ class
 // - data members
 // - member functions

 class Student {

     // declaration of private data members
     int no;
     char grade[14];

     public:

	// declaration of public member functions
	void set( int n, const char * g );
	void display();

 };


 int main () {

       Student harry, larry;   // 2 C++ objects

       //harry.no = 99999;
       //strcpy( harry.grade, "ABCD" );


       harry.set( 1234, "ABACA" ); // member function call

       larry.set( 5678, "BBCDCA" );

       harry.display();

       larry.display();

       return 0;
 }



/* implemenation of a C++ class */

 void Student::set(int n, const char* g){

	  no = n;
	  strcpy( grade, g );
 }

 void Student::display() {

	cout << setfill( '0' ) << setw(7) << no
	     << setfill( 'x' ) << setw(15) << grade << endl;

	// How many 'x'es are displayed?
 }












