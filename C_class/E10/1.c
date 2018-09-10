#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int a[11][11],sum=0,min;
	float avg;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			a[i][j]=rand()%100+1;
			
	min=a[0][0];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
		sum+=a[i][j];
		if(a[i][j]<min)
			min=a[i][j];	
		}
	}
	avg=(float)sum/100;
	printf("%g %d\n",avg,min);
	
	return 0;
}
