#include <stdio.h>
#define M 8
#define N 8
void horizontal_swap(int*);
void vertical_swap(int*);
void random_swap(int*);
int main()
{
    void (*func[])(int*)={horizontal_swap,vertical_swap,random_swap};
    int arr[M][N],i,j,ch;
    /*Manual input*/
    /*printf("\nEnter the elements of the matrix:\n ");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }*/
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            arr[i][j]=rand()%90+10;/*2 digit random value*/
    printf("\n\nOriginal matrix is:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    do{
        printf("\nEnter your choice: \n\t1. Horizontal swap\n\t2.Vetical Swap\n\t3.Random swap\n\t0.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            func[0](arr);
            break;
        case 2:
            func[1](arr);
            break;
        case 3:
            func[2](arr);
            break;
        default:
            printf("\nWrong Input!");
            break;
        }
        /*horizontal_swap(arr);
        vertical_swap(arr);
        random_swap(arr);*/
    }while(ch!=0); //while(ch);
    return 0;
}
void horizontal_swap(int arr[M][N])
{
    int i,j,temp;

    for(i=0;i<(M/2);i++)
    {
        for(j=0;j<N;j++)
        {
            temp=arr[i][j];
            arr[i][j]=arr[M-1-i][j];
            arr[M-1-i][j]=temp;
        }
    }
    printf("\nMatrix after Horizontal swapping is:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    return;
}
void vertical_swap(int arr[M][N])
{
    int i,j,temp;

    for(i=0;i<M;i++)
    {
        for(j=0;j<(N/2);j++)
        {
            temp=arr[i][j];
            arr[i][j]=arr[i][j+(N/2)];
            arr[i][j+(N/2)]=temp;
        }
    }
    printf("\nMatrix after Vertical swapping is:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    return;
}
void random_swap(int arr[M][N])
{
    int check[M][N]={0},i,j,iindex,jindex,temp,count=0;
    printf("\n");
    outer: for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(check[i][j]==1)
                continue;
            do{
                iindex=rand()%M;
                jindex=rand()%N;
                if((check[iindex][jindex]==0)&&(iindex==i&&jindex==j))
                {
                    continue;
                    /*iindex=(iindex+1)%M;
                    jindex=(jindex+1)%N;*/
                }
            }while((check[iindex][jindex]==1));
            temp=arr[i][j];
            arr[i][j]=arr[iindex][jindex];
            arr[iindex][jindex]=temp;
            count+=2;
            printf("\narr[%d][%d] swapped with arr[%d][%d]",i,j,iindex,jindex);
            //printf("\nCount: %d",count);
            check[i][j]=1;
            check[iindex][jindex]=1;
            /*if(count==M*N)
                break;*/
        }
        if(count==M*N)
            break;
    }
    printf("\nMatrix after swapping is:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    return;
}
