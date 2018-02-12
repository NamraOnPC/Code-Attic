 // operator overloading
 // the this pointer

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

	student equalgrades( sttudent );

	// operator overloading!
	// a copy of an object is returned
	Student operator >( Student );
 };

// member function vs friend function
// - return a copy of a Student object!
Student Student::operator >( Student right ) {

	 // data members of the current object:
	 // grades, no

	 Student temp; // initialized by the default constructor

	 bool done = false;

	 for (int i=0; i<strlen(grades) && 
		       i<strlen(right.grades) && !done; i++)

	      if ( grades[i] < right.grades[i] ){
		   temp = *this;  // a copy of the current object
		   done = true;
	      }
	      else if (grades[i] > right.grades[i]){
		   temp = right;
		   done = true;
	      }

	 if ( done == false )
	      temp = *this;

	 return temp;
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

     
     // an array of 3 C++ objects
     Student a[3];

     a[0].set( 1000, "ABBF" );
     a[1].set( 1001, "ABCABB" );
     a[2].set( 1002, "ABBA" );

     cout << "... calling the overloaded operator > ..." << endl;

     Student answer; // initialized by the default constructor

     for (int i=0; i<3; i++) {

	  cout << "a[0] and a[" << i<< "]:" << endl;

	  a[0].display(); // member function call
	  a[i].display();

	  answer = a[0] > ( a[i] ); // calling an operator!
				    // an object is returned

	  // answer = a[0].operator > (a[i]);

	  cout << "+ student with a higher grade: ";
	  answer.display();
     }
     return 0;
 }
