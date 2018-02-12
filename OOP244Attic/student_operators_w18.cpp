 // operator overloading in C++
 // 1. operator == (helper function) 
 // 2. operator +  (member function/member operator)

 #include <cstring>
 #include <iostream>
 using namespace std;

 // C++ constant declaration
 const int  MAX=12;

 class Student {

     int no;
     float marks[MAX];
     int counter;

     public:
	Student();
	Student( int, const float[], int );

	void set();
	void set( int, const float[], int );
	void display() const;

	Student operator + ( float ) const; 
		// return a new object, not the current object
		
	// alternative design: helper function
	// friend Student operator+ ( const Studdent&, float ) ;

    // a helper function
    friend bool operator == ( const Student&, const Student& );           
 };

// opertor == (a friend function): equal marks
bool operator ==( const Student& one, const Student& two ) {

	 bool result;

	 if (one.counter != two.counter)  // access private data members!
	     result = false;

	 else {
	       result = true;

	       for (int k=0; ((k < one.counter) && (result == true)); k++)
		    if (one.marks[k] != two.marks[k])
			result = false;         
	 }
	 return result;
 }

 // operator overloading - member operator
 Student Student::operator + ( float moreMarks ) const {
 
    Student x;  // a local object, initialized by the default constructor

    x = *this;  // a copy of the current object

    // Note: the current object is NOT changed!

    x.no += 1111; // change the data member of object x, not the current object 
   
    if (x.counter < MAX-1){
	x.marks[counter] = moreMarks;
	(x.counter)++;
    }

    return x; // return the new object, not the current object
 }

 Student::Student() { set(); }

 Student::Student( int m, const float data[], int sz) {
    set(m, data, sz); 
 }

 void Student::set(int num, const float data[], int size){
 
    no = num;
    counter = size;

    for (int k=0; k<size; k++)
	 marks[k] = data[k];
 }

 void Student::set() {
 
    float data[] = { 88.5, 67.5, 75.5 };
    set( 12345, data, 3);
 }

 void Student::display() const {

     cout << "student number: " << no << endl
	  << counter << " marks: ";

     for (int i=0; i<counter; i++)
	  cout << marks[i] << " ";
     cout << endl;
 }

 int main (void) {

     float scores[] = { 55.5, 65.5, 75.5, 85.5 };

     Student c, d, e(77899, scores, 4);

     // Part 1
 /*
     cout << "### Operator Overloading - Helper Functions ###" << endl;

     if ( c == d )      // operator function: operator ==( c, d )

	  cout << "c and d: equal objects" << endl;
     
     if ( c == e)
	   cout << "c and e: equal objects" << endl;
     else  cout << "c and e: UNEQUAL objects" << endl;
 */

     // Part 2
     cout << "### Operator Overloading - Member Operators ###" << endl;

     e.display();
     d.display();

     cout << "... apply the operator + (binary operator)" << endl;

     d =  e + 77.5; 

     // d = e.operator+( 77.5 )

     e.display();
     d.display();

     return 0;
 }
