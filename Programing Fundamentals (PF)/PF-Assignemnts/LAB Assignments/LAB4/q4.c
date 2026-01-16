#include <stdio.h>
int main()
{
    float a;
    float b;
    float c;
    int n;
    printf("Choose 1 for Calculating the Area of the Circle \n");
    printf("Choose 2 for Calculating the Area of the Rectangle \n");
    printf("Choose 3 for Calculating the Area of the Triangle \n");
    printf("Choose 4 for Exit \n");
    scanf("%d", &n);
    switch(n){
        case 1:
            printf("Enter the Radius of the Circle: ");
            scanf("%f", & a);
            c = 3.1416 * a * a;
            printf("Your Answer is: %.2f \n", c);
            break;
        case 2:
            printf("Enter the Length of the Rectangle: ");
            scanf("%f", & a);
            printf("Enter the Width of the Rectangle: ");
            scanf("%f", & b);
            c = a * b;
            printf("Your Answer is: %.2f \n", c);
            break;
        case 3:
            printf("Enter the Length of the Trianlge: ");
            scanf("%f", & a);
            printf("Enter the Length of the base of the Triangle: ");
            scanf("%f", & b);
            c = (a * b) / 2;
            printf("Your Answer is: %.2f \n", c);
            break;
        case 4:
            printf("Exiting the system");
        default:
            printf(" Kindly provide proper intructions");
            break;
    }
    return 0;
}