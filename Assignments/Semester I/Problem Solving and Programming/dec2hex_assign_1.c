/* Subject: Problem Solving and Programming (MCS-011)
 * Question 1:  Assignment for Semester I 
 * An interactive program to convert a decimal number to its hexadecimal equivalent.
*/
#include <stdio.h>
int main()
{
    // variable declaration
    double decimal_input, decimal_digits, multiplicand;
    long int dividend; 
    int index =0, int_length = 0, fract_length = 0, remainder, resultant;
    char hexa_decimal_output[128], hexa_fractional_output[128], hex_output[256];
    printf("Enter a decimal number:");
    scanf("%lf", &decimal_input);
    // getting the integer part of the decimal number entered
    dividend = (long int) decimal_input;
    // getting the fractional part of the decimal number entered
    decimal_digits = decimal_input - dividend; 
    
    //finding the hexa decimal equivalent for integer part of decimal number
    while (dividend != 0 )
    {
        remainder = dividend % 16; 
        // using ascii equivalent of integer value to make it character 
        if (remainder  < 10)
        {
            remainder = remainder + 48;
        }
        else
        {
            remainder = remainder + 55;
        }
        hexa_decimal_output[index] = remainder;
        int_length++;
        index++;
        dividend = dividend / 16; 
    }
    for(int i = int_length - 1; i >=0; i--)
    {
        hex_output[int_length - (i + 1)] = hexa_decimal_output[i];
    }
    
    // logic for the case where there is decimal point digits in the decimal input. 
    if (decimal_digits > 0.0)
    {
        
        index = 0;
        multiplicand = decimal_digits;
        
        while (multiplicand != 0 )
        {
            resultant = (int) (multiplicand * 16); 
            multiplicand = (multiplicand * 16 -  resultant );
            // using ascii equivalent of integer value to make it character 
            if (resultant  < 10)
            {
                resultant = resultant + 48;
            }
            else
            {
                resultant = resultant + 55;
            }
            hexa_fractional_output[index] = resultant;
            fract_length++;
            index++;
        }
        hex_output[int_length] = '.';
        for(int i = 0; i < fract_length ; i++)
        {
            hex_output[int_length + i + 1 ] = hexa_fractional_output[i];
        }      
    }
    printf("Decimal input is: %lf\n", decimal_input);
    printf("Hexadecimal output is:%s \n", hex_output);
	return 0;
}
