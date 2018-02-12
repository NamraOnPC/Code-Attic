 // operator overloading in C++
 // operator ==, operator +

 // BTP200
 // January 2007

 #include <new>
 #include <iostream>
 using namespace std;

 #include <string.h>
 #define MAX 13

 class Student {

     int no;
     char grade[MAX+1];

     public:
	Student();
	Student( int, const char* );

	void set();
	void set( int, const char* );
	void display() const;

	Student operator + ( const char * ); // the current object is NOT changed
					     // or friend Student operator + (Student, const char *);

    //friend Student operator + ( Student, const char * );

    friend bool operator == ( Student, Student );
 };

bool operator ==( Student one, Student two ) {

	 bool result = false;

	 if ( (strlen(one.grade) == strlen(two.grade)) &&
	      (strcmp(one.grade, two.grade) == 0) )

	       result = true;

	 return result;
 }

  Student Student::operator + ( const char * s ) { // the current object is NOT changed

    Student x;

    //strcpy( x.grade, grade );
    //x.no = no;


    x = *this ;   // this: a pointer to the current object

     if ( strlen(x.grade)+strlen(s) <= MAX ) {

	 strcat( x.grade, s );
      }

    return x;
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
	     grade[i] = g[i]; // A, B, C, D or F
	 else
	     grade[i] = '?';  // else, store ?
     }

     grade[i] = '\0';        // last byte null
 }

 void Student::display() const {

     cout << "student number: " << no << ',' << grade << endl;
 }

 int main () {

     Student a( 12345, "AAAAAAA" ), b;

     char s[][3] = { "BC", "BB", "CC" };

     for( int k=0; k<3; k++) {

			     // a.set( 6666, "BBBB" );
	  b = a + s[k];      // member function:  a.operator+( s[k] )
	  a.display();
	  b.display();

	  cout << ".......\n";
     }

     return 0;
 }
