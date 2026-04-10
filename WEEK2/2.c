/*Leap Year Checker
Determine whether a given year is a leap year using conditional and logical
operators.*/
#include <stdio.h>
int main()
{
    int year;
    printf("Enter a year: ");
    scanf("%d",&year);
    if((year%4==0 && year%100!=0) || (year%400==0))
        printf("%d is a leap year",year);
    else
        printf("%d is not a leap year",year);
    return 0;
}
//gcc 2.c -o 2.exe
//./2.exe
//output
//Enter a year: 2020
//2020 is a leap year