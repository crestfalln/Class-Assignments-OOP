

# Assignment No. 1   
##### Himanshu Gupta CSE49   

## [Pull with Git?](https://github.com/crestfalln/Class-Assignments-OOP.git)  

>This assignment is best viewed on GitHub. Use above link.

## Index

1. [CREATE A CLASS  STUDENT CONSIDERING SOME SET OF ATTRIBUTES AND FUNCTIONS, WAP TO DEMONSTRATE ITS WORKING.](#question-no-1)
 

---
#### Question No. 1  
:   
>CREATE A CLASS  STUDENT CONSIDERING SOME SET OF ATTRIBUTES AND FUNCTIONS, WAP TO DEMONSTRATE ITS WORKING.
  

#### Code
```c
//QUESTION CREATE A CLASS  STUDENT CONSIDERING SOME SET OF ATTRIBUTES AND FUNCTIONS, WAP TO DEMONSTRATE ITS WORKING.
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
```

#### $ Assign1/bin/1.o     

-

**Input**  
 

**Output**  
40   

---


