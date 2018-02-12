
 #include <iostream>
 using namespace std;
 #include <string.h>

 #define MAX 13

 class z {

     int  num;
     char s[MAX+1];

     public:
	z();
	z( int, const char* );

	void set();
	void set( int, const char* );
	void display() const;

	const char * foo() { return s; }

	z operator - ( const char * );

    friend z operator * ( z, z );
 };

z operator * ( z x, z y ) {

	 x = y - x.foo();
	 
	 x.display();
	 y.display();
	    //ohboy
	 return x;
 }

 z z::operator - ( const char * st ) { // the current object is NOT changed

    z x;

    x = *this;

    strcat(s, st);
    num += strlen(s);

    display();
	 //very important
    x.num += num;
    strcat(x.s, s);

    return x;
 }

 z::z() { set(); }

 z::z( int m, const char * g) { set(m, g); }

 void z::set() { set( 100, "c++" ); }

 void z::set( int n, const char* g ){

      num = n;
      strcpy( s, g );
 }

 void z::display() const {

     cout << "student number: " << num << ',' << s << endl;
 }

 int main () {

	z a( 456, "ABC" ), b, c;

	a.display();
	b.display();

	c = a * b;

	a.display();
	b.display();
	c.display();
	return 0;
 }
