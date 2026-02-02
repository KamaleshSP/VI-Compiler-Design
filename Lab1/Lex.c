#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
bool isDelimiter(char chr)
{
    return (chr == ' ' || chr == '+' || chr == '-'
            || chr == '*' || chr == '/' || chr == ','
            || chr == ';' || chr == '%' || chr == '>'
            || chr == '<' || chr == '=' || chr == '('
            || chr == ')' || chr == '[' || chr == ']'
            || chr == '{' || chr == '}');
}
bool isOperator(char chr)
{
    return (chr == '+' || chr == '-' || chr == '*'
            || chr == '/' || chr == '>' || chr == '<'
            || chr == '=');
}
bool isValidIdentifier(char* str)
{
    return (!isdigit(str[0]) && !isDelimiter(str[0]));
}
bool isKeyword(char* str)
{
    const char* keywords[] = {
        "auto","break","case","char","const","continue","default","do",
        "double","else","enum","extern","float","for","goto","if",
        "int","long","register","return","short","signed","sizeof","static",
        "struct","switch","typedef","union","unsigned","void","volatile","while"
    };
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
        if (strcmp(str, keywords[i]) == 0)
            return true;
    return false;
}
bool isInteger(char* str)
{
    if (*str == '\0')
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}
char* getSubstring(char* str, int start, int end)
{
    int subLength = end - start + 1;
    char* subStr = (char*)malloc(subLength + 1);
    strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return subStr;
}
void lexicalAnalyzer(char* input)
{
    int left = 0, right = 0;
    int len = strlen(input);
    while (right <= len && left <= right)
    {
        if (!isDelimiter(input[right]))
            right++;

        if (isDelimiter(input[right]) && left == right)
        {
            if (isOperator(input[right]))
                printf("Token: Operator, Value: %c\n", input[right]);

            right++;
            left = right;
        }
        else if ((isDelimiter(input[right]) && left != right)
                 || (right == len && left != right))
        {
            char* subStr = getSubstring(input, left, right - 1);

            if (isKeyword(subStr))
                printf("Token: Keyword, Value: %s\n", subStr);
            else if (isInteger(subStr))
                printf("Token: Integer, Value: %s\n", subStr);
            else if (isValidIdentifier(subStr))
                printf("Token: Identifier, Value: %s\n", subStr);
            else
                printf("Token: Unidentified, Value: %s\n", subStr);

            free(subStr);
            left = right;
        }
    }
}
int main()
{
    char lex_input[MAX_LENGTH];
    printf("Enter the expression: ");
    scanf("%[^\n]", lex_input);
    printf("\nFor Expression \"%s\":\n", lex_input);
    lexicalAnalyzer(lex_input);
    return 0;
}
