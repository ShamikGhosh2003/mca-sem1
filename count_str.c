#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(char *);
int main()
{
    char str[300],*article[]={" a "," an "," the "," A "," An "," The "};
    int countArticle=0,c1=0, countUpper=0, i, j, k;
    input(str);
    printf("\nInputted String is \"%s\"",str);
    for(k=0;k<sizeof(article)/sizeof(article[0]);k++)
    {
        for(i=0;i<strlen(str);i++)
        {
            c1=0;
            for(j=0;j<strlen(article[k]);j++)
            {
                if(str[i+j]==article[k][j])
                    c1++;
            }
            if(c1==strlen(article[k]))
                countArticle++;
        }
    }
    for(i=0;i<strlen(str)-1;i++)
    {
        if(str[i]==' '||str[i]=='-')
            if(str[i+1]>=65 && str[i+1]<=90)
                countUpper++;
    }
    printf("\n\nArticle count is: %d",countArticle);
    printf("\nUppercase word count is: %d",countUpper);
    return 0;
}
void input(char *str)
{
    int i;
    printf("\nEnter a multi-line string (>80 words), terminated by a #: ");
    scanf("%[^#]",str);
    getchar();
    str[strlen(str)]=' ';
    str[strlen(str)+1]='\0';
    for(i=strlen(str);i>=0;i--)
        str[i]=str[i-1];
    str[0]=' ';
    return;
}
