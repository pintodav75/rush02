#include "rush.h"

int		verif(char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '0')
	{
		if (!is_num(str[i + 1]))
			break;
		i++;
	}
	while (str[i] && is_num(str[i]))
	{
		num++;
		i++;
	}
	while (str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	if (num == 0)
		return (0);
	return (1);
}

int		find_word(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!is_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print(char *s, int count)
{
	while (is_space(*s))
		s++;
	while (!is_space(*s) && *s != '\n')
	{
		ft_putchar(*s);
		s++;
		count++;
	}
	if (find_word(s))
	{
		ft_putchar(' ');
		return (print(s, count + 1));
	}
	else
		return;
}

int		ft_dico(char *s, char *dictionary)
{
	char	*str;
	char 	buffer[10001];
	char	*tmp;
	int		fd;
	
	if (!verif(s))   // verif si largument comporte un nombre valide
		return (0);
	if (!(str = ft_strdup(ft_itoa(ft_atoi(s))))) // stock le nombre sans espace dans une chaine malloc de la bonne taille
		return (0);
	if ((fd = open(dictionary, O_RDONLY)) == -1) // jouvre le dico et le stock dand char*buffer
		return (0);
	if (read(fd, buffer, 10000) == -1)
		return (0);
	buffer[10000] = '\0';
	//printf("%s", buffer);   // jaffiche ici le buffer pour bien voir que le dico est ouvert et lu et est bien stocker dedans
	if ((tmp = ft_strstr(buffer, str)) != NULL)
		if ((tmp = ft_strstr(tmp, ":")) != NULL)
			print(tmp + 1, 0);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		ft_putstr("Error\n");
	if (ac == 2)   // si on menvoi juste un nombre, jenvoi le dico de base stocker dans default.txt
		if (!ft_dico(av[1], "default.txt"))
			ft_putstr("Error\n");
	if (ac == 3)   // si on menvoi un dico et bien je lenvoi dans ma fonction
		if (!ft_dico(av[1], av[2]))
			ft_putstr("Error\n");
	return (0);
}
