#include <stdio.h>
#include<ctype.h>
int main(void)
{
	int c;
	printf("   0 1 2 3 4 5 6 7 8 9\n");
	for (c = 30; c <= 127; c++)
	{
		if (c % 10 == 0)
			printf("%2d ", c / 10);
		if (isprint(c))
			printf("%c ", c);
		else
			printf(" ");
		if (c % 10 == 9)
			printf("\n");
	}

	return 0;
}

