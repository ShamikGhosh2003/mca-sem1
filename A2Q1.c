/*Find the 3rd max, 5th min and mid of 1-D array without sorting it*/

/*Inefficient code according to ma'm, but easy to read and modular*/
#include <stdio.h>
#include <stdlib.h>

void input(int*,int);
void third_max(int*,int);
void fifth_min(int*,int);
void (*func[])(int *,int)={input,third_max,fifth_min};
int main()
{
    int *arr,n,i;
    printf("\nEnter the size of the array (size>5): ");
    scanf("%d",&n);
    if(n<=5)
    {
        printf("\nSize is less then 5!!\n");
        exit(0);
    }
    arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<3;i++)
        func[i](arr,n);
    return 0;
}
void input(int *arr,int n)
{
    int i;
    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        printf("\n[%d]: ",(i+1));
        scanf("%d",&arr[i]);
    }
}
void third_max(int *arr,int n)
{
    int i,j,k=0,max,index[3]={-1,-1,-1};
    for(i=0;i<3;i++)
    {
        max=-9999999; /*Fix this later*/
        for(j=0;j<n;j++)
        {
            if(j==index[0]||j==index[1]||j==index[2])
                continue;
            else
            {
                if(max<arr[j])
                {
                    index[k]=j;
                    max=arr[j];
                }
            }
        }
        k++;
    }
    printf("\nThird maximum is: %d",max);
}
void fifth_min(int *arr,int n)
{
    int i,j,k=0,min,index[5]={-1,-1,-1,-1,-1};
    for(i=0;i<5;i++)
    {
        min=9999999; /*Fix this too*/
        for(j=0;j<n;j++)
        {
            if(j==index[0]||j==index[1]||j==index[2]||j==index[3]||j==index[4])
                continue;
            else
            {
                if(min>arr[j])
                {
                    index[k]=j;
                    min=arr[j];
                }
            }
        }
        k++;
    }
    printf("\nFifth minimum is: %d",min);
}
