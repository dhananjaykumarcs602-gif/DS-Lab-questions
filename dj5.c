#include <stdio.h>

int main() {
    int a[] = {10, 20, 5, 30, 15};
    int n = 5;
    int largest, second;

    largest = second = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if (a[i] > second) {
            second = a[i];
        }
    }

    printf("Second largest = %d", second);

    return 0;
}
