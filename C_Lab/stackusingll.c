#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*root=NULL;

void push(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=root;
	root=newNode;
	printf("%d is pushed \n",data);
}

void pop()
{
	if(root==NULL)
	{
		printf("Stack is underflown \n");
		return;
	}
	else
	{
		printf("%d is popped \n",root->data);
		struct node* temp= root;
		root=root->next;
		free(temp);
	}
}

void display()
{
	if(root==NULL)
        {
                printf("Stack is underflown \n");
                return;
	}
	else
	{
		struct node* temp=root;
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
	printf("NULL\n");
	}
}

void main(){
    int ch, n;
    while (1)
    {

    printf("1 Push\n2 Pop\n3 Display\n4 Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("\nEnter data to insert: ");
        scanf("%d",&n);
        push(n);
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);

    default:
        break;
    }
}
}
