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

// implementation of stack using linked list
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

// checks if the stack is empty
int isEmptyL()
{
    return top?0:1;
}

// A stack is full if the a memory is unable to create as the memory stack is full. The pointer will equate to NULL
// checks if the stack is full
int isFullL()
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    int x=t?1:0;
    free(t);
    return x;
}

// insertion in a stack
void pushL(int data)
{
    struct Node *p =(struct Node *)malloc(sizeof(struct Node));
    if(p==NULL)
    {
        printf("stack overflow\n");
        return;
    }
    p->data=data;
    p->next=top;
    top=p;
}

// deletion in a stack
int popL()
{
    int x;
    struct Node *d=top;
    if(top==NULL)
    {
        printf("stack is empty\n");
        return -1;
    }
    top=top->next;
    x=d->data;
    free(d);
    return x;
}

// prints the contents in a stack;
void displayL()
{
    struct Node *t=top;
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
}

// returns the value corresponding to the index given
int peekL(int index)
{
    struct Node *t=top;
    for(int i=0;i<index-1&&t!=NULL;i++)
        t=t->next;
    if(t==NULL)
        return -1;
    return t->data;
}

// returns the topmost value in a stack
int stackTopL()
{
    if(top)
        return top->data;
    return -1;
}