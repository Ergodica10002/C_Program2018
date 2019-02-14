#include <stdio.h>
#include <string.h>
char art[100][260];
int interval[100] = {0};
int main(void)
{
    char s[260];
    int m, c = 0, length = 0;
    scanf("%d", &m);
    while (scanf("%s", art[c]) != EOF)
    {
        if (strlen(art[c]) + length + c <= m)
        {
            length += strlen(art[c]);
            c++;
            continue;
        }
        int snum = m - length;
        int intnum = c - 1;
        if (intnum == 0) intnum = 1;
        for (int j = 0; j < snum; j++)
            interval[j % intnum]++;
        for (int j = 0; j < c; j++){
            printf("%s", art[j]);
            if ((j != c - 1) || (c == 1))
                for (int k = 0; k < interval[j]; k++)
                    printf(" ");
        }
        printf("\n");
        for (int j = 0; j < intnum; j++)
            interval[j] = 0;
        strcpy(art[0], art[c]);
        c = 1;
        length = strlen(art[0]);
    }
    int snum = m - length;
        int intnum = c - 1;
        if (intnum == 0) intnum = 1;
        for (int j = 0; j < snum; j++)
            interval[j % intnum]++;
        for (int j = 0; j < c; j++)
        {
            printf("%s", art[j]);
            if ((j != c - 1) || (c == 1))
                for (int k = 0; k < interval[j]; k++)
                    printf(" ");
        }
        printf("\n");
    return 0;
}
