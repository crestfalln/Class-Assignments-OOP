#include <iostream>

constexpr int sum(int const &a, int const &b) // constexpr hints the compiler to do calculations at compile time 
{                                             // Also function is an example of derived data type
    return a + b;
}

class t_pair // classes are types of user-defined data type
{
public:
    int a, b;
    t_pair(int n, int nn) : a(n), b(nn){};
};

int main()
{
    using std::cout;
    using std::endl;

    const int num1 = 10; // int is a pirmitive data type.
                         // const modifer is used to make rval constant and unchangable after initialization
    t_pair pair(1, 2);
    int a, b;
    std::cin >> a >> b;
    cout << sum(pair.a, pair.b) << endl; // Most probabaly done at compile time.
    cout << sum(num1, 10);               // Most probabaly done at compile time.
    cout << a + b << endl;               // Done at runtime
}