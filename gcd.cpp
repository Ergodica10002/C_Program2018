#include <stdio.h>
int tower(int a, char buffer, char source, char dest)
{
	if (a == 1)
	{
		printf("move 1 disk form %c to %c\n", source, dest);
		return 1;
	}
	else
	{
		int x = tower(a - 1, dest, source, buffer);
		printf("move 1 disk form %c to %c\n", source, dest);
		int y = tower(a - 1, source, buffer, dest);
		return x + y + 1;
	}
}
int main(void)
{
	int a;
	char buffer, source, dest;
	scanf("%d", &a);
	buffer = 'B';
	source = 'A';
	dest = 'C';
	int num = tower(a, buffer, source, dest);
	printf("total move %d times\n", num);


	return 0;
}

