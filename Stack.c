#include <stdio.h>
#include <stdlib.h>

typedef struct Stack 
{
    int data;
    struct Stack *next;
}Node;

Node *top = NULL;

void push(int n)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = n;
    temp->next = NULL;
    if(!top)
        top = temp;
    else 
    {
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    Node *ptr = top;
    top = top->next;
    free(ptr);
}

void display()
{
    Node *ptr = top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    push(3);
    display();
    push(2);
    display();
    push(1);
    display();
    pop();
    pop();
    display();
    return 0;
}