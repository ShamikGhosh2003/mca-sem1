/*Write a function which will accept two strings and check
whether the second string is present in the first one. If it is, it
returns the starting position else returns 0. Write a program
which dynamically allocates memory for two strings taken from
keyboard and uses the above function for searching one string
into another.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(void);
int main()
{
    int res=func();
    if(res)
        printf("\nSubstring found at position: %d",res);
    else
        printf("\nSubstring not found!");
    return 0;
}
int func()
{
    char *str,*substr,ch;
    int size=10,l=0,i,j,c,flag=0,pos,l1,l2;;

    str=(char *)malloc(size*sizeof(char));
    substr=(char*)malloc(size*sizeof(char));
    if(str==NULL||substr==NULL)
    {
        printf("\nMemory allocation failed!");
        return 1;
    }
    printf("\nEnter a string (haystack) (press enter to stop): ");
    while((ch=getchar())!='\n')
    {
        if(l>=size-1)
        {
            size*=2;
            str=(char*)realloc(str,size);
        }
        str[l++]=ch;
    }
    str[l]='\0';
    l=0;size=10;
    printf("\nEnter another string (needle) (press enter to stop): ");
    while((ch=getchar())!='\n')
    {
        if(l>=size-1) //size-1 considering the null character
        {
            size*=2;
            substr=(char*)realloc(substr,size);
        }
        substr[l++]=ch;
    }
    substr[l]='\0';
    printf("\nEntered haystack is: %s",str);
    printf("\nEntered needle is: %s",substr);
    l1=strlen(str);l2=strlen(substr);
    for(i=0;i<l1;i++)
    {
        c=0;
        for(j=0;j<l2;j++)
        {
            if(str[i+j]==substr[j])
                c++;
        }
        if(c==l2)
        {
            flag=1;
            pos=i;
            break;
        }
    }
    if(flag)
    {
        return (pos+1);
        //printf("\nSubstring found at position: %d",pos);
        /*for(i=pos;i<(pos+l2);i++)
            printf("%c",str[i]);*/
    }
    else
        return 0;
        //printf("\nSubstring not found!");
    free(str);
    free(substr);
}
