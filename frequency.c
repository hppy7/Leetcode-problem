#include <stdio.h>
#include <limits.h> // For INT_MIN

int main() {
    int n, i, j, count;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Element frequency:\n");
    for(i = 0; i < n; i++) {
        if(arr[i] == INT_MIN) {
            continue; // Skip already processed elements
        }
        
        count = 1;
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = INT_MIN; // Mark as visited
            }
        }
        printf("%d occurs %d times\n", arr[i], count);
    }

    return 0;
}
