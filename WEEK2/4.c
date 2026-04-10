/*4. Number Pattern Printing with Loops
Print various number patterns using for, while, and do...while loops (e.g.,
triangle, square).*/
#include <stdio.h>
int main()
{
    int num,i,j;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("Triangle pattern:\n");
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    printf("Square pattern:\n");
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
//gcc 4.c -o 4.exe
//./4.exe
//output
//Enter a number: 5
//Triangle pattern:
//1
//12
//123
//1234
//12345
//Square pattern:
//11111  
//22222
//33333
//44444
//55555