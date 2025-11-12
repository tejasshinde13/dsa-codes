#include <stdio.h>
#define MAX 100

void bubble_sort(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        float temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int inputMarks(float arr[]) {
    int n;
    printf("Enter number of students (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of students!\n");
        return 0;
    }

    printf("Enter marks for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    return n;
}

void displayTopFive(float arr[], int n) {
    bubble_sort(arr, n); 

    int count = n < 5 ? n : 5;
    printf("Top %d marks are:\n", count);
    for (int i = n - 1; i >= n - count; i--) {
        printf("%.2f\n", arr[i]);
    }
}

int main() {
    float marks[MAX];
    int n = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Sort using bubble sort (with new input)\n");
        printf("2. Sort using selection sort (with new input)\n");
        printf("3. Display top 5 marks\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = inputMarks(marks);
                if (n > 0) {
                    bubble_sort(marks, n);
                    printf("Marks sorted using bubble sort.\n");
                }
                break;
            case 2:
                n = inputMarks(marks);
                if (n > 0) {
                    selection_sort(marks, n);
                    printf("Marks sorted using selection sort.\n");
                }
                break;
            case 3:
                if (n > 0) {
                    displayTopFive(marks, n);
                } else {
                    printf("No marks to display! Please enter marks first.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
