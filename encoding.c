#include <stdio.h>

void encode_decode(char*,char*);
void compare(char*,char*);
int main()
{
    char sname[50],dname[50];
    int ch;
    void (*func[])()={encode_decode,encode_decode,compare};
    do
    {
        printf("\n\n------------MENU-----------");
        printf(" \n1. Encode a file\n 2. Decode a file\n 3. Compare two files\n 4. Exit");
        printf("\n\t Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        case 2:
        case 3:
             printf("\nEnter the name of the source file: ");
             scanf("%s",sname);
             printf("\nEnter the name of the destination file: ");
             scanf("%s",dname);

             func[ch-1](sname,dname);
             break;
        case 4:
            break;
        default:
            printf("\nWrong choice, enter again!");
            break;
        }
    }while(ch!=4);
    return 0;
}
void encode_decode(char *sname,char *dname)
{
    FILE *src,*dest;
    int key;
    char c;
    src=fopen(sname,"r");
    dest=fopen(dname,"w+");
    if(!src||!dest)
    {
        printf("\nOne or both files couldn't be opened. ");
        return;
    }
    printf("\nEnter the key: ");
    scanf("%d",&key);
    while((c=fgetc(src))!=EOF)
    {
        if(c!='\n')
            fputc(c^key,dest);
        else
            fputc(c,dest);
    }
    printf("\nEncrypted/Decrypted file: \n");
    rewind(dest);
    while((c=fgetc(dest))!=EOF)
    {
        printf("%c",c);
    }
    fclose(src);
    fclose(dest);
}
void compare(char *sname, char *dname)
{
    FILE *src,*dest;
    char c1,c2;
    int f=1;
    src=fopen(sname,"r");
    dest=fopen(dname,"r");
    if(!src||!dest)
    {
        printf("\nOne or both files couldn't be opened. ");
        return;
    }
    while((c1=fgetc(src))!=EOF&&(c2=fgetc(dest))!=EOF)
    {
        if(c1!=c2)
        {
            printf("\n\nBoth files are not the same, they differ at character %d, (%c!=%c)",ftell(src),c1,c2);
            f=0;
            break;
        }
    }
    if(f)
        printf("\nBoth files are same");
    fclose(src);
    fclose(dest);
}
