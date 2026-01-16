#include <stdio.h>
int main()
{
    char ch;
    // Input from user
    printf("Enter a character: ");
    scanf("%c", &ch);
    // Check if the character is a digit
    if (ch >= '0' && ch <= '9') 
    {
        printf("The character is a digit.\n");
    }
    // Check if the character is a vowel
    else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
    {
        printf("The character is a vowel.\n");
    }
    // Check if the character is a consonant
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
     {
        printf("The character is a consonant.\n");
    }
    // If it is a special character
    else 
    {
        printf("The character is a special character.\n");
    }
    return 0;
}