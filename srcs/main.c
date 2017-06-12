/*
** main.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Tue Feb 21 18:10:45 2017 Mathias Rahmani
** Last update Sun Mar 19 18:56:33 2017 Mathias Rahmani
*/

#include "get_next_line.h"
#include "tetris.h"

void	wait_for_game()
{
  char	c;

  my_putstr("Press any key to start Tetris\n");
  read(0, &c, 1);
}

int	process_main(t_game game, t_tetrimino *tetrinit, char **env, t_debug *dbg)
{
  if (game.info.debug == 1)
    {
      my_putstr("*** DEBUG MODE ***\n");
      display_dbg(game);
      if (full_tetri(&tetrinit) == 84)
	return (84);
      wait_for_game();
      setup_terminal(env, 1);
    }
  else
    {
      if (no_display(&tetrinit) == 84)
	return (84);
    }
  init_curse(game, tetrinit);
  free(dbg);
  free_struct_tetri(tetrinit);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  DIR		*dir;
  t_tetrimino	*tetrinit;
  t_debug	*dbg;
  t_game	game;
  int		ret;

  (void)&tetrinit;
  if ((dbg = init_struct()) == NULL)
    return (-1);
  init_keys(&game, env);
  ret = init_param(ac, av, dbg, &game);
  if (ret == 1)
    return (0);
  else if (ret == -1)
    return (84);
  if ((dir = opendir("./tetriminos")) == NULL)
    return (84);
  if (closedir(dir) == -1)
    return (84);
  process_main(game, tetrinit, env, dbg);
  return (0);
}
