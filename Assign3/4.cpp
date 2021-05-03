#include <iostream>
extern int a;   //Declared here
extern int a;   //Declare any no of times
extern int b;
extern int b;

int main()
{

    int a;  //Defined Here, Initialized here(Runtime maybe)
    const int b = 10; //Defined here, initialized here(Most-probably compile time)
    //int a = 10; //Error! Cannot redefine!
    a = 10; //Reinitialized Here
    //b = 11; //Error cannot reinitialize a const 
}