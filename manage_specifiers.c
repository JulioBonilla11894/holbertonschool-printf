#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * manage_integer - Converts an integer to a string and sends it to stdout.
 * @args: A va_list of arguments from _printf.
 * Return: The number of characters printed.
 */
int manage_integer(va_list args)
{
    int num = va_arg(args, int);
    char buffer[12];
    char *s;
    int count = 0;

    sprintf(buffer, "%d", num);
    s = buffer;
    while (*s)
    {
        count += write(1, s++, 1);
    }
    return (count);
}

/**
 * manage_char - Sends a character to stdout.
 * @args: A va_list of arguments from _printf.
 * Return: 1 (number of characters printed).
 */
int manage_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * manage_string - Sends a string to stdout.
 * @args: A va_list of arguments from _printf.
 * Return: The number of characters printed.
 */
int manage_string(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
    {
        count += write(1, s++, 1);
    }
    return (count);
}
