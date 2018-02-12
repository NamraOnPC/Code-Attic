 // 1. function overloading
 // 2. constructors
 // 3. friend(non-member) function vs member function in C++

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

	// member funcion  vs friend function
	// - number of parameters?
	// - an implicit parameter: the current object
	bool equalgrades( Student);
 };

// member function vs friend function
// - Student::
// - data members of the current object

bool Student::equalgrades( Student right ) {

	 // 1. data members of the current object:
	 //    grades, no
	 // 2. private data members of the object right:
	 //    right.grades, right.no

	 bool result = false;

	 if ( (strlen(grades) == strlen(right.grades)) &&
	      (strcmp(grades, right.grades) == 0) )

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


     if ( x.equalgrades(z) )  // member function call
	  cout << "the grades are equal" << endl;
     else cout << "the grades are not equal" << endl;

     // an array of 3 C++ objects
     Student a[3];

     cout << "......\n";
/*
     for (int i=0; i<3; i++)
	  a[i].display();    // default consturctor


     a[0].set( 1000, "ABBA" );
     a[1].set( 1001, "ABBABB" );
     a[2].set( 1002, "ABBA" );

     cout << "... compare the grades of student objects ..." << endl;

     for (int i=0; i<3; i++) {

	  cout << "a[0] and a[" << i<< "]:" << endl;

	  a[0].display(); 
	  a[i].display();

	  if ( a[0].equalgrades( a[i] ) )  // member function call!!!

	       cout << ">>> the grades are EQUAL " << endl;

	  else cout << ">>> the grades are NOT EQUAL " << endl;
     }
*/
     return 0;
 }
