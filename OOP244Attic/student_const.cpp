
// version 2: constructor, const char *, const member function;
//            data validation; M

#include <iostream>
#include <iomanip>
using namespace std;

#include <string.h>

#define M 13

class Student {

	 // private data members
     int no;
     char grade[M+1];


     public:

	Student();

	Student( int, const char * );

	// public member functions
	void set(int n,  const char * g);  // const pointer

	void display() const;            // const member function
 };

 int main () {

       Student harry, larry;

       harry.display(); //what will happen?


       char z[] = "ABACA";

       harry.set( 1234, z );

       cout << z;

       larry.set(1235, "BBCDCA");

       harry.display();
       larry.display();

       Student mary( 6789, "ABAB" );

       mary.display();

       return 0;
 }



  void Student::set(int n,  const char* g){

      int i;

      strcpy(g, "hahaha" );

      if (n > 0)
	  no = n; // accept n if positive
      else
	  no = 0; // store 0 otherwise

      // validate grades received
      for (i = 0; g[i] && i < M; i++) {
	  if (g[i] >= 'A' && g[i] <= 'F' &&
	      g[i] != 'E')
	      grade[i] = g[i]; // A-D, or F
	  else
	      grade[i] = '?';  // ? default
      }
      grade[i] = '\0';        // last byte

      
  }

  void Student::display() const {

      cout << "hahaha";

      strcpy( grade, "----" );

      cout << setfill('0') << setw(6)
	   << no << setfill('.') << setw(15) << grade 
	   << "bybeyeyeyy" << endl;
  }

 Student::Student() {
      set( 1, "AAAAA" );
  }
  

  
 Student::Student( int m, const char * s) {

	 set(m, s);
 }
   








