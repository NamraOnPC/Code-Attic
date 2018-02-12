/* Passing the address of a C++ structure variable
 */

 struct Student {
     int no;
     char grade[14];
 };

 #include <iostream>
 using namespace std;

 void set( Student * ptr_std );

 void display( Student harry );

 int main( ) {

     Student hPotter;    // a C++ structure variable

     set( &hPotter );

     display( hPotter );

     return 0;
 }
 void set( Student* ptr_std ){

     
     (*ptr_std).no = 9754;
     (*ptr_std).grade[0] = 'A';
     (*ptr_std).grade[1] = 'B';
     (*ptr_std).grade[2] = 'C';

     (*ptr_std).grade[3] = '\0';
     
     /*     
	ptr_std->no = 9999;
	ptr_std->grade[0] = 'F';
	ptr_std->grade[1] = 'A';
	ptr_std->grade[2] = 'B';
	ptr_std->grade[3] = '\0';
      */
 }

 void display( Student harry ){

     cout << "Grades for student " << harry.no;

     cout << " : " << harry.grade << endl;

 }
