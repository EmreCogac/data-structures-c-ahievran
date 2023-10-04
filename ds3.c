#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};
//liste içerisindeki elemanları ekrana yazdır
void listeyiYazdir(struct node * head)
{
    struct node * temp = head;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
//listenin başına eleman ekleme işlemi
struct node * basaEkle(struct node * head, int eklenecekData)
{
    struct node * temp = malloc(sizeof(struct node));
    temp->data= eklenecekData;
    temp->next=NULL;
    temp->next= head;
    struct node * last = head;
    while(last->next!=head)
        last=last->next;
    last->next=temp;
    head=temp;
    return head;

};

//sona eleman ekleme işlemi
struct node * sonaEkle(struct node * head, int eklenecekData)
{
    struct node * temp=malloc(sizeof(struct node));
    temp->data=eklenecekData;
    
    struct node * last = head;
    while(last->next!=head)
        last=last->next;
    
    last->next=temp;
    temp->next= head;
    return head;
};
//bastan eleman sil
struct node * bastanSil(struct node *head)
{
    struct node * last=head;
    while(last->next=head)
        last=last->next;
    last->next= head->next;
    
    struct node * silinecekDugum=head;
    head=head->next;
    free(silinecekDugum);
    return head;
};
//sondan eleman sil
struct * node sondanSil(struct node * head)
{
    struct node * temp=head;
    while (temp->next->next!=head)
        temp=temp->next;
    struct node * silinecek= temp->next;
    temp->next= head;
    free(silinecek);
    return head;
};
//aranan değere sahip olan düğümü silen metot
//1.Durum=sileceğim eleman ilk sırada
//2.Durum=sileceğim eleman ilk sırada değil
//3.Durum=sileceğim eleman yok
struct node* arananElemaniSil(struct node * head, int aranan)
{
    struct node * temp=head;
    if(temp->data==aranan)
    {
        head= bastanSil(head);
        return head;
    }
    else
    {
        while(temp->next->data!=aranan)
        {
            if(temp->next->next==head)
            {
                printf("Aradiginiz eleman listede yok");
                return head;
            }
            temp=temp->next;
        }
            
            
        struct node * silinecek= temp->next;
        temp->next= temp->next->next;
        free(silinecek);
        return head;
    }
};



int main()
{
    struct node * head= malloc(sizeof(struct node));
    head->data= 5;
    head->next=NULL;


    head->next=malloc(sizeof(struct node));
    head->next->data=10;
    head->next->next=head;
    head=basaEkle(head,1);
    listeyiYazdir(head);

    return 0;
}