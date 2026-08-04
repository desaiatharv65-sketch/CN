#include <stdio.stdio.h>

int main() {
    int a[100], b[100];
    int n, i, j, count;

    // Step 1: Read the frame length n
    printf("Enter frame length: ");
    scanf("%d", &n);

    // Step 2: Read the input frame into array a[]
    printf("Enter the frame (0s and 1s separated by space): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Step 3: Initialize variables
    i = 0;
    j = 0;
    count = 0;

    // Steps 4-9: Process all bits
    while (i < n) {
        // Step 5: Copy a[i] to b[j]
        b[j] = a[i];

        // Step 6: Update consecutive 1s count
        if (a[i] == 1) {
            count++;
        } else {
            count = 0;
        }

        // Step 7: Insert 0 if five consecutive 1s are encountered
        if (count == 5) {
            j++;
            b[j] = 0;  // Insert 0 into b[j + 1]
            count = 0; // Reset count
        }

        // Step 8: Increment both i and j
        i++;
        j++;
    }

    // Step 10: Display the frame after bit stuffing
    printf("Frame after bit stuffing: ");
    for (int k = 0; k < j; k++) {
        printf("%d ", b[k]);
    }
    printf("\n");

    return 0;
}