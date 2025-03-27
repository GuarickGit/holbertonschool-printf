#include "main.h"

/*fonction pour traduire un unsigned int en binaire*/
int print_binary(va_list arguments)
{
    /*variable de boucle + initialisation d'un compteur + array*/
    /*un unsigned int occupe 32 bits en général*/
    int i = 0, count = 0, waiting_binary[32];
    /* On récupère la valeur de l'argument */
	unsigned int value = va_arg(arguments, unsigned int);

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
