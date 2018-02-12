
// C++ class declaration and class implementation in ONE source file
// a better design: a header file (.h) + an implmentation file (.cpp)

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/* C++ class declaration 
   - private data members
   - public  memeber functions 
 */

class Student {
		      /* declaration of data members */
     int no;
     char grade[14];

     public:         
		     /* declaration of constuctors */
	Student( );
	Student( int, const char* );
	Student(int);
		     /* declaration of member functions */
	void set( int n,  const char * g );
	void display();
 };

 /* C++ class implementation */
 Student::Student(int d) { set(d, "A+A+");  } 
 Student::Student() { set( 12345, "ABCF" ); }

 Student::Student(int m, const char * s) { set(m, s); }
 
 void Student::set(int n, const char* g){

	  no = n;

	  strcpy( grade, g );
 }
 
 void Student::display() {

	cout << setfill('0') << setw(7) << no
	     << setfill( 'x' ) << setw(15) << grade << endl;
 }


int main(){

    Student c(1111), a, b(9987, "AAAAA");

    c.display();
    a.display();  // what if constructors are missing?
    b.display();

    a.set( 3453, "BBFAC" );
    b.set( 1111, "CCCCCCF" );

    a.display();
    b.display();
    return 0;
}

