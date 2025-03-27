#include "main.h"

/**
 * print_binary - Affiche la représentation binaire d’un unsigned int
 * @arguments: liste d’arguments contenant la valeur à convertir
 *
 * Cette fonction récupère un entier non signé depuis une liste
 * d’arguments variadiques (va_list), le convertit en binaire,
 * puis affiche chaque bit un par un avec _putchar.
 *
 * Return: Le nombre total de caractères affichés (toujours ≥ 1).
 */

int print_binary(va_list arguments)
{
	/*variable de boucle + initialisation d'un compteur + array*/
	/*un unsigned int occupe 32 bits en général*/
	int i = 0, count = 0, waiting_binary[32];
	/* On récupère la valeur de l'argument */
	unsigned int value = va_arg(arguments, unsigned int);

	/*gérer si value = 0*/
	/*sinon la boucle ne bouclera pas*/
	if (value == 0)
	{
		_putchar('0');
		return (1);
	}

	/*on continue tant que value n'est pas égale à 0*/
	while (value != 0)
	{
		/*bit = 0 ou 1 binaire*/
		waiting_binary[i] = value % 2; /*on stock le bit*/
		value = value / 2; /*on avance au bit suivant*/
		i++; /*on avance à l'emplacement suivant du tableau*/
	}
	/* on affiche les chiffres dans le bon ordre (en les lisant à l'envers) */
	/*car ils sont stocker comme ça : 000111 or on veut 111000*/
	while (i--)
	{
		_putchar('0' + waiting_binary[i]); /* on affiche le caractère actuel */
		count++; /* on incrémente le compteur de caractères */
	}
	/* on retourne le nombre total de caractères affichés */
	return (count);
}
