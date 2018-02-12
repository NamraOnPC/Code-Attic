// OBJECTS AND DYNAMIC MEMORY ALLOCATION
// proper copying (deep copying):
// - overload the copy constructor and
//   the assignment operator

// What if operator= does NOT return a reference to the object?
// a) dependent on the copy constructor b) no chaining

#include <cstring>
#include <iostream>
#include <new>
using namespace std; 

class Employee {
   char * name;      // NO memory has been allocated!
   int    idnum;
   double salary;

   void init( int, const char*);  // private member function

   public:
      Employee(const char*, int, double);

      ~Employee();

      Employee( const Employee & ); //COPY constructor

      Employee& operator =( const Employee & );
				  // assignment operator: member function!
      
      void display();
      void replace( const char *s );   
};

void Employee::replace( const char *s ) {
     strcpy( name, s );
}

void Employee::init( int size, const char *s) {
     
     name = new (nothrow) char[ size+1 ];
  
     if ( name )
	strcpy( name, s );
}

// overload the assignment operator
Employee& Employee::operator=( const Employee& rhs )
{
   // data members of the current object(LHS)

   if ( &rhs != this )            // check for self-assignment: x=x;
   {
	cout << "\t =: release memory for [" << name << "]" << endl;

	delete [] name;   // release current memory storage

	cout << "\t =: allocate new memory storage\n";

	// request memory storage and copy the data
   
	/*     init( strlen( rhs.name ), rhs.name ); */

	name =  new (nothrow) char [strlen(rhs.name) + 1];
  
	if (name) strcpy( name, rhs.name);

	if ( name ) {

	     idnum = rhs.idnum;
	     salary = rhs.salary;
	}
   }

   return *this;
}

// overload the COPY constructor
Employee::Employee( const Employee & source )
{
   cout << "\t inside the copy constructor" << endl;
  
   // dynamic memory allocation!
   /* init( strlen(source.name), source.name );    */

   name = new (nothrow) char [strlen(source.name) + 1];

   if (name) strcpy(name, source.name);

   if ( name ) {
      idnum = source.idnum;
      salary = source.salary;
   }

   cout << "\t leaving the copy constructor..." << endl;
}


// Dynamic Memory Allocation and the Constructor
Employee::Employee( const char *s, int m, double t )
{
   // data members of the current object: name, idnum, salary
   init( strlen(s), s ); // dynamic memory allocation

   if (name) {
      idnum = m;
      salary = t;
   }

   cout << "...constructor: allocate memory for the data member ["
	<< name << " ] " << endl;
}

Employee::~Employee()
{
   if (name){
       cout << "...destructor: release the memory allocated for the data member ["
	    << name << "]" << endl;
       delete [] name;  // a BLOCK of memory!
   }
}

void Employee::display()
{
   cout << "Name: " << name << " id: " << idnum
	<< " salary:$" << salary << endl;
}

int main()
{
   cout << "Testing the overloaded operator =..."
	<< endl;

   Employee old("David", 1, 1.1),
	    young("Bill Gates", 999, 2000.01), 
	    m("MMMMM", 1, 3.3);
   
  
   old.display();  young.display();

   cout << "\tDEEP/proper copying: old = young;" << endl;

   old = young;

   cout << "\n\tmain(): old.display(); young.display()..." << endl;

   old.display(); young.display();

   cout << "\n\tmain(): old.replace()...\n";

   old.replace( "!@#$%" );
   old.display();
   young.display();

   cout << "\n--- The End ---" << endl;
   return 0;
}
