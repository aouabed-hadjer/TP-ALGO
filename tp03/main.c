#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {

    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar(); // clear buffer

    str = LoadString(n);
    int len = StringLength(str);

    char arr[len + 1], rev[len + 1];

    LoadArray(str, arr);

    printf("\nOriginal array: ");
    DisplayArray(arr, len);

    ReverseArray(arr, rev, len);

    printf("\nReversed array: ");
    DisplayArray(rev, len);

    int sum = SumStringASCII(str);
    printf("\nSum of ASCII values (recursive): %d\n", sum);

    ReverseString(str, str + len - 1);
    printf("String reversed recursively: %s\n", str);

    free(str);
    return 0;
}
