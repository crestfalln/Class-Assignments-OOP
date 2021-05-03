#include <iostream>
#include <gtkmm-3.0/gtkmm/button.h>

constexpr int sum(int const &a, int const &b) // constexpr makes function do calculation at compile time if possible
{                                             // Also function is an example of derived data type
    return a + b;
}

class t_pair // classes are types of user-defined data type
{
public:
    int a, b;
    t_pair()
    {
        std::cout << "Constructor calles";
    };
    t_pair(int n, int nn) : a(n), b(nn){};
};

int main()
{
    const int num1 = 10; // int is a pirmitive data type.
                         // const modifer is used to make rval constant and unchangable after initialization
    t_pair pair{1, 2};
    std::cout << sum(pair.a, pair.b) << std::endl; //Most probabaly done at compile time.
    std::cout << sum(num1, 10);                    // Most probabaly done at compile time.
    std::allocator<t_pair> alloc;

}