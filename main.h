#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct type_specifier - structure qui associe un caractère de type
 * à une fonction capable d'afficher cet argument
 * @specifier: le caractère représentant le type (ex: 'c', 'i', 'f', 's')
 * @print_func: pointeur vers la fonction qui affiche ce type
 */

typedef struct type_specifier
{

	char specifier;
	int (*print_func)(va_list arguments);
} type_specifier;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arguments);
int print_string(va_list arguments);
int print_percent(va_list arguments);
int print_integer(va_list arguments);
int print_binary(va_list arguments);
int print_unsigned (va_list arguments);
int print_hexa(unsigned int n, int uppercase);
int print_hexa_lower(va_list args);
int print_hexa_upper(va_list args);


#endif /* MAIN_H */
