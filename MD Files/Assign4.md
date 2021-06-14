

# Assignment No. 4   
##### Himanshu Gupta CSE49   

## [Pull with Git?](https://github.com/crestfalln/Class-Assignments-OOP.git)  

>This assignment is best viewed on GitHub. Use above link.

## Index

1. [WAP for "Student management system" to insert, delete, search display student records using functions and classes. Demonstrate function prototyping, function definition, function call, default arguments, inline functions, function overloading, call be value,  call be pointer, call by reference, arrays within classes, accessing private data and functions etc. through it.](#question-no-1)
 

---
#### Question No. 1  
:   
>WAP for "Student management system" to insert, delete, search display student records using functions and classes. Demonstrate function prototyping, function definition, function call, default arguments, inline functions, function overloading, call be value,  call be pointer, call by reference, arrays within classes, accessing private data and functions etc. through it.
  

#### Code
```c
//QUESTION WAP for "Student management system" to insert, delete, search display student records using functions and classes. Demonstrate function prototyping, function definition, function call, default arguments, inline functions, function overloading, call be value,  call be pointer, call by reference, arrays within classes, accessing private data and functions etc. through it.

#include <iostream>
#include <map>
#include <memory>

struct student
{
    std::string m_Name;
    int m_Roll;
    std::string m_Class;
    std::string m_Grade;
    student(std::string const &name, int roll, std::string const &a_class, std::string const &grade)
        : m_Name(name), m_Roll(roll), m_Class(a_class), m_Grade(grade){};
};

class student_db
{
private:
    std::multimap<std::string , std::unique_ptr<student>> m_db;

public:
    void insert(std::string const &name, int roll, std::string const &a_class, std::string const &grade);
    student &retrieve();
    student &searchByName(std::string const &);
    student_db() = default;
};

void student_db::insert(std::string const &name, int roll, std::string const &a_class, std::string const &grade)
{
    std::unique_ptr<student> el = std::make_unique<student>(name , roll , a_class , grade);
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
    db.insert("Himanshu" , 49 , "CSE1" , "B+");
    db.insert("Rahul" , 29 , "EEE1" , "A+");
    db.insert("Ritika" , 12 , "ECE1" , "C+");
    std::cout << "Last Written Name: " << db.retrieve().m_Name << std::endl;
    std::cout << "Grade of Himanshu: " << db.searchByName("Himanshu").m_Grade << std::endl;
    return 0; 
}
 
```

#### $ Assign4/bin/1.o     

-

**Input**  
 

**Output**  
Last Written Name: Ritika  
Grade of Himanshu: B+  
 

---


