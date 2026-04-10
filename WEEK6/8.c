#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i=0;i<n;i++){
        printf("Checking index %d -> %d\n", i, arr[i]);
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,key,index;
    printf("This program does Linear Search\n");
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int a[50];
    for(int i=0;i<n;i++){
        printf("Enter element %d : ", i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter key to search: ");
    scanf("%d",&key);

    index = linearSearch(a,n,key);

    if(index!=-1){
        printf("Key %d found at index %d\n",key,index);
    }
    else{
        printf("Key %d not found, return -1\n",key);
    }

    printf("Program finished\n");
    return 0;
}
