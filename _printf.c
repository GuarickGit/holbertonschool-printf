#include "main.h"

/* Fonction pour afficher un caractère inconnu après '%' */
/**
 * print_unknown_char - Affiche '%' suivi d'un caractère inconnu.
 * @c: le caractère inconnu à afficher après '%'.
 *
 * Return: nombre de caractères affichés (toujours 2).
 */
int print_unknown_char(char c)
{
	_putchar('%'); /*on print %*/
	_putchar(c); /*et on print le char a la suite de %*/
	return (2); /*on ajoute donc 2 char dans la length*/
}

/* Fonction pour gérer la recherche dans la structure et l'appel associé */
/**
 * handle_specifier - Cherche un specifier dans la structure
 * et appelle la fonction associée.
 * @symbol: tableau contenant les specifiers et les fonctions associées.
 * @c: le caractère suivant '%'.
 * @arguments: liste des arguments variadiques.
 *
 * Return: nombre de caractères imprimés,
 * ou gestion du caractère inconnu si non trouvé.
 */
int handle_specifier(type_specifier *symbol, char c, va_list arguments)
{
	int j = 0;

	/*on boucle sur la structure pour trouver un match*/
	while (symbol[j].specifier != '\0')
	{
		/*on check dans la structure si il y a match de char*/
		if (c == symbol[j].specifier)
		{
			/*si ok on renvoie la fonction liée au char*/
			return (symbol[j].print_func(arguments));
		}
		j++; /*on avance sur la structure*/
	}
	/*si aucun specifier n'est trouvé*/
	return (print_unknown_char(c));
}

/* Fonction principale _printf */
/**
 * _printf - Fonction principale qui reproduit printf.
 * @format: chaîne de caractères à analyser.
 *
 * Return: nombre total de caractères imprimés, ou -1 si erreur.
 */
int _printf(const char *format, ...)
{
	va_list arguments; /*j'ouvre ma liste d'arguments*/
	int i = 0, count = 0; /*variables de boucle + compteur de char*/

	type_specifier symbol[] = { /*je personnalise ma structure*/
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_integer},
		{'i', print_integer},
		{'\0', NULL} /*quand on arrive à la fin de la string on renvoie null*/
	};

	va_start(arguments, format); /*on lit les argu après format*/

	if (format == NULL) /*vérifier si format est null*/
		return (-1);

	while (format[i]) /*on parcours format via son pointeur*/
	{
		if (format[i] == '%')
		{
			/*si le char est en fin de chaine = pas de char après*/
			if (format[i + 1] == '\0')
				return (-1);

			i++; /*on avance au char suivant*/
			/*on délègue la gestion du specifier*/
			count += handle_specifier(symbol, format[i], arguments);
		}
		else
		{
			_putchar(format[i]); /*on print la chaine de char*/
			count++; /*et on incrémente le compteur de char*/
		}
		i++; /*on avance sur format*/
	}
	/*on ferme la lecture de liste proprement & évite fuite mémoire*/
	va_end(arguments);
	/*retourner le compteur de caractères*/
	return (count);
}
