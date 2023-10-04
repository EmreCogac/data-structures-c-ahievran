#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};

//listenin sonuna eleman ekleme
struct node * sonaEkle(struct node* head, int eklenecekVeri)
{
    struct node * temp;
    temp=malloc(sizeof(struct node));
    temp->data=eklenecekVeri;
    temp->next=NULL;

    struct node * temp2=head;

    while(temp2->next!=NULL)
        temp2=temp2->next;

    temp2->next=temp;
    return head;
};

//listenin başına eleman ekleyen metot
struct node * basaEkle(struct node * head, int eklenecekData)
{
    struct node * temp;
    temp= malloc(sizeof(struct node));
    temp->data=eklenecekData;
    temp->next=head;
    head=temp;
    return head;
};

//liste içerisindeki tüm elemanları yazdıran metot
void ekranaYaz(struct node * head)
{
    struct node* temp= head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
//ekrana yazma metodunu RECURSİVE olarak yazınız
void ekranaYazRec(struct node * head)
{
    if(head!=NULL)
    {
        printf("%d\t",head->data);
        ekranaYazRec(head->next);
    }
}
//bir listedeki düğümlerin sayısını hesaplayan
//ve geriye döndüren metot
int dugumSay (struct node * head)
{
    int sayac=0;
    struct node * temp=head;
    while(temp!=NULL)
    {
        sayac++;
        temp=temp->next;
    }
    return sayac;
}
//listenin ilk elemanını silen metodu yazınız
struct node * basElemaniSil(struct node * head)
{
    struct node * temp = head;
    head= head->next;
    free(temp);
    return head;
};
//sondaki elemanı ve aradaki bir elamanı silen metot
//ÖDEV

int main()
{
    struct node * head;
    head= malloc(sizeof (struct node));
    head->data=6;
    head->next=NULL;

    head->next=malloc(sizeof(struct node));
    head->next->data=10;
    head->next->next=NULL;

    head= sonaEkle(head,15);
    head= basaEkle(head,3);

    ekranaYaz(head);


    return 0;
}
