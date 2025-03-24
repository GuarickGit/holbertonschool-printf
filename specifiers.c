#include "main.h"

int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);
	_putchar(c);
	return (0);
}

int print_string(va_list arguments)
{
	int i;
	int counter = 0;

	char *str = va_arg(arguments, char *);

	if (!str)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		counter += _putchar(str);
	}


}
