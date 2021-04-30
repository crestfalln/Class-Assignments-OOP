---
pagestyle: empty
geometry: margin=1cm
---


# Assignment No. 1  
##### Himanshu Gupta CSE49  

## [<span style="color:blue">Pull with Git?</span>](https://github.com/crestfalln/Class-Assignments-OOP.git)

---
#### Ouestion
> CREATE A CLASS  STUDENT CONSIDERING SOME SET OF ATTRIBUTES AND FUNCTIONS, WAP TO DEMONSTRATE ITS WORKING.

#### Code

```c
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
>**Input**  
>  
>**Output**  
>40  


