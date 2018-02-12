
// the current object

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/* C++ class declaration 
   - declarations of private data members
   - declarations of public  memeber functions: function prototypes 
 */

class Student {
		      /* declarations of private data members */
     int no;
     char grades[14];

     public:         
		     /* declarations of constuctors */
	 Student( );
	 Student( int, const char* );

		     /* declarations of public member functions */
	void set( int n,  const char * g );
	void display() const;

	Student update( const char* );
 };

 /* C++ class implementation */
 
 // this member function returns "an old copy" of the current object
 Student Student::update( const char* list ){
 
    //Student oldcopy = *this;   // this: a system pointer to the current object
			       // *this: the current object (in the main function)
			      
	
    strcpy(grades, list);     // grade: data member of the current object
    return *this;            // Question: return *this???
 }

 Student::Student() { set( 12345, "FFFFF" ); }

 Student::Student(int m, const char * s) { set(m, s); }

 void Student::set(int n, const char* g){

	  no = n;

	  strcpy( grades, g );
 }
 
 void Student::display() const {

	cout << setfill('0') << setw(7) 
	     << no << "  "
	     << setfill( 'x' ) << setw(10) << " " 
	     << grades << endl;
 }

int main(void){

    Student a, b( 9876, "FFFF" ), old;

    a.display();  // the current object: a
    b.display();  // the current object: b

    cout << "...update the grades" << endl;

    old = b.update( "AAAA" );  // the current object: b
	
    b.display();
    old.display();

    //
    b.update("CCC").update("DDD");
    b.display();

    return 0;
}
