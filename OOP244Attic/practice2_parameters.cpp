 #include <iostream>
 #include <cstring>
 #include <iomanip>
 using namespace std;

 class x {
     int y;
     char z[14];

     public:
	    x();
	    x(int, const char*);
	    void set(int, const char*);
	    void display();
 };

 void foo( x std );
 void wow( x* ptr_std );
 void hello( x[] );

 x::x() { set(11111, "ABCDF"); }

 x::x(int num, const char* zs){ set(num, zs); }

 void x::set(int n, const char * s){
      y = n;
      strcpy( z, s );
 }

 void x::display(){  cout << setw(7) << y << setw(14) << z << endl; };

 void foo( x std ){ std.set( 22222, "CCCCC" ); }

 void wow( x* ptr_std ){
      ptr_std->set( 123456, "BBAAFF" );
      ptr_std->display();
 }
 
 void hello( x what[] ){
      what[0].set( -101, "BBB" );
      what[1].set( -999, "FFF" );
 }

 int main( ) {
     x one, two( 2345, "CCCD" ), three[3];

     one.display();
     two.display();
	 
     foo(one);
     wow( &two );
     hello( three );
	 
     one.display();
     two.display();
	 
     for(int k=0; k<3; k++)
	     three[k].display();
		 
     return 0;
 }

