/* An interactive C program to find the MINIMUM and MAXIMUM (value) 
 * array elements in a given 3X3 matrix.
 */
#include<stdio.h>

int main()
{
    int matrix[3][3];
    int input, max, min; 
    printf("Enter the elements of 3X3 matrix A:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("Enter element A[%d,%d]: ", i + 1, j + 1);
            scanf("%d", &input);
            matrix[i][j] = input;
        }
    }
    max = min = matrix[0][0];
    printf("The given matrix A is: \n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
            }
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
            }
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("The maximum value in the matrix A is %d\n", max);
    printf("The minimum value in the matrix A is %d\n", min);
    return 0;
}
