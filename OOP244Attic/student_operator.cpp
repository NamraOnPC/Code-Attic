 // operator overloading in C++
 // 1. operator == (helper function) 
 // 2. operator +  (member function/member operator)

 #include <cstring>
 #include <iostream>
 using namespace std;

 // C++ constant declaration
 const int  MAX=13;

 class Student {

     int no;
     char grades[MAX+1];

     public:
	Student();
	Student( int, const char* );

	void set();
	void set( int, const char* );
	void display() const;

	Student operator + ( const char * ) const; 
		// the current object is NOT changed
		
	// another coding option:
	// friend Student operator+ ( Studdent, const char * ) ;

    // a helper function
    friend bool operator == ( Student, Student );           
 };

// opertor == (a friend function): equal grades
bool operator ==( Student one, Student two ) {

	 bool result = false;

	 if ( (strlen(one.grades) == strlen(two.grades)) &&
	      (strcmp(one.grades, two.grades) == 0) )

	       result = true;

	 return result;
 }

 Student Student::operator + ( const char * s ) const {
 
    // the current object is NOT changed

    // strcpy (grades, "FFFF" );

    Student x;  // a local object, initialized by the default constructor

    x = *this;

    if ( strlen(x.grades)+strlen(s) <= MAX ) {

	 strcat( x.grades, s );

    }  // the current object is NOT changed!

    return x; // return an object
 }

 Student::Student() { set(); }

 Student::Student( int m, const char * g) { set(m, g); }

 void Student::set() { set( 1, "AAAAA" ); }

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

     grades[i] = '\0';        // last byte null
 }

 void Student::display() const {

     cout << "student number: " << no << ", grades: " << grades << endl;
 }

 int main () {

     Student c, d, e( 77777, "BBCCA" );

/*
     if ( c == d )      // operator function: operator ==( c, d )

	  cout << "c and d: equal objects" << endl;
     
     if ( c == e)
	   cout << "equal objects" << endl;
     else  cout << "UNEQUAL objects" << endl;

*/
     // Part 2
     cout << "### Member Operators ###" << endl;

     d =  e + "FFF"; // d = e.operator+( "FFF" )

     d.display();
     e.display();

     // Part 3: Member Operators and an Array of Objects
/*
     Student a( 12345, "AAAAAAA" ), b;

     char s[][3] = { "BC", "CD", "DF" };

     for( int k=0; k<3; k++) {

	  b = a + s[k];  // a.operator +( s[k] );

	  a.display();
	  b.display();

	  cout << ".......\n";
     }
  */
     return 0;
 }
