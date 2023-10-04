#include <stdio.h>
#include <stdlib.h>
void selectionSort(int gelenDizi[], int n)
{
    int enKucuk,temp;
    for(int step = 0; step<n; step++)
    {
        enKucuk=step;
        for(int i = step+1; i<n; i++ )
        {
            if(gelenDizi[i]<gelenDizi[enKucuk])
                enKucuk=i;
        }
        temp=gelenDizi[step];
        gelenDizi[step] = gelenDizi[enKucuk];
        gelenDizi[enKucuk]=temp;
    }

    printf("\nDizi elemanlari yazdiriliyor...\n");
    for(int i =0; i<n; i++)
    {
        printf("%d ",gelenDizi[i]);
    }
}

void insertionSort(int gelenDizi[], int n)
{
    int key,j;
    for(int i = 1; i<n; i++)
    {
        j=i-1;
        key=gelenDizi[i];
        while(j>=0 && gelenDizi[j]>key)
        {
            gelenDizi[j+1]= gelenDizi[j];
            j--;
        }
        gelenDizi[j+1]=key;
    }
}



int main()
{
    int dizi [] = {3,67,34,5,90,25};
    int elemanSayisi = sizeof(dizi) / sizeof(dizi[0]);
    selectionSort(dizi, elemanSayisi);


    return 0;
}