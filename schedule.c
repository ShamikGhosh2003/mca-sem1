/* What does this C program do? */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book_bank{
	char title[50];
	char author[100];
	int pages;
	float price;
} ;
typedef struct {
        int day;
		int hr;
		int mn;
		char book[50];
} myTime; // new type name
void insert_books();
void create_schedule();
void print_schedule();
int main()
{
    int ch;
    void (*func[])()={insert_books,create_schedule,print_schedule};
    do
    {
        printf("\n\n 1. Insert books\n 2. Create Schedule\n 3. Print Schedule\n 0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            func[ch-1]();
            break;
        default:
            printf("\nWrong Input");
        }
    }while(ch);
   return 0;
}
void insert_books()
{
    FILE *bookBank;
    int i,bn;
    struct book_bank *books;
    printf("\n\nEnter the details of the books: ");
    bookBank=fopen("Book_Bank","w");
    printf("\nEnter the number of books you want to store: ");
    scanf("%d",&bn);
    if(bn<=0)
    {
        printf("Value can't be below 0");
        exit(0);
    }
    books=(struct book_bank*)malloc(bn*sizeof(struct book_bank));
    for(i=0;i<bn;i++)
    {
        printf("\nBook [%d]:",i+1);
        getchar();
        printf("\n\tTitle: ");
        scanf("%[^\n]s",books[i].title);
        getchar();
        printf("\n\tAuthor: ");
        scanf("%[^\n]s",books[i].author);
        printf("\n\tPages: ");
        scanf("%d",&books[i].pages);
        printf("\n\tPrice (in Rs): ");
        scanf("%f",&books[i].price);
        fprintf(bookBank,"%s,%s,%d,%.2f\n",books[i].title,books[i].author,books[i].pages,books[i].price);
    }
    printf("\n Book Details written to file Book_Bank\n");
    fclose(bookBank);
}
void create_schedule()
{
    FILE *bookBank,*schedule;
    char fname[50],c,str[200];
    char *token;
    myTime schedulestr[10];
    int count=0,i,l,ch,scount=0;
    struct book_bank *books;
    /*printf("\nEnter the file where the books are stored: ");
    scanf("%s",fname);*/
    bookBank=fopen("Book_Bank","r");
    if(!bookBank)
    {
        printf("\nBook Bank file doesn't exist yet!");
        exit(0);
    }
    while((c=fgetc(bookBank))!=EOF)
    {
        if(c=='\n')
            count++;
    }
    if(count==0)
    {
        printf("\nBook Bank is empty!");
        return;
    }
    rewind(bookBank);
    books=(struct book_bank*)malloc(count*sizeof(struct book_bank));
    for(i=0;i<count;i++)
    {
        fgets(str,200,bookBank);
        token=strtok(str,",");
        strcpy(books[i].title, token);
        token = strtok(NULL,",");//Move to the next token
        strcpy(books[i].author, token);
        token = strtok(NULL,",");
        books[i].pages = atoi(token); //atoi() converts ascii to int
        token = strtok(NULL,",");
        books[i].price = atof(token); //atof() converts ascii to float
    }
    fclose(bookBank);
    do
    {
        printf("-------------------------------------------------");
        printf("\nBook details: ");
        printf("\nSl. No\tTitle\t\tAuthor\t\tPages\t\tPrice\n");
        for(i=0;i<count;i++)
        {
            printf("\n%d: %s\t%s\t%d\t%.2f",(i+1),books[i].title,books[i].author,books[i].pages,books[i].price);
        }
        printf("-------------------------------------------------");
        printf("\n\nEnter 0 to exit");
        printf("\nChoose a book from above: ");
        scanf("%d",&ch);
        if(ch==0)
        {
            printf("\nExit from the program!");
            break;
        }
        printf("\nSelected book: %s",books[ch-1].title);
        strcpy(schedulestr[scount].book,books[ch-1].title);
        printf("\nEnter day number- (0:Sunday, 7: Saturday): ");
        scanf("%d",&schedulestr[scount].day);
        printf("\nEnter the hour you want to study:(24hr) ");
        scanf("%d",&schedulestr[scount].hr);
        printf("\nEnter the minute of the day: ");
        scanf("%d",&schedulestr[scount].mn);
        scount++;
    }while(ch!=0);
    schedule=fopen("schedule","w");
    for(i=0;i<scount;i++)
    {
        fprintf(schedule,"%s,%d,%d,%d\n",schedulestr[i].book,schedulestr[i].day,schedulestr[i].hr,schedulestr[i].mn);
    }
    printf("\nSchedule Written to file schedule");
    printf("-------------------------------------------------");
    fclose(schedule);
}
void print_schedule()
{
    FILE *schedule;
    int count=0,i;
    myTime *sch;
    char str[200],*token,c;
    char *days[]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
    schedule=fopen("schedule","r");
    if(!schedule)
    {
        printf("\nYet to create a schedule!");
        return;
    }
    while((c=fgetc(schedule))!=EOF)
    {
        if(c=='\n')
            count++;
    }
    if(count==0)
    {
        printf("\nSchedule is empty!");
        return;
    }
    rewind(schedule);
    sch=(myTime *)malloc(count*sizeof(myTime));
    printf("\n\nSchedule is:\n");
    printf("-------------------------------------------------");
    printf("\nBook\t\t\tDay\t\t\tTime\n");
    for(i=0;i<count;i++)
    {
        fgets(str,200,schedule);
        token=strtok(str,",");
        strcpy(sch[i].book, token);
        token = strtok(NULL,",");
        sch[i].day=atoi(token);
        token = strtok(NULL,",");
        sch[i].hr = atoi(token);
        token = strtok(NULL,",");
        sch[i].mn = atoi(token);
        printf("\n%s\t\t%s\t\t%d:%dhrs",sch[i].book,days[sch[i].day],sch[i].hr,sch[i].mn);
    }
    fclose(schedule);
}

