#include<stdio.h>
int mult(int n)
{
    int num;
    if(n==1)
        return 1;
    num=n*mult(n-1);
}


int main()
{
	int n;
    scanf("%d",&n);
    printf("%d\n",mult(n));
    return 0;
}