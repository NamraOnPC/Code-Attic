 // constructors, destructor, arrays
 // dynamic memory allocation

 // BTP200
 // January 2007

 #include <new>
 #include <iostream>
 using namespace std;

 #include <string.h>

 class Student {

     int no;
     char* name;
     char grade[14];

     public:
	Student();
	Student( int, const char*, const char* );

	~Student();

	void set();
	void set(int, const char*, const char*);
	void display() const;
 };

 Student::Student() { set(); }

 Student::~Student() {

     cout << "trace: entering the destructor for " << name << endl;

     if (name) delete [] name;
 }

 void Student::set() { set( 1, "AAAAA", "unknown" ); }

 void Student::set( int n, const char* g, const char* nm ){

     int i;

     if (n > 0)
	 no = n; // accept n if positive
     else
	 no = 0; // store 0 otherwise

     // validate grades received
     for (i = 0; g[i] != '\0' && i < 13; i++) {
	 if (g[i] >= 'A' && g[i] <= 'F' &&
	     g[i] != 'E')
	     grade[i] = g[i]; // A, B, C, D or F
	 else
	     grade[i] = '?';  // else, store ?
     }
     grade[i] = '\0';        // last byte null

     // allocate memory storage
     name = new (nothrow) char [ strlen(nm) + 1 ];

     if ( name )
	  strcpy(name, nm );
 }

 void Student::display() const {

     cout << "name: " << name << ':' << no << ' ' << grade << endl;
 }

 int main () {


	for(int i=0; i<3; i++) {
		Student y;
		y.set(5000,"D","Vedo");
	}
	 Student x;

	 x.display();


     Student a[3];  // an array of 3 Student objects

     a[0].set(1000, "AAAAA", "Harry");
     a[1].set(1001, "BBBBBA", "Larry");
     a[2].set(1002, "CCCCCBB", "Veronica");

     for (int i = 0; i < 3; i++)

	  a[i].display();

     // Part 2

     Student * z;

     z = new Student [4]; // allocate an array of 4 Student objects dynamically

     z[0].set( 3001, "CCCB", "Frank" );
     z[1].set( 3002, "BAB", "Dave" );
     z[2].set( 3003, "AA", "Mike" );
     z[3].set( 3004, "ABAC", "Ray" );

     for (int j=0; j < 4; j++)

	  z[j].display();

     delete [] z;

     cout << "byebye...\n";
     return 0;
 }




