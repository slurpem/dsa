#include<stdio.h>
#include<stdlib.h>

int front = -1;
int rear  = -1;
int n;

void enqueue(int a[],int e)
{
	if(rear==n-1)
	{
		printf("Queue is full \n ");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		a[++rear]=e;
		printf("%d is inserted \n",a[rear]);
	}
}

void dequeue(int a[])
{
	if(rear==-1 || front>rear)
	{
		printf("Queue is empty \n");
	}
	else
	{
		printf(" %d is deleted \n",a[front++]);
		if(front>rear)
		{
			front=rear=-1;
		}
	}
}

void display(int a[])
{
	if(rear==-1 || front>rear)
	{
		printf("Queue is empty \n");
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d ",a[i]);
		}
	printf("\n");
	}
}

void main()
{
	printf("Enter the size of queue : ");
	scanf("%d",&n);
	int a[n],e,ch;
	while(1)
	{
		printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be inserted :");
				scanf("%d",&e);
				enqueue(a,e);
				break;
			case 2:dequeue(a);
				break;
			case 3:display(a);
				break;
			case 4:exit(0);
			default:printf("Enter choice correctly");
				break;
		}
	}
}
