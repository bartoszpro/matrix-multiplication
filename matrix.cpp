#include <stdio.h>

int main()
{
    int n0, n1;
    int matrix1[100][100], matrix2[100][100], result_matrix[100][100];

    // Open bin files
    FILE *matrixFileOne = fopen("matrix1.bin", "rb");
    FILE *matrixFileTwo = fopen("matrix2.bin", "rb");
    FILE *matrixResult = fopen("result.bin", "wb");

    // Check if bin files are opened
    if (!matrixFileOne || !matrixFileTwo || !matrixResult)
    {
        if (!matrixFileOne)
        {
            perror("Error opening binary file one");
            return 1;
        }
        if (!matrixFileTwo)
        {
            perror("Error opening binary file two");
            return 1;
        }
        if (!matrixResult)
        {
            perror("Error opening result.bin");
            return 1;
        }
    }

    // Read matrix dimensions from bin files
    fread(&n0, sizeof(int), 1, matrixFileOne);
    fread(&n1, sizeof(int), 1, matrixFileTwo);

    // Check if matrices are the same size
    if (n0 != n1)
    {
        printf("Matrices are different sizes");
        return 1;
    }
    if (n0 > 100)
    {
        printf("n > 100");
        return 1;
    }

    // Read matrix data from bin files
    for (int i = 0; i < n0; i++)
    {
        fread(matrix1[i], sizeof(int), n0, matrixFileOne);
        fread(matrix2[i], sizeof(int), n0, matrixFileTwo);
    }

    // Matrix multiplication
    for (int i = 0; i < n0; i++)
    {
        for (int k = 0; k < n0; k++)
        {
            int temp = matrix1[i][k];
            for (int j = 0; j < n0; j++)
            {
                result_matrix[i][j] += temp * matrix2[k][j];
            }
        }
    }

    // Write size of result matrix to result bin file
    fwrite(&n0, sizeof(int), 1, matrixResult);

    // Write result matrix data to result bin file
    for (int i = 0; i < n0; i++)
    {
        fwrite(result_matrix[i], sizeof(int), n0, matrixResult);
    }

    // Close bin files
    if (fclose(matrixFileOne) != 0)
        perror("Error closing binary file one");
    if (fclose(matrixFileTwo) != 0)
        perror("Error closing binary file two");
    if (fclose(matrixResult) != 0)
        perror("Error closing matrix result file");

    return 0;
}