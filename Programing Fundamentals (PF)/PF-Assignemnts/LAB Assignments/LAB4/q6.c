#include <stdio.h>
int main()
{
    float actual_amount, saved_amount, amount_after_discount;
    // Input
    printf("Enter the shopping cost: ");
    scanf("%f", &actual_amount);
    // process
    if(actual_amount < 500)
    {
        saved_amount = 0;
        amount_after_discount = actual_amount;
        printf("Sorry! The Minimum amount eligible for a discount is 500. \n ");
    }else if(actual_amount > 500 && actual_amount < 2000)
    {
        saved_amount = (actual_amount * 5) / 100;
        amount_after_discount = actual_amount - saved_amount;
    }else if(actual_amount > 2000 && actual_amount < 4000)
    {
        saved_amount = (actual_amount * 10) / 100;
        amount_after_discount = actual_amount - saved_amount;
    }else if(actual_amount > 4000 && actual_amount < 6000)
    {
        saved_amount = (actual_amount * 20) / 100;
        amount_after_discount = actual_amount - saved_amount;
    }else
    {
        saved_amount = (actual_amount * 35) / 100;
        amount_after_discount = actual_amount - saved_amount;
    }
    // Output
    printf("Actual Amount: %.2f\n", actual_amount);
    printf("Saved Amount: %.2f\n", saved_amount);
    printf("Amount After Discount:%.2f\n", amount_after_discount);
    return 0;
}