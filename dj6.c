#include <stdio.h>
int main() {
    char a[] = "abcdea";

    for (int i = 0; a[i] != '\0'; i++) {
      for (int j = i + 1; a[j] != '\0'; j++) {
         if (a[i] == a[j]) {
          printf("First repeated character = %c", a[i]);
          return 0;
            }
        }
    }
    printf("No repeated character");
    return 0;
}

