//QUESTION WAP to demonstrate all operations using pointers

#include <iostream>

int main()
{
	int* p1 = new int[10]; //p1 is a pointer it points to the memory address of the newly generated int array

	//Dereferencing
	*p1 = 10; // '*' derefs the pointer to get to the data underneath, in this case int;

	//Arthemetic Operations 
	*(p1 + 1) = 11; // Pointers follow + - operators, this points to the second element in the array
	//Increment Decrement Operations
	for(int i = 0 , *p2 = p1; i < 10; ++p2, ++i) //Pointer support increment and decrement operators this loop set array to {10 , 11 , 12 , 13...}
		*p2 = 10 + i; 
	for(int i = 0 , *p2 = p1; i < 10; ++p2, ++i) //Pointer support increment and decrement operators this loop set array to {10 , 11 , 12 , 13...}
		std::cout << *p2 << std::endl;
	return 0;
}