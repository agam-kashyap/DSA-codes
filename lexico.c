#include<stdio.h>
#include<stdlib.h>

void findnext(int a[], int n);
void sort(int a[], int m, int n);
void swap(int *a, int *b);
void merge(int a[], int n, int m, int k);

int main()
{
   int a[6] = {5,3,4,9,7,6};
   findnext(a,6);
   for(int i=0;i<6;i++)
   {
       printf("%d",a[i]);
   }
   printf("\n");
}

void findnext(int a[], int n)
{
    int i;
    for(i=n-1;i>0;i--)
    {
        if(a[i] < a[i+1])
            break;
    }
    if(i == 0)
    {
        printf("No number possible\n");
    }
    else
    {
        int min= i+1;
        for(int j= i+1;j<n;j++)
        {
            if(a[j] < a[min] && a[j]> a[i])
                min = j;
        }
        swap(&a[i],&a[min]);
        sort(a,i+1,n-1);
    }
}

void sort(int a[], int m, int n)
{
    int mid = (m+n)/2;
    if(m<n)
    {
        sort(a,m,mid);
        sort(a,mid+1,n);
        merge(a,m,n,mid);
    }
}

void merge(int a[],int m,int n,int k)
{
    int b[n-m+1];
    int l = m,r=k+1, p = 0;
    while(l<= k && r<=n ) 
    {
        if(a[l] <= a[r])
            b[p++] = a[l++];
        else if(a[l] > a[r])
            b[p++] = a[r++];
    }
    while(l<= k)
        b[p++] = a[l++];
    while(r<=n)
        b[p++] = a[r++];
    p=0;
    for(int i=m;i<=n;i++)
    {
        a[i] = b[p++];
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
