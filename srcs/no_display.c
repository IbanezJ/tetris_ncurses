/*
** no_display.c for tetris in /home/ibanez_j/PSU_2016_tetris/srcs
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Thu Mar  2 17:54:38 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:46:54 2017 Mathias Rahmani
*/

#include "tetris.h"

int	no_display(t_tetrimino **tetris)
{
  int		compt;
  int		i;
  int		n;
  struct dirent	**dp;

  compt = 0;
  i = 0;
  if ((n = scandir("./tetriminos", &dp, 0, alphasort)) == -1)
    return (84);
  if (((*tetris) = malloc(sizeof(t_tetrimino) * (count_dir("./tetriminos")
						 + 1))) == NULL)
    return (84);
  while (compt < n)
    {
      if ((i = no_disp_struct(tetris, dp[compt])) == -1)
	return (84);
      compt++;
    }
  (*tetris)[i].width = -1;
  (*tetris)[i].height = -1;
  (*tetris)[i].object = NULL;
  while (n--)
    free(dp[n]);
  free(dp);
  return (0);
}
