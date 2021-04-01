#include <stdio.h>

#define MAX_N 100

int top;
int stack[MAX_N];

void stackInit(void)
{
	top = 0;
}

int stackIsEmpty(void)
{
	return (top == 0);
}

int stackIsFull(void)
{
	return (top == MAX_N);
}

int stackPush(int value)
{
	if (stackIsFull())
	{
		printf("stack overflow!");
		return 0;
	}
	stack[top] = value;
	top++;

	return 1;
}

int stackPop(int *value)
{
	if (top == 0) 
	{
		printf("stack is empty!");
		return 0;
	}
	top--;
	*value = stack[top];

	return 1;
}

int main(int argc, char* argv[])
{
	int T, N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		stackInit();
		for (int i = 0; i < N; i++) 
		{
			int value;
			scanf("%d", &value);
			stackPush(value);
		}

		printf("#%d ", test_case);

		while (!stackIsEmpty())
		{
			int value;
			if (stackPop(&value) == 1)
			{
				printf("%d ", value);
			}
		}
		printf("\n");
	}
	return 0;
}

/// Stack