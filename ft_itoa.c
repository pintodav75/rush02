#include "rush.h"

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
