#include <stdio.h>
#include <stdlib.h>
struct node
{
    int label;
    struct node * komsular[20];
    int counter;
    //GRAFLA ALAKASI YOKKKK
    struct node * next;
};

struct node * bas=NULL;
struct node * son = NULL;

void dugumOlustur(int gelenLabel)
{
    struct node * temp= malloc(sizeof(struct node));
    temp->label= gelenLabel;
    temp->counter=0;
    temp->next=NULL;
    if(bas==NULL)
    {
        bas=son=temp;
    }
    else
    {
        son->next=temp;
        son=son->next;
    }
}

void dugumleriYazdir()
{
    printf("\nGraf icerisindeki dugumler: ");
    struct node * temp= bas;
    while(temp!=NULL)
    {
        printf(" %d", temp->label);
        temp=temp->next;
    }
}

struct node * dugumBul(int arananLabel)
{
    struct node * arananDugum=bas;
    while(arananDugum->label!=arananLabel)
        arananDugum=arananDugum->next;
    return arananDugum;
}

void komsulukEkle(int komsu1Label, int komsu2Label)
{
    struct node* komsu1= dugumBul(komsu1Label);
    struct node* komsu2= dugumBul(komsu2Label);

    komsu1->komsular[komsu1->counter]=komsu2;
    komsu1->counter++;

    komsu2->komsular[komsu2->counter]=komsu1;
    komsu2->counter++;
}

//parametre olarak aldığı labela sahip düğümün
//komşularını ekrana yazsın
void komsulariYazdir(int label)
{
    struct node * temp = dugumBul(label);
    printf("\n%d Label degerine sahip kosenin komsulari:",label);
    for(int i = 0; i< temp->counter; i++)
    {
        printf(" %d", temp->komsular[i]->label);
    }
}






int main()
{
    dugumOlustur(1);
    dugumOlustur(2);
    dugumOlustur(3);
    dugumOlustur(4);
    dugumleriYazdir();

    komsulukEkle(1,2);
    komsulukEkle(1,4);
    komsulukEkle(2,3);
    komsulukEkle(2,4);
    komsulukEkle(3,4);
    komsulariYazdir(4);

    return 0;

}
