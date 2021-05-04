#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    int a = 2;
    double b = 10.2;
    cout << a + b << endl;     // a implicitly casted to double
    cout << double(a) << endl; // a explicitly casted to double(c-style)
    cout << static_cast<double>(a); // a explicitly casted to double(c++ only)
}