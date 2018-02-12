 // walkthrough on operator overloading in C++
 // the current object

 #include <iostream>
 using namespace std;
 #include <string.h>

 #define MAX 13

 class Student {

     int  no;
     char grade[MAX+1];

     public:
	Student();
	Student( int, const char* );

	void set();
	void set( int, const char* );
	void display() const;

	Student operator + ( const char * ); // the current object is NOT changed
					     // or friend Student operator + (Student, const char *);

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

    x.no = no;                                  // data member of the current object
    strcpy( x.grade, grade );

    if ( strlen(x.grade) + strlen(s) <= MAX )

		 strcat( x.grade, s );

    return x;
 }

 Student::Student() { set(); }

 Student::Student( int m, const char * g) { set(m, g); }

 void Student::set() { set( 100, "" ); }

 void Student::set( int n, const char* g ){

      no = n;
      strcpy( grade, g );
 }

 void Student::display() const {

     cout << "student number: " << no << ',' << grade << endl;
 }

 int main () {

     Student a( 456, "AAA" ), b;

     for (int k=1; k<=2; k++) {

	 a.display();
	 b.display();

	 if ( a == b )
		 cout << "both objects have the same grades" << endl;
	  else {
		 cout << "the objects are different" << endl;

		 b = b + "AAA";  // current object?
	       }

      }

      b = a + "CCC";   // current object?

      a.display();
      b.display();


     return 0;
 }
