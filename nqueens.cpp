#include <stdio.h>
#include <time.h>
#define n 11
int c = 0;
int setqueen(int grid[n][n], int queen[n], int put)
{
	if (put == n)
	{
		printf("(%d)\n", c + 1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%d ", grid[i][j]);
			printf("\n");
		}
		printf("\n");
		c++;
		return 1;
	}
	if (put == 0)
	{
		static int fput = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				grid[i][j] = 0;
		for (int i = 0; i < n; i++)
		{
			queen[0] = fput;
			//printf("col 0 at %d\n", queen[0]);
			grid[fput][0] = 1;
			setqueen(grid, queen, put + 1);
			grid[fput][0] = 0; 
			fput++;
		}
		if (fput == n)
			return 1;
	}
	else
	{
		int test = 1, back = 1;
		int dr, dc;
		for (int i = 0; i < n; i++)
		{
			test = 1;
			for (int col = 0; col < n; col++)
			{
				if (grid[i][col] != 0)
				{
					test = 0;
					break;
				}
			}
			dr = dc = 0;
			while (test == 1 && i + dr >= 0 && put + dc >= 0 && i + dr < n)
			{
				if (grid[i + dr][put + dc] != 0)
				{
					test = 0;
					break;
				}
				dr--;
				dc--;
			}
			dr = dc = 0;
			while (test == 1 && i + dr >= 0 && put + dc >= 0 && i + dr < n)
			{
				if (grid[i + dr][put + dc] != 0)
				{
					test = 0;
					break;
				}
				dr++;
				dc--;
			}
			if (test == 1)
			{
				queen[put] = i;
				grid[i][put] = 1;
				setqueen(grid, queen, put + 1);
				grid[i][put] = 0;
			}
		}
		return 1;	  
	}
}
int main(void)
{
	clock_t start, end;
	start = clock();
	int queen[n];
	int grid[n][n] = {{0}};
	int put = 0;
	setqueen(grid, queen, put);
	end = clock();
	double diff = end - start;
	printf("c = %d, run time: %lf", c, diff);
	
	return 0;
}

