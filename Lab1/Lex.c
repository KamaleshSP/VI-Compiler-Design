#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
bool isDelimiter(char chr)
{
    return (chr == ' ' || chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == ',' || chr == ';' || chr == '%' || chr == '>' || chr == '<' || chr == '=' || chr == '(' || chr == ')' || chr == '[' || chr == ']' || chr == '{' || chr == '}');
}
bool isOperator(char chr)
{
    return (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '>' || chr == '<' || chr == '=');
}
bool isKeyword(char *str)
{
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
        if (strcmp(str, keywords[i]) == 0)
            return true;
    return false;
}
bool isInteger(char *str)
{
    if (*str == '\0')
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}
bool isRealNumber(char *str)
{
    bool hasDecimal = false;
    bool hasDigit = false;
    if (str == NULL || *str == '\0')
        return false;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            hasDigit = true;
        }
        else if (str[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else
        {
            continue;
        }
    }
    return hasDecimal && hasDigit;
}
bool isFloatNumber(char *str)
{
    char *dot = strchr(str, '.');
    if (!dot)
        return false;
    int digitsAfterDecimal = strlen(dot + 1);
    return digitsAfterDecimal <= 6;
}
bool isDoubleNumber(char *str)
{
    char *dot = strchr(str, '.');
    if (!dot)
        return false;
    int digitsAfterDecimal = strlen(dot + 1);
    return digitsAfterDecimal > 6;
}
char *getSubstring(char *str, int start, int end)
{
    int subLength = end - start + 1;
    char *subStr = (char *)malloc(subLength + 1);
    strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return subStr;
}
bool isValidIdentifier(char *str)
{
    if (str == NULL || *str == '\0')
        return false;
    if (!(isalpha(str[0]) || str[0] == '_'))
        return false;
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return false;
    }
    if (isKeyword(str))
        return false;
    return true;
}
void lexicalAnalyzer(char *input)
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
        else if ((isDelimiter(input[right]) && left != right) || (right == len && left != right))
        {
            char *subStr = getSubstring(input, left, right - 1);
            if (strlen(subStr) == 0)
            {
                free(subStr);
                left = right;
                continue;
            }
            if (isKeyword(subStr))
                printf("Token: Keyword, Value: %s\n", subStr);
            else if (isInteger(subStr))
                printf("Token: Integer, Value: %s\n", subStr);
            else if (isRealNumber(subStr) && isFloatNumber(subStr))
                printf("Token: Float, Value: %s\n", subStr);
            else if (isRealNumber(subStr) && isDoubleNumber(subStr))
                printf("Token: Double, Value: %s\n", subStr);
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
    FILE *fp;
    char lex_input[MAX_LENGTH];
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    printf("Lexical Analysis Output:\n\n");
    while (fgets(lex_input, MAX_LENGTH, fp) != NULL)
    {
        lex_input[strcspn(lex_input, "\n")] = '\0';
        if (strlen(lex_input) == 0)
            continue;
        printf("For Expression \"%s\":\n...", lex_input);
        lexicalAnalyzer(lex_input);
        printf("\n");
    }
    fclose(fp);
    return 0;
}