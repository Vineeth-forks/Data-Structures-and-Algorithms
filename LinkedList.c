// Linked list is the collection of nodes where each nodes contain data and pointer to the next node.
/* Reasons to use linked list - data to be stored in the heap and to create a variable size structure*/
/* Linked list consists of nodes which in turn consists of - data and a pointer to the next node*/
// Addresses in linked list are not contiguous.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data; // node data
    struct Node *next; // self-referential structure and holds the address to the next node
}*first = NULL;

//Circular linked list
struct CNode
{
    int data;
    struct CNode *next;
}*head=NULL;
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

// When a node is not in used it should be deleted or free-ed from the memory.

// Deleting a node
void deleteNode(struct Node *p,int pos)
{
    struct Node *q = NULL;
    if(pos==1)
    {
        first = first->next;
        free(p);
    }
    else if(pos>1)
    {
        for(int i = 0; i<pos-1 && p; i++)
        {
            q=p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            free(p);
        }
        else
        {
            printf("Position doesnt exist");
        }
    }
    else
    {
        printf("position cannot be zero or negative");
    }
}

// To check if a linked list is sorted or not
void sortOrNot(struct Node *p)
{
    while(p->next!=NULL)
    {
        if((p->data)>((p->next)->data))
        {
            printf("Not sorted");
            return;
        }
        p = p->next;
    }
    printf("Sorted");
}

// To delete duplicate nodes in a sorted linked list
void deleteDuplicate(struct Node *q)
{
    struct Node *p = q->next;
    while (p!=NULL) 
    {
        if(q==p)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}

// Reversing a linked list using a copy array
void reverse(struct Node *p)
{
    int store[countNodes(p)];
    int i = 0;
    while(p!=NULL)
    {
        store[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while(p!=NULL)
    {
        p->data = store[i];
        p = p->next;
        i--;
    }
}

// Reversing a linked list through sliding pointers (preferred method)
void reverseAlt(struct Node *p)
{
    struct Node *q,*r = NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Concatenating two linked list
void concate(struct Node *p,struct Node *q)
{
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
    free(q);
} 

// Merging two linked list in a sorted order
void merge(struct Node *p,struct Node *q)
{
    struct Node *r,*pFirst = NULL;
    if(p->data<q->data)
    {
        r = pFirst = p;
        p = p->next;
        r->next = NULL;
    }
    else
    {
        r = pFirst = q;
        q = q->next;
        r->next = NULL;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
            r->next = NULL;
        }
        else
        {
            r->next = q;
            r = q;
            q = q->next;
            r->next = NULL;
        }
    }
    if(p==NULL)
    {
        r->next = q;
    }
    else
    {
        r->next = p;
    }
}

// To find whether a linked list is a loop or not
void isLoop(struct Node *p)
{
    struct Node *q = p;
    do
    {
        p = p->next;
        q = q->next;
        q = q!=NULL?q->next:NULL;
    }while(p&&q);
    if(p==q)
    {
        printf("It is a loop");
    }
    else
    {
        printf("It is a linear linked list");
    }
}

// In a circular linked list there is no first node, we can assume a particular node to be a head(marked as a reference)

// creating and displaying of a circular linked list
void createC(int A[],int n)
{
    struct CNode *t,*last;
    head=(struct CNode *)malloc(sizeof(struct CNode));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=(struct CNode *)malloc(sizeof(struct CNode));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void displayCircular(struct CNode *t)
{
    do
    {
        printf("%d",t->data);
        t=t->next;
    }while(t!=head);
}

// length of the circular linked list
int lengthCircular(struct CNode *t)
{
    int count=0;
    do
    {
        count++;
        t=t->next;
    }while (t!=head);
    return count;
}

// Insertion in a circular linked list
void insertCircular(struct CNode *p,int pos,int data)
{
    struct CNode *t=NULL;
    if(pos>lengthCircular(p))
    {
        return;
    }
    if(pos==0)
    {
        t=(struct CNode *)malloc(sizeof(struct CNode));
        t->data=data;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
                p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1;i++)
            p=p->next;
        t=(struct CNode *)malloc(sizeof(struct CNode));
        t->data=data;
        t->next=p->next;
        p->next=t;
    }
}

// Deletion of a node in a circular linked list
void deleteCircular(struct CNode *p,int pos)
{
    struct CNode *q;
    if(pos>lengthCircular(p))
        return;
    if(pos==0)
    {
        while(p->next!=head)
            p=p->next;
        if(head==p)
        {
            head=p;
            head->next=head;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        p=p->next;
        q=p->next;
        p->next=q->next;
        free(q);

    }
}