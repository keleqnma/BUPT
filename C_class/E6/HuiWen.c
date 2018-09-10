#include<stdio.h>
int huiwen(int n)
{
	int num=0;
	while(n)  
    {  
        num=num*10+n%10;  
        n=n/10;  
    }  
	return num;
}

int main()
{
    int t;
	scanf("%d",&t);
	if(huiwen(t)!=t)
        printf("no\n");
    else 
       printf("yes\n");
    return 0;
}

