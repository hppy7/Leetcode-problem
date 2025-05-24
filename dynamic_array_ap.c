#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int isap(int [],int);
int isap(int arr[], int n)
{
    if (n < 2) return 1; // An array with 0 or 1 element is always in AP

    int cd = arr[1] - arr[0];  // Common difference
    int flag = 1;  // Assume it is an AP

    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i-1] != cd)
        {
            flag = 0;  // Not an AP
            break;     // No need to check further
        }
    }

    return flag;  // Return whether it's AP (1 for yes, 0 for no)
}

int main()
{
    int n,i;
    printf("Enter the size of array : ");
    scanf("%d",&n);
   int *arr=(int*)malloc(n*sizeof(int));
   printf("Enter the elements of array. ");
   for(i=0;i<n;i++)
   {
    scanf("%d",&arr[i]);
   }
    if(isap(arr,n))
    {
    printf("it is ap");
    }
    else
    {
    printf("it is not a ap");
    }
    free(arr);
    return 0;
}