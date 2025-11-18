#include <stdio.h>
int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar();

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
char *LoadString(int N) {
    char *p = (char *)malloc((N + 1) * sizeof(char));
    if (!p) { printf("Memory allocation failed\n"); exit(1); }
    printf("Enter a string:\n");
    fgets(p, N + 1, stdin);
    int len = strlen(p);
    if (p[len - 1] == '\n') p[len - 1] = '\0';
    return p;
}
int StringLength(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}
void LoadArray(char *p, char arr[]) {
    int i = 0;
    while (p[i] != '\0') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '\0';
}
void ReverseArray(char arr[], char rev[], int n) {
    for (int i = 0; i < n; i++)
        rev[i] = arr[n - 1 - i];
    rev[n] = '\0';
}
void DisplayArray(char arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c", arr[i]);
    printf("\n");
}
int SumStringASCII(char *p) {
    if (*p == '\0')
        return 0;
    return *p + SumStringASCII(p + 1);
}
void ReverseString(char *start, char *end) {
    if (start >= end)
        return;
    char temp = *start;
    *start = *end;
    *end = temp;
    ReverseString(start + 1, end - 1);
}
}
