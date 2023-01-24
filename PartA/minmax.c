#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int max, min;
int Maxmin(int, int, int []);

void delay(int delay)
{
    int now = time(NULL);
    int later = now + delay;
    while (now <= delay)
        now = time(NULL);
}

void main(){
    int i, n;
    double t;
    clock_t begin, end;
    printf("\n Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("\n Enter array elements : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    begin = clock();
    Maxmin(0, n - 1, a);
    end = clock();
    printf("\n Maximum element = %d", max);
    printf("\n Minimum element = %d", min);
    t = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Time taken = %f ", t);
}

int Maxmin(int i, int j, int a[]){
    delay(10000);
    int mid, max1, min1;
    if(i == j){
        max = min = a[i];
    } else{
        if( i == j){
            if( a[i] < a[j]){
                max = a[j];
                min = a[i];
            }else{
                max = a[i];
            }
        } else {
            mid = (i + j) / 2;
            Maxmin(i, mid, a);
            max1 = max;
            min1 = min;
            Maxmin(mid + 1, j, a);
            if(max < max1)
                max = max1;
            if( min > min1)
                min = min1;
        }
    }
    return 0;
}