## Array
---
* It is the collection of similar Data elements.
* Declarating and storing of an array -
    ```C
    int arr[5]; /* 5 blocks of memory is allocated starting from 0 to 4 */
    arr[0] = 25;
    int arr2[] = {1,6,9};
    ```
* Main memory is divided into - Heap, Stack and code section.
* When an array is declared, it is stored in the stack memory(Use malloc to store the array in heap).
* A loop can be used to print the contents of an array.
    ```C
    for(int i = 0; i<3; i++)
    {
        printf("%d",arr2[i]);
    }
    ```

## Structure
---
* It is a collection of data members where all the related data members come under one name. The data members can be of similar type or dissimilar type.
* Structure is used for defining user defined data types.
* Declaring and accessing of an Structure
    ```C
    struct Rectangle
    {
        /* assuming integer takes 2 bytes, the whole structure will take 4 bytes */
        int length;
        int breadth;
    };
    /* The memory is not consumed because its just a definition */
    int main()
    {
        struct Rectangle r; /* This is the declaration of structure. Now r occupies 4 */
        struct Rectangle r2 = {5,2}; /* To declare and initialise structure */
        /* The memory is now allocated in the stack */
        r.length = 15; /* To access a member we use .(dot) operator */
        r.breadth  = 10;
        printf("Area of rectangle is %d",(r.length*r.breadth));
    }
    ```
* Examples of using structure
    1. Complex numbers (a+ib)
        ```C
        struct Complex
        {
            /* space = 2 + 2 = 4 bytes
            int real;
            int img;
        };
        ```
    2. Student record
        ```sql
        struct Student
        {
            /* space = 2 + 25 + 10 + 50 = 77 bytes */
            int roll;
            char name[25];
            char dept[10];
            char address[50];
            int age;
        };
        int main()
        {
            /* space = 77 * 10 = 770 bytes */
            struct Student s[10]; /* array of structures is declared */
            s[0].age = 17;
            printf("%d",s[0].age);
        }
        ```

## Pointers
---
* Pointer is an address variable that is meant for storing address of data variable.
* Pointers can be used for accessing the data indirectly.
* A program can access the stack and code section of the memory directly while the heap cant be accessed directly. 
* The need for pointers -
    * So to access heap memory we use pointers.
    * To access external files and resources outside the program
    * Used for passing parameters
* Every variable created in C is stored in stack memory.
* To allocate memory in heap, we use malloc(). To use this function, we import a library \#include<stdlib.h>
* malloc() takes in the amount of size required in the heap memory. It is given in bytes.
* Pointer can be used for dynamic memory allocation of a variable. Ex:
    ```C
    int *ptr;
    int n=1;
    ptr = &n;
    ```
* *(&n) is equivalent to n.
* Postfix unary increment (++) and decrement (––) operators have greater precedence than the dereference operator (*).  Therefore, the expression *ptr++ is equivalent to *(ptr++).
* Null pointer is a pointer variable that doesnt point to any memory location.
    ```C
    int *p = NULL;
    ```
* A null pointer can also be declared by equating to 0. To make it clear, use 'NULL'.
* Generic pointers or void pointers is a special pointer that can point to variables of any data type. Use it unless it is necassary.
* In C, since you cannot have a variable of type void, the void pointer will therefore not point to any data and, thus, cannot be dereferenced. You need to cast a void pointer to another kind of pointer before using it.
*  A double pointer stores the address of a another point, use * for each level of reference.
Example:
    ```C
    int main()
    {
        int count = 1;
        int *ptr,**ptr2,***ptr3;
        ptr = &count;
        ptr2 = &ptr;
        ptr3 = &ptr2;
        (***ptr3)++;
        printf("%d %d %d",*ptr,**ptr2,***ptr3);// prints 2 2 2
        return 0;
    }
    ```
* Declaring and accessing of a pointer -
    1. Accessing stack memory
        ```C
        int main()
        {
            int a = 10; /* data variable, Since the variable is 2 bytes, it has 2 address */
            int *p; /* address variable, a pointer also occupies memory of 2 bytes and has 2 address*/
            /* Consider the address of a variable as 200/201 and address of p pointer as 210/211 */
        
            p = &a; /* initialise of pointer */
            /* The pointer stores the address of a i.e 200/201 */

            printf("%d",a); /* prints 10 */
            printf("%d", *p); /* prints 10, the portion with *p is dereferencing*
        }
        ```
    2. Accessing Heap memory
        ```C
        #include<stdlib.h>
        int main()
        {
            int *p;
            p = (int *)malloc(5*sizeOf(int)); /* Now 5*2(assuming) = 10 bytes is allocated to the heap memory */ 
            /* Since the malloc function returns void pointer, we type cast it to integer pointer */
            /* In C++, we use new keyword to allocate memory in heap
                p = new int[5];
            */
        }
        ```

## Reference(Only available in C++)
---
It is an alias given to the variable. The address of reference is same as that of the variable it is refering.
Example:
```C
int main()
{
    int a = 10; // Stored in stack memory
    int &r = a; // A reference is defined by &(ampersand)
    cout<<a; // prints 10;
    r++;
    cout<<a; // prints 11;
    cout<<r; // prints 11;
}
```

## Pointer to a Structure
---
*  Example 1 (Stack)
    ```C
    struct Rectangle
    {
        int length;
        int breadth;
    };
    int main()
    {
        struct Rectangle r = {10,5};
        struct Rectangle *p = &r;/* The size of the pointer is equal to the integer. Its always 2 bytes condsidering integer to be 2 bytes. */
        r.length = 20;
        (*p).length = 10; /* The higher precedence is for .(dot) operator, so we wrap *p */
        /* The alternative to the above statement is given below */
        p->length = 20;
    }
    ```
* Example (heap - dynamically)
    ```C
    struct Rectangle
    {
        int length;
        int breadth;
    };
    int main()
    { 
        struct Rectangle *p;
        p = (struct Rectangle *) malloc(sizeof(struct Rectangle));
        /* Since malloc returns void pointer, we type cast it as a Rectangle type structure pointer */
        p->length = 14;
        p->breadth = 6;
    }
    ```
## Functions
---
* It is a group is instructions to perform a task. Functions help to break down into smaller modules. This helps in reusability.
* The execution begins from the main function.
* Use a function declaration before using the function.
    ```C
    return_data_type function_name(data_type variable1, data_type variable2,..);
    ```
* Using functions and integrating into main function is called modular programming.
* call by value: The values of the variables are passed by the calling function to the called function.Values of the variables in the calling functions remain unaffected when the arguments are passed using the call-by-value technique.
* call by reference: The addresses of the variables are passed by the calling function to the called function. The function can change the value of the argument and the change is reflected in the calling function.
* Parameter passing methods -
    * Pass by value
    * Pass by address
    * Pass by reference(C++, not in C)
* Example of pass by value
    ```C
    void swap(int x, int y) /* Formal parameters */
    {
        x = x + y;
        y = x - y;
        x = x - y; 
    }
    int main()
    {
        int a,b;
        a = 10;
        b = 20;
        swap(a,b); /* actual parameters */
        printf("%d %d", a,b);
    }
    /* In this the actual parameters are not changed */
    ```
* Example of pass by address
    ```C
    void swap(int *x, int *y) /* Formal parameters */
    {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y; 
    }
    int main()
    {
        int a,b;
        a = 10;
        b = 20;
        swap(&a,&b); /* actual parameters */
        printf("%d %d", a,b);
    }
    /* In this actual parameters are changed */
    ```
* Example of pass by reference
    ```C
    void swap(int &x, int &y) /* Formal parameters */
    {
        x = x + y;
        y = x - y;
        x = x - y; 
    }
    int main()
    {
        int a,b;
        a = 10;
        b = 20;
        swap(a,b); /* actual parameters */
        printf("%d %d", a,b);
    }
    /* In this actual parameters are changed */
    ```
## Array as parameter
---
* Example for passing an array
    ```C
    void output(int arr[], int n)
    {
        for(int i = 0;i<n;i++)
            printf("%d",arr[i]);
    }
    int main()
    {
        int arr[5] = {1,2,4,5,7};
        output(arr,5);
    }
    /* Array is passed only by address and cant be passed by value */
    ```
* Example for returning an array
    ```C
    int[] output(int n)
    {
        int *p;
        p = (int *)malloc(n*sizeof(int));
        return (p);
    }
    int main()
    {
        int *arr;
        arr = output(5);
    }
    ```
## Structure as parameter
---
* Example
    ```C
    struct rectangle
    {
        int length;
        int breadth;
    };
    int area(struct rectangle r1)
    {
        r1.length++; /* This doesnt affect the actual parameters value
        return (r1.length*r1.breadth);
    }
    int main()
    {
        struct rectangle r = {20,23};
        printf("%d",area(r));
    }
    ```
* Example by reference
    ```C
    struct rectangle
    {
        int length;
        int breadth;
    };
    int changeLength(struct rectangle &r1)
    {
        r1.length++; /* This does affect the actual parameters value since this is reference */
        return (r1.length);
    }
    int main()
    {
        struct rectangle r = {20,23};
        printf("%d",changeLength(r));
    }
    ```
* Example by address
    ```C
    struct rectangle
    {
        int length;
        int breadth;
    };
    int changeLength(struct rectangle *p)
    {
        p->length++; /* This does affect the actual parameters value
        return (p->length);
    }
    int main()
    {
        struct rectangle r = {20,23};
        printf("%d",changeLength(&r));
    }
    /* An array cant be passed by value but a structure containing an array can be passed by value by passing the structure */
    ```
* Example
    ```C
    struct Arr
    {
        int arr[5];
        int n;
    };
    void test(struct Arr a1) /* A new memory is allocated and changes made is independent of formal parameters */
    {
        ...
    }
    int main()
    {
        struct Arr a = {{5,4,3,4,6},5};
        test(a);
    }
    ```

## Structure and Functions
---
* Example
    ```C
    struct rectangle
    {
        int length;
        int breadth;
    };
    void initialise(struct rectangle *r,int l,int b)
    {
        (*r).length = l;
        r->breadth = b;
    }
    void area(struct rectangle r)
    {
        r->length*r->breadth;
    }
    void changeLength(struct rectangle *r, int l)
    {
        r->length = l;
    }
    int main()
    {
        struct rectangle r;
        initialise(&r,10,5);
        area(r);
        changeLength(&r,15);
    }
    ```

## Changing C program to C++
---
* Example from the last one
    ```C
    class Rectangle
    {
        private:
            int length;
            int breadth;
        Rectangle(int l,int b) // Constructor is used to initialise the object
        {
            length = l;
            breadth = b;
        }
        void area()
        {
            length*breadth;
        }
        void changeLength(int l)
        {
            length = l;
        }
        int main()
        {
            Rectangle r(10,5);
            r.area();
            r.changeLength(15);
        }
    }
    ```
## Class and Constructor(C++)
* Example
    ```C
    #include<iostream>
    using namespace std;

    class Rectangle
    {
        private:
            int length;
            int breadth;
        public:
            // Constructor overloading
            Rectangle(){
                length = 4;
                breadth = 5;
            }
            Rectangle(int l, int b); // prototype or a signature of a function
            int area();
            int perimeter();
            int getLength(){ return length;}
            void changeLength(int l){ length = l;}
            // Destructor
            ~Rectangle();
    };
    Rectangle::Rectangle(int l,int b)
    {
        length = l;
    }
    int Rectangle::area()
    {
        return length*breadth;
    }
    int Rectangle::perimeter()
    {
        return 2*(length+breadth);
    }
    Rectangle::~Rectangle()
    {

    }
    int main()
    {
        Rectangle r(10,5);
        cout<<r.area;
        cout<<r.perimeter;
        r.changeLength(15);
        cout<<r.getLength;
    }
    ```
## Template class(C++)
* Generic class is created to operate on any type of data using Template.
Example:
    ```C
    template <class T>
    class Arithmetic
    {
        private:
            T a;
            T b;
        public:
            Arithmetic(T a, T b);
            T add();
            T sub();
    };

    template <class T>
    Arithmetic<T>::Arithmetic(T a,T b)
    {
        this->a=a; // this points to the object
        this->b=b;
    }
    template <class T>
    T Arithmetic<T>::add()
    {
        T c;
        c = a+b;
        return c;
    }
    T template <class T>
    Arithmetic<T>::sub()
    {
        T c;
        c = a-b;
        return c;
    }
    int main()
    {
        Arithmetic<int> ar(10,5);
        cout<<ar.add();
        Arithmetic<float> ar(13.4,4.4);
        cout<<arr.sub();
    }
    ```
## Miscellaneous
---
* Identifiers cant be of any special characters or punctuation marks apart from underscore '_'. Also there cant be two successive underscores.
* In C by convention all keywords are written in lower case letters.
* In the memory characters are all stored in memory by their ASCII values in binary format.
* C supports four modifiers - two sign specifiers[signed and unsigned(positive only)] and two size specifiers(short and long).
* To declare a constant, precede the normal variable with the const keyword and assign it to a value.
* Some standard libraries
        string.h : for string handling functions
        stdlib.h : for some miscellaneous functions
        stdio.h : for standardized input and output functions
        math.h : for mathematical functions
        alloc.h : for dynamic memory allocation
        conio.h : for clearing the screen
* The scanf function ignores any blank space, tabs and new lines entered by the user.
* The prototype of the control string in scanf function can be given as,
        %[*][width][modifier]type
        example: %4d reads a four digit number of type integer 
* In case of reading strings, we dont use the & sign in the scanf function.
* The prototype of the control string in printf function can be given as,
        %[flags][width][.precision][modifier]type
* Modulus operator '%' can be used on integers only and cant be used on double or float values.
* ++x is equivalent to x = x +1
* y = x++ is equivalent to y = x;x = x + 1;
* The expression x << y is equivalent to multiplication of x by 2y. And the expression x >> y is equivalent to division of x by 2y if x is unsigned or has a non-negative value.
* sizeof is a unary operator used to calculate the size of a data type.
* In case the statement block contains only one statement, putting curly brackets becomes optional.
* Switch executes faster than if-else statements.
* Do-while is the only iterative loop which checks condition after running the loop body.
* On 32 bit systems, integer variable is allocated 4 bytes while on 16 bit systems it is allocated 2 bytes.
* Equality operators have lower precedence than relational operators.
* Among all the operators, comma operator has the lowest precedence.
* The break statement is used to terminate the execution of the nearest enclosing loop in which it appears.
* The continue statement skips the code following it and jumps to the next iteration of the nearest loop. For continue, a loop is required.