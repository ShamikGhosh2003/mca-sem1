/*12. Write a program to store the country names and sort them in
alphabetical order. Use array of pointers to store the country
names and pass the array to the function sort().*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char**,int);
int main()
{
    char *country[100];
    char str[50];
    int n,i;
    printf("\nEnter the number of countries you want to store: ");
    scanf("%d",&n);
    if(n<=0 || n>100)
    {
        printf("\nInput out of range!");
        return 1;
    }
    printf("\nEnter the name of the countries: ");
    for(i=0;i<n;i++)
    {
        printf("\n[%d]: ",i+1);
        getchar();
        scanf("%[^\n]",str);
        country[i]=(char *)malloc((strlen(str)+1)*sizeof(char));
        strcpy(country[i],str);
    }
    printf("\n\nList of countries are:\n");
    for(i=0;i<n;i++)
        printf("%s ",country[i]);
    sort(country,n);
    printf("\n\nList of countries after sorting is:\n");
    for(i=0;i<n;i++)
    {
        printf("%s ",country[i]);
        free(country[i]);
    }
    return 0;
}
void sort(char **country,int n)
{
    char *temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(strcmp(country[j],country[j+1])>0)
            {
                temp=country[j];
                country[j]=country[j+1];
                country[j+1]=temp;
            }
        }
    }
}
