//QUESTION WAP to demonstrate various types of operator overloading for unary and binary operators.

#include <iostream>

class int_wrap
{
	int* m_data;
	public:
	int_wrap() = default;
	int_wrap(int data)
	{
		m_data = new int(data);
	}
	int& operator*() const //Unary
	{
		return *m_data;
	}
	int_wrap operator+(int_wrap const & other) //binary
	{
		return int_wrap(**this + *other);
	}
	friend std::ostream& operator<<(std::ostream& os , int_wrap const & );
	~int_wrap() noexcept
	{
		delete m_data;
	}
};
std::ostream& operator<<(std::ostream& os , int_wrap const & integer)
{
	os << *integer;
	return os;
}

int main()
{
	int_wrap int1(12) , int2(10);
	int & int1_ref = *int1;
	int1_ref = 2;
	std::cout << int1 + int2;
}