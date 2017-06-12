/*
** check_tetri.c for tetris in /home/ibanez_j/PSU_2016_tetris/srcs
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Tue Feb 21 18:16:01 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:43:21 2017 Mathias Rahmani
*/

#include "get_next_line.h"
#include "tetris.h"

int	star_len(char *line)
{
  int	size;

  size = my_strlen(line) - 1;
  while (line[size] != '*' && size != -1)
    size--;
  return (size + 1);
}

int	is_it_only_num(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] < '0' || line[i] > '9')
	return (84);
      i++;
    }
  return (0);
}

int	check_spaces(char *line)
{
  int	compt;
  int	i;

  compt = 0;
  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] >= '0' && line[i] <= '9' && line[i + 1] == ' ')
	compt++;
      i++;
    }
  i = 0;
  return (compt);
}

int	end_check(int i, int nb_line, char **first_line, char *filepath)
{
  char	*line;
  int	j;
  int	fd;

  j = 0;
  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (84);
  while ((line = get_next_line(fd)) != NULL)
    {
      if (j++ > 0 && bad_char(line) == 84)
	{
	  free(line);
	  free_tab(first_line);
	  return (84);
	}
      free(line);
    }
  close(fd);
  if (i != my_getnbr(first_line[0]) || nb_line != my_getnbr(first_line[1]))
    {
      free_tab(first_line);
      return (84);
    }
  free_tab(first_line);
  return (0);
}

int	check_tetri(char *filepath)
{
  char	**first_line;
  char	*line;
  int	fd;
  int	i;
  int	nb_line;

  line = NULL;
  nb_line = 0;
  i = 0;
  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (84);
  if ((line = bad_spaces(fd)) == NULL)
    return (84);
  if (check_value_nb(first_line = put_in_tab(line, ' ')) == 84)
    return (84);
  free(line);
  while ((line = get_next_line(fd)) != NULL)
    {
      i = (i < star_len(line)) ? star_len(line) : i;
      if (check_spaces_only(line) == 84 || nb_line < my_getnbr(first_line[1]))
	nb_line++;
      free(line);
    }
  return (end_check(i, nb_line, first_line, filepath));
}
