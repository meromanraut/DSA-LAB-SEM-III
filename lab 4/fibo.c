/*wap to generate fibonaci using recursion */

#include<stdio.h>
int fib(int n);
int main()
{
    int n,i,a;
    printf("How many number of sequnce u want to print");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a=fib(i);
        printf("\n%d",a);


    }
}
int fib(int n)
{
    int a,b,sum;
    if(n==0||n==1)
    return n;
    else
    {
        a = fib(n-1);
        b = fib(n-2);
        sum = a+b;
        return sum;

    }
}