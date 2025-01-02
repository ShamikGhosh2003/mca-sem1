/*10.Write a function to convert a decimal number to any other
base given by the user..*/
#include <stdio.h>
#include <string.h>

int main()
{
    int n,cpy,base,r,i=0;
    char res[100];
    char rep[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    printf("\nEnter a decimal number: ");
    scanf("%d",&n);
    printf("\nEnter any base (>1 & <62): ");
    scanf("%d",&base);
    if(base<2 || base >62)
    {
        printf("\nInvalid base!");
        return 1;
    }
    cpy=n;
    while(n!=0)
    {
        r=n%base;
        res[i++]=rep[r];
        n/=base;
    }
    res[i]='\0';
    printf("\nDecimal number %d converted to base %d is: %s",cpy,base,strrev(res));
    return 0;
}
