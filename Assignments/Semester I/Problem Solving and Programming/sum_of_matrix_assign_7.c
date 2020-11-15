/* An interactive C program to find the sum of all the elements of a 3X3 matrix
 * using pointers
 */
#include<stdio.h>

int main()
{
    int matrix[3][3];
    int input;
    long int sum = 0; 
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
    printf("The given matrix A is: \n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            sum = sum + *(*(matrix + i) + j);
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    
    printf("The sum of the matrix A is %ld\n", sum);
    return 0;
}
