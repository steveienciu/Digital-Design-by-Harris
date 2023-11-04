// convert unsigned binary to decimal 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char *bin;
    int dec = 0, len;

    printf("\nEnter length of binary string: ");
    scanf("%d", &len);

    bin = malloc(len * sizeof(char));

    printf("\nEnter binary string: ");
    for (int i = 0; i < len; ) {
        dec = dec + pow(2, len - i - 1);
        ++i;
    }

    printf("\nThe decimal number is: %d", dec);

    return 0;
}