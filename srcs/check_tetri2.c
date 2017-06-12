/*
** check_tetri2.c for tetris in /home/ibanez_j/PSU_2016_tetris
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Thu Mar  9 14:52:43 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:43:29 2017 Mathias Rahmani
*/

#include "get_next_line.h"
#include "tetris.h"

char	*bad_spaces(int fd)
{
  char	*line;

  if ((line = get_next_line(fd)) == NULL)
    return (NULL);
  if (check_spaces(line) != 2)
    {
      free(line);
      return (NULL);
    }
  return (line);
}

int	bad_char(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] != '*' && line[i] != ' ')
	return (84);
      i++;
    }
  return (0);
}
