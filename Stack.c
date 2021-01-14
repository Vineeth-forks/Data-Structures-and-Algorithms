// Stacks are a collection of elements where deletion and insertion operations happens through LIFO(last in first out) principle
// Stacks can be used to reverse
// Stacks can be used to convert recursion to iterative
/* ADT on stack:
    Data: -> Space for storing the data element
          -> Top pointer to point to the topmost element of a point
    operations: push(x), pop(), peek(index), stackTop(), isEmpty(), isFull() */

// Implementation of stack using array
#include <stdio.h>
#include <stdlib.h>
struct StackArray
{
    int size;
    int top;
    int *s;
};

// creates a stack
void createA(struct StackArray *st)
{
    printf("Enter the size of the stack\n");
    scanf("%d",&st->size);
    st->s=(int *)malloc(st->size*sizeof(int));
    st->top=-1;   
}

// checks if the stack is full
int isFull(struct StackArray *st)
{
    if(st->top==st->size-1)
        return 1;
    return 0;
}

// checks if the stack is empty
int isEmpty(struct StackArray *st)
{
    if(st->top==-1)
        return 1;
    return 0;
}

// displays the elements of the stack
void display(struct StackArray st)
{
    for(int i=st.top;i>=0;i--)
        printf("%d\n",st.s[i]);
}

// insertion in a stack
void push(struct StackArray *st,int data)
{
    if(isFull(st)!=0)
    {
        st->s[st->top+1]=data;
        st->top++;
    }
    else
        printf("Stack overflow\n");
}

// deletion in stack
int pop(struct StackArray *st)
{
    if(isEmpty(st)!=0)
        return st->s[st->top--];
    printf("Stack underflow\n");
    return -1;
}

// returns the value of the corresponding index given
int peek(struct StackArray st,int index)
{
    
    if(index>=0&&st.top<=index)
        return st.s[index];
    printf("index doesnt exist\n");
    return -1;
}

// returns the topmost value in the stack
int stackTop(struct StackArray st)
{
    if(isEmpty(&st)!=0)
        return (st.s[st.top]);
    printf("Stack underflow\n");
    return -1;
}
int main()
{
    struct StackArray st;
    createA(&st);
    return 0;
}