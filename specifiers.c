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

#include "main.h"

/**
 * print_integer - affiche un entier signé (pour %d ou %i)
 * @arguments: va_list contenant l'entier à afficher
 *
 * Return: nombre de caractères affichés
 */
int print_integer(va_list arguments)
{
	/* utilisation de long pour éviter un overflow si on a INT_MIN */
	long n;
	int count = 0, i = 0;

	/* on prépare un tableau pour stocker les chiffres à l'envers */
	/* suffisant pour contenir tous les chiffres d’un long */
	char waiting_numbers[20];

	/* récupération de l'entier depuis la liste d'arguments (toujours en int) */
	n = (long)va_arg(arguments, int);

	/* si le nombre est négatif, on affiche '-' et on le rend positif */
	if (n < 0)
	{
		_putchar('-'); /* on affiche le signe moins */
		count++; /* on compte ce caractère affiché */
		n = -n; /* on passe en positif (en sécurité car n est un long) */
	}
	/* si le nombre est zéro, on l'affiche tout de suite */
	if (n == 0)
	{
		_putchar('0'); /* on affiche le chiffre 0 */
		return (count + 1); /* on retourne le nombre total de caractères */
	}

	/* On extrait les chiffres un à un (du dernier au premier) */
	while (n > 0)
	{
		/* on convertit chaque chiffre en caractère */
		waiting_numbers[i++] = (n % 10) + '0';
		n /= 10; /* On enlève ce chiffre du nombre */
	}
	/* on affiche les chiffres dans le bon ordre (en les lisant à l'envers) */
	while (i--)
	{
		_putchar(waiting_numbers[i]); /* on affiche le caractère actuel */
		count++; /* on incrémente le compteur de caractères */
	}
	/* on retourne le nombre total de caractères affichés */
	return (count);
}
