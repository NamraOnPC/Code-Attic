 // Dynamic Memory Allocation
 // matrix: g++ -std=c++0x dynamic_mem2_w17.cpp
 
 #include <cstring>
 #include <iostream>
 using namespace std;

 struct Student{
    int number;
    float grades[2];
 };

 int main(void) {

     Student* student = nullptr; // a pointer
     int size;

     cout << "Enter the number of students : ";
     cin >> size;

     student = new Student[size]; // dynamic memory allocation

     for (int i = 0; i < size; i++) {
	  cout << "Student Number: ";
	  cin  >> student[i].number;

	  cout << "Student Grade 1: ";
	  cin  >> student[i].grades[0];

	  cout << "Student Grade 2: ";
	  cin  >> student[i].grades[1];
     }

     for (int i = 0; i < size; i++) {
	  cout << student[i].number << ": "
	       << student[i].grades[0] << ", " 
	       << student[i].grades[1]
	       << endl;
     }

     delete [] student; // deallocate memory storage (avoid memory leak)
     student = nullptr;

     return 0;
 }
