#include<stdio.h>
#include<string.h>

int main()
{
    char n[101];
    int i;
	float m,p;
    FILE *fout;
    fout=fopen("out.txt","w");
	
	for(i=1;i<=5;i++)
	{
		scanf("%s %f",&n,&p);
		m=(0.8*p)/12;
		fprintf(fout, "No.%d    %s    %.2f    %.2f\n",i,n,p,m);
	}
	fclose(fout);
	return 0;
}
