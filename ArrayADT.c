#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void input(struct Array *arr)
{
    printf("Enter all the elements\n");
    for(int i = 0;i<arr->length;i++)
    {
        scanf("%d",&arr->A[i]);
    }
}

void display(struct Array *arr)
{
    printf("The elements in the array are:\n");
    for (int i = 0;i<arr->length;i++)
    {
        printf("%d\n",arr->A[i]);
    }
}

void append(struct Array *arr)
{
    int x;
    printf("Enter the element to append\n");
    scanf("%d",&x);
    arr->A[arr->length] = x;
    arr->length++;
}

void insert(struct Array *arr)
{
    int index,num;
    printf("Enter the index\n");
    scanf("%d",&index);
    printf("Enter the number\n");
    scanf("&d",&num);
    for(int i = arr->length;i<index;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = num;
    arr->length++;
}

void delete(struct Array *arr)
{
    int index,num;
    printf("Enter the index of the element to be deleted\n");
    scanf("%d",&index);
    for(int i = index;i<arr->length;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
}

void linear(struct Array *arr)
{
    int key;
    printf("Enter the element to be searched");
    scanf("%d",&key);
    for(int i =0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            printf("Element found in index %d",i);

            return;
        }
    }
    printf("Element not found");
}

void binary(struct Array *arr)
{
    
}

int main() 
{
    struct Array arr;
    printf("Enter the size of the array\n");
    scanf("%d",&arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    printf("Enter the number of elements in an array\n");
    scanf("%d",&arr.length);
    if(arr.length<=arr.size)
    {
        input(&arr);
    }else{
        printf("The number of elements exceeds the size of the array\n");
    }
    int choice;
    Return :
    printf("Enter the options below\n");
    printf("Press 0 to display the elements of an array\n");
    printf("Press 1 to append an element in an array\n");
    printf("Press 2 to insert an element in an array\n");
    printf("Press 3 to delete an element\n");
    printf("Press -1 tp exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case -1: break;
        case 0: display(&arr);
                goto Return;
        case 1: if((arr.size-arr.length)>=1)
                    append(&arr);
                else
                    printf("Cant add element as the size of the array is full\n");
                goto Return;
        case 2: if((arr.size-arr.length)>=1)
                    insert(&arr);
                else
                    printf("Cant add element as the size of the array is full\n");
                goto Return;
        case 3: delete(&arr);
                goto Return;
        case 4: linear(&arr);
                goto Return;
        case 5: binary(&arr);
                goto Return;
    }
}