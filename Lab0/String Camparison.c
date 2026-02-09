#include <stdio.h>
#include <string.h>
int main()
{
     char str1[100], str2[100];
     int i = 0, flag = 0;
     printf("Enter first string: ");
     scanf("%s", str1);
     printf("Enter second string: ");
     scanf("%s", str2);
     printf("Comparing strings with build-in function...\n");
     if (strcmp(str1, str2) == 0)
          printf("Strings are equal\n");
     else
          printf("Strings are not equal\n");
     printf("Comparing strings without build-in function:\n");
     while (str1[i] != '\0' || str2[i] != '\0')
     {
          if (str1[i] != str2[i])
          {
               flag = 1;
               break;
          }
          i++;
     }

     if (flag == 0)
          printf("Strings are equal\n");
     else
          printf("Strings are not equal\n");
     return 0;
}
