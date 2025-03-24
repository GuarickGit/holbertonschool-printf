#include "main.h"

/**
 * print_char - Affiche un caractère
 * @arguments: va_list contenant le caractère à afficher
 *
 * Return: 1 si succès, -1 en cas d'erreur d'écriture
 */
int print_char(va_list arguments)
{
	/* On récupère le caractère depuis la liste */
	char c = va_arg(arguments, int);

	/* On tente de l'afficher, si échec on retourne -1 */
	if (_putchar(c) == -1)
		return (-1);

	return (1); /* Succès, on a affiché 1 caractère */
}

/**
 * print_string - Affiche une chaîne de caractères
 * @arguments: va_list contenant la chaîne à afficher
 *
 * Return: Nombre de caractères affichés, ou -1 en cas d'erreur
 */
int print_string(va_list arguments)
{
	int i;
	int counter = 0;
	/* On récupère la chaîne depuis la liste */
	char *str = va_arg(arguments, char *);

	/* Si la chaîne est NULL, on affiche "(null)" */
	if (!str)
		str = "(null)";

	/* On parcourt chaque caractère de la chaîne */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* On affiche chaque caractère un par un */
		if (_putchar(str[i]) == -1)
			return (-1); /* Si une écriture échoue, on retourne -1 */

		counter++; /* Incrémentation du compteur si succès */
	}

	return (counter); /* On retourne le nombre total de caractères affichés */
}

/**
 * print_percent - Affiche un caractère pourcentage (%)
 * @arguments: va_list (non utilisé mais requis pour la signature)
 *
 * Return: 1 si succès, -1 en cas d'erreur d'écriture
 */
int print_percent(va_list arguments)
{
	(void)arguments; /* On ignore l'argument car inutile ici */

	/* On tente d'afficher le caractère '%' */
	if (_putchar('%') == -1)
		return (-1); /* Si échec, on retourne -1 */

	return (1); /* Sinon, on a affiché 1 caractère */
}
