_printf Function

This is our printf Function project! This implementation mimics the behavior of the standard C library function printf. It provides formatted output capabilities and demonstrates a deep understanding of C programming concepts.
_____________________________________________________________________________________________________________________

Table of Contents:

   • Features
   • Getting Started
   • Usage
   • Supported Format Specifiers
   • Examples
   • Contributing

____________________________________________________________________________________________________________________
 
Features: 
	• Handles basic and advanced format specifiers (e.g., %c, %s, %d, %i, %u, %x, %X).
	• Custom logic for precision, width, and flags.
	• Robust error handling.
	• Optimized for performance and memory usage.
_____________________________________________________________________________________________________________________

Getting Started:
To compile and use this project we will need:

• A GCC compiler: 
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

• Unix environment (Not mandatory but recommended)


_____________________________________________________________________________________________________________________

Supported Format Specifiers:

| Specifier  | Description                          |
|------------|--------------------------------------|
|    %c      | Character                            |
|    %s      | String                               |
|  %d, %i    | Signed integer (decimal)            |
|    %u      | Unsigned integer                    |
|   %x/%X  | Unsigned hexadecimal (lower/upper)    |
_____________________________________________________________________________________________________________________

Examples:

• _printf("%c\n", 'Z');                       //Outputs: Z
• _printf("%s\n", "Hello, World!");          //Outputs: Hello, World!
• _printf("Number: %d\n", 0948);            //Outputs: Number: 0948
• _printf("Hex: %x\n", 255);               //Outputs: Hex: ff
• _printf ("f\n", 3.14);                  //Outputs: 3.14
_____________________________________________________________________________________________________________________

Contributors:
Authors that contributed to this project : 

• Emanuel Mendoza 
• Julio Bonilla 
• Aurelio Pagan 

If you’d like to contribute, please fork this repository, make your changes, and submit a pull request.
