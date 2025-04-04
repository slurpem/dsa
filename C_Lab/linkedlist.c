#include<stdlib.h>
#include<stdio.h>
int count=0;
int MAX_SIZE=0;

struct node
{
	int data;
	struct node* next;
}*head=NULL;

struct node* createNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

void insertAtBegin(int data)
{
	if(count>=MAX_SIZE)
	{
		printf("Full");
		return;
	}
	struct node* newNode=createNode(data);
	newNode->next=head;
	head=newNode;
	count++;
}

void insertAtEnd(int data)
{
	if(count>=MAX_SIZE)
	{
		printf("List is full");
		return;
	}

	struct node* newNode = createNode(data);
	if(head==NULL)
	{
	head=newNode;
	}
	else
	{
	struct node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newNode;
	}
	count++;
}

void insertAtMiddle(int data,int pos)
{
	if(count>=MAX_SIZE)
	{
		printf("List is full");
		return;
	}

	if(pos<1)
	{
		insertAtBegin(data);
		return;
	}

	struct node* newNode = createNode(data);
	struct node* temp=head;

	for(int i=1;temp!=NULL &&  i<pos;i++)
		temp=temp->next;
	if(temp==NULL)
	{
		printf("Position out of range");
		free(newNode);
		return;
	}

	newNode->next=temp->next;
	temp->next=newNode;
	count++;
}

void deleteBegin()
{
	if(head==NULL)
	{
		printf("list is empty");
		return;
	}
	struct node* temp=head;
	head=head->next;
	free(temp);
	count--;
}

void deleteEnd()
{
	if(head==NULL)
	{
		printf("list is empty");
	return;
	}

	struct node* temp=head;
	struct node* prev=NULL;

	while(temp->next!=NULL)
	{
	 prev=temp;
	temp=temp->next;
	}
	if(prev==NULL)
	{
		head=NULL;
	}
	else
	{
		prev->next=NULL;
	}
	free(temp);
	count--;
}

void deleteInMiddle(int pos)
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}

	struct node* temp=head;
	struct node* prev=NULL;

	if(pos<1)
	{
		head=head->next;
		free(temp);
		count--;
		return;
	}

	for(int i=1;temp!=NULL && i<pos;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Out of range");
		return;
	}
	prev->next= temp->next;
	free(temp);
	count--;
}

void displayList()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}

	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}

void searchList(int data)
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}

	struct node* temp=head;
	int pos=0;
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			printf("%d found at pos %d",data,pos);
			return;
		}
		temp=temp->next;
		pos++;
	}
}

int main()
{
	int ch,data,pos;
	printf("Enter the size of list: ");
	scanf("%d",&MAX_SIZE);
	while(1)
	{
		printf( "\n1.Insert at Beginning 2.Insert at End 3.Insert at Pos"
	 		"\n4.Delete at Beginning 5.Delete at End 6.Delete at Pos"
			"\n7.Display List        8.Search List   9. Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data to insert at Beginning :");
				scanf("%d",&data);
				insertAtBegin(data);
				break;
			case 2:
                                printf("Enter data to insert at End :");
                                scanf("%d",&data);
                                insertAtEnd(data);
                                break;
			case 3:
                                printf("Enter data to insert :");
                                scanf("%d",&data);
				printf("Enter the position to be inserted: ");
				scanf("%d",&pos);
                                insertAtMiddle(data,pos);
                                break;
			case 4:
                                deleteBegin();
                                break;
			case 5:
				deleteEnd();
				break;
			case 6:
                                printf("Enter pos to be deleted :");
                                scanf("%d",&pos);
                                deleteInMiddle(pos);
                                break;
			case 7:
				displayList();
				break;
			case 8:
                                printf("Enter data to searched :");
                                scanf("%d",&data);
                                searchList(data);
                                break;
			case 9:
				printf("Exiting...");
				exit(0);
			default:
				printf("Invalid choice! Try agian. \n");
		}
	}
}
