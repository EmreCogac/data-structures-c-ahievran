#include <stdio.h>
#include <stdlib.h>
//doğrusal arama- indexof
int linearSearch(int gelenDizi[], int arananSayi, int elSay)
{
    for(int i = 0; i<elSay; i++ )
    {
        if(gelenDizi[i]==arananSayi)
            return i;
    }
    return -1;
}
//ikili-binary search
int binarySearch(int gelenDizi[], int arananSayi, int elSay)
{
    int sol=0;
    int sag=elSay-1;

    while(sag>=sol)
    {
        int orta = sol + (sag-sol)/2;
        if(gelenDizi[orta]==arananSayi)
            return orta;
        else if (arananSayi > gelenDizi[orta])
            sol=orta+1;
        else
            sag=orta-1;
    }
    return -1;
}
//binary search -recursive
int binarySearchR(int gelenDizi[], int arananSayi,int sol, int sag)
{
    if(sag >= sol)
    {
        int orta = sol + (sag-sol)/2;
        if(gelenDizi[orta]==arananSayi)
            return orta;
        else if (arananSayi>gelenDizi[orta])
            return binarySearchR(gelenDizi, arananSayi,orta+1,sag);
        else
            return binarySearchR(gelenDizi, arananSayi,sol,orta-1);
    }

    else
        return -1;
}

//bubble sort- kabarcık sıralama
int sirala(int gelenDizi[],int diziUzunluk)
{
    int temp;
    for(int i=0; i<diziUzunluk ; i++ )
    {
        for(int j=0; j<diziUzunluk-1-i; j++)
        {
            if(gelenDizi[i]>gelenDizi[i+1])
            {
                // 2-4
                // i-i+1
                //temp=4
                temp=gelenDizi[i];
                gelenDizi[i]=gelenDizi[i+1];
                gelenDizi[i+1]=temp;
            }
        }
    }
    printf("\nDizi elemanları yazdiriliyor.\n");
    for(int k = 0; k<diziUzunluk; k++)
        printf("%d\t",gelenDizi[k]);
}



int main()
{
    int dizi [] = {2,1,4,3,5,7,6};
    int aranan = 2;
    //length, len, count
    int elemanSayisi = sizeof(dizi) / sizeof(dizi[0]);


    sirala(dizi, elemanSayisi);
    return 0;
}