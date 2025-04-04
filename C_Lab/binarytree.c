#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node  *left,*right;
}*root=NULL;

struct node* insert(struct node* root,int data)
{
	if(root==NULL)
	{
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data=data;
		newNode->left=newNode->right=NULL;
		return newNode;
	}

	char choice;
	printf("Insert %d to the left or right of %d : ",data,root->data);
	scanf(" %c",&choice);
	if(choice== 'l' || choice=='L')
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
	}
}

int main()
{
	int ch,data;
	while(1)
	{
		printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value to be inserted : ");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2: printf("Preorder :");
				preorder(root);
				printf("NULL");
				break;
			case 3: printf("Inorder :");
                                inorder(root);
                                printf("NULL");
                                break;
			case 4: printf("Postorder :");
                                postorder(root);
                                printf("NULL");
                                break;
			case 5: exit(0);
			default :printf("Enter valid choice \n");
		}
	}
	return 0;
}
