#include <iostream>
#include <vector>

int main()
{
    using std::cout;
    using std::endl;

    //Selection
    if (1)
        cout << "Inside if" << endl;
    else
        cout << "Inside Else" << endl; //Never executed.

    //Iterative
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    for (auto it : vec)
        cout << it << " Inside for loop" << endl; //Executed Multiple times

    //Jump
    goto label;             //DO NOT use goto; makes code impossible to read and debug
    cout << "Outside Goto"; //Never Executed
label:
    cout << "Inside label" << endl; //Executed twice
    return 0;
    cout << "After Label"; //Never Executed
}