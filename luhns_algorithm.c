#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int number = get_int("Number: ");

    int digits = floor(log10(abs(number))) + 1;

    int x = 10;
    int y = 1;
    int sum_even = 0;
    int sum_odd = 0;
    int sum_luhn;
//EVEN NUMBER INDEX SUM*2
    for (int i = 0 ; i < digits / 2 ; i++)
    {
        int luhn_even = (number / x) % 10;
        sum_even = sum_even + luhn_even;
        printf("Luhn Even Number %i: %i\n", i+1 ,luhn_even);

        x *= 100;
    }
    printf("Even Luhn Number Sum: %i\n" , 2 * sum_even);

//ODD NUMBER INDEX SUM*1
//the problem is if digits are even, it includes also 0, do if st for check
    if (digits % 2 == 0) //even case
    {
        for (int i = 0 ; i < digits / 2 ; i++)
        {
            int luhn_odd = (number / y) % 10;
            sum_odd = sum_odd + luhn_odd;
            printf("Luhn Odd Number %i: %i\n", i+1 ,luhn_odd);
            y *= 100;
        }
        printf("Odd Luhn Number Sum: %i\n" , sum_odd);
    }
    else //odd case
    {
        for (int i = 0 ; i < (digits / 2) + 1 ; i++)
        {
            int luhn_odd = (number / y) % 10;
            sum_odd = sum_odd + luhn_odd;
            printf("Luhn Odd Number %i: %i\n", i+1 ,luhn_odd);
            y *= 100;
        }
        printf("Odd Luhn Number Sum: %i\n" , sum_odd);
    }


//SUM BOTH
    sum_luhn = sum_odd + 2 * sum_even;
    printf("Sum of luhn numbers: %i\n" , sum_luhn);

    if (sum_luhn % 10 == 0)
    {
        printf("Card is Legit\n");
    }
    else
    {
        printf("Card is not legit\n");
    }

}
