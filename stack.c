#include<stdio.h>

#define SIZE 4

typedef struct stack{
	int arr[SIZE];
	int top;
	int size;
}stack_t;

void sInit(stack_t *pStack);
void sPush(stack_t *pStack, int value);
int sPop(stack_t *pStack);
int sPeek(stack_t *pStack);

int sIsEmpty(stack_t *pStack);
int sIsFull(stack_t *pStack);


int main(void)
{
	stack_t s1;		//, s2, s3;
	int choice, value;
	
	sInit(&s1);

	do
	{
		printf("0. Exit\n1. Push\n2. Pop\n3. Peek\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter value : ");
				scanf("%d", &value);
				sPush(&s1, value);
				break;

			case 2:
				printf("Poped value = %d\n", sPop(&s1));
				break;

			case 3:
				printf("Peeked value = %d\n", sPeek(&s1));
				break;

		}
	}while(choice != 0);


	return 0;
}

void sInit(stack_t *pStack)
{
	pStack->top = -1;
	pStack->size = SIZE;
}

void sPush(stack_t *pStack, int value)
{
	//1. if stack is full
	if(sIsFull(pStack))
		printf("Stack is full\n");
	//2. if stack is not full
	else
	{
		//2.1 reposition top (inc)
		pStack->top++;
		//2.2 insert value at top position
		pStack->arr[pStack->top] = value; 
	}
}

int sPop(stack_t *pStack)
{
	int temp = -1;
	//1. if stack is empty
	if(sIsEmpty(pStack))
		printf("Stack is empty\n");
	//2. if stack is not empty
	else{
		temp = pStack->arr[pStack->top];
		//2.1 reposition top	
		pStack->top--;
	}
	return temp;
}

int sPeek(stack_t *pStack)
{
	int temp = -1;
	//1. if stack is empty
	if(sIsEmpty(pStack))
		printf("Stack is empty\n");
	//2. if stack is not empty
	else
		//2.1 read value of top position
		temp = pStack->arr[pStack->top];

	return temp;
}

int sIsEmpty(stack_t *pStack)
{
	return pStack->top == -1;
}

int sIsFull(stack_t *pStack)
{
	return pStack->top == pStack->size - 1;
}





















