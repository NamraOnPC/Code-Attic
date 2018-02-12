 
  #include <iostream>
  using namespace std;

 // a C++ structure type 
 struct Student {
     int no;
     char grade[14];
 };

 // a C++ container type
 struct Section {

     int numOfStudents;

     Student students[40];  // C++ syntax
 };

 void display( const Section* );

 int main(){

     Section section;

     Student std1 = { 10123, "ABC" },
	     std2 = { 10567, "CDF" };

     section.numOfStudents = 2;

     section.students[0] = std1;
     section.students[1] = std2;

     //section.students[0].no = -123456;

     display( &section );
     
     return 0;
 }

 void display( const Section* ptr_section ){

      cout << "This section has " 
	   << ptr_section->numOfStudents << " students." << endl;

      for (int k=0; k < ptr_section->numOfStudents; k++)

	   cout << (k+1) << ": " 
		<< ptr_section->students[k].no << ","
		<< ptr_section->students[k].grade << endl;
 }

