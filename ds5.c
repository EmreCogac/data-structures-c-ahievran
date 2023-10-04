#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
//düğümleri yazdır
void dugumleriYazdir(struct node * head)
{
    struct node * temp=head;
    do
    {
        printf("\t%d\t",temp->data);
        temp=temp->next;
    }while(temp!=head);
};
//basa ve sona ekle
struct node * basaEkle(struct node * head, int gelenData)
{
    struct node * temp = malloc(sizeof(struct node));
    temp->data=gelenData;
    temp->next =head;
    head->prev->next=temp;
    temp->prev=head->prev;
    head->prev=temp;
    return temp;
};
struct node * sonaEkle(struct node * head, int gelenData)
{
    struct node * temp= malloc(sizeof(struct node));
    temp->data=gelenData;
    temp->next=head;
    head->prev->next= temp;
    temp->prev=head->prev;
    head->prev=temp;
    return head;

};
//Sıralı bir listede, parametre olarak gönderilen datayı ilgili yere ekle
struct node * dugumEkle(struct node * head, int eklenecekData)
{
    if(eklenecekData<head->data)
       return basaEkle(head,eklenecekData);
    else if(eklenecekData>head->prev->data)
       return sonaEkle(head,eklenecekData);
    else
    {
        struct node *temp= head;
        while(eklenecekData>=temp->data)
            temp=temp->next;
        basaEkle(temp,eklenecekData);
        return head;
    }
};
//baştan sondan sil
struct node * bastanSil(struct node * head)
{
    struct node * temp=head;
    head=head->next;
    head->prev=temp->prev;
    temp->prev->next=head;
    free(temp);
    return head;
};
struct node * sondanSil(struct node * head)
{
    struct node * temp=head->prev;
    head->prev=temp->prev;
    temp->prev->next=head;
    free(temp);
    return head;
};
//aranan değere sahip olan düğümü liste içerisinden sil
struct node * dugumSil(struct node * head, int arananData)
{
    if(arananData==head->data)
        return bastanSil(head);
    else if(arananData==head->prev->data)
        return sondanSil(head);
    else
        {
            struct node *temp=head;
            while(arananData!=temp->data)
            {
                temp=temp->next;
                if(temp==head)
                {
                    printf("\nSilmek istediginiz data listede yer almiyor!\n");
                    return head;
                }
            }
            bastanSil(temp);
            return head;

        }
};
//aranan düğümün liste içerisinde kaçıncı sırada olduğunu döndüren metot
int siraNoBul(struct node * head, int arananData)
{
    int sayac=1;
    struct node * temp =head;
    while(arananData!=temp->data)
    {
        temp=temp->next;
        sayac++;
        if(temp==head)
            return -1;
    }
    return sayac;
}
//parametre olarak gelen 2 bağlı listeyi birbirine ekleyen metodu yazınız
struct node * listeleriBirlestir(struct node * head1, struct node *head2)
{
    struct node * temp= head2->prev;
    head1->prev->next=head2;
    head2->prev=head1->prev;
    head1->prev=temp;
    temp->next=head1;
    return head1;

};
//parametre olarak gelen sıralı iki bağlı listeyi sıralı bir şekilde birleştiriniz



int main()
{
    struct node * head= malloc(sizeof(struct node));
    head->data=5;

    struct node * temp1= malloc(sizeof(struct node));
    temp1->data=10;

    struct node * temp2= malloc(sizeof(struct node));
    temp2->data=15;

    head->next = temp1;
    temp1->prev= head;
    temp1->next=temp2;
    temp2->prev=temp1;
    temp2->next=head;
    head->prev=temp2;

    //head= dugumEkle(head,10);
    //head= dugumSil(head,10);
    dugumleriYazdir(head);

    int indisNo=siraNoBul(head,15);
    if(indisNo==-1)
        printf("\nAradiginiz data liste icinde yer almiyor.");
    else
        printf("\nAradiginiz data %d . sirada yer aliyor", indisNo);






    return 0;
}
