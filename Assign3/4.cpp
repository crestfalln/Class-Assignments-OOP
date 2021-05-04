#include <iostream>
extern int a;   //Declared here
extern int a;   //Declare any no of times
extern int b;
extern int b;

int main()
{
    int a; //Defined here, Initialized here(Compile time)
    //int a = 10; //Compiletime-error! Cannot redefine!
    int const b = 10; //Defined here, initialized here(Compile time)
    //b = 11; //Compiletime-error cannot reinitialize a const 
    std::cin >> a;
    int c(a); // Defined here, Initialized here(Runtime)
    return 0;
}