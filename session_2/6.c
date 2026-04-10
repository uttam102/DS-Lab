/*6. Prime Number Checker
Check whether a number is prime using a for loop and break statement.*/
#include <stdio.h>
int main()
{
    int num,i,c=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
        {
            c=1;
            break;
        }
    }
    if(c==0)
        printf("%d is a prime number",num);
    else
        printf("%d is not a prime number",num);
    return 0;
}
//gcc 6.c -o 6.exe
//./6.exe
//output
//Enter a number: 5
//5 is a prime number
//Enter a number: 10
//10 is not a prime number