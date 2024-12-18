#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Outputs a formatted string to stdout.
 * @format: A format string containing specifiers.
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    const char *ptr;
    int count = 0;

    if (!format)
        return (-1);

    va_start(args, format);
    ptr = format;

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            switch (*ptr)
            {
            case 'd':
            case 'i':
                count += manage_integer(args);
                break;
            case 'c':
                count += manage_char(args);
                break;
            case 's':
                count += manage_string(args);
                break;
            case '%':
                count += write(1, "%", 1);
                break;
            default:
                count += write(1, "%", 1);
                count += write(1, ptr, 1);
                break;
            }
            ptr++;
        }
        else
        {
            count += write(1, ptr, 1);
            ptr++;
        }
    }

    va_end(args);
    return (count);
}
