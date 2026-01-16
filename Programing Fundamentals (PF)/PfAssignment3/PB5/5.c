#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int row, col, value;
} SparseElement;

typedef struct 
{
    int rows, cols, nonZeroCount;
    SparseElement *elements;
} SparseMatrix;

SparseMatrix *createSparseMatrix(int rows, int cols, int nonZeroCount);
void inputSparseMatrix(SparseMatrix *matrix);
SparseMatrix *addSparseMatrices(SparseMatrix *a, SparseMatrix *b);
SparseMatrix *multiplySparseMatrices(SparseMatrix *a, SparseMatrix *b);
void displaySparseMatrix(SparseMatrix *matrix);
void freeSparseMatrix(SparseMatrix *matrix);

int main() 
{
    int rowsA, colsA, nonZeroA, rowsB, colsB, nonZeroB;
    printf("Enter rows, columns, and number of non-zero elements for Matrix A: ");
    scanf("%d %d %d", &rowsA, &colsA, &nonZeroA);
    SparseMatrix *A = createSparseMatrix(rowsA, colsA, nonZeroA);
    printf("Enter Matrix A (row column value):\n");
    inputSparseMatrix(A);
    printf("Enter rows, columns, and number of non-zero elements for Matrix B: ");
    scanf("%d %d %d", &rowsB, &colsB, &nonZeroB);
    SparseMatrix *B = createSparseMatrix(rowsB, colsB, nonZeroB);
    printf("Enter Matrix B (row column value):\n");
    inputSparseMatrix(B);
    if (A->rows == B->rows && A->cols == B->cols) 
    {
        SparseMatrix *sum = addSparseMatrices(A, B);
        printf("Matrix A + Matrix B:\n");
        displaySparseMatrix(sum);
        freeSparseMatrix(sum);
    } 
    else 
    {
        printf("Addition not possible due to dimension mismatch.\n");
    }

    if (A->cols == B->rows) 
    {
        SparseMatrix *product = multiplySparseMatrices(A, B);
        printf("Matrix A * Matrix B:\n");
        displaySparseMatrix(product);
        freeSparseMatrix(product);
    } 
    else 
    {
        printf("Multiplication not possible due to dimension mismatch.\n");
    }
    freeSparseMatrix(A);
    freeSparseMatrix(B);
    return 0;
}

SparseMatrix *createSparseMatrix(int rows, int cols, int nonZeroCount) 
{
    SparseMatrix *matrix = (SparseMatrix *)malloc(sizeof(SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->nonZeroCount = nonZeroCount;
    matrix->elements = (SparseElement *)malloc(nonZeroCount * sizeof(SparseElement));
    return matrix;
}
void inputSparseMatrix(SparseMatrix *matrix) 
{
    for (int i = 0; i < matrix->nonZeroCount; i++) 
    {
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}
SparseMatrix *addSparseMatrices(SparseMatrix *a, SparseMatrix *b) 
{
    SparseMatrix *result = createSparseMatrix(a->rows, a->cols, a->nonZeroCount + b->nonZeroCount);
    int i = 0, j = 0, k = 0;

    while (i < a->nonZeroCount && j < b->nonZeroCount) 
    {
        if (a->elements[i].row < b->elements[j].row || 
           (a->elements[i].row == b->elements[j].row && a->elements[i].col < b->elements[j].col)) 
        {
            result->elements[k++] = a->elements[i++];
        } 
        else if (b->elements[j].row < a->elements[i].row || 
                (b->elements[j].row == a->elements[i].row && b->elements[j].col < a->elements[i].col)) 
        {
            result->elements[k++] = b->elements[j++];
        } 
        else 
        {
            result->elements[k] = a->elements[i];
            result->elements[k++].value += b->elements[j++].value;
            i++;
        }
    }
    while (i < a->nonZeroCount) 
    {
        result->elements[k++] = a->elements[i++];
    }
    while (j < b->nonZeroCount) 
    {
        result->elements[k++] = b->elements[j++];
    }
    result->nonZeroCount = k;
    return result;
}
SparseMatrix *multiplySparseMatrices(SparseMatrix *a, SparseMatrix *b) 
{
    SparseMatrix *result = createSparseMatrix(a->rows, b->cols, a->nonZeroCount * b->nonZeroCount);
    int k = 0;
    for (int i = 0; i < a->nonZeroCount; i++) 
    {
        for (int j = 0; j < b->nonZeroCount; j++) 
        {
            if (a->elements[i].col == b->elements[j].row) 
            {
                result->elements[k].row = a->elements[i].row;
                result->elements[k].col = b->elements[j].col;
                result->elements[k].value = a->elements[i].value * b->elements[j].value;
                k++;
            }
        }
    }
    result->nonZeroCount = k;
    return result;
}

void displaySparseMatrix(SparseMatrix *matrix) 
{
    for (int i = 0; i < matrix->nonZeroCount; i++) 
    {
        printf("(%d, %d, %d)\n", matrix->elements[i].row, matrix->elements[i].col, matrix->elements[i].value);
    }
}

void freeSparseMatrix(SparseMatrix *matrix) 
{
    free(matrix->elements);
    free(matrix);
}