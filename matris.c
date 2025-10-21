#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Matrisin satir sayisini gir: ");
    scanf("%d", &rows);
    printf("Matrisin sutun sayisini gir: ");
    scanf("%d", &cols);

    int mat[rows][cols];

    printf("Matris elemanlarini gir:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Sparse matristeki sifir olmayan elemanlar:\n");
    printf("Satir\tSutun\tDeger\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] != 0)
            {
                printf("%d\t%d\t%d\n", i, j, mat[i][j]);
            }
        }
    }

    return 0;
}
