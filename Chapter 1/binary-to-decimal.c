// convert unsigned binary to decimal 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char *bin;
    int dec = 0, len, count = 0, ch;

    printf("\nEnter length of binary string: ");
    scanf("%d", &len);

    bin = malloc(len * sizeof(char));

    printf("Enter binary string: ");
    while (count != len) {
        ch = getchar();
        if (ch == '\n') {
            continue;
        }
        bin[count] = ch;
        dec = dec + (bin[count] - '0') * pow(2, len - count - 1);
        ++count;
    }

    printf("\nThe decimal number is: %d\n", dec);

    return 0;
}