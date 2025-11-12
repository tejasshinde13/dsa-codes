#include <stdio.h>

void swap(float *x, float *y){
    float temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(float a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(&a[j], &a[j+1]);
}

void selection_sort(float a[], int n){
    for(int i=0;i<n-1;i++){
        int low = i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[low])
                low = j;
        swap(&a[i], &a[low]);
    }
}

void displayTop5(float a[], int n){
    printf("\nTop 5 Scores:\n");
    for(int i=n-1, c=0; i>=0 && c<5; i--, c++)
        printf("%.2f\n", a[i]);
}

int main(){
    int n, ch;
    printf("Enter number of students: ");
    scanf("%d", &n);
    float a[n];
    printf("Enter percentages:\n");
    for(int i=0;i<n;i++) scanf("%f", &a[i]);

    printf("\n1. Selection Sort\n2. Bubble Sort\nEnter choice: ");
    scanf("%d", &ch);

    if(ch == 1) selection_sort(a, n);
    else bubble_sort(a, n);

    printf("\nSorted Percentages (Ascending):\n");
    for(int i=0;i<n;i++) printf("%.2f ", a[i]);

    displayTop5(a, n);
    return 0;
}

