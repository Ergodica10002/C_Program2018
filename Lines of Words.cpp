#include <stdio.h>
#include <string.h>
char **fw[150];
char *sw[2000];
char w[10000];
int main(void)
{
	int n, m, sc = 0, fc = 0, wc = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char t;
		fw[fc] = &sw[sc]; 
		while (scanf("%s%c", &w[wc], &t) == 2)
		{
			sw[sc] = &w[wc];
			wc += strlen(&w[wc]) + 1;
			sc++;
			if (t == '\n')
				break;
		}
		sw[sc] = NULL;
		sc++;
		fc++;
	}
	scanf("%d", &m);
	int r1, c1, r2, c2;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
//		printf("1 %s\n", fw[r1][c1]);
//		printf("2 %s\n", fw[r2][c2]);
		char *temp;
		temp = fw[r1][c1];
		fw[r1][c1] = fw[r2][c2];
		fw[r2][c2] = temp;
//		printf("1 %s\n", fw[r1][c1]);
//		printf("2 %s\n", fw[r2][c2]);	
	}
	int j = 0;
	for (int i = 0; i < fc; i++)
	{
		printf("%s", sw[j]);
		j++;
		while (sw[j] != NULL){
			printf(" %s", sw[j]);
			j++;
		}
		j++;	
		printf("\n");
	}
	return 0;
}

