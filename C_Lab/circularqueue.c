#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
int n;

void enqueue(int a[],int e)
{
	if((rear+1)%n == front)
	{
		printf("Queue is full \n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		a[rear]=e;
	}
	else
	{
	 	rear=(rear+1)%n;
		a[rear]=e;
		printf("%d is inserted \n",a[rear]);
	}
}

void dequeue(int a[])
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty \n");
	}
	else if(front==rear)
	{
		printf("%d is deleted \n",a[front]);
		front=rear=-1;
	}
	else
	{
		printf("%d is deleted",a[front]);
		front=(front+1)%n;
	}
}

void display(int a[])
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty \n");
	}
	else
	{
		int i=front;
		while(i!=rear)
		{
			printf("%d ",a[i]);
			i=(i+1)%n;
		}
		printf("%d \n",a[rear]);
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
