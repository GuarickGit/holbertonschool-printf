#include "main.h"

/**
 * print_char - affiche un caractère
 * @arguments: va_list contenant le caractère à afficher
 *
 * Return: nombre de caractères affichés, toujours 1, puisque character
 */
int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);

	_putchar(c);

	return (1);
}

/**
 * print_string - affiche une chaîne de caractères
 * @arguments: va_list contenant la string à afficher
 *
 * Return: nombre de caractères affichés
 */
int print_string(va_list arguments)
{
	int i;
	int counter = 0;

	char *str = va_arg(arguments, char *);

	/* si la string est NULL, le contenu de str devient "(null)" */
	if (!str)
		str = "(null)";

	/* on parcourt chaque caractère de la string */
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		counter++;
	}

	return (counter);
}

/**
 * print_percent - affiche un pourcentage (%)
 * @arguments: va_list non utilisé, mais nécessaire pour la cohérence de
 * la structure
 *
 * Return: nombre de caractères affichés, toujours 1, puisque character */
int print_percent(va_list arguments)
{
	(void)arguments;
	_putchar('%');
	return (1);
}
