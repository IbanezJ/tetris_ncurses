/*
** set_funcs.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Mon Feb 27 16:58:56 2017 Mathias Rahmani
** Last update Sun Mar 19 18:48:20 2017 Mathias Rahmani
*/

#include "tetris.h"

int	set_kl(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  my_strcpy(game->input.key[keyleft], arg);
  return (0);
}

int	set_kr(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  my_strcpy(game->input.key[keyright], arg);
  return (0);
}

int	set_kd(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  my_strcpy(game->input.key[keydrop], arg);
  return (0);
}

int	set_kp(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  my_strcpy(game->input.key[keypause], arg);
  return (0);
}

int	set_kt(t_game *game, char *arg)
{
  arg = parse_arg(arg);
  my_strcpy(game->input.key[keyturn], arg);
  return (0);
}
