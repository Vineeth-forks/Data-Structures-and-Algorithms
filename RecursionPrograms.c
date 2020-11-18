#include <stdio.h>
// Sum of N natural numbers
int sum(int n)
{
    if(n>0)
    {
        return sum(n-1) + n;
    }else {
        return 0;
    }
}

// Factorial of a number
int fact(int n)
{
    if(n>0)
    {
        return fact(n-1)*n;
    }
    else
    {
        return 1;
    }
}

// Power of a number
int power(int n, int p)
{
    if(p>0)
    {
        return power(n,p-1)*n;
    }
    else {
        return 1;
    }
}

int fib(int n)
{
    if(n<=1)
        return n;

    return fib(n-1)+fib(n-2);
}
int main()
{
    printf("%d\n",sum(5));
    printf("%d\n",fact(4));
    printf("%d\n",power(2, 3));
    printf("%d\n",fib(15));
    return 0;
}