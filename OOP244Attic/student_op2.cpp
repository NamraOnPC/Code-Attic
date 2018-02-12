 // operator overloading in C++
 // unary operators: +=, ++
 // - reuse operator +

 #include <iostream>
 #include <cstring>
 using namespace std;

 #define MAX 13    // const int MAX=13;

 class Student {

     int no;
     char grade[MAX+1];

     public:
	Student();
	Student( int, const char* );

	void set();
	void set( int, const char* );
	void display() const;

	Student operator + ( const char * ) const;

	Student operator += ( const char * );

	Student operator ++();    // prefix ++

	Student operator ++(int); // postfix ++

    friend bool operator == ( Student, Student );
 };

bool operator ==( Student one, Student two ) {

	 bool result = false;

	 if ( (strlen(one.grade) == strlen(two.grade)) &&
	      (strcmp(one.grade, two.grade) == 0) )

	       result = true;

	 return result;
 }

 Student Student::operator + ( const char * s ) const { 

    // the current object is NOT changed

    Student x;

    x = *this;

    if ( strlen(x.grade) + strlen(s) <= MAX ) {

	 strcat( x.grade, s );
    }

    return x;
 }

 Student Student:: operator += ( const char * more ) { 

      // reuse operator +

      /*
	  if ( strlen(grade)+strlen(more) <= MAX)
	       strcat(grade, more);

	  Student z;
	  z.no = no;
	  z.grade = grade;
	  return z;

       */

      *this = *this + more;

      return *this; // return (*this + more); ???
 }

 Student Student::operator ++() {

	no++;  // the data member of the current object

	return *this;
 }

 Student Student::operator ++(int) { // postfix ++

	Student old = *this;

	no++;  // the data member of the current object

	return old;
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

     Student a( 12345, "AAA" ), b;

     char s[] = "BC";

     a.display();

     b = a + s;

     for( int k=1; k<=5; k++) {

	  b = a += s; // a.operator+=(s);

	  b.display();
	  a.display();
	  cout << "...\n";
     }

     b = ++a;

     a.display();
     b.display();

     cout << "///\n";
     b= a++;
     a.display();
     b.display();

     return 0;
 }
