 // 1. function overloading
 // 2. constructors
 // 3. friend(non-member) function in C++
 //    - a helper function for a C++ class

 // C++ object = private data members + public member functions

 #include <iostream>
 #include <cstring>
 using namespace std;

 class Student {
     int no;
     char grades[14];

     public:
		   // 2 constructors
	Student();
	Student( int, const char* );

	void set();
	void set(int, const char* );
	void display() const;

     friend bool equalgrades( Student, Student );
 };

// a friend function/a helper function: 
// - a non-member fucntion 
// - access privilege to private data members
bool equalgrades( Student one, Student two ) {

	 bool result = false;

	 if ( (strlen(one.grades) == strlen(two.grades)) &&   // private data members
	      (strcmp(one.grades, two.grades) == 0) )         // private data memebrs

	       result = true;

	 return result;
 }

 // 2 constructors
 Student::Student() { set(); }

 Student::Student( int num, const char * s){
     set(num, s);
 }

 // 2 overloaded member functions
 void Student::set() { set( 11111, "AAAAA" ); }

 void Student::set( int n, const char* g ){

     int i;

     if (n > 0)
	 no = n; // accept n if positive
     else
	 no = 0; // store 0 otherwise

     // validate grades received
     for (i = 0; g[i] != '\0' && i < 13; i++) {
	 if (g[i] >= 'A' && g[i] <= 'F' &&
	     g[i] != 'E')
	     grades[i] = g[i]; // A, B, C, D or F
	 else
	     grades[i] = '?';  // else, store ?
     }

     grades[i] = '\0';        // insert the null byte
 }

 // member function
 void Student::display() const {

     cout << "student number: " << no 
	  << " grades: " << grades << endl;
 }

 int main () {

     Student x;    // a C++ object
     x.display();

     Student z( 90876, "FFDC" );  // a C++ object
     z.display();

     cout << "... compare the grades" << endl;

     if ( equalgrades(x,z) )
	  cout << "grades are equal" << endl;
     else cout << "grades are not equal" << endl;

     // an array of 3 C++ objects
     Student a[3];

     cout << "... compare the grades in an array of student objects\n";

     for (int i=0; i<3; i++)
	  a[i].display();    // default consturctor


     a[0].set( 1000, "ABBA" );
     a[1].set( 1001, "ABBABB" );
     a[2].set( 1002, "ABBA" );

     for (int i=0; i<3; i++) {

	  cout << "a[0] and a[" << i<< "]:" << endl;

	  a[0].display(); // member function call
	  a[i].display();

	  if ( equalgrades( a[0], a[i] ) )  // "friend"/helper function call

	       cout << "--- the grades are EQUAL " << endl;

	  else cout << "--- the grades are NOT EQUAL " << endl;
     }
     return 0;
 }
