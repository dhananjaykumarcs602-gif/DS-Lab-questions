#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 4
bool binarySearch2D(int matrix[ROWS][COLS], int target, int *foundRow, int *foundCol) {
    int low = 0;

    int high = (ROWS * COLS) - 1; 
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        int r = mid / COLS;
        int c = mid % COLS;
        
        int current_element = matrix[r][c];

        if (current_element == target) {
            *foundRow = r;  
            *foundCol = c;  
            return true;    
        }
        else if (current_element < target) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
    return false;
}
int main() {
    
    int matrix[ROWS][COLS] = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 16;
    int foundRow = -1, foundCol = -1;

    if (binarySearch2D(matrix, target, &foundRow, &foundCol)) {
        printf("Element %d found at index: [%d][%d]\n", target, foundRow, foundCol);
    } else {
        printf("Element %d not found in the matrix.\n", target);
    }
    return 0;
}

