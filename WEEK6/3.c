#include <stdio.h>

int main(){
    int a[100],n,i,j,temp,comp=0,swap=0;

    printf("This program sorts numbers using Bubble Sort\n");
    printf("Enter how many elements : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Sorting started...\n");

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            comp++;
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swap++;
            }
        }
    }

    printf("Sorting finished!\n");
    printf("Sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    printf("Total comparisons = %d\n",comp);
    printf("Total swaps = %d\n",swap);

    printf("Program finished\n");
    return 0;
}
