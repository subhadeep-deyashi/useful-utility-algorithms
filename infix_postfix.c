#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ele)
{
	stack[++top] = ele;
}

char pop()
{
	return stack[top--];
}

int priority(char x)
{
	if(x == '^')
		return 3;
	else if(x == '/' || x == '*')
		return 2;
	else if(x == '+' || x == '-')
		return 1;
}

void in2po(char infix[], char postfix[])
{
	int i = 0, j = 0;
	char n;
	for(i = 0; infix[i] ; ++i)
	{
		if((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))	//for operands
			postfix[j++] = infix[i];

		else if(infix[i] == '(')
			push(infix[i]);

		else if(infix[i] == ')')
		{
			while(stack[top] != '(')
				postfix[j++] = pop();
			n = pop();
		}

		else	 //for operators
		{
			if(top == -1)
				push(infix[i]);

			else
			{
				while(priority(infix[i]) <= priority(stack[top]) && stack[top] != '(')
					postfix[j++] = pop();
				push(infix[i]);
			}
		}
	}

	while(top != -1)
		postfix[j++] = pop();
	postfix[j] = '\0';
}

int main()
{
	char infix[50], postfix[50];
	printf("Enter the infix expression : ");
	scanf("%s", infix);
	in2po(infix, postfix);
	printf("\nEquivalent Postfix Expression : %s\n", postfix);
	return 0;
}