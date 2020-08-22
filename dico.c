#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f')
		return (1);
	if (c == '\n' || c == ' ' || c == '\r')
		return (1);
	return (0);
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		verif(char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '0')
		i++;
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

int		ft_atoi(char *s)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (is_space(s[i]))
		i++;
	while (is_num(s[i]))
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (res);
}

int		size_num(int nb)
{
	int i;

	i = 1;
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	engine(char *str, int n)
{
	if (n / 10 > 0)
		engine(str - 1, n / 10);
	*str = (n % 10) + 48;
}

//char	*ft_strstr(char *str, char *need)
//{
//
//}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = size_num(n);
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	str[length] = '\0';
	engine(str + length - 1, n);
	return (str);
}

void	print(char *s)
{
	while (is_space(*s))
		s++;
	while (!is_space(*s) && *s != '\n')
	{
		ft_putchar(*s);
		s++;
	}
	if (*s != '\n')
		return (print(s));
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
	printf("%s", buffer);   // jaffiche ici le buffer pour bien voir que le dico est ouvert et lu et est bien stocker dedans
//	if ((tmp = ft_strstr(buffer, str) != NULL))
//		if ((tmp = ft_strstr(tmp, ":")))
//			print(tmp);
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
