#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int length = 0;
    printf("Enter string: ");
    scanf("%s", str);
    printf("Length of string with build-in function: %d...\n", strlen(str));
    while (str[length] != '\0')
        length++;
    printf("Length of string without build-in function: %d...\n", length);
    return 0;
}