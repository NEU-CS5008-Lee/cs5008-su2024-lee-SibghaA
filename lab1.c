#include <stdio.h>

int main() {
    // Integer to print
    int num = 48;

    // Array of integers to print and find sum
    int numbers[] = {100, 10, 23, 45, 67, 90};
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    // Variable to hold the sum
    int sum = 0;

    // Printing the integer
    printf("Integer: %d\n", num);

    // Printing the array elements and calculating the sum
    printf("Array: ");
    for (int i = 0; i < array_size; ++i) {
        printf("%d ", numbers[i]);
        sum += numbers[i];  
    }
    printf("\n");

    // Printing the sum of the array
    printf("The sum of the numbers in the array is: %d\n", sum);

    // Array for searching an element
    int arr[6] = {8, 9, 6, 5, 4, 3};
    int target = 3;
    int found = 0;  
    int index = -1; 
    // Linear search through the array
    for (int i = 0; i < 6; ++i) {
        if (arr[i] == target) {
            found = 1;  // Set flag to 1 if found
            index = i;  // Store the index where the target is found
            break;      // Stop searching once the target is found
        }
    }

    // Output the result of the search
    if (found) {
        printf("Element %d found at index %d in the search array.\n", target, index);
    } else {
        printf("Element %d not found in the search array.\n", target);
    }

    // Finding the greatest of three numbers
    int a = 18, b = 27, c = 22;
    int greatest;

    if (a > b) {
        if (a > c) {
            greatest = a;
        } else {
            greatest = c;
        }
    } else {
        if (b > c) {
            greatest = b;
        } else {
            greatest = c;
        }
    }

    // Print the greatest of the three numbers
    printf("The greatest of the numbers %d, %d, and %d is: %d\n", a, b, c, greatest);

    return 0;
}
