#include <stdio.h>

int main(){
    int a[100],n,i,key,low,high,mid,found,steps1=0,steps2=0;

    printf("This program compares Linear and Binary Search\n");
    printf("Enter number of elements : ");
    scanf("%d",&n);

    printf("Enter elements in sorted order :\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter number to search : ");
    scanf("%d",&key);

    found=0;
    for(i=0;i<n;i++){
        steps1++;
        if(a[i]==key){
            found=1;
            break;
        }
    }
    if(found==1)
        printf("Linear Search: %d found in %d steps\n",key,steps1);
    else
        printf("Linear Search: %d not found, total steps = %d\n",key,steps1);

    low=0;
    high=n-1;
    found=0;
    while(low<=high){
        steps2++;
        mid=(low+high)/2;
        if(a[mid]==key){
            found=1;
            break;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    if(found==1)
        printf("Binary Search: %d found in %d steps\n",key,steps2);
    else
        printf("Binary Search: %d not found, total steps = %d\n",key,steps2);

    printf("Program finished\n");
    return 0;
}
