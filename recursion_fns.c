/*9.Write a recursive function for each of the following problems
a)to generate Fibonacci number.
b)to find the GCD of two numbers.
c)to generate permutations of n numbers
d)to find the sum of the digits of any number.
e) to convert from decimal to binary representation
f) To compute Cos series up to n terms.*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int fibonacci(int);
int gcd(int,int);
void swap(char*,char*);
void permute(char*,int,int);
int sumOfDigits(int);
int DecToBin(int,int);
double cosineRecursive(double,int,double,int);
int main()
{
    int ch,n,a,b,i;
    double x;
    char num[10];
    do
    {
        printf("\n----------------MENU----------------\n");
        printf("\n1. Fibonacci series \n2. GCD of two numbers \n3. Generate permutations of n numbers. \n4. Sum of digits. \n5. Decimal to binary. \n6. Compute cos series. \n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            break;
        case 1:
            printf("\nEnter the number of terms(n): ");
            scanf("%d",&n);
            printf("\nFibonacci series is: ");
            for(i=0;i<n;i++)
                printf("%d ",fibonacci(i));
            break;
        case 2:
            printf("\nEnter the first number: ");
            scanf("%d",&a);
            printf("\nEnter the second number: ");
            scanf("%d",&b);
            printf("\nGCD of %d and %d is: %d",a,b,gcd(a,b));
            break;
        case 3:
            printf("\nEnter a number: ");
            getchar();
            scanf("%[^\n]",num);
            permute(num,0,strlen(num)-1);
            break;
        case 4:
            printf("\nEnter a number: ");
            scanf("%d",&n);
            printf("\nSum of digits is: %d",sumOfDigits(n));
            break;
        case 5:
            printf("\nEnter a decimal number: ");
            scanf("%d",&n);
            printf("\nBinary of %d is %d",n,DecToBin(n,0));
            break;
        case 6:
            printf("\nEnter the value of x (in radian) in cos x: ");
            scanf("%lf",&x);
            printf("\nEnter the value of n: ");
            scanf("%d",&n);
            printf("\nCos %.3lf is: %lf",x,cosineRecursive(x,n-1,1.0,1));
            //printf("\nCos %.3lf using built-in fn is: %lf",x,cos(x));
            break;
        default:
            printf("\nWrong Input!");
            break;
        }
    }while(ch);
    return 0;
}
int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
int gcd(int a,int b)
{
    //Everything divides 0
    if(a==0)
        return b;
    if(b==0)
        return a;
    //base case
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
}
void swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void permute(char *a, int l, int u)
{
    int i;
    if (l==u)
        printf("%s\n", a);
    else
    {
        for (i=l;i<=u;i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, u);

            //backtrack
            swap((a + l), (a + i));
        }
    }
}
int sumOfDigits(int n)
{
    int r;
    static int s=0;
    if(n==0)
        return s;
    else
    {
        r=n%10;
        s=s+r;
        return sumOfDigits(n/10);
    }
}
int DecToBin(int n,int d)
{
    int r;
    static int s=0;
    if(n==0)
        return s;
    else
    {
        r=n%2;
        s=s+r*pow(10,d);
        return DecToBin(n/2,d+1);
    }
}
double cosineRecursive(double x, int n, double term, int factorial) {
    if (n==0)
        return 1.0;
    term = -term * (x * x / (factorial * (factorial + 1)));
    return term + cosineRecursive(x, n - 1, term, factorial + 2);
}

