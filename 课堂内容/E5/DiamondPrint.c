#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n,i,j;
	scanf("%d",&n);
	char a[2*n+3][2*n+3];
	memset(a,32,sizeof(a));
	a[1][n+1]='*';
	a[2*n+1][n+1]='*';

	for (i = 1; i <= n; i++)
	{
		a[i+1][n+1+i]='*';
		a[i+1][n+1-i]='*';
		a[2*n+1-i][n+1+i]='*';
		a[2*n+1-i][n+1-i]='*';
	}

	for (i = 1; i <= 2*n+1; i++)
	{
		for (j= 1; j<= 2*n+1; j++)
		{
			if((i==1 || i==2*n+1 ) && a[i][j-1]=='*')
				break;
			else if((i!=1 && i!=2*n+1 )&& a[i][j-1]=='*' && j>n+1)
				break;
			else
				printf("%c",a[i][j]);
		}
		printf("\n");
	}

	return 0;
}