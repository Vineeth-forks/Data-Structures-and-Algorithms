/* A function calling itself is called recursion */
// example
// Tracing of recursive function can be done in the form of a tree
#include <stdio.h>
void funcB(int n);
void func(int n)
{
    if(n>0)
    {
        printf("%d",n);
        func(n-1);
    }
}// output is 3 2 1

void func2(int m)
{
    if(m>0)
    {
        func2(m-1);
        printf("%d",m);
    }
}// output is 1 2 3

int func3(int n)
{
    static int x = 0;
    if(n>0)
    {
        x++;
        return func3(n-1)+x;
    }
    return 0;
}// output 25

// Tree function
void func4(int n)
{
    if(n>0)
    {
        printf("%d",n);
        func4(n-1);
        func4(n-1);
    }
}// output 3211211

// Indirect function
void funcA(int n)
{
    if(n>0)
    {
    printf("%d", n);
    funcB(n-1);
    }
}
void funcB(int n)
{
    if(n>1)
    {
        printf("%d",n);
        funcA(n/2);
    }
}

// Nested recursion
int func5(int n)
{
    if(n>100)
    {
        return n-10;
    }
    else {
        return func5(func5(n+11));
    }
}

int fact(int n)
{
    if(n<=1)
        return 1;

    return n*fact(n-1);
}

int main() 
{
    func(3);
    printf("\n");
    func2(3);
    printf("\n");
    printf("%d\n",func3(5));
    func4(3);
    printf("\n");
    funcA(20);
    printf("\n");
    func5(95);
    printf("%d",fact(10));
    return 0;
}