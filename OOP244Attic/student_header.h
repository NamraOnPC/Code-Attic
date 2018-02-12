
// C++ class declaration
// student_header.h

class Student {
		      /* declaration of data members */
     int  no;
     char grade[14];

     public:         
		     /* declaration of constuctors */
	Student( );
	Student( int, const char* );

		     /* declaration of member functions */
	void set( int n,  const char * g );
	void display() const;
 };

