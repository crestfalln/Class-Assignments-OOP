//QUESTION WAP to demonstrate expressions and their types(Integer, Float, Constant, relational, logical, bitwise, assignment, compound)
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    int const con = 10;     // Constant
    auto a = 3 + 3.13;      // RHS Returns double rval ref
    auto b = 3 + int(3.13); // RHS Retruns int rval ref
    (b = 3) /* returns &b */ 
             = 4; // sets &b to 4
    a == b; // Returns bool rval ref
    a < 2; // Returns a-type constant rval ref
    int c(10); // Constructor; Does not return anything.
    int d = (b = a); // LHS returns &b which is a lval ref. RHS calls the constructor and initializes d to &a.
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl; // Returns std::cout modifiable lval ref
    return 0;
}