#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
//liste elemanlarını yazdır
void printList(struct node* head)
{
    struct node * temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
//başa ve sona ekle
struct node * addHead(struct node * head, int gelenData)
{
    struct node * temp= malloc(sizeof(struct node));
    temp->data=gelenData;
    temp->next=NULL;
    temp->prev=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head=temp;
    }
    return head;
};

struct node * addToEnd(struct node * head, int gelenData)
{
    struct node * last = head;
    while(last->next!=NULL)
        last=last->next;
    last->next=malloc(sizeof(struct node));
    last->next->data=gelenData;
    last->next->next=NULL;
    last->next->prev=last;
    return head;
};
//baştan ve sondan sil
struct node * deleteFromHead(struct node * head)
{
    struct node * temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    free(temp);
    return head;
};

struct node * deleteFromEnd(struct node * head)
{
    struct node * last = head;
    while(last->next!=NULL)
        last=last->next;

    last->prev->next=NULL;
    last->prev=NULL;
    free(last);
    return head;
};
//aranan düğümü sil
struct node * searchAndDelete(struct node * head, int arananData)
{
    struct node * temp=head;
    if(head->data==arananData)
    {
        head=deleteFromHead(head);
    }
    else
    {
        while(temp->data!=arananData)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\nAradiginiz veri liste icerisinde yok!\n");
                return head;
            }
        }
        //sileceğim düğümü buldum
        //sileceğim düğüm temp düğümü
        temp->prev->next=temp->next;
        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
        free(temp);
    }
    return head;
};
//iki listeyi birbirine ekle

//terse çevir
struct node * reverseList(struct node * head)
{
    struct node * newList = NULL;
    struct node * last = head;
    while(last->next!=NULL)
        last=last->next;
    while(last!=NULL)
    {
        newList=addToEnd(newList,last->data);
        last=last->prev;
    }
    
    return newList;
};


int main()
{
    struct node * head=malloc(sizeof(struct node));
    head->data=5;
    head->next=NULL;
    head->prev=NULL;

    head->next=malloc(sizeof(struct node));
    head->next->data=10;
    head->next->prev=head;
    head->next->next=NULL;

    //head=addHead(head,1);
    //head=addToEnd(head,15);
    //head=deleteFromHead(head);
    //head=deleteFromEnd(head);
    //head=searchAndDelete(head,10);
    printList(head);

    return 0;
}