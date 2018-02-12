 #include <iostream>
 #include <cstring>
 using namespace std;

 class coffee {
     int c1;
     char c2[14];

     public:
	    void set( int, const char* );
	    void foo();
 };
 
 class store {

     int n;
     coffee data[40];  

     public:
	    void set( int );
	    bool add( int, coffee );
	    void foo();
 };

 int main(){
     store store;       // bad coding style!
     coffee std1, std2;   

     store.set(3);  
     std1.set( 10234, "CDF" );
	 std2.set( 20345, "DFA" );
	 
     store.add( 1, std2 );
	 store.add( 2, std1 );
     store.foo();
	 
	 store.set(2);
	 store.foo();
     return 0;
 }

 void coffee::set( int m, const char * s ){
      c1 = m;
      strcpy(c2, s);
 }

 void coffee::foo(){
	  cout << "coffee: " << c1
	       << " >>> " << c2 << endl;
 }

 void store::set(int m){
      coffee cf;
	  
	  n = m;
	  for (int k=0; k<n; k++){
	       cf.set( k+11111, "ABC" ); 
	       data[k] = cf; 
	  }
 }

 bool store::add( int q, coffee cf ){
	  bool result = true;

	  if ( n < 40 ){
	
	   data[n] = data[q];
	   n++;
	   data[q].foo();
	   data[q] = cf;
      }
      else result = false;
      return result;
 }

 void store::foo(){

	  cout << "..." << n << endl;
	  for (int k=0; k<n; k++)
		   data[k].foo();  
 }

