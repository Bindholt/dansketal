#include <stdio.h>
#include "dansketal.h"

int main()
{
    char s[256];
    int number = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    dansketal(number, s);
    printf("%s\n", s);
    return 0;
}