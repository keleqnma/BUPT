#include<stdio.h>
#include<string.h>

int main()
{
    char n[101];
    int a,b,c,d;
    FILE *fout;
    fout=fopen("out.txt","w");

    scanf("%s",&n);
    scanf("%d%d%d%d",&a,&b,&c,&d);

    fprintf(fout, "%s\n",n);
    fprintf(fout, "%d %d %d %d",a,b,c,d);
	fclose(fout);
	return 0;
}
