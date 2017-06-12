/*
** utils2.c for tetris in /home/ibanez_j/PSU_2016_tetris
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Thu Mar 16 20:26:34 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:51:30 2017 Mathias Rahmani
*/

#include "tetris.h"

int	my_strlen(char *str)
{
  int	count;

  if (str == NULL)
    return (0);
  count = 0;
  while (*str)
    {
      count++;
      str++;
    }
  return (count);
}

void	find_name(char *str)
{
  int	size;
  int	i;

  i = 0;
  size = my_strlen(str) - 1;
  while (str[size] != '.')
    size--;
  while (i < size)
    {
      write(1, &str[i], 1);
      i++;
    }
}

int	my_strncmp(char *s1, char *s2, int nb)
{
  while (nb && *s1 && (*s1 == *s2))
    {
      s1++;
      s2++;
      nb--;
    }
  if (nb == 0)
    return (0);
  else
    return (*s1 - *s2);
}

char	*get_terminal(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], "TERM=", 5) == 0)
	return (&env[i][5]);
      i++;
    }
  return (NULL);
}

int	is_nbr_only(char *str)
{
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
	str++;
      else
	return (1);
    }
  return (0);
}
