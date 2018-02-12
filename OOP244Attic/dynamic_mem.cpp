 // Dynamic Memory Allocation in C++
 // - allocate an array of CHARACTERS dynamically (i.e. at run-time)
 // - 3 steps
 
 // matrix: g++ -std=c++0x

 #include <cstring>
 #include <iostream>
 using namespace std;

 int main( ) {

     char waste[1000]; // a static array


     for (int j=0; j < 2; j++) {

	  cout << "Enter an English word (without any blank space): ";
	  cin >> waste;

	  int n = strlen(waste);

	  cout << "your word contains " << n << " characters;"
	       << "\nhow much array storage is wasted?" << endl;
     }

     // part 2

	int m;
	cout << "\n...number of characters in the English word: ";
	cin >> m;


	char * word = nullptr;           // 1. declare a pointer

	word = new char [m+1]; // 2. allocate memory storage

	// assume that memory allocation is successful
	cout << "...now enter the English word: ";
	cin >> word;

	for (int k=0; k<strlen(word); k++)
	     cout << word[k] << endl;        

	cout << "...here is your word: " << word
	     << "\n...it has " << strlen(word) << " characters" << endl;


	delete [] word;    // 3. release memory storage (memory leak)
	word = nullptr;

	return 0;
 }
