#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int manage_integer(va_list args);
int manage_char(va_list args);
int manage_string(va_list args);
int _printf(const char *format, ...);

#endif /* MAIN_H */
