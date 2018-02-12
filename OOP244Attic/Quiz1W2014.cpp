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
		void hello(int);
	    void display() const;
 };

 void foo( x  yup );
 void wow( x* zoo );

 x::x() { set(555, "AAA"); }

 x::x(int num, const char* zs){ set(num, zs); }

 void x::set(int n, const char * s){
                 y = n;
                 strcpy( z, s );
 }

 void x::display() const{  cout << setw(7) << y << setw(14) << z << endl; };

 void x::hello(int m) { y += m; }

 void foo( x yup ){ yup.set( 777, "DDD" );
                    yup.display();        }

 void wow( x* zoo ){
      zoo->set( 2468, "FFAA" );
      zoo->display();
 }

 int main( ) {
     x one(1234, "ABCD") , two, three[3];

     one.display();
     two.display();

     foo(one);
	 wow( &two );

     one.display();
	 two.display();

	 cout << "...more" << endl;

	 three[2].hello(200);

	 for(int k=0; k<3; k++)
	     three[k].display();

     return 0;
 }