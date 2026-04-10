/*7. Sum of Digits and Reverse Number
Find the sum of digits and reverse of a number using loop constructs.*/
#include <stdio.h>
int main(){
    int num,sum=0,rev=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    int temp=num;
    while(temp!=0){
        int digit=temp%10;
        sum+=digit;
        rev=rev*10+digit;
        temp/=10;
    }
    printf("Sum of digits: %d\n",sum);
    printf("Reverse number: %d\n",rev);
    return 0;
}
//gcc 7.c -o 7.exe
//./7.exe
//output
//Enter a number: 12345
//Sum of digits: 15
//Reverse number: 54321
