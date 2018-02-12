// C++ structures:
//     private data members;
//     public  member functions

 #include <iostream>
 #include <cstring>
 using namespace std;

 struct Student {

	 // private data members
     private:
	int no;
	char grades[14];

     // public member functions
     public:
	void set( int, const char* );
	void display();  // no parameters!
			 // struct2.cpp: void display( Student std);
 };


 int main( ) {

     // a C++ object defined as a C++ structure variable
     Student hPotter;

     /* hPotter.no = 10123; */
     /* strcpy( hPotter.grade, "ABC" ); */

     // member function call
     hPotter.set( 10123, "ABC" );

     // member function call
     hPotter.display(); // no parameters! Where do the values come from?

     hPotter.set( 98765, "FFF" );
     hPotter.display();

     return 0;
 }

 // implementation of a member function; use of ::
 void Student::set( int m, const char* s ){

     no = m;               // no of what?
     strcpy( grades, s );  // grades of what?
 }

 // implementation of a member function; use of ::
 void Student::display(){

     cout << "student number: " << no;       // no of what?
     cout << ", student grades: " << grades  // no of what?
	  << endl;

     // ok?
     // no = -12345;
 }







