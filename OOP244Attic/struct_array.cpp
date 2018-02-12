
 #include <iostream>
 using namespace std;
 

 struct Student {
     int no;
     char grade[14];
 };

 void show( Student [], int );

 void display_copy( Student );

 void display( const Student* );  

 // What's the advantage of passing an address?


 int main() {

     int num;
     
     // an array of 40 C++ structures

     Student students[40] = { 10001,"CAC",
			      10002,"CBB",
			      10003,"AAB"};
     num = 3;

     show ( students, num );

     for (int i=0; i < num; i++){

	  display_copy( students[i] );

	  display( &students[i] ); // advantage?
     }

     return 0;
 }

 void show( Student list [], int q ){

      for (int k=0; k<q; k++)

	   cout << list[k].no << "..."    
		<< list[k].grade << endl;

      /*list[0].no = -1111;*/
 }

 void display_copy( Student std ){

      cout << std.no << ";" 
	   << std.grade << endl;
 }

 void display( const Student* s) {

     cout << s->no << 'x'          // (*s).no
	  << s->grade << endl;     // (*s).grade

     //s->no = -999; 
 }

