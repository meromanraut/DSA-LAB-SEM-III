/*wap to implement TOH problem*/
#include<stdio.h>


void transfer(int n, char from, char to, char temp);
int main()
{
    int n;
    printf("\n Enter the number of disks:\n");
    scanf("%d",&n);
    transfer (n,'L','R','C');
}
void transfer (int n,char from, char to, char temp)
{
    if(n==0)
    return;
    else{
        transfer (n-1,from,temp,to);
        printf("\n Move disk %d from %c to %c",n,from,to);
        transfer(n-1,temp,to,from);
    }
}
