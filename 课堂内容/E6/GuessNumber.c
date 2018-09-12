#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,g;
	n=rand()%1000+1;
    while(1)
    {
        scanf("%d",&g);
        if (g==n)
        {
            printf("Excellent! You guessed the number!\n");
            break;
        }
        else if (g>n)
            printf("Too high.Try again\n");
        else if (g<n)
            printf("Too low.Try again\n");
     }
    return 0;
}