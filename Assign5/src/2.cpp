//QUESTION WAP to demonstrate various ambiguities during inheritance and how to resolve those.

#include <iostream>

struct foo
{
	int a;
	void print()
	{
		std::cout << a << std::endl;
	}
};

struct bar
{
	int a;
	void print()
	{
		std::cout << a << std::endl;
	}
};

struct foobar : public foo , public bar
{
	int c;
	void print_foobar()
	{
		//std::cout << a; //Which A? Ambiguity
		std::cout << foo::a; //Better;
	}
};

int main()
{
	foobar FooBar;
	FooBar.foo::a = 10;
	FooBar.bar::a = 12;
	//FooBar.print(); //Which print? Ambiguity
	FooBar.foo::print(); // Prints foo's a
	FooBar.bar::print(); // Prints bar's a
}


