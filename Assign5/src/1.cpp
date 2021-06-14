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
