#include "rush.h"

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

char	*ft_strstr(char *str, char *need)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (need[j] == str[i + j])
			j++;
		if (need[j] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
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
