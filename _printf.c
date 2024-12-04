#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Prints formatted text to stdout
 * @format: Format specifier string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    if (!format)
        return (-1);

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'c') // Ejemplo básico: manejo de %c
        {
            format++;
            char c = va_arg(args, int);
            putchar(c);
            printed_chars++;
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }
    va_end(args);

    return (printed_chars);
}
