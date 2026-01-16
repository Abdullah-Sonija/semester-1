#include <stdio.h>
int main(){
    float value, result;
    char from_unit, to_unit;
    int valid = 1;
    printf("Select the input temperature unit (C, F, K): ");
    scanf(" %c", &from_unit);
    printf("Enter the temperature value: ");
    scanf(" %f", &value);
    printf("Select the unit to convert to (C, F, K): ");
    scanf(" %c", &to_unit);

    switch(from_unit){
        case 'C':
            switch(to_unit)
            {
                case 'F':
                    result = (value * 9 / 5) + 32;
                    break;
                case 'K':
                    result = value + 273;
                    break;
                case 'C':
                    result = value;
                    break;
                default:
                    printf("invalid unit. \n");
                    valid = 0;
                    break;
            } 
            break;
        case 'F':
            switch(to_unit)
            {
                case 'C':
                    result = (value -32) * 5 / 9;
                    break;
                case 'K':
                    result = (value -32) * 5 / 9 + 273;
                    break;
                case 'F':
                    result = value;
                    break;
                default:
                    printf("invalid unit. \n");
                    valid = 0;
                    break;
            }    
            break;
        case 'K':
            switch(to_unit)
            {
                 case 'C':
                    result = value - 273;
                    break;
                case 'F':
                    result = (value - 273.15) * 9 / 5 + 32;
                    break;
                case 'K':
                    result = value;
                    break;
                default:
                    printf("invalid unit. \n");
                    valid = 0;
                    break;
            }
            break;
        default:
            printf("Invalid input temperature unit.\n");
            valid = 0;
            break;
    }
    if (valid) {
    printf("Converted temperature: %.2f %c\n", result, to_unit);
    }
    printf("Thank you for using our AI-powered temperature converter.");
    return 0;
}