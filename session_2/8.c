/*Arrays
8. Find Maximum and Minimum in an Array
Read n numbers into an array and find the maximum and minimum
elements. */
#include <stdio.h>
int main()
{
    int n,i,max,min;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    min=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("Maximum element: %d\n",max);
    printf("Minimum element: %d\n",min);
    return 0;
}
//gcc 8.c -o 8.exe
//./8.exe
//output
//Enter the number of elements: 5
//Enter the elements: 1 2 3 4 5
//Maximum element: 5
//Minimum element: 1