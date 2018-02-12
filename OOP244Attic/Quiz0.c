#include <string.h>
#include <stdio.h>

 struct xyz {
     int num;
     char data[12];
 };

 void set( struct xyz* ptr );

 void display( struct xyz wow );

 int main( ) {

     struct xyz snow;

     snow.num = -999;
     strcpy( snow.data, "Seneca" );

     display( snow );

     set( &snow );

     display( snow );

     return 0;
 }
 void set( struct xyz* ptr ){

     (*ptr).num += 12345;
     (*ptr).data[0] += 2;
     (*ptr).data[1] -= 3;
     (*ptr).data[2] = '0';
	 (*ptr).data[4] = '0';
     (*ptr).data[5] = '7';
     (*ptr).data[6] = '?';
     (*ptr).data[7] = '\0';

     display( *ptr );
 }

 void display( struct xyz wow ){

     printf( "num: %d, data: %s\n", wow.num, wow.data );
     wow.num = 333;
     strcpy(wow.data, "hello!" );
 }
