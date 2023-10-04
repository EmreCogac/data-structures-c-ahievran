#include <stdio.h>
#include <stdlib.h>

//ENQUEUE
//DEQUEUE
struct node 
{
    int data;
    struct node * next;
};
struct node * front=NULL;
struct node * rear=NULL;

void enqueue (int data)
{
    struct node * temp= malloc(sizeof(struct node));
    temp->data= data;
    temp->next=NULL;
    
    if(front==NULL && rear == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear= temp;
    }
}

void dequeue()
{
    if(front==NULL && rear==NULL)
        printf("\nKuyruk bos old. icin silme islemi yapilamadi.\n");
    else
    {
        struct node * temp= front;
        front = front->next;
        free(temp);
    }
}

void printQueue()
{
    struct node * temp = front;
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
        
}


//PUSH
//POP

struct node * stack=NULL;

void push(int data)
{
    struct node * temp = malloc(sizeof(struct node));
    temp->data= data;
    temp->next=NULL;
    
    if(stack==NULL)
        stack=temp;
    else
    {
        temp->next=stack;
        stack=temp;
    }
}

void pop()
{
    struct node * temp = stack;
    stack=stack->next;
    free(temp);
}

//hanoi kuleleri



int main()
{
    
    
    return 0;
}