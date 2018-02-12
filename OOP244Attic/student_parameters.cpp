/* Passing C++ objects and object addresses
   BTP200 (Winter 2014)
   Peter Liu
 */

 #include <iostream>
 #include <cstring>
 #include <iomanip>
 using namespace std;

 class Student {
     int no;
     char grade[14];

     public:
	Student();
	Student(int, char*);
	void set(int, char*);
	void display();
 };

 void passCopy( Student std );
 void passAddress( Student* ptr_std );

 /* implementation of the C++ class */
 Student::Student() { set(1234, "AAAA"); }

 Student::Student(int num, char* grades){
    set(num, grades);
 }

 void Student::set(int n, char * s){
      no = n;
      strcpy( grade, s );
 }

 void Student::display(){
    cout << setw(7) << no << setw(14) << grade << endl;
 };

 /* implementaton of two C-like functions */
 void passCopy( Student std ){
    
    //std.no = -1111;

    std.set( 77777, "FFFFF" );
    std.display();
 }

 void passAddress( Student* ptr_std ){

    ptr_std->set( 66666, "CCCCC" );
    ptr_std->display();
 }

 int main( ) {

     Student one, two( 10102, "DDDDD" );

     one.display();
     two.display();

     passCopy( one );
     one.display();

     passAddress( &two );
     two.display();

     return 0;
 }

