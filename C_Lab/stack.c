#include<stdio.h>
#include<stdlib.h>
int top=-1;
int n;

void push(int a[],int e)
{
	if(top>=n-1)
	{
		printf("Stack is overflown \n");
	}
	else
	{
		a[++top] = e;
		printf("%d is pushed \n", e);
	}
}

void pop(int a[])
{
	if(top==-1)
	{
		printf("Stack is underflown \n");
	}
	else
	{
		printf("%d is popped \n",a[top--]);
	}
}

void display(int a[])
{
	if(top==-1)
	{
		printf("Stack is underflown \n");
	}
	else
	{
		for(int i=top;i>-1;i--)
		{
			printf("%d ",a[i]);
		}
	}
}

void main()
{
	printf("Enter the size of stack : ");
	scanf("%d",&n);
	int a[n],e,ch;
	while(1)
	{
		printf(" \n 1.Push 2.Pop 3.Display 4.Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be pushed : ");
				scanf("%d",&e);
				push(a,e);
				break;
			case 2: pop(a);
				break;
			case 3: display(a);
				break;
			case 4: exit(0);
			default: printf("Enter correct choice \n");
		}
	}
}
