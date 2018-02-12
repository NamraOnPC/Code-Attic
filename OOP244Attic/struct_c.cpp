/* A C++/C Program */

 #include <cstring> 
 #include <iostream>
 using namespace std;

 /* declaration of a structure in C style 
    - concept: composite data type 
	       (a group of data elements)
  */
 struct Student {

     int no;          // data field
     char grade[14];  // data field

 }; // semicolon!


 void display(int, char []);

 int main( ){

     struct Student x;   /* a C structure variable */

     x.no = 101;
     strcpy( x.grade, "BCD" );

     ++x.no;
     strcat( x.grade, "12345" );

     display( x.no, x.grade );

     struct Student hPotter = { 975, {"ABC"} };  // initialization of a C structure variable

     display( hPotter.no, hPotter.grade );

     return 0;
 }

 void display( int no, char grade[] ){

     cout << "Grades for student " << no;

     cout << " : " << grade << endl;

 }
