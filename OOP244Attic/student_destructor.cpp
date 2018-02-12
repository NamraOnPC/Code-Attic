
// class declaration and class implementation in ONE source file
// a better design: a header file (.h) + an implmentation file (.cpp)

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/* C++ class declaration 
   - private data members
   - public  member functions
   + constructors
   + destructor   
 */

class Student {
		      /* declarations of data members */
     int no;
     char grades[14];

     public:         
	 /* declarations of constructors */
	 Student( );
	 Student( int, const char* );

	 /* declarations of member functions */
	 void set( int n,  const char * g );
	 void display() const;
	 
	 /* declaration of the destructor*/
	 ~Student();
 };

 /* C++ class implementation */

 Student::Student() { set( 1010, "ABCD" ); }

 Student::Student(int m, const char * s) { set(m, s); }

 void Student::set(int n, const char* g){

	  no = n;
	  strcpy( grades, g );
 }
 
 void Student::display() const {

	cout << setfill('0') << setw(7) << no
	     << setfill( 'x' ) << setw(15) << grades << endl;
 }
 
 Student::~Student() { 
    cout << "...destructor: invoked when an object goes out of scope (i.e. destroyed)\n"
	 << "...bye bye: " << no << "," << grades << endl;
 }

int main(void){

    Student a, b( 9876, "AAFF" );

    //a.display();
    //b.display();

    a.set( 3453, "BBFAC" );
    // b.set( 1111, "CCCCCCF" );

    //a.display();
    //b.display();
	
    // Part 2: an array of C++ objects (invocation of constructors and destructor)
	
    Student c[5]; 
	   
    for (int j=0; j<5; j++)
	 c[j].display();
	  
    c[0].set( 123, "AAA" );
    c[2].set( 456, "BBB" );
    c[4].set( 789, "CCC" );
	   
    for (int k=0; k<5; k++)
	 c[k].display();

    // Question: How many object will go out scope?

    return 0;
}
