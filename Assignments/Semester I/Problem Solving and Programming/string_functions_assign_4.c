/* 
 * a) Replace a character in a given string with a character suggested by the user.
 * b) Convert the given string into uppercase.
 * c) Convert the alternate character into upper case.
 * d) Check each and every character in the string and display whether it is an alphabet, digit or special character.
 * Write an interactive C (main) program to provide the above string functions 
 * as options to the user using switch statement and perform the functions accordingly.
 */

#include<stdio.h>
#include <string.h>
#define MAX_LENGTH 256
void replace_character(char *input_string, int length)
{
    char old_char, new_char;
    printf("Enter a character to be replaced: ");
    scanf(" %c", &old_char);
    printf("Enter another character to be used to replace the character %c : ",old_char);
    scanf(" %c", &new_char);
    printf("The given string is: %s\n", input_string);    
    for(int i; i < length; i++)
    {
        if(input_string[i] ==  old_char)
        {
            input_string[i] = new_char;
        }
    }
    printf("The string after replacement of %c with %c is %s\n", old_char, new_char, input_string);
}

void convert_all_upper(char input_string[], int length)
{
    printf("The given string is: %s\n", input_string);   
    for(int i = 0; i < length; i++)
    {
        if ( input_string[i] > 96 && input_string[i] < 123 )
        {
            input_string[i] = input_string[i] - 32;
        }
    }
    printf("The given string in all upper case is %s\n", input_string); 
}

void convert_alternative_upper(char input_string[], int length)
{
    printf("The given string is: %s\n", input_string);   
    for(int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            if ( input_string[i] > 64 && input_string[i] < 91 )
            {
                input_string[i] = input_string[i] + 32;
            }
        }            
        else
        {
            if ( input_string[i] > 96 && input_string[i] < 123 )
            {
                input_string[i] = input_string[i] - 32;
            }
        }
    }
    printf("The given string with alternate characters as upper case is %s\n", input_string);     
}

void character_type(char input_string[], int length)
{
    printf("The given string is: %s\n", input_string); 
    for(int i = 0; i < length; i++)
    {
        if ( input_string[i] > 47 && input_string[i] < 58 )
        {
            printf("The character %c: is a number\n", input_string[i]);
        }
        else if ( ( input_string[i] > 64 && input_string[i] < 91 ) || ( input_string[i] > 96 && input_string[i] < 123 ))
        {
            printf("The character %c: is an alphabet\n", input_string[i]);
        }
        else if (input_string[i] > 31 && input_string[i] < 127)
        {
            printf("The character %c: is a special character\n", input_string[i]);
        }
        else if (input_string[i] < 32)
        {
            printf("The character %c: is a control character\n", input_string[i]);
        }
        else if (input_string[i] == 127)
        {
            printf("The character %c: is DEL input\n", input_string[i]);
        }
        else
        {
            printf("The character %c: is an extended version ASCII character\n", input_string[i]);
        }
    }
}
int main()
{
    char string_input[256];
    char choice;
    int length;
    printf("Enter a string (Maximum length: 256 characters):");
    fgets(string_input, MAX_LENGTH, stdin);
    length = strlen(string_input);
    printf("Choose from the following:\n");
    printf("a) Replace a character in a given string with a character suggested by the user.\n");
    printf("b) Convert the given string into uppercase.\n");
    printf("c) Convert the alternate character into upper case.\n");
    printf("d) Check each and every character in the string and display whether it is an alphabet, digit or special character.\n");
    printf("Choose any other letter to exit: \n");    
    scanf(" %c", &choice);
    switch(choice)
    {
        case 'a': replace_character (string_input, length);
                break;
        case 'b': convert_all_upper (string_input, length);
                break;
        case 'c': convert_alternative_upper (string_input, length);
                break;
        case 'd': character_type (string_input, length);
                break;
        default: printf("Exiting..\n");
    }
}

