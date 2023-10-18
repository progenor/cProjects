#include <stdio.h>

int main() {
    int n, p, total = 0;
    printf("Enter the size of the family: ");
    scanf("%d", &n);
    int t[n];
    p = n / 2;

    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i < p; i++) {
        total += t[i];
    }

    return 0;
}
