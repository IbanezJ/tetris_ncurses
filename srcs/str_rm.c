/*
** my_strcpy.c for tetris in /home/ibanez_j/PSU_2016_tetris
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Fri Mar 17 18:19:46 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:49:56 2017 Mathias Rahmani
*/

#include "tetris.h"

int	spaces_only(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
	return (84);
      i++;
    }
  return (0);
}

char	*rm_space(char *str)
{
  int	i;
  char	*cpy;
  int	size;

  size = my_strlen(str) - 1;
  while (str[size] == ' ')
    size--;
  size++;
  if ((cpy = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      cpy[i] = str[i];
      i++;
    }
  cpy[i] = '\0';
  return (cpy);
}

int	check_spaces_only(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
	return (84);
      i++;
    }
  return (0);
}
