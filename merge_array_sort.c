/*Write a function to take two 2-D arrays, sort those two arrays,
then merge them into a third array that will also be sorted.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr1,*arr2,*arr3,i,j,n1,n2,min_pos,temp,c1=0,c2=0;
    /*Array 1 size and elements input*/
    printf("\nEnter the size of array 1: ");
    scanf("%d",&n1);
    arr1=(int*)malloc(n1*sizeof(int));
    printf("\nEnter the elements of Array 1:\n");
    for(i=0;i<n1;i++)
    {
        printf("[%d]: ",i+1);
        scanf("%d",&arr1[i]);
    }
    /*Array 2 size and elements input*/
    printf("\n\nEnter the size of array 2: ");
    scanf("%d",&n2);
    arr2=(int*)malloc(n2*sizeof(int));
    printf("\nEnter the elements of Array 2:\n");
    for(i=0;i<n2;i++)
    {
        printf("[%d]: ",i+1);
        scanf("%d",&arr2[i]);
    }
    /*Displaying the original arrays*/
    printf("\n\nOriginal Array 1: ");
    for(i=0;i<n1;i++)
        printf("%d ",arr1[i]);
    printf("\nOriginal Array 2: ");
    for(i=0;i<n2;i++)
        printf("%d ",arr2[i]);

    /*Selection sorting array 1*/
    for(i=0;i<n1-1;i++)
    {
        min_pos=i;
        for(j=i+1;j<n1;j++)
        {
            if(arr1[j]<arr1[min_pos])
                min_pos=j;
        }
        temp=arr1[min_pos];
        arr1[min_pos]=arr1[i];
        arr1[i]=temp;
    }
    printf("\n\nSorted Array 1 is: ");
    for(i=0;i<n1;i++)
        printf("%d ",arr1[i]);

    /*Bubble sorting array 2*/
    for(i=0;i<n2-1;i++)
    {
        for(j=0;j<n2-1-i;j++)
        {
            if(arr2[j+1]<arr2[j])
            {
                temp=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=temp;
            }
        }
    }
    printf("\nSorted Array 2 is: ");
    for(i=0;i<n2;i++)
        printf("%d ",arr2[i]);

    arr3=(int*)malloc((n1+n2)*sizeof(int));
    printf("\n\nMerged sorted array: ");
    i=0;
    while(c1<n1&&c2<n2)
    {
        if(arr1[c1]<arr2[c2])
            arr3[i++]=arr1[c1++];
        else
            arr3[i++]=arr2[c2++];
        //printf("%d ",arr3[i]);
    }
    while(c1<n1)
    {
        arr3[i++]=arr1[c1++];
        //printf("%d ",arr3[i]);
    }
    while(c2<n2)
    {
        arr3[i++]=arr2[c2++];
        //printf("%d ",arr3[i]);
    }
    for(i=0;i<(n1+n2);i++)
        printf("%d ",arr3[i]);
    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}
