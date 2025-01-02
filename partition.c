#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_partition(int *,int *,int);
int main()
{
    int *arr,*narr,n,i;
    printf("\nEnter the size of the array: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    narr=(int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        printf("\n[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    random_partition(arr,narr,n);
    printf("\nArray after partitioning is: ");
    for(i=0;i<n;i++)
        printf("%d ",narr[i]);
    free(arr);
    free(narr);
    return 0;
}
void random_partition(int *arr,int *narr,int n)
{
    int i,k=0,r;
    srand(time(NULL));
    r=rand()%n;
    printf("\nRandom element picked is: '\033[1;32m%d\033[0m'",arr[r]);//\033[1;32m%d\033[0m
    for(i=0;i<n;i++)
        if(arr[i]<=arr[r])
            narr[k++]=arr[i];
    for(i=0;i<n;i++)
        if(arr[i]>arr[r])
            narr[k++]=arr[i];
    printf("\nk=%d, n=%d",k,n);
    return;
}
