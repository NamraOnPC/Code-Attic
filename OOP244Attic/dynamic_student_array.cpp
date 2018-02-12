// Allocate an array of OBJECTS dynamically in C++
// Source: BTP200 (January 2007)
// updated to C++11 standard
// g++ -std=c++0x dynamic_student_array.cpp student_impl.cpp


 #include <iostream>
 using namespace std;

 #include "student_header.h"

 int main( ) {

     int n;

     Student * students;         // step 1 - what does it mean?

     n = 3;

     students = new (nothrow) Student[n]; // step 2 - what does it mean?

     if (students == nullptr) // what does it mean?

	   cout << "memory allocation has failed" << endl;
     else {
	   cout << "memory allocation has succeeded" << endl;

	   students[0].set( 1111, "AAA" );
	   students[1].set( 2222, "BBBA" );
	   students[2].set( 3333, "CCB" );

	   for (int i=0; i < n; i++)

		students[i].display();

	   delete [] students;   // step 3 - what does it mean?

	   students = nullptr;   // step 3 - what does it mean?
     }

     return 0;
 }
