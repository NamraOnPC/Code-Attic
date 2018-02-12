  #include <iostream>
  using namespace std;

 struct x {
     int  num;
     char s[14];
 };

 struct y {
     int q;
     x   r[40]; 
 };

 void foo( y* );

 int main(){

     y z;

     x std1 = { 10123, "DDD" },
	   std2 = { 20234, "FFF" },
	   std3 = { 30456, "EEE" };

     z.q = 3;
     z.r[0] = std1;
     z.r[2] = std2;
	 z.r[1] = std3;

     foo( &z );
     return 0;
 }

 void foo( y* ptr_y ){

      cout << "..." << ptr_y->q << endl;

      for (int k=0; k < ptr_y->q; k++){

	    ptr_y->r[k].num += 2;
	    ptr_y->r[k].s[k] -= 2;
	   
	    cout << (k+1) << ": " 
		     << ptr_y->r[k].num << ","
		     << ptr_y->r[k].s << endl;
      }
 }

