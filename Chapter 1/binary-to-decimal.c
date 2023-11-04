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

    printf("Enter binary string: ");
    for (int i = 0; i < len; ) {
        scanf("%c", &bin[i]);
        dec = dec + (bin[i] - '0') * pow(2, len - i - 1);
        ++i;
    }

    printf("\nThe decimal number is: %d\n", dec);

    return 0;
}