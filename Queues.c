// Queues are a collection of elements where deletion and insertion happens through FIFO(First In First Out) principle
/* ADT on queue:
    Data: -> Space for storing the data element
          -> Front pointer for deletion
          -> Rear pointer for insertion
    operations: enqueue(x),dequeue(), isEmpty(), isFull(), first(), last() */

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
