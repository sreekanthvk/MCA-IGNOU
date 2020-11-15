/*Write the following functions that: 
 * a) Calculate simple interest. 
 * b) Calculate compound interest.
 * an interactive C (main) program to provide the above functions as options 
 * to the user using switch statement and performs the functions accordingly.
 */
#include<stdio.h>
#include<math.h>
double simple_interest(double principal, float period, float rate)
{
    // interest is P*(r/100)*t
    return (principal * ( 1 + (period * rate / 100)));
}

double compound_interest(double principal, float period, float rate)
{
    // amount after given years at calculating annually 
    // P(1+(r/1))^t
    return ( principal * (pow(( 1 + rate / 100), period)) );
}

int main()
{
    double principal;
    float interest_rate, time_period;
    char choice;
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);  
    printf("Enter the time period in years: ");
    scanf("%f", &time_period); 
    printf("MATURITY AMOUNT CALCULATION\n");
    printf("Please choose the interest to be used to calculate maturity amount. The options are as follows\n");
    printf("a. Simple interest\n");
    printf("b. Compound interest\n");
    printf("Enter any other input to exit.\n");
    printf("Please enter your choice: ");
    scanf(" %c", &choice);
    switch (choice)
    {
        case 'a': printf("The maturity amount is %.2lf \n", simple_interest(principal, time_period, interest_rate));
                break;
        case 'b': printf("The maturity amount is %.2lf \n", compound_interest(principal, time_period, interest_rate));
                break;
        default: printf("Exiting...\n");
    }
    return 0;
}
