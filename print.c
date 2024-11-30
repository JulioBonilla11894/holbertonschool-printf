#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    va_list args;
    int length = 0; /* To count the number of characters printed */
    int i; /* Index for iterating through the format string */
    int j; /* Index for reversing the buffer */
    int k; /* Index for printing the buffer */
    char buffer[50]; /* Buffer to store string representations */
    int value; /* Variable to store the value being printed (signed) */
    unsigned int uvalue; /* Variable for unsigned value */
    char *str; /* Pointer to a string for %s specifier */
    char *hex_digits = "0123456789abcdef"; /* Hexadecimal digits */
    char *hex_digits_upper = "0123456789ABCDEF"; /* Uppercase hexadecimal digits */
    unsigned long address; /* Address for %p specifier */
    void *ptr; /* Pointer for %p specifier */

    va_start(args, format);

    /* Loop through the format string */
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && (format[i + 1] != '\0')) {
            switch (format[i + 1]) {
                case 'd':
                case 'i':
                    /* Print signed integer */
                    value = va_arg(args, int);
                    if (value < 0) {
                        write(1, "-", 1);
                        value = -value;
                        length++;
                    }
                    /* Convert integer to string (reverse conversion) */
                    j = 0;
                    do {
                        buffer[j++] = (value % 10) + '0';
                        value /= 10;
                    } while (value > 0);
                    /* Print the digits in correct order */
                    for (k = j - 1; k >= 0; k--) {
                        write(1, &buffer[k], 1);
                        length++;
                    }
                    i++; /* Move past the format specifier */
                    break;

                case 'u':
                    /* Print unsigned integer */
                    uvalue = va_arg(args, unsigned int);
                    j = 0;
                    do {
                        buffer[j++] = (uvalue % 10) + '0';
                        uvalue /= 10;
                    } while (uvalue > 0);
                    for (k = j - 1; k >= 0; k--) {
                        write(1, &buffer[k], 1);
                        length++;
                    }
                    i++;
                    break;

                case 'o':
                    /* Print unsigned octal */
                    uvalue = va_arg(args, unsigned int);
                    j = 0;
                    do {
                        buffer[j++] = (uvalue % 8) + '0';
                        uvalue /= 8;
                    } while (uvalue > 0);
                    for (k = j - 1; k >= 0; k--) {
                        write(1, &buffer[k], 1);
                        length++;
                    }
                    i++;
                    break;

                case 'x':
                    /* Print unsigned hexadecimal (lowercase) */
                    uvalue = va_arg(args, unsigned int);
                    j = 0;
                    do {
                        buffer[j++] = hex_digits[uvalue % 16];
                        uvalue /= 16;
                    } while (uvalue > 0);
                    for (k = j - 1; k >= 0; k--) {
                        write(1, &buffer[k], 1);
                        length++;
                    }
                    i++;
                    break;

                case 'X':
                    /* Print unsigned hexadecimal (uppercase) */
                    uvalue = va_arg(args, unsigned int);
                    j = 0;
                    do {
                        buffer[j++] = hex_digits_upper[uvalue % 16];
                        uvalue /= 16;
                    } while (uvalue > 0);
                    for (k = j - 1; k >= 0; k--) {
                        write(1, &buffer[k], 1);
                        length++;
                    }
                    i++;
                    break;

                case 'c':
                    /* Print single character */
                    value = va_arg(args, int);
                    write(1, &value, 1);
                    length++;
                    i++;
                    break;

                case 's':
                    /* Print string */
                    str = va_arg(args, char *);
                    if (str == NULL) {
                        write(1, "(null)", 6);
                        length += 6;
                    } else {
                        for (j = 0; str[j] != '\0'; j++) {
                            write(1, &str[j], 1);
                            length++;
                        }
                    }
                    i++;
                    break;

                case 'p':
                    /* Print pointer (address) */
                    ptr = va_arg(args, void *); /* Get the pointer */
                    address = (unsigned long)ptr; /* Cast pointer to unsigned long */

                    write(1, "0x", 2); /* Print the `0x` prefix */
                    length += 2;

                    /* Handle the case where the pointer is NULL */
                    if (address == 0) {
                        write(1, "0", 1);
                        length++;
                    } else {
                        /* Convert the address to a hexadecimal string */
                        j = 0;
                        do {
                            buffer[j++] = hex_digits[address % 16];
                            address /= 16;
                        } while (address > 0);

                        /* Print the digits in the correct order */
                        for (k = j - 1; k >= 0; k--) {
                            write(1, &buffer[k], 1);
                            length++;
                        }
                    }
                    i++;
                    break;

                case '%':
                    /* Print literal '%' */
                    write(1, "%", 1);
                    length++;
                    i++;
                    break;

                default:
                    /* Handle unknown specifier */
                    write(1, &format[i], 1);
                    length++;
            }
        } else {
            /* Print regular characters */
            write(1, &format[i], 1);
            length++;
        }
    }

    va_end(args);
    return length;
}

