#include <stdio.h>
#include <string.h>

class foo {
     int number;
     char string[20];
public:
     foo( ) { set(3, 5); }

     void set(int a, int b){ number = a * b;
			     strcpy( string, "hi" ); }

     void mess(char s[]){ strcpy(string,s);}
     void messagain();
     void output(){ printf( "Number is %d and string is %s\n",
			     number, string );
		  }
};

void showyanothing( foo a, foo & b );


int main()
{
     foo x, y; 
    
     showyanothing( x, y );

     x.output();
     y.output();
   
     return 0;
}

void foo::messagain()              //notice scope resolution
{
     strcat( string," stuff" );
     number = number * 2;
}

void showyanothing( foo a, foo & b )         
{
     a.messagain();
     b.messagain();

     a.output();
     b.output();



}





















void showyasomething(foo * a)     //notice we have an address
{
     a->messagain();   // (*a).messagain();
     a->output();

}





















