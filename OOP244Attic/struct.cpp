 /* A C++ Program */

 #include <cstring>
 #include <iostream>
 using namespace std;

 // declaration of a structure in C++
 struct Student {

     int no;          // data field
     char grade[14];  // data field

 }; // semicolon!

 
 void display(int, char []);

 int main( ){

     Student x;  // a C++ structure variable; 
		 // the keyword struct is omitted

     x.no = 101;
     strcpy( x.grade, "BCD" );

     display( x.no, x.grade );

     Student hPotter = { 975, {"ABC"} };  // initialization of a C++ structure variable

     display( hPotter.no, hPotter.grade );

     return 0;
 }

 void display( int no, char grade2[] ){

     cout << "Grades for student " << no;

     cout << " : " << grade2 << endl;

 }
