// overload the copy constructor
// - proper copying/deep copying logic 

// g++ -std=c++0x shallow2a.cpp

#include <cstring>
#include <iostream>
using namespace std;

class Employee {
   char * name;      // NO memory has been allocated!
   int  idnum;
   double salary;
   void init( int size, const char *s);

   public:
      Employee(const char*, int, double);

      ~Employee();
    
      Employee( const  Employee & ); // COPY CONSTRUCTOR!
     
      void display();

   friend void makecopy( Employee );
};

// the copy constructor initializes arg!
void makecopy( Employee arg ) {

     
     //strcpy( arg.name, "1234567890123456789qwert" );
     // what will happen?

     strcpy( arg.name, "Olivier" );
     arg.display();

     cout << "... bye bye from makecopy" << endl;
}

int main()
{
	 cout << "A demo on using the overloaded copy constructor ..."
	      << endl;

   Employee  Another("Bill Gates", 999, 2000.01);

   Another.display();

	 cout << "\nmaking a copy  ..." << endl;
   
    makecopy( Another );

   Another.display();

	 cout << "\n\t --- The End ---" << endl;
   return 0;
}

void Employee::init( int size, const char * s) {

	  name = new (nothrow) char[ size + 1 ];   // step 1
   

    if ( name != nullptr )
	 strcpy( name, s );  // step 2
}

// User-defined COPY constructor: proper copying/deep copying
Employee::Employee(const Employee & source)
{
		     cout << "\t inside the copy constructor" << endl;

      // dynamic memory allocation!
      //init( strlen(source.name), source.name );

      // step 1
      name = new (nothrow) char [strlen( source.name) + 1];
   
      // step 2
      if ( name != nullptr ) {
	   strcpy( name, source.name );
	   idnum = source.idnum;
	   salary = source.salary;
      }
		     cout << "\t leaving the copy constructor..." << endl;

}








// Dynamic Memory Allocation and the Constructor
Employee::Employee(const char *s, int m, double t)
{
   init( strlen(s), s );

   if ( name != nullptr ) {
      idnum = m;
      salary = t;
   }
		 cout << "...constructor: allocate memory for the data member ["
		      << name << "]" << endl;
}

Employee::~Employee() {

   if ( name != nullptr ) {
		 cout << "...destructor: release the memory allocated for <"
		      << name << ">" << endl;

      delete [] name;  // a BLOCK of memory!
   }
		cout << "\t ...leaving the destructor..." << endl;
}

void Employee::display()
{
   if (name != nullptr)
	cout << "Name: " << name << " id: " << idnum
	     << " salary:$" << salary << endl;
}


