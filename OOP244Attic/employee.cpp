// C++ Classes with (Dynamically Allocated) Resources
// - an object uses resources outside its own memory space
// - a pointer, constructors, and destructor

// - command line on matrix: g++ -std=c++0x employee.cpp

#include <cstring>
#include <iostream>
using namespace std;

class Employee {

   char  * name;      // NO memory has been allocated!
   int    idnum;
   double salary;

   public:

      Employee(const char*, int, double);
      Employee();

      ~Employee();   // destructor
      void display() const;
};


int main()
{
   Employee e( "Bill Gates", 12345, 9999.99),
	    jake;
  
   e.display();  
   jake.display(); 
  
   return 0; // 2 objects go out of scope; in what order?
}



// Dynamic Memory Allocation and the Constructor
Employee::Employee(const char * s, int m, double t)
{
   // data members of the current object: name, idnum, salary
  
   name = new (nothrow) char[ strlen(s)+1 ];

   if ( name != nullptr ) { // C++11 standard
       strcpy(name, s);
       idnum = m;
       salary = t;
   }

   cout << "... constructor: allocate memory for the data member: ["
	<< name << "]" << endl;
}


// initialize an object to a SAFE EMPTY STATE
Employee:: Employee() { name = nullptr;
			idnum = 0;
			salary = 0.0;  }

Employee::~Employee()
{
    if (name != nullptr){  // C++11 standard

      cout << "... destructor: release the memory allocated for the data member: ["
	   << name << "]" << endl;

      delete [] name;

      name = nullptr;
   }
}

void Employee::display() const
{
   if (name == nullptr)
	cout << "*** the object is in a safe empty state" << endl;

   else cout << "***  employee name: " << name << ", id:" << idnum
	     << ", salary:$ " << salary << endl;
}












