
// problem caused by runnign the default copy connstructor
// - memberwise copying(shallow copying) and
// Exercise: Test this out on the PC platform!!!

// g++ -std=c++0x shallow1b.cpp

#include <iostream>
#include <cstring>
using namespace std;

class Employee {

   char*  name;      // NO memory has been allocated!
   int    idnum;
   double salary;

   public:

      Employee(const char*, int, double);
      Employee();
      ~Employee();
      void display();
   friend void shallow1b(Employee);
      
};

void shallow1b( Employee arg ) {
   
     cout << "\t... shallow1b: an object is COPIED into arg"
	  << endl;
     cout << "\t... shallow1b: change the object(arg)" << endl;

   strcpy( arg.name, "E. Weaver" );   // Be careful! How much storage??
   arg.idnum = -999;
   arg.salary = -1111; 
  
   arg.display();

     cout << "\t... shallow1b: return to the main" << endl;   
}

int main()
{
       cout << "*** memberwise copying and the default copy constructor ***"
	    << endl;
       cout << "\t*** what's wrong here?\n\n";

   Employee Clerk( "Bill Gates", 999, 2000.01 );
  
   Clerk.display();

	cout << "\n\t main: pass a copy of an object into a fucntion" << endl;

   shallow1b( Clerk );

	cout << "\t main: returned from the function! \n\t main: display the object Clerk:\n";
  
   Clerk.display();
  
	cout << "\n\t--- The End ---" << endl;
   return 0;
}

// Dynamic Memory Allocation and the Constructor
Employee::Employee(const char * s, int m, double t)
{
   // data members of the current object: name, idnum, salary

	name = new (nothrow) char[ strlen(s)+1 ];
   
   if ( name != nullptr ) { 
       strcpy(name, s);
       idnum = m;
       salary = t;
   }

   cout << "...constructor: allocate memory for the data member ["
	<< name << "]" << endl;
}

Employee::Employee() {

       name = nullptr;
       idnum = 0;
       salary = 0.0;

}

Employee::~Employee() {

   if (name!= nullptr) 
   {
      cout << "...release the memory allocated for the data member <"
	   << name << ">" << endl;

      delete [] name;  // a BLOCK of heap storage
   }
}

void Employee::display()
{
   if (name != nullptr)
       cout << ">>> name: " << name << " id:" << idnum
	    << " salary:$" << salary << endl;
   else cout << ">>> safe empty state" << endl;
}












