#include <iostream>

class student
{
    public:
    int roll;
    std::string name , grade , school;
    int getRoll() { return roll;}
};

int main()
{
    student s1;
    s1.roll = 40;
    std::cout << s1.getRoll();
}