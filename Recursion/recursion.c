#include <stdio.h>



int main()
{
	printf("This is a recursive function\n");

	int x,y;

	scanf("%d %d", &x, &y);

	printf("Sum: %d\n", x+y);

	
	main();
	return 0;
}