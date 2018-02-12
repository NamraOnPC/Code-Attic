
 /* function overloading
  */

 struct Student {
     int no;
     char grade[14];
 };

 #include <iostream>
 using namespace std;

 #include <string.h>

 void set( Student* harry);

 void set( Student * ptr_std, int n, char z[] );  // function overloading in C++

 void display(const Student* harry); // constant pointer

 int main( ) {

     Student hPotter;

     set( &hPotter );

     display( &hPotter );

     set( &hPotter, 802, "BCDAC" );

     display( &hPotter );

     return 0;
 }

 void set( Student* harry ){

     (*harry).no = 975;   // harry -> no = 975;
     (*harry).grade[0] = 'A';
     (*harry).grade[1] = 'B';
     (*harry).grade[2] = 'C';
     (*harry).grade[3] = '\0';  // the null byte

 }

 void display(const Student* harry){

     cout << "Grades for student " << (*harry).no;

     cout << " : " << (*harry).grade << endl;   // a string

 }

 void set( Student * ptr_std, int n, char z[] ) {

	 ptr_std->no = n;

	 strcpy( ptr_std->grade, z );
 }








