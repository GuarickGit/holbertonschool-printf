#include "main.h"
#include "specifiers.c"

int _printf(const char *format, ...)
{
	/*j'ouvre ma liste d'arguments*/
	va_list arguments;

	/*variables de boucle + compteur de char*/
	int i = 0, j, count = 0;

	/*je personnalise ma structure*/
	type_specifier symbol[] = {
		/*{si 'bla', utiliser telle fonction}*/
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		/*gérer les %%*/
		/*il faut gérer les autres lettres après "%"*/
		{'\0', NULL} /*quand on arrive à la fin de la string on renvoie null*/
	};
	/*on lit les argu après format*/
	va_start(arguments, format);

	/*vérifier si format est null*/
	if (format == NULL)
	{
		return (-1);
	}

	/*on parcours format via son pointeur*/
	while (format[i])
	{
		/*on reboot le check de la structure*/
		j = 0;
		if (format[i] == '%')
		{
			/*si le char est en fin de chaine = pas de char après*/
			if (format[i] == '%' && format[i + 1] == '\0')
				return (-1);
			/*on avance au char suivant*/
			i++;
			/*on boucle sur la structure pour trouver un match*/
			while (symbol[j].specifier != '\0')
			{
				/*on check dans la structure si il y a match de char*/
				if (format[i] == symbol[j].specifier)
				{
					/*si ok on renvoie la fonction liée au char*/
					/*on incrémente le compteur de char*/
					count += symbol[j].print_func(arguments);
					break;
				}
				j++;
			}
		}
		/*si pas de %*/
		else
		{
			/*on print la chaine de char*/
			_putchar(format[i]);
			/*et on incrémente le compteur de char*/
			count++;
		}
		/*on avance sur format*/
		i++;
	}

	/*on ferme la lecture de liste proprement & évite fuite mémoire*/
	va_end(arguments);
	/*retourner le compteur de caractères*/
	return (count);
}
