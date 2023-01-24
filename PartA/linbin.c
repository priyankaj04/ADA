#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 20

int pos = 0;

void delay(int delay){
    int now = time(NULL);
    int later = now + delay;
    while (now <= delay)
        now = time(NULL);
}

int binsearch(int n, int a[], int k, int low, int high){
    int mid;
    delay(5);
    if(low < high){
        mid = (high + low) / 2;
        if( k == a[mid])
            return mid;
        else if(k < a[mid])
            return binsearch(n, a, k, low, mid - 1);
        else if(k > a[mid])
            return binsearch(n, a, k, mid + 1, high);
    }
    return -1;
}

int linsearch(int n, int a[], int k)
{
    delay(5);
    if(n < 0)
        return -1;
    if(k == a[n - 1])
        return n - 1;
    else
        return linsearch(n - 1, a, k);
}

void main(){
    double t;
    int n, i, a[MAX], k, ch, low, high, pos;
    clock_t begin, end;
    printf("\n\t\t * * * * * * * MENU * * * * * * *");
    printf("\n 1. Linear Search \n 2. Binary Search");
    printf("\n\t Enter your choice : ");
    scanf("%d", &ch);

    switch(ch){
        case 1:
            printf("\n\t ------ Linear Search ------");
            printf("\n Enter total number of elements in the array : ");
            scanf("%d", &n);
            printf("\n Enter array elements : ");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);
            printf("\n Enter the element to be searched : ");
            scanf("%d", &k);
            begin = clock();
            pos = linsearch(n, a, k);
            if( pos < 0 )
                printf("\n Element not found");
            else
                printf("\n %d found in %d position.", k, pos + 1);
            printf("\n Time taken = %.2f milliseconds", (end - begin) / CLOCKS_PER_SEC);
            printf("\n\n __________________________________________________________\n\n");
            break;
        case 2 :
            printf("\n\t ------ Binary Search ------");
            printf("\n Enter total number of elements in the array : ");
            scanf("%d", &n);
            printf("\n Enter array elements : ");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);
            printf("\n Enter the element to be searched : ");
            scanf("%d", &k);
            low = 0;
            high = n - 1;
            begin = clock();
            pos = binsearch(n, a, k, low, high);
            if (pos < 0)
                printf("\n Element not found");
            else
                printf("\n %d found in %d position.", k, pos + 1);
            printf("\n Time taken = %.2f milliseconds", (end - begin) / CLOCKS_PER_SEC);
            printf("\n\n __________________________________________________________\n\n");
            break;
        default:
            printf(" XXXXX Invalid Choice XXXXX ");
        }
}