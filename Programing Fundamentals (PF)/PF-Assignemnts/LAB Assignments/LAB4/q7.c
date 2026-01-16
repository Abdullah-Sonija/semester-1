#include <stdio.h>
int main()
{
    int customer_id, units_consumed;
    char customer_name[50];
    float amount, surcharge = 0, total_amount, charge_per_unit;
    // Input customer details
    printf("Enter Customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter Customer Name: ");
    scanf("%s", customer_name); 
    printf("Enter Units Consumed: ");
    scanf("%d", &units_consumed);
    // Calculate charges based on unit consumed
    if (units_consumed <= 199) 
    {
        charge_per_unit = 16.20;
    } else if (units_consumed >= 200 && units_consumed < 300) 
    {
        charge_per_unit = 20.10;
    } else if (units_consumed >= 300 && units_consumed < 500) 
    {
        charge_per_unit = 27.10;
    } else
    {
        charge_per_unit = 35.90;
    }
    // Amount Calculation 
    amount = units_consumed * charge_per_unit;
    if (amount > 18000)
    {
        surcharge = amount * 0.15;  // 15% surcharge
    }
    total_amount = amount + surcharge;
    // Output the bill details
    printf("\nCustomer ID: %d\n", customer_id);
    printf("Customer Name: %s\n", customer_name);
    printf("Units Consumed: %d\n", units_consumed);
    printf("Amount Charges @Rs. %.2f per unit: %.2f\n", charge_per_unit, amount);
    printf("Surcharge Amount: %.2f\n", surcharge);
    printf("Net Amount Paid by the Customer: %.2f\n", total_amount);
    return 0;
}