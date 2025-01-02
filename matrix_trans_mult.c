#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,k,count=0;
    int **arr,**trans,**mul;
    printf("\nEnter the number of rows of the matrix: ");
    scanf("%d",&m);
    printf("\nEnter the number of columns of the matrix: ");
    scanf("%d",&n);
    arr=(int **)malloc(m*sizeof(int*));
    mul=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        arr[i]=(int *)malloc(n*sizeof(int));
        mul[i]=(int *)malloc(m*sizeof(int));
    }
    trans=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        trans[i]=(int *)malloc(m*sizeof(int));
    printf("\nEnter the elements of the matrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("[%d][%d]: ",i,j);
        scanf("%d",&arr[i][j]);
    }
    printf("\nOriginal Matrix:\n");
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
     }
     printf("\nTransposed Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            trans[i][j]=arr[j][i];
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix after multiplication is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            mul[i][j]=0;
            for(k=0;k<n;k++)
                mul[i][j]+=arr[i][k]*trans[k][j];
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(trans);
    free(mul);
    return 0;
}
