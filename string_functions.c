#include <stdio.h>

int Strlen(char *);
void Strcpy(char *,char *);
void Strcat(char *,char *);
int Strcmp(char *,char *);

int main()
{
    int ch;
    char str1[100],str2[50];
    do
    {
        printf("\n-------------------MENU----------------\n");
        printf("\n1. To find the length of the string.\n2. To copy a string.\n3. To concatenate a string.\n4. To reverse a string. \n5. To compare two strings. \n0.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        getchar();
        switch(ch)
        {
        case 0:
            break;
        case 1:
            printf("\nEnter a string: ");
            scanf("%[^\n]",str1);
            getchar();
            printf("\nLength of the entered string is: %d",Strlen(str1));
            break;
        case 2:
            printf("\nEnter a string: ");
            scanf("%[^\n]",str1);
            getchar();
            Strcpy(str1,str2);
            printf("\nCopied String: '%s'",str2);
            break;
        case 3:
            printf("\nEnter a string: ");
            scanf("%[^\n]",str1);
            getchar();
            printf("\nEnter another string: ");
            scanf("%[^\n]",str2);
            getchar();
            Strcat(str1,str2);
            printf("\nConcatenated String is: '%s'",str1);
            break;
        case 4:
            printf("\nEnter a string: ");
            scanf("%[^\n]",str1);
            getchar();
            Strrev(str1);
            printf("\nString after reversing is: '%s'",str1);
            break;
        case 5:
            printf("\nEnter a string: ");
            scanf("%[^\n]",str1);
            getchar();
            printf("\nEnter another string: ");
            scanf("%[^\n]",str2);
            getchar();
            printf("\nFirst string compared with the second is: %d",Strcmp(str1,str2));
            break;
        default:
            printf("\nWrong choice!");
            break;
        }
    }while(ch);
    return 0;
}
int Strlen(char *str)
{
    int l=0;
    while(str[l]!='\0')
        l++;
    return l;
}
void Strcpy(char *str1,char *str2)
{
    int i=0;
    while(str1[i]!='\0')
    {
        str2[i]=str1[i];
        i++;
    }
    str2[i]='\0';
}
void Strcat(char *str1,char *str2)
{
    int i=0,j=0;
    while(str1[i]!='\0')
        i++;
    while(str2[j]!='\0')
        str1[i++]=str2[j++];
    str1[i]='\0';
}
void Strrev(char *str1)
{
    int u=Strlen(str1)-1,l=0;
    char t;
    while(l<u)
    {
        t=str1[l];
        str1[l]=str1[u];
        str1[u]=t;
        l++;u--;
    }
}
int Strcmp(char *str1,char *str2)
{
    int i=0;
    while(str1[i]!='\0'&&str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
            return (int)(str1[i]-str2[i]);
        i++;
    }
    if(str1[i]!='\0')
        return 1;
    if(str2[i]!='\0')
        return -1;
    return 0;
}
