#include<stdio.h>

void toh(int n,char A,char B,char C)
{
	if(n>0)
	{
 		toh(n-1,A,C,B);
		printf("Move disk %d from %c to %c \n",n,A,C);
		toh(n-1,B,A,C);
	}
}

int main()
{
	int n;
	printf("Enter the number of disk : ");
	scanf("%d",&n);
	toh(n,'A','B','C');
	return 0;
}
