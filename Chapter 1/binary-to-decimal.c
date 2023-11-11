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
    if (bin == NULL) {
        fprintf(stderr, "Cannot allocate space for binary string. Leaving program.\n");
    }

    printf("Enter binary string: ");
    while (count != len) {
        ch = getchar();
        if (ch == '\n') { // to take into account for trailing enter
            continue;
        }
        if (ch != '0' && ch != '1') {
            printf("\nInvalid character. Leaving program.\n");
            exit(0);
        }
        bin[count] = ch;
        dec = dec + (bin[count] - '0') * pow(2, len - count - 1);
        ++count;
    }

    printf("\nThe decimal number is: %d\n", dec);

    free(bin);

    return 0;
}