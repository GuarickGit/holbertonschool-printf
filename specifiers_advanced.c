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
		value = value / 2; /*on avance au bit suivant dans le tableau*/
		i++; /*on avance à l'emplacement suivant du tableau*/
	}
	/*on affiche les chiffres dans le bon ordre*/
	/*car ils sont stocker comme ça : 000111 or on veut 111000*/
	while (i--)
	{
		_putchar('0' + waiting_binary[i]); /*on affiche le caractère actuel*/
		count++; /*on incrémente le compteur de caractères*/
	}
	/*on retourne le nombre total de caractères affichés*/
	return (count);
}

/**
 * print_unsigned - Affiche un entier non signé en base 10
 * @arguments: liste d’arguments contenant la valeur à afficher
 *
 * Cette fonction récupère un unsigned int depuis une liste variadique,
 * le convertit en décimal, puis affiche chaque chiffre avec _putchar.
 * Le nombre est d'abord stocké à l'envers dans un tableau temporaire,
 * puis affiché dans le bon ordre. Si la valeur est 0,
 * elle est affichée directement.
 *
 * Return: le nombre total de caractères affichés
 */
int print_unsigned (va_list arguments)
{
	unsigned int number; /*variable pour manipuler l'arg*/
	int count = 0, i = 0; /*variable de boucle + compteur*/

	/*tableau pour stocker les chiffres à l'envers */
	/*20 suffisant pour contenir tous les chiffres d’un long */
	char waiting_numbers[20];

	/*récupération de l'entier depuis la liste d'arguments*/
	number = va_arg(arguments, unsigned int);

	/*si le nombre est zéro, on l'affiche tout de suite*/
	if (number == 0)
	{
		_putchar('0'); /*on affiche le chiffre 0*/
		return (count + 1); /*on retourne le nombre de caractères */
	}

	while (number > 0) /*on parcours number */
	{
		/*on convertit chaque chiffre en caractère */
		waiting_numbers[i] = '0' + (number % 10);
		i++; /*on avance dans l'index de number*/
		number = number / 10; /*on passe au chiffre suivant ds le tableau*/
	}

	while (i--) /*on affiche les chiffres dans le bon ordre*/
	{
		_putchar(waiting_numbers[i]); /*on affiche le caractère actuel*/
		count++; /*on incrémente le compteur de caractères*/
	}
	/*on retourne le nombre total de caractères affichés*/
	return (count);
}
