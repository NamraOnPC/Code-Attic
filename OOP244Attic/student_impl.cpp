
// C++ class implementation 

 #include "student_header.h"
 #include <iomanip>
 #include <iostream>
 #include <cstring>
 using namespace std;

 /* C++ class implementation */ 
 Student::Student() { set( 12345, "ABCF" ); }

 Student::Student(int m, const char * s) { set(m, s); }
 
 void Student::set(int n, const char* g){

	  no = n;

	  strcpy( grade, g );
 }
 
 void Student::display() const { // Warning: Do not omit "const" here!

	cout << setfill('0') << setw(7) << no
	     << setfill( 'x' ) << setw(15) << grade << endl;
 }



