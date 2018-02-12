 // Dynamic Memory Allocation
 
 #include <cstring>
 #include <iostream>
 using namespace std;

 #include "student.cpp"   // include a C++ source file

 int main( ) {

	int m;
	cout << "\n...create an array dynamically\n"
	     << "... enter the number of scores to be processed: ";
	cin >> m;

	double * scores;

	scores = new double [m];

	for (int k=0; k < m; k++ ) {

	    cout << ">>> enter the marks: ";
	    cin >> scores[k];
	    }

	    cout << "scores: ";

	    for (int j=0; j < m; j++)
		 cout << ' ' << scores[j];

	 // part 2
	    cout << "\n\n...create an object dynamically" << endl;

	    Student * pstd;

	    pstd = new Student;

	    pstd->set( 4567, "AABCC" );
	    pstd->display();

	 // part 3
	    cout << "\n... create an array of 3 objects dynamically" << endl;

	    Student* list;

	    list = new Student [3];

	    for (int k=0; k<3; k++)
		    list[k].display();

	 // release memory storage!
	    cout << "\n... release memory storage" << endl;

	    delete [] scores;
	    delete pstd;
	    delete [] list;

     return 0;
 }
