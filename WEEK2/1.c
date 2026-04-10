/*1. Menu-Driven Calculator
Use switch to perform addition, subtraction, multiplication, and division
based on user choice.*/ 
#include <stdio.h>
int main()
{
    int a,b;
    char op;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c",&op);
    switch(op)
    {
        case '+':
            printf("%d",a+b);
            break;
        case '-':
            printf("%d",a-b);
            break;
        case '*':
            printf("%d",a*b);
            break;
        case '/':
            printf("%d",a/b);
            break;
        default:
            printf("Invalid operator");
            break;
    }
    return 0;
}
//gcc 1.c -o 1.exe
//./1.exe