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

 x::x() { set(2468, "ABCDF"); }

 x::x(int num, const char* zs){
    set(num, zs);
 }

 void x::set(int n, const char * s){
      y = n;
      strcpy( z, s );
 }

 void x::display(){
    cout << setw(7) << y << setw(14) << z << endl;
 };

 void foo( x std ){
    
    std.set( 13579, "CCCCC" );
    std.display();
 }

 void wow( x* ptr_std ){

    ptr_std->set( 56781, "BBAAF" );
    ptr_std->display();
 }

 int main( ) {

     x one, two( 22335, "CCCCC" );

     one.display();
     two.display();
	 
     wow( &one );
	 foo( two );
	 
     one.display();
	 two.display();
     return 0;
 }

