

# Assignment No. 5   
##### Himanshu Gupta CSE49   

## [Pull with Git?](https://github.com/crestfalln/Class-Assignments-OOP.git)  

>This assignment is best viewed on GitHub. Use above link.

## Index

1. [EXTEND  "Student management system" to insert, delete, search display student records using CONSTRUCTORS(default, parameterised, copy), DESTRUCTORS, DYNAMIC MEMORY ALLOCATION using constructors and destructors, INHERITANCE(SINGLE, MULTILEVEL, MULTIPLE, HYBRID), VIRTUAL BASE CLASS, INITIALISING BASE CONSTRUCTORS USING DERIVED, ABSTRACT CLASSES ETC](#question-no-1)
2. [WAP to demonstrate various ambiguities during inheritance and how to resolve those.](#question-no-2)
3. [WAP to demonstrate various types of operator overloading for unary and binary operators.](#question-no-3)
4. [Write programs to demonstrate type conversions:  a)Basic to Class,  b)Class to Basic c)Class to Class](#question-no-4)
5. [WAP to demonstrate all operations using pointers](#question-no-5)
 

---
#### Question No. 1  
:   
>EXTEND  "Student management system" to insert, delete, search display student records using CONSTRUCTORS(default, parameterised, copy), DESTRUCTORS, DYNAMIC MEMORY ALLOCATION using constructors and destructors, INHERITANCE(SINGLE, MULTILEVEL, MULTIPLE, HYBRID), VIRTUAL BASE CLASS, INITIALISING BASE CONSTRUCTORS USING DERIVED, ABSTRACT CLASSES ETC
  

#### Code
```c
//QUESTION EXTEND  "Student management system" to insert, delete, search display student records using CONSTRUCTORS(default, parameterised, copy), DESTRUCTORS, DYNAMIC MEMORY ALLOCATION using constructors and destructors, INHERITANCE(SINGLE, MULTILEVEL, MULTIPLE, HYBRID), VIRTUAL BASE CLASS, INITIALISING BASE CONSTRUCTORS USING DERIVED, ABSTRACT CLASSES ETC

#include <iostream>
#include <map>
#include <memory>
#include <cstring>
#include <climits>

struct print_interface{
	virtual void print() = 0;
};

struct kid : virtual public print_interface //Virtual Inheritance?
{
	std::string m_Name;
	void print() override
	{
		std::cout << "Printing Something from kid...\n";
		std::cout << m_Name;
	}
	kid() = default;
	kid(std::string const & name)
		: m_Name(name){};
};

struct student : virtual public print_interface , public kid //Virtual keyword added for fun. // Multiple Inheritance?
{
    int m_Roll;
    std::string m_Class;
    std::string m_Grade;
	char* m_Mem = new char[100];
	student() = default;
    student(std::string const &name, int roll, std::string const &a_class, std::string const &grade , const char* mem)
        : kid(name) , m_Roll(roll), m_Class(a_class), m_Grade(grade)
	{
		strncpy(m_Mem , mem , 99);
		m_Mem[99] = '\0'; 
	};
	student(student const & std) // Copy Constructor
		: kid(std.m_Name) , m_Roll(std.m_Roll) , m_Class(std.m_Class) , m_Grade(std.m_Grade)
	{
		strcpy(m_Mem , std.m_Mem);
	};
	~student()
	{
		delete[] m_Mem;
	}
	void print() override
	{
		std::cout << "Printing Something from student...\n"
				  << m_Grade;
	}
};

struct man : public student , virtual public print_interface //Hybrid Inheritance?
{
	man() = default;
	int manliness = INT_MAX;
	void print() override
	{
		std::cout << "Printing Something from man...\n"
				<< manliness;
	}
};

class student_db
{
private:
    std::multimap<std::string , std::unique_ptr<student>> m_db;

public:
    void insert(std::string const &name, int roll, std::string const &a_class, std::string const &grade, char const * mem);
    student &retrieve();
    student &searchByName(std::string const &);
    student_db() = default;
};

void student_db::insert(std::string const &name, int roll, std::string const &a_class, std::string const &grade , char const * mem)
{
    std::unique_ptr<student> el = std::make_unique<student>(name , roll , a_class , grade , mem);
    m_db.insert({el->m_Name , std::move(el)});
}

student &student_db::retrieve()
{
    return *((--m_db.end())->second);
}

student& student_db::searchByName(std::string const& name)
{
    return *(m_db.find(name)->second);
}

int main()
{
    student_db db;
    db.insert("Himanshu" , 49 , "CSE1" , "B+" , "asdfasd");
    db.insert("Rahul" , 29 , "EEE1" , "A+" , "asdfqwerwefvzsdfg");
    db.insert("Ritika" , 12 , "ECE1" , "C+" , "qwexcertx");
	man karl;
	strcpy(karl.m_Mem, "In mam");
    std::cout << "Last Written Name: " << db.retrieve().m_Name << std::endl;
    std::cout << "Grade of Himanshu: " << db.searchByName("Himanshu").m_Grade << std::endl;
    std::cout << "Print() of Himanshu: "; db.searchByName("Himanshu").print();
	std::cout << std::endl << "Print() of kid in Himanshu: "; db.searchByName("Himanshu").kid::print();
	std::cout << std::endl << "Print() of man: "; karl.print();
    return 0; 
}
 
```

#### $ Assign5/bin/1.o     

-

**Input**  
 

**Output**  
Last Written Name: Ritika  
Grade of Himanshu: B+  
Print() of Himanshu: Printing Something from student...  
B+  
Print() of kid in Himanshu: Printing Something from kid...  
Himanshu  
Print() of man: Printing Something from man...  
2147483647   

---


#### Question No. 2  
:   
>WAP to demonstrate various ambiguities during inheritance and how to resolve those.
  

#### Code
```c
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


 
```

#### $ Assign5/bin/2.o     

-

**Input**  
 

**Output**  
10  
12  
 

---


#### Question No. 3  
:   
>WAP to demonstrate various types of operator overloading for unary and binary operators.
  

#### Code
```c
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
```

#### $ Assign5/bin/3.o     

-

**Input**  
 

**Output**  
12   

---


#### Question No. 4  
:   
>Write programs to demonstrate type conversions:  a)Basic to Class,  b)Class to Basic c)Class to Class
  

#### Code
```c
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
 
```

#### $ Assign5/bin/4.o     

-

**Input**  
 

**Output**  
c_str1(basic cstring made directly): Hello, World!  
str1(user-defined casted from c_str1): Hello, World!  
c_str2(basic cstring casted from user-defined class): Hello, World!  
cxx_str(std::string casted from user-defined class): Hello, World!  
Hello, World!   

---


#### Question No. 5  
:   
>WAP to demonstrate all operations using pointers
  

#### Code
```c
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
```

#### $ Assign5/bin/5.o     

-

**Input**  
 

**Output**  
10  
11  
12  
13  
14  
15  
16  
17  
18  
19  
 

---


