// convert numbers from some base to another base specified by the user

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int base_to_decimal(int b1, int len, char *string);
void decimal_to_base(int decimal, int b2, int b1);

int main()
{
    int b1, b2, len, ch, decimal;
    char *string;

    printf("\nPlease enter 16 for hexadecimal, 10 for decimal, 8 for octal, and 2 for binary");
    printf("\nEnter the first base: ");
    scanf("%d", &b1);
    printf("Enter the second base: ");
    scanf("%d", &b2);

    // check for proper user inputs
    if ((b1 != 2 && b1 != 8 && b1 != 10 && b1 != 16) || (b2 != 2 && b2 != 8 && b2 != 10 && b2 != 16)) {
        fprintf(stderr, "\nImproper base entered in main. Leaving program.\n");
        exit(0);
    }
    else if (b1 == b2) {
        fprintf(stderr, "\nBases equal in main. Leaving program.\n");
        exit(0);
    }

    if (b1 != 10) { // get string of chars for base 2, base 8, and base 16
        printf("\nEnter length of base %d string: ", b1);
        scanf("%d", &len);
        string = malloc(len * sizeof(char));
        printf("Enter your base %d number: ", b1);
        for (int i = 0; i < len; ) { // will only take first len characters inpuuted, rest will be ignored
            ch = getchar();
            if (ch == '\n') {
                continue;
            }
            string[i++] = tolower(ch);

            // check for proper user inputs
            if (b1 == 2 && (ch != '0' && ch != '1')) {
                fprintf(stderr, "\nImproper base %d string inputted. Leaving program.\n", b1);
                free(string);
                exit(0);
            }
            else if (b1 == 8 && (ch < '0' || ch > '7')) {
                fprintf(stderr, "\nImproper base %d string inputted. Leaving program.\n", b1);
                free(string);
                exit(0);
            }
            else if (b1 == 16 && ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f'))) {
                fprintf(stderr, "\nImproper base %d string inputted. Leaving program.\n", b1);
                free(string);
                exit(0);
            }
        }
    }
    else { // get integer value for base 10 number
        printf("\nEnter your base %d number: ", b1);
        scanf("%d", &decimal);
    }

    if (b2 == 10) { // produce the output of the conversion
        decimal = base_to_decimal(b1, len, string);
        printf("Conversion from base %d to base %d is %d.\n", b1, b2, decimal);
    }
    else if (b1 != 10) {
        decimal = base_to_decimal(b1, len, string);
        decimal_to_base(decimal, b2, b1);
    }
    else {
        decimal_to_base(decimal, b2, b1);
    }

    free(string);

    return 0;
}

int base_to_decimal(int b1, int len, char *string)
{
    int count = 0, sum = 0;

    // could put some error checking here to make sure pre and post results are good
    for (int i = 0; i < len; ++i) {
        if (isalpha(string[i])) {
            sum = sum + (string[i] - 'a' + 10) * pow(b1, len - i - 1);
        } 
        else {
            sum = sum + (string[i] - '0') * pow(b1, len - i - 1);
        }
    }

    return sum;
}

void decimal_to_base(int decimal, int b2, int b1)
{
    int temp = decimal, count = 0, quot;
    char *output, ch, hex[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

    while (temp != 0) {
        temp = temp / b2;
        ++count;
    }

    // could put some error checking here to make sure pre and post results are good
    output = malloc(count * sizeof(char));
    for (int i = 0; i < count; ++i) {
        quot = decimal / b2;
        temp = decimal - quot * b2;
        if (temp > 9) {
            ch = hex[temp - 10];
        }
        else {
            ch = (decimal - quot * b2) + '0';
        }
        output[i] = ch;
        decimal = quot;
    }

    printf("Conversion from base %d to base %d is ", b1, b2);
    for (int i = count; i > 0; --i) {
        printf("%c", output[i - 1]);
    }
    printf(".\n");

    free(output);
}