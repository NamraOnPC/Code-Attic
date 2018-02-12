\
// current object
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/* C++ class declaration 
   - private data members
   - public  memeber functions 
 */

class Student {
		      /* declarations of data members */
     int no;
     char grade[14];

     public:         
		     /* declarations of constuctors */
	 Student( );
	 Student( int, const char* );

		     /* declarations of member functions */
	void set( int n,  const char * g );
	void display();
	
	Student update( const char* );
 };

 /* C++ class implementation */
 
 Student Student::update( const char* list ){
 
      Student temp;

      temp.no = no;   // (*this).no;  
      strcpy(temp.grade, list);

      *this = temp;
      return *this;
 }

 Student::Student() { set( 12345, "FFFFF" ); }

 Student::Student(int m, const char * s) { set(m, s); }

 void Student::set(int n, const char* g){

	  no = n;

	  strcpy( grade, g );
 }
 
 void Student::display() {

	cout << setfill('0') << setw(7) << no
	     << setfill( 'x' ) << setw(15) << grade << endl;
 }

int main(void){

    Student a, b( 9876, "AAFF" );

    a.display();
    b.display();

    a = b.update( "BBB" );
	
    a.display();
    b.display();
    return 0;
}
