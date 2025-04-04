#include<stdio.h>
#include<ctype.h>

char stack[20];
int top=-1;

void push(int n)
{
	stack[++top]=n;
}

int pop()
{
	return stack[top--];
}

int main()
{
	char postfix[20];
	char *e;
	int n,n1,n2,n3;
	printf("Enter the expression : ");
	scanf("%s",&postfix);
	e = postfix;
	while( *e!='\0')
	{
		if(isdigit(*e))
		{
			n = *e - '0';
			printf("%d \n", n);
			push(n);
		}
		else
		{
			n1 = pop();
			n2 = pop();
			switch(*e)
			{
				case '+' :
					n3=n2+n1;
					break;
				case '-' :
                                        n3=n2-n1;
                                        break;
				case '*' :
                                        n3=n2*n1;
                                        break;
				case '/' :
                                        n3=n2/n1;
                                        break;

			}
		push(n3);
		}
	e++;
	}
	printf("The result : %d", pop());
}

