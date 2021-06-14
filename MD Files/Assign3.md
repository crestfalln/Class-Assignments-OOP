

# Assignment No. 3   
##### Himanshu Gupta CSE49   

## [Pull with Git?](https://github.com/crestfalln/Class-Assignments-OOP.git)  

>This assignment is best viewed on GitHub. Use above link.

## Index

1. [WAP to demonstrate working of various datatypes( Primitive, derived, user defined) including modifiers](#question-no-1)
2. [WAP to demonstrate expressions and their types(Integer, Float, Constant, relational, logical, bitwise, assignment, compound)](#question-no-2)
3. [WAP to demonstrate various control structures(Selection, Iterative, Jump)](#question-no-3)
4. [WAP to demonstrate variable declarations including flexible declaration and runtime initialisation.](#question-no-4)
5. [WAP to demonstrate Implicit and Explicit conversions.](#question-no-5)
 

---
#### Question No. 1  
:   
>WAP to demonstrate working of various datatypes( Primitive, derived, user defined) including modifiers
  

#### Code
```c
//QUESTION WAP to demonstrate working of various datatypes( Primitive, derived, user defined) including modifiers
#include <iostream>

constexpr int sum(int const &a, int const &b) // constexpr hints the compiler to do calculations at compile time
{                                             // Also function is an example of derived data type
    return a + b;
}

class t_pair // classes are types of user-defined data type
{
public:
    int a, b;
    t_pair(int n, int nn) : a(n), b(nn){};
};

int main()
{
    using std::cout;
    using std::endl;

    const int num1 = 10; // int is a pirmitive data type.
                         // const modifer is used to make rval constant and unchangable after initialization
    t_pair pair(1, 2);
    int a, b;
    std::cin >> a >> b;
    cout << sum(pair.a, pair.b) << endl; // Most probabaly done at compile time.
    cout << sum(num1, 10) << endl;       // Most probabaly done at compile time.
    cout << a + b << endl;               // Done at runtime
} 
```

#### $ Assign3/bin/1.o     

-

**Input**  
12 43     

**Output**  
3  
2055  
 

---


#### Question No. 2  
:   
>WAP to demonstrate expressions and their types(Integer, Float, Constant, relational, logical, bitwise, assignment, compound)
  

#### Code
```c
//QUESTION WAP to demonstrate expressions and their types(Integer, Float, Constant, relational, logical, bitwise, assignment, compound)
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    int const con = 10;     // Constant
    auto a = 3 + 3.13;      // RHS Returns double rval ref
    auto b = 3 + int(3.13); // RHS Retruns int rval ref
    (b = 3) /* returns &b */ 
             = 4; // sets &b to 4
    a == b; // Returns bool rval ref
    a < 2; // Returns a-type constant rval ref
    int c(10); // Constructor; Does not return anything.
    int d = (b = a); // LHS returns &b which is a lval ref. RHS calls the constructor and initializes d to &a.
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl; // Returns std::cout modifiable lval ref
    return 0;
} 
```

#### $ Assign3/bin/2.o     

-

**Input**  
 

**Output**  
6.13 6 10 6  
 

---


#### Question No. 3  
:   
>WAP to demonstrate various control structures(Selection, Iterative, Jump)
  

#### Code
```c
//QUESTION WAP to demonstrate various control structures(Selection, Iterative, Jump)
#include <iostream>
#include <vector>

int main()
{
    using std::cout;
    using std::endl;

    //Selection
    if (1)
        cout << "Inside if" << endl;
    else
        cout << "Inside Else" << endl; //Never executed.

    //Iterative
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    for (auto it : vec)
        cout << it << " Inside for loop" << endl; //Executed Multiple times

    //Jump
    goto label;             //DO NOT use goto; makes code impossible to read and debug
    cout << "Outside Goto"; //Never Executed
label:
    cout << "Inside label" << endl; //Executed twice
    return 0;
    cout << "After Label"; //Never Executed
} 
```

#### $ Assign3/bin/3.o     

-

**Input**  
 

**Output**  
Inside if  
1 Inside for loop  
2 Inside for loop  
3 Inside for loop  
4 Inside for loop  
5 Inside for loop  
6 Inside for loop  
7 Inside for loop  
Inside label  
 

---


#### Question No. 4  
:   
>WAP to demonstrate variable declarations including flexible declaration and runtime initialisation.
  

#### Code
```c
//QUESTION WAP to demonstrate variable declarations including flexible declaration and runtime initialisation.
#include <iostream>
extern int a;   //Declared here
extern int a;   //Declare any no of times
extern int b;
extern int b;

int main()
{
    int a; //Defined here, Initialized here(Compile time)
    //int a = 10; //Compiletime-error! Cannot redefine!
    int const b = 10; //Defined here, initialized here(Compile time)
    //b = 11; //Compiletime-error cannot reinitialize a const 
    std::cin >> a;
    int c(a); // Defined here, Initialized here(Runtime)
    return 0;
} 
```

#### $ Assign3/bin/4.o     

-

**Input**  
12     

**Output**  
 

---


#### Question No. 5  
:   
>WAP to demonstrate Implicit and Explicit conversions.
  

#### Code
```c
//QUESTION WAP to demonstrate Implicit and Explicit conversions.
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    int a = 2;
    double b = 10.2;
    cout << a + b << endl;     // a implicitly casted to double
    cout << double(a) << endl; // a explicitly casted to double(c-style)
    cout << static_cast<double>(a); // a explicitly casted to double(c++ only)
} 
```

#### $ Assign3/bin/5.o     

-

**Input**  
 

**Output**  
12.2  
2  
2   

---


