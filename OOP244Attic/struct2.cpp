/* Passing a C++ structure to a function
 */

 struct Student {
     int no;
     char grade[14];
 };

 #include <iostream>
 using namespace std;

 void display( Student std );

 int main( ) {

     Student hPotter = { 975, {"ABC"}};

     display( hPotter );

     display( hPotter );

     return 0;
 }
 void display( Student std ){

     cout << "Grades for student " << std.no;
     cout << " : " << std.grade << endl;

     std.no = -12345;
     

 }







