#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

class abc {
		    
     int no;
     char grade[14];

     public:         
	 
	 abc( );
	 abc( int, const char* );
     ~abc();
	 
	 void set( int n,  const char * g );
	 void display()const;
	 int hello(abc&, abc);
	 int hello(int);
 };

 abc::abc() { set( 1000, "AAAA" ); }

 abc::abc(int m, const char * s) { set(m, s); }

 void abc::set(int n, const char* g){

	  no = n;
	  strcpy( grade, g );
 }
 
 void abc::display() const {

	cout << setfill('0') << setw(7) << no
	     << setfill( '#' ) << setw(7) << grade << endl;
 }
 
 abc::~abc() { 
    cout << "... bye bye: " << no << "," << grade << endl;
 }
 
 int abc::hello(int no) {
     int t;
	 
	 t = (*this).no;
     (*this).no = no - (*this).no;
	 return t;
 }
 
 int abc::hello( abc& x, abc y ){
     cout << "be careful..." << endl;
     *this = y;
	 ++no;
	 x.set( -111, "BBBB" );
	 y.set( -333, "DDDD" );
     return x.no + y.no;
 }

int main( ){
    // watch out for the invocations of constructors and destructor
	
    abc a, b( 900, "ABABA" ), f(800, "BCBCB");

	cout << a.hello(12) << endl;
	cout << b.hello(24) << endl;
	a.display();
	b.display();

	a.set(1000, "AAAAA");
	b.set(900,  "ABABA");
    cout << f.hello(a, b) << endl;
	a.display();
	b.display();
	f.display();
    return 0;
}
