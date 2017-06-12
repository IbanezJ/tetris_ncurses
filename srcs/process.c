/*
** process.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Sat Mar 18 17:29:09 2017 Mathias Rahmani
** Last update Sun Mar 19 19:09:34 2017 Mathias Rahmani
*/

#include "tetris.h"

int	dbg_check(char *str)
{
  if (my_strcmp(str, "-d") != 0 && my_strcmp(str, "--debug") != 0)
    return (0);
  else
    return (1);
}

int	get_param(t_debug *dbg, char **av, t_game *game, int *i)
{
  int	j;

  j = -1;
  while (dbg[++j].flag_1 != NULL)
    {
      if (my_strcmp(av[*i], dbg[j].flag_1) == 0)
      	{
	  if ((dbg_check(av[*i]) == 0) ? dbg[j].func(game, av[++(*i)])
	      : dbg[j].func(game, av[*i]) == 1)
	    return (1);
	  break;
	}
      else if (my_strcmp(av[*i], dbg[j].flag_2) == 2 && str_equal(av[*i]) == 0)
	{
	  if (dbg[j].func(game, av[*i]) == 1)
	    return (1);
	  break;
	}
    }
  if (dbg[j].flag_1 == NULL)
    return (-1);
  return (0);
}

int	process_param(int ac, char **av, t_debug *dbg, t_game *game)
{
  int	i;
  int	ret;

  i = 0;
  while (++i < ac)
    {
      ret = get_param(dbg, av, game, &i);
      if (ret == 1)
	return (1);
      else if (ret == -1)
	return (-1);
    }
  return (0);
}

int	init_param(int ac, char **av, t_debug *dbg, t_game *game)
{
  int	ret;

  ret = process_param(ac, av, dbg, game);
  if (ret == 1)
    {
      print_help(av);
      return (1);
    }
  else if (ret == -1 || check_all_keys(*game) == 1)
    {
      print_help(av);
      return (-1);
    }
  else
    return (0);
}

void	init_keys(t_game *game, char **env)
{
  setup_terminal(env, 0);
  my_strcpy(game->input.key[keyleft], tigetstr("kcub1"));
  my_strcpy(game->input.key[keyright], tigetstr("kcuf1"));
  my_strcpy(game->input.key[keyturn], tigetstr("kcuu1"));
  my_strcpy(game->input.key[keydrop], tigetstr("kcud1"));
  my_strcpy(game->input.key[keyquit], "q");
  my_strcpy(game->input.key[keypause], " ");
  game->info.lines = 0;
  game->info.score = 0;
  game->info.level = 1;
  game->info.w_next = 0;
  game->info.row = 20;
  game->info.col = 10;
  game->info.debug = 0;
}
