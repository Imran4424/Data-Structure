#include <stdio.h>

#define MAX_N 100

int front;
int rear;
int queue[MAX_N];

void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueIsEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if ((front + 1) % MAX_N == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(int value)
{
	if (queueIsFull())
	{
		printf("queue is full!");
		return 0;
	}
	queue[front] = value;
	front++;
	if (front == MAX_N)
	{
		front = 0;
	}

	return 1;
}

int queueDequeue(int *value)
{
	if (queueIsEmpty()) 
	{
		printf("queue is empty!");
		return 0;
	}
	*value = queue[rear];
	rear++;
	if (rear == MAX_N)
	{
		rear = 0;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int T;
	int N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		queueInit();
		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			queueEnqueue(value);
		}

		printf("#%d ", test_case);

		while (!queueIsEmpty())
		{
			int value;
			if (queueDequeue(&value) == 1)
			{
				printf("%d ", value);
			}
		}
		printf("\n");
	}
	return 0;
}

/// Queue