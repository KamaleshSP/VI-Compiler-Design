#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], rev[100], original[100], temp;
    int i = 0, j, k, l;
    printf("Enter string: ");
    scanf("%s", str);
    strcpy(original, str);
    printf("String Reverse with build-in function...\n");
    l = strlen(str) - 1;
    for (k = 0; k < l; k++, l--)
    {
        temp = str[k];
        str[k] = str[l];
        str[l] = temp;
    }
    printf("Reversed string: %s\n", str);
    printf("String Reverse without build-in function...\n");
    while (original[i] != '\0')
        i++;
    for (j = 0; j < i; j++)
        rev[j] = original[i - j - 1];
    rev[j] = '\0';
    printf("Reversed string: %s", rev);
    return 0;
}