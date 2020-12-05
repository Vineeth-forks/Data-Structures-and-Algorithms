#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;// global variable

// Creating a node containing data and address to the next node
void create(int A[],int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));// creation of the memory
        t->data = A[i];// inputing the data
        t->next = NULL;// linking them
        last->next = t;
        last = t;
    }
}

// traversing through the node and printing the contents
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}

// to count the number of nodes
int count(struct Node *p)
{
    int counter=0;
    while(p!=NULL)
    {
        counter++;
        p=p->next;
    }
    return counter;
}

// sum of all the elements in a linked list
void add(struct Node *p)
{
    int sum = 0;
    while(p!=NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    printf("\nThe sum of all the elements in the linked list is %d\n",sum);
}

void maxElement(struct Node *p)
{
    int max = p->data;
    while(p!=NULL)
    {
        if(max<p->data)
        {
            max = p->data;
        }
        p=p->next;
    }
    printf("%d\n",max);
}

// searching an element using linear search
// Binary search cant be performed on linked list
void improvedLSearch(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q=p;
        p=p->next;
    }
}

// Insertion of a node
void insertion(struct Node *p,int index,int data)
{
    struct Node *t;
    if(index<0||index>count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    if(index==0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {   
            p=p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

// Inserting a node in a sorted linked list
void sortInsertion(struct Node *p,int index,int data)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    if(first=NULL)
    {
        first=t;
    }
    else
    {
        while(p&&p->data<data)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {1,4,5,6,3,2,4};
    create(A,7);
    display(first);
    int nodes = count(first);
    add(first);
    maxElement(first);
}