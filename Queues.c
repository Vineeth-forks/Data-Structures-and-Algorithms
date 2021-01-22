// Queues are a collection of elements where deletion and insertion happens through FIFO(First In First Out) principle
/* ADT on queue:
    Data: -> Space for storing the data element
          -> Front pointer for deletion
          -> Rear pointer for insertion
    operations: enqueue(x),dequeue(), isEmpty(), isFull(), first(), last() */
// In a queue, front is used for deletion and rear is used for deletion

// Implementation of queues using array
// While using a front pointer, it should point before the first element
#include <stdio.h>
#include <stdlib.h>

// linear Queue implemented using array
// drawbacks:every location can only be used once
// solution: Circular queue
struct Queue
{
    int size;
    int rear;
    int front;
    int *Q;
};

// creates a queue of a desired size
void create(struct Queue *queue)
{
    printf("Enter the size of the queue\n");
    scanf("%d\n",&queue->size);
    queue->Q=(int *)malloc(queue->size*sizeof(int));
    queue->front=queue->rear=-1;
}

// To check if a queue is empty or not
int isEmpty(struct Queue *queue)
{
    return (queue->rear==queue->front)?1:0;
}
// Insertion in a queue
void enqueue(struct Queue *queue,int data)
{
    if(queue->rear==queue->size-1)
    {
        printf("Queue is full");
        return;
    }
    queue->Q[++(queue->rear)]=data;
}

// Deletion in a queue
int dequeue(struct Queue *queue)
{
    if(queue->rear==queue->front)
    {
        printf("Queue is empty");
        return -1;
    }
    return queue->Q[++(queue->front)];
}

// Displaying a queue
void display(struct Queue queue)
{
    for(int i=queue.front-1;i<=queue.rear;i++)
        printf("%d\n",queue.Q[i]);
}

// Circular queue implemented using array
// We, use rear=(rear+1)%size to it circular
// The front index doest store any data
struct CQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// creating a circular queue is same as that of a linear queue
// In queue, we initalise front and rear as 0 instead of -1(in case of linear queue)
void createC(struct CQueue *queue)
{
    printf("Enter the size of the circular queue\n");
    scanf("%d\n",&queue->size);
    queue->Q=(int *)malloc(queue->size*sizeof(int));
    queue->front=queue->rear=0;
}

// insertion in a circular queue
void enqueueC(struct CQueue *queue,int data)
{
    if((queue->rear+1)%queue->size==queue->front)
    {
        printf("Queue is full");
        return;
    }
    queue->rear=(queue->rear+1)%queue->size;
    queue->Q[queue->rear]=data;
}

// deletion in a circular queue
int dequeueC(struct CQueue *queue)
{
    if(queue->front==queue->rear)
    {
        printf("Queue is empty");
        return -1;
    }
    queue->front=(queue->front+1)%queue->size;
    return queue->Q[queue->front];
}

// Displaying the elements in a circular queue
void displayC(struct CQueue queue)
{
    int i=queue.front+1;
    do
    {
        printf("%d\n",queue.Q[i]);
        i=(i+1)%queue.size;
    }while(i!=(queue.rear+1)%queue.size);
}

// queue implented using linked list
struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

// insertion in a queue
void enqueueL(struct Node *p,int data)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Queue is full");
        return;
    }
    t->data=data;
    t->next=NULL;
    if(front==NULL)
    {
        front=rear=t;
        return;
    }
    rear->next=t;
    rear=t;
}

//deletion in a queue
int dequeueL(struct Node *p)
{
    int x;
    if(front==NULL)
    {
        printf("Queue is empty");
        return -1;
    }
    x=front->data;
    front=front->next;
    free(p);
    return x;
}

// displaying of all the elements in a queue
void displayL(struct Node *t)
{
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
}

// In double ended queue, insertion and deletion can be done by either from the front or the rear
// A priority queue is a data structure in which each element is assigned a priority.  