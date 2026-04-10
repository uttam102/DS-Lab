/*5.Loops and Flow Control 
Factorial Calculator
Calculate the factorial of a given number using a while loop.*/
#include <stdio.h>
int main()
{
    int num,i;
    unsigned long long factorial=1;
    printf("Enter a number: ");
    scanf("%d",&num);
    i=num;
    while(i>=1)
    {
        factorial*=i;
        i--;
    }
    printf("Factorial of %d is %llu",num,factorial);
    return 0;
}
//gcc 5.c -o 5.exe
//./5.exe
//output
//Enter a number: 5
//Factorial of 5 is 120

