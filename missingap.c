#include <stdio.h>

int main() {
    int n, i, diff, expected_value;
    int missing_term = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate expected common difference
    diff = (arr[n - 1] - arr[0]) / n;

    // Find the missing term
    for(i = 1; i < n; i++) {
        expected_value = arr[0] + i * diff;
        if(arr[i] != expected_value) {
            missing_term = expected_value;
            break;
        }
    }

    if(missing_term != -1) {
        printf("The sequence is in AP with one missing term: %d\n", missing_term);
    } else {
        printf("The sequence is in AP with no missing term.\n");
    }

    return 0;
}
