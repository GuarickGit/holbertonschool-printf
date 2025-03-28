#include "main.h"

/**
 * print_hexa - Affiche un entier non signé en hexadécimal
 * @n: Le nombre à convertir et afficher
 * @uppercase: Si True, uppercase (A-F), sinon lowercase (a-f) (Boolean)
 *
 * Return: Nombre de caractères affichés
 */
int print_hexa(unsigned int n, int uppercase)
{
	int i = 0; /* Index pour remplir le tableau temporaire */
	int digit; /* Stocke chaque chiffre hexadécimal (0 à 15) */
	int count = 0; /* Nombre de caractères à retourner */
	char waiting_hex_numbers[8]; /* Suffisant pour 32 bits (max 8 chiffres) */

	if (n == 0) /* Si n vaut 0, on affiche '0' directement */
	{
		_putchar('0');
		return (1);
	}

	/* Conversion du nombre en hexadécimal (chiffres de droite vers la gauche) */
	while (n > 0)
	{
		digit = n % 16; /* donne le chiffre le plus à droite du nombre en base 16 */
		if (digit < 10)
			waiting_hex_numbers[i] = '0' + digit;
		else
		{
			if (uppercase)
				waiting_hex_numbers[i] = 'A' + (digit - 10);
			else
				waiting_hex_numbers[i] = 'a' + (digit - 10);
		}
		i++;		/* Prochaine case du tableau */
		n = n / 16; /* On retire le chiffre traité */
	}

	/* On affiche les chiffres du tableau à l'envers (ordre correct) */
	while (i > 0)
	{
		i--;
		_putchar(waiting_hex_numbers[i]);
		count++;
	}

	return (count); /* Nombre total de caractères affichés */
}

/**
 * print_hexa_lower - Gère %x (hexadécimal en minuscule)
 * @args: Liste des arguments
 * Return: Nombre de caractères affichés
 */
int print_hexa_lower(va_list args)
{
	return (print_hexa(va_arg(args, unsigned int), 0));
}

/**
 * print_hexa_upper - Gère %X (hexadécimal en majuscule)
 * @args: Liste des arguments
 * Return: Nombre de caractères affichés
 */
int print_hexa_upper(va_list args)
{
	return (print_hexa(va_arg(args, unsigned int), 1));
}
