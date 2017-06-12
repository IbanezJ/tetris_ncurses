/*
** set_funcs2.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Mon Feb 27 16:59:57 2017 Mathias Rahmani
** Last update Sun Mar 19 18:48:37 2017 Mathias Rahmani
*/

#include "tetris.h"

int	set_kq(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  my_strcpy(game->input.key[keyquit], arg);
  return (0);
}

int	set_level(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  if (is_nbr_only(arg) == 1)
    return (1);
  game->info.level = my_atoi(arg);
  return (0);
}

int	set_next(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  game->info.w_next = my_atoi(arg);
  return (0);
}

int	set_debug(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  game->info.debug = 1;
  return (0);
}

int	set_mapsize(t_game *game, char *arg)
{
  char	*row;
  char	*col;

  parse_size_arg(&row, &col, arg);
  if (is_nbr_only(row) == 1 || is_nbr_only(col) == 1)
    return (1);
  game->info.row = my_atoi(row);
  game->info.col = my_atoi(col);
  free(row);
  free(col);
  return (0);
}
