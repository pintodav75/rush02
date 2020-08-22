#ifndef RUSH_H
#define RUSH_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_atoi(char *s);
int		size_num(int nb);
void	engine(char *str, int n);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
char	*ft_strstr(char *str, char *need);
int		ft_strlen(char *str);
int		is_space(char c);
int		is_num(char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif
