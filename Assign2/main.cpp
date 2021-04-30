#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    cout << 1 << ". " << 3 + 4 << endl ; // Returns Summation 
    cout << 2 << ". " << 3 - 4 << endl ; // Returns Difference 
    cout << 3 << ". " << 3 * 4 << endl ; // Returns Product 
    cout << 4 << ". " << 3 / 4 << endl ; // Returns Quotient 
    cout << 5 << ". " << 3 % 4 << endl ; // Returns Remainder
    cout << 6 << ". " << (3 == 4) << endl ; // Returns True if equal
    cout << 7 << ". " << (3 != 4) << endl ; // Returns False if equal
    cout << 8 << ". " << (3 >= 4) << endl ; // Returns True if LHS equal/greater RHS
    cout << 9 << ". " << (3 <= 4) << endl ; // Returns True if RHS equal/greater LHS
    cout << 10 << ". " << (3 < 4) << endl ; // Returns True if RHS greater LHS
    cout << 12 << ". " << (3 > 4) << endl ; // Returns True if LHS greater RHS
    cout << 13 << ". " << (3 ^ 4) << endl ; // Returns XOR of every bit
    cout << 14 << ". " << (3 & 4) << endl ; // Returns AND of every bit
    cout << 15 << ". " << (3 | 4) << endl ; // Returns OR of every bit
    cout << 16 << ". " << (~3) << endl ; // Returns NOT of every bit
    cout << 17 << ". " << (3 << 2) << endl ; // Returns LHS right-shifted RHS bits, basically 3*2^2
    cout << 18 << ". " << (3 >> 2) << endl ; // Returns LHS left-shifted RHS bits, basically 3/2^2
    int a , b; // Constructs multiple objects
    cout << 19 << ". " << (a = 2) << endl ; // Returns LHS after succesful assignment
    cout << 20 << ". " << (a += 2) << endl ; // Returns LHS after adding RHS to it
    cout << 21 << ". " << (a -= 2) << endl ; // Returns LHS after subtracting RHS from it
    cout << 22 << ". " << (a *= 2) << endl ; // Returns LHS after multiplying RHS to it
    cout << 23 << ". " << (a /= 2) << endl ; // Returns LHS after dividing RHS by it
    cout << 24 << ". " << (a++) << endl ; // Returns operand increments after expression
    cout << 25 << ". " << (++a) << endl ; // Returns operand increments before expression
    cout << 25 << ". " << sizeof(a) << endl ; // Returns size of operand on stack
}