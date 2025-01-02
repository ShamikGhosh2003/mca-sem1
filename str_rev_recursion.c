#include <stdio.h>

void rev(char *);
void rev_rec(char *,int);
int main()
{
    char str[50];
    printf("\nEnter a string: ");
    scanf("%[^\n]",str);
    getchar();
    rev(str);
    printf("\nReversed string (recursive) is: ");
    rev_rec(str,strlen(str)-1);
    return 0;
}
void rev(char *str)
{
    int i;
    printf("\nEntered string reversed (non-recursive) is: ");
    for(i=strlen(str)-1;i>=0;i--)
        printf("%c",str[i]);
    return;
}
void rev_rec(char *str,int i)
{
    if(i<0)
        return;
    printf("%c",str[i]);
    return rev_rec(str,--i);//i-- is postfix, it will not update itself in the function call
}
