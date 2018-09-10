#include <stdio.h>
#include <string.h>
 int main(int argc, char const *argv[])
 {
 	int n,i,j,k,a[10001];
 	
	scanf("%d",&n);
	memset(a,-1,sizeof(a));
	 
	i=2;
	a[1]=0;
	 	 
	while(i*i<=n)
	{
		if(a[i]==-1)
			for (j = i; j <= n; j+=i)
				if(j!=i)
					a[j]=0;
		for (k = i+1; k <= n; k++)
			if(a[k]==-1)
				break;
		i=k;
	}

 	for (i = 1; i <= n; i++)
		if(a[i]==-1)
			printf("%d\n", i);
			
	return 0;
 }



 #include <stdio.h>
#include <string.h>
 int main(int argc, char const *argv[])
 {
 	int n,i,j,k,a[10001];
 	
	scanf("%d",&n);
	memset(a,-1,sizeof(a));
	 
	i=2;
	a[1]=0;
	 	 
	while(i*i<=n)
	{
		if(a[i]==-1)
			for (j = i; j <= n; j+=i)
				if(j!=i)
					a[j]=0;
		for (k = i+1; k <= n; k++)
			if(a[k]==-1)
				break;
		i=k;
	}

 	for (i = 1; i <= n; i++)
		if(a[i]==-1)
			printf("%d\n", i);
			
	return 0;
 }