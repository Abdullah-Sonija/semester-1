#include <stdio.h>
int main ()
{
    int num;
    // Input from user
    printf("Enter an integer: ");
    scanf("%d", &num);
    // Check if the number is even or odd
    if (num % 2 == 0)
    {
        printf("This number is even.\n");
    } else
    {
        printf("This number is odd.\n");
    }
    return 0;
}