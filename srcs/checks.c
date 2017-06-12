/*
** checks.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Sat Mar 18 17:34:10 2017 Mathias Rahmani
** Last update Sun Mar 19 18:43:37 2017 Mathias Rahmani
*/

#include "tetris.h"

int	check_all_keys(t_game game)
{
  int	i;
  int	j;

  i = 0;
  while (i < 6)
    {
      j = i + 1;
      while (j < 6)
	{
	  if (my_strcmp(game.input.key[i], game.input.key[j]) == 0)
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_line_full(char *line, t_game *game)
{
  int	i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] == ' ')
	return (1);
      i++;
    }
  game->info.lines++;
  if (game->info.lines % 2 == 0)
    game->info.level++;
  return (0);
}

int	detect_end(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
	return (1);
      i++;
    }
  return (0);
}

int	nb_tetri(t_tetrimino *tetris)
{
  int	i;

  i = 0;
  while (tetris[i].object != NULL)
    i++;
  return (i);
}

void	check_collisions(char ***board, t_actual *actual,
			 t_tetrimino *tetri, t_game game)
{
  if ((*board)[actual->cur.height + actual->row] == NULL
      || col_tetri(actual, *board) == 1)
    {
      actual->cur = actual->next;
      srand((unsigned int) time(NULL));
      actual->next = tetri[rand() % nb_tetri(tetri)];
      actual->row = 0;
      actual->col = game.info.col * 3 / 2;
      game.info.score += 10;
    }
  else
    {
      clear_tetrimino(*actual, board);
      actual->row++;
    }
}
