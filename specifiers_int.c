#include "main.h"

/**
 * print_number - Fonction récursive qui affiche un entier
 * chiffre par chiffre.
 * @n: entier à afficher.
 *
 * Return: nombre de caractères affichés (length).
 */
int print_number(int n)
{
	/*on initialise un compteur (length)*/
	int count = 0;

	/*gérer si l'entier est égale à 0*/
	if (n == 0)
	{
		_putchar('0'); /*on print 0*/
		return (1); /*on retourne 1 caractère*/
	}
	/*gérer si l'entier est négatif*/
	if (n < 0)
	{
		_putchar('-'); /*on print un symbole moins*/
		count++; /*on incrémente le compteur de 1*/
		n = -n; /*on indique de l'entier est négatif*/
	}
	/*gérer si l'entier est superieur à 9 (nombre)*/
	if (n > 9)
		/*fonction récursive pour "découper" le nombre en chiffre*/
		/*7890 devient 7 8 9 0*/
		/*on ajoute le nb de caractère le compteur*/
		count += print_number(n / 10);
	/*on affiche le dernier chiffre du nombre sous forme de caractère */
	_putchar('0' + (n % 10));
	/*on incrémente le compteur de 1*/
	count++;
	/*on renvoie le compteur (length)*/
	return (count);
}

/**
 * print_integer - Récupère l'argument entier depuis va_list et l'affiche.
 * @arguments: liste d'arguments variadiques.
 *
 * Return: nombre de caractères affichés.
 */
int print_integer(va_list arguments)
{
	/*on récupère dans une variable la valeur de l'argument*/
	int integer = va_arg(arguments, int);
	/*on renvoie le return de la fonction print_number*/
	return (print_number(integer));
}
