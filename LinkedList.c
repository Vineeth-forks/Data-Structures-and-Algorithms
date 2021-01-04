// Linked list is the collection of nodes where each nodes contain data and pointer to the next node.
/* Reasons to use linked list - data to be stored in the heap and to create a variable size structure*/
/* Linked list consists of nodes which in turn consists of - data and a pointer to the next node*/
// Addresses in linked list are not contiguous.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next; // self-referential structure
}*first = NULL;
void singleNode()
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 10;
    p->next = NULL;
}
// When a pointer p is equated to another pointer q i.e p=q then the address the p is being copied to q.
// q = p->next; this means q is pointing to the next node of p
// p = p->next; this means p is pointing to the next node of p
// if(p==NULL) or if(p==0) or if(!p) to check if a pointer is empty
// if(p->next==NULL) or if(p->next==0) to check for the last node

// creates a single linked list with a pointer first pointing to the head of the node and pointer last to the tail of the node
void create(int A[],int length)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<length; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while(p!=0)
    {
        printf("%d",p->data);
        p = p->next;
    }
}
int countNodes(struct Node *t)
{
   int count = 0;
   while(t!=0)
   {
       count++;
       t = t->next;
   }
   return count;
}
int sumOfElements(struct Node *t)
{
    int sum = 0;
    while(t!=0)
    {
        sum = sum + t->data;
        t = t->next;
    }
    return sum;
}
int MaxElement(struct Node *t)
{
    int max = t->data;
    while(t!=0)
    {
        if(t->data>max)
            max = t->data;
        t = t->next;
    }
    return max;
}

// Binary search isnt possible with linked list

// Linear search
struct Node* linearSearch(struct Node *t, int key)
{
    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        t = t->next; 
    }
    return NULL;
}

// Transposition linear search
struct Node* tLinearSearch(struct Node *t, int key)
{
    struct Node *q = NULL;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            if(key==first->data)
            {
                return t;
            }
            else
            {
                q->next = t->next;
                t->next = first;
                first = t;
                return t;
            }
        }
        q = t;
        t = t->next;
    }
    return NULL;
}

// Insertion of a node
void insertionNode(struct Node *p, int data, int pos)
{
    struct Node *t;
    if(pos==0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = data;
        t->next = first;
        first = t;
    }
    else if(pos>0)
    {
        for(int i = 0; i<pos-1 && p;i++)
        {
            p = p->next;
        }
        if(p)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            t->next = p->next;
            p->next = t;
        }
        else
        {
            printf("Position doesnt exist\n");
        }
    }
    else
    {
        printf("position cant be negative\n");
    }
}

// Insertion sort
void InsertSort(struct Node *p,int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = NULL;
    t->data = data;
    t->next = NULL;
    if(first==NULL)
    {
        first = t;
    }
    else
    {
        while(p!=NULL && p->data<data)
        {
            q=p;
            p = p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t; 
        }
    }
}