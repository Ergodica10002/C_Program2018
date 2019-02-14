#include <stdio.h>
#include <time.h>
int c = 0;
FILE* fp = fopen("8queens.txt", "w");
int setqueen(int grid[8][8], int queen[8], int put)
{
	if (put == 8)
	{
		printf("(%d)\n", c + 1);
		fprintf(fp, "(%d)\n", c + 1);
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				printf("%d ", grid[i][j]);
				fprintf(fp, "%d ", grid[i][j]);
			}
			printf("\n");
			fprintf(fp, "\n");
		}
		printf("\n");
		fprintf(fp, "\n");
		c++;
		return 1;
	}
	if (put == 0)
	{
		static int fput = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				grid[i][j] = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				for (int k = 0; k < 8; k++)
					grid[j][k] = 0;
			queen[0] = fput;
			//printf("col 0 at %d\n", queen[0]);
			grid[fput][0] = 1;
			setqueen(grid, queen, put + 1);
			fput++;
		}
		if (fput == 8)
			return 1;
	}
	else
	{
		int test = 1, back = 1;
		int dr = 0, dc = 0;
		for (int i = 0; i < 8; i++)
		{
			test = 1;
			for (int col = 0; col < 8; col++)
			{
				if (grid[i][col] != 0)
				{
					test = 0;
					break;
				}
			}
			dr = dc = 0;
			while (i + dr >= 0 && put + dc >= 0 && i + dr < 8)
			{
			//	printf("%d %d %d\n", i + dr, put + dc, grid[i + dr][put + dc]);
				if (grid[i + dr][put + dc] != 0)
				{
					test = 0;
					break;
				}
				dr--;
				dc--;
			}
			dr = dc = 0;
			while (i + dr >= 0 && put + dc >= 0 && i + dr < 8)
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
				back = 0;
				queen[put] = i;
			//	printf("col %d at %d\n", put, queen[put]);
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
	int queen[8];
	int grid[8][8] = {{0}};
	int put = 0;
	setqueen(grid, queen, put);
	end = clock();
	double diff = end - start;
	printf("c = %d, run time: %lf\n", c, diff);
	fprintf(fp, "c = %d, run time: %lf\n", c, diff);
	fclose(fp);
	return 0;
}

