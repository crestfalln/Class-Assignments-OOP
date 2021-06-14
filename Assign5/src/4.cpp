//QUESTION Write programs to demonstrate type conversions:  a)Basic to Class,  b)Class to Basic c)Class to Class

#include <vector>
#include <string>
#include <iostream>

class my_str : public std::vector<char>
{
	using std::vector<char>::vector;

public:
	explicit operator char *() // Don't do; Causes a memory leak; Generally a bad idea for funtions to allocate memory on the heap and not free it in their scope; Just for demonstartion of conversion
	{
		char *str = new char[this->size() + 1];
		int i = 0;
		for (i = 0; i < this->size(); i++)
		{
			*(str + i) = (*this)[i];
		}
		str[i] = '\0';
		return str;
	}
	operator std::string()
	{
		std::string tmp;
		for (auto const &it : *this)
			tmp.push_back(it);
		return tmp;
	}
	// Constructor overloading is how you achive basic -> class
	my_str(char const *str)
	{
		for (int i = 0; *(str + i) != '\0'; i++)
			push_back(*(str + i));
	};

};

int main()
{
	char c_str[] = "Hello, World!";
	my_str str1 = static_cast<my_str>(c_str);			  // basic -> class
	char *c_str2 = static_cast<char *>(str1);			  // class -> basic
	std::string cxx_str = static_cast<std::string>(str1); // class -> class
	std::cout << "c_str1(basic cstring made directly): " << c_str << "\nstr1(user-defined casted from c_str1): "
			  << static_cast<std::string>(str1)/*for some reason won't do imlicit cast*/ << "\nc_str2(basic cstring casted from user-defined class): "
			  << c_str2 << "\ncxx_str(std::string casted from user-defined class): "
			  << cxx_str << std::endl;
	int size = std::char_traits<char>::length(c_str2);
	std::cout << cxx_str;
	delete[] c_str2;
	return 0;
}
