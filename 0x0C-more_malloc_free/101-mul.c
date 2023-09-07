#include <stdio.h>
#include <stdlib.h>

/**
 * my_isdigit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if @c is a digit, 0 otherwise
 */
int my_isdigit(char c) {
    return (c >= '0' && c <= '9');
}

/**
 * my_strlen - Calculate the length of a string
 * @str: The string to calculate the length of
 *
 * Return: The length of the string
 */
int my_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

/**
 * multiply - Multiply two numbers as strings
 * @num1: The first number as a string
 * @num2: The second number as a string
 *
 * Return: A pointer to the result as a string
 */
char *multiply(char *num1, char *num2) {
    int len1 = 0, len2 = 0, i, j;
    char *result;

    /* Calculate the length of num1 and num2 */
    while (num1[len1] != '\0') {
        len1++;
    }

    while (num2[len2] != '\0') {
        len2++;
    }

    /* Allocate memory for the result */
    result = (char *)malloc(len1 + len2 + 1);
    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(98);
    }

    /* Initialize the result to '0' */
    for (i = 0; i < len1 + len2; i++) {
        result[i] = '0';
    }
    result[len1 + len2] = '\0';

    /* Multiply the digits and update the result */
    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] - '0' + product;
            result[i + j + 1] = (sum % 10) + '0';
            result[i + j] += sum / 10;
        }
    }

    /* Remove leading zeros */
    i = 0;
    while (result[i] == '0' && result[i + 1] != '\0') {
        i++;
    }

    /* Shift the result to the beginning */
    for (j = 0; result[i + j] != '\0'; j++) {
        result[j] = result[i + j];
    }
    result[len1 + len2 - i] = '\0';

    return result;
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[]) {
    char *num1, *num2, *result;
    int i;

    if (argc != 3) {
        fprintf(stderr, "Error\n");
        return 98;
    }

    num1 = argv[1];
    num2 = argv[2];

    /* Check if both numbers are composed of digits */
    for (i = 0; num1[i] != '\0'; i++) {
        if (!my_isdigit(num1[i])) {
            fprintf(stderr, "Error\n");
            return 98;
        }
    }

    for (i = 0; num2[i] != '\0'; i++) {
        if (!my_isdigit(num2[i])) {
            fprintf(stderr, "Error\n");
            return 98;
        }
    }

    result = multiply(num1, num2);
    printf("%s\n", result);

    free(result);

    return 0;
}