/*
** error_hdl.c for tetris in /home/ibanez_j/PSU_2016_tetris/srcs
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Mon Feb 27 11:55:41 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:44:34 2017 Mathias Rahmani
*/

#include <dirent.h>
#include "tetris.h"

int	good_end(char *file_name)
{
  int	size;

  size = my_strlen(file_name);
  if (size < my_strlen(".tetrimino") + 1)
    return (84);
  if (file_name[size - 1] == 'o' &&
      file_name[size - 2] == 'n' &&
      file_name[size - 3] == 'i' &&
      file_name[size - 4] == 'm' &&
      file_name[size - 5] == 'i' &&
      file_name[size - 6] == 'r' &&
      file_name[size - 7] == 't' &&
      file_name[size - 8] == 'e' &&
      file_name[size - 9] == 't' &&
      file_name[size - 10] == '.')
    return (0);
  return (84);
}

int	check_value_nb(char **first_line)
{
  if (my_getnbr(first_line[2]) < 0 || my_getnbr(first_line[2]) > 7)
    return (84);
  if (is_it_only_num(first_line[0]) == 84 ||
      is_it_only_num(first_line[1]) == 84 ||
      is_it_only_num(first_line[2]) == 84)
    return (84);
  return (0);
}

int		full_struct(t_tetrimino **tetris, struct dirent *dp)
{
  char		*full_path;
  static int	i = 0;

  if (good_end(dp->d_name) == 0)
    {
      my_printf("Tetriminos : Name ");
      find_name(dp->d_name);
      if (check_tetri((full_path = add_tetrimino(dp->d_name))) == 84)
	my_printf(" : Error\n");
      else
	{
	  free(full_path);
	  (*tetris)[i] = full_case((full_path = add_tetrimino(dp->d_name)));
	  if ((*tetris)[i].object == NULL)
	    return (-1);
	  my_printf(" : Size %d*%d : Color %d :\n", (*tetris)[i].width,
		    (*tetris)[i].height, (*tetris)[i].color);
	  disp_tab((*tetris)[i].object);
	  i++;
	}
      free(full_path);
    }
  return (i);
}

void	free_struct_tetri(t_tetrimino *tetris)
{
  int	i;

  i = 0;
  while (tetris[i].object != NULL)
    {
      free_tab(tetris[i].object);
      i++;
    }
  free(tetris);
}

int	no_disp_struct(t_tetrimino **tetris, struct dirent *dp)
{
  char	*full_path;
  static int	i = 0;

  if (good_end(dp->d_name) == 0)
    {
      if (check_tetri((full_path = add_tetrimino(dp->d_name))) != 84)
	{
	  (*tetris)[i] = full_case(full_path);
	  if ((*tetris)[i].object == NULL)
	    return (-1);
	  i++;
	}
      free(full_path);
    }
  return (i);
}
