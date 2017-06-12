/*
** utils.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Wed Feb 22 14:09:45 2017 Mathias Rahmani
** Last update Sun Mar 19 18:51:05 2017 Mathias Rahmani
*/

#include "tetris.h"

int	str_equal(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '=' && str[i + 1] != '\0')
	return (0);
      i++;
    }
  return (1);
}

int	my_strcmp(char *s1, char *s2)
{
  while (*s1)
    {
      if (*s2 == '\0')
	return (2);
      if (*s2 > *s1)
	return (-1);
      if (*s1 > *s2)
	return (1);
      s1++;
      s2++;
    }
  return (0);
}

char 	*my_strdup(char *src)
{
  char *str;
  char *p;

  if ((str = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  p = str;
  while (*src)
    *p++ = *src++;
  *p = '\0';
  return (str);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int	my_atoi(char *str)
{
  int	res;
  int	sign;

  if (str == NULL)
    return (-1);
  sign = 1;
  res = 0;
  if (str[0] == '-')
    {
      sign = -1;
      str++;
    }
  while (*str && *str != '\0')
    {
      res = res * 10 + (*str) - '0';
      str++;
    }
  return (sign * res);
}
