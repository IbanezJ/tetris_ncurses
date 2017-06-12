/*
** win_init.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Thu Mar 09 15:50:07 2017 Mathias Rahmani
** Last update Sun Mar 19 23:32:25 2017 Jean-Alexandre IBANEZ
*/

#include "tetris.h"

void	init_all_win(WINDOW **win, t_game game, t_tetrimino *tetri)
{
  win[0] = title_win();
  win[1] = board_win(game);
  win[2] = next_win(tetri, game);
  win[3] = score_win(game);
  win[4] = level_win(game);
}

WINDOW	*level_win(t_game game)
{
  WINDOW	*level;

  if ((level = newwin(7, 12, 15 + 4, game.info.col * 3 + 2)) == NULL)
    return (NULL);
  box(level, 0, 0);
  mvwprintw(level, 1, 1, "Lines :");
  mvwprintw(level, 3, 1, "----------");
  mvwprintw(level, 4, 1, "Level :");
  wrefresh(level);
  return (level);
}

WINDOW	*score_win(t_game game)
{
  WINDOW	*score;

  if ((score = newwin(4, 12, 15, game.info.col * 3 + 2)) == NULL)
    return (NULL);
  box(score, 0, 0);
  mvwprintw(score, 1, 1, "Score :");
  wrefresh(score);
  return (score);
}

WINDOW	*next_win(t_tetrimino *tetris, t_game game)
{
  WINDOW	*next;
  int	temp_width;
  int	temp_height;
  int	i;

  i = 0;
  temp_width = 0;
  temp_height = 0;
  while (tetris[i].object != NULL)
    {
      if (tetris[i].width > temp_width)
	temp_width = tetris[i].width;
      if (tetris[i].height > temp_height)
	temp_height = tetris[i].height;
      i++;
    }
  if (temp_width < 5)
    temp_width = 6;
  if ((next = newwin(temp_height + 3, temp_width + 3, 15 + 11,
		     game.info.col * 3 + 2)) == NULL)
    return (NULL);
  box(next, 0, 0);
  mvwprintw(next, 1, 1, "Next :");
  wrefresh(next);
  return (next);
}

WINDOW	*board_win(t_game game)
{
  WINDOW	*board;

  if ((board = newwin(game.info.row, game.info.col * 3, 15, 2)) == NULL)
    return (NULL);
  box(board, 0, 0);
  wrefresh(board);
  return (board);
}
