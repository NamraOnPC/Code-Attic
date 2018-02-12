// problem caused by the assignment operator
// shallow copying/memberwise copying:
// Exercise: Run the code on the PC platform

// g++ -std=c++0x shallow2c.cpp

#include <iostream>
#include <cstring>
using namespace std;

class Employee {
   char * name;      // NO memory has been allocated!
   int  idnum;
   double salary;
   void init( int size, const char *s);

   public:
      Employee(const char*, int, double);

      ~Employee();
    
      Employee( const  Employee & ); //COPY constructor
     
      void display();
      void replace(const char*);

};


int main()
{
	 cout << "A demo on using the default assignment operator..."
	      << endl;
	 cout << "\t*** what's wrong here? ***\n";

   Employee  Old( "David",1,1.1), Another("Bill Gates", 999, 2000.01);

   Old.display(); 
   Another.display();

	cout << "\n\t main: operator = uses shallow copying!" << endl;
  
   Old = Another;

	cout << "\n\t main: displaying the two objects" << endl;
   Old.display();       
   Another.display();

	cout << "\n\t main: changing the object Old" << endl;
   Old.replace( "@!#$%" );
   
	cout << "\n\tdisplaying the two objects again..." << endl;
   Old.display(); 
   Another.display();

   cout << "\n\t --- THE END ---" << endl;
   return 0;
}
// assumption: strlen(s) <= strlen(name)!
void Employee::replace(const char *s) {
	strcpy(name, s);
}

void Employee::init( int size, const char * s) {

	  name = new (nothrow) char[ size + 1 ];  
   

    if ( name != nullptr )
	 strcpy( name, s );  // step 2
}

// User-defined COPY constructor: proper copying/deep copying
Employee::Employee(const Employee & source)
{
		     cout << "\t inside the copy constructor" << endl;

      // dynamic memory allocation!
      init( strlen(source.name), source.name );

      if ( name != nullptr ) {
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
		 cout << "\t constructor: allocate memory for the data member:"
		      << name << endl;
}



Employee::~Employee()
{
   if (name != nullptr) {
		 cout << "\t destructor: release the memory allocated for <"
		      << name << ">" << endl;

      delete [] name;  // a BLOCK of memory!
   }
		cout << "\t ...leaving the destructor..." << endl;
}

void Employee::display()
{
   cout << "Name: " << name << " id: " << idnum
	<< " salary:$" << salary << endl;
}


