/*
** draw.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Sun Mar 19 18:03:14 2017 Mathias Rahmani
** Last update Sun Mar 19 18:44:19 2017 Mathias Rahmani
*/

#include "tetris.h"

void	draw(WINDOW **win, t_game game, t_actual actual)
{
  draw_level(win[4], game.info.lines, game.info.level);
  draw_score(win[3], game.info.score);
  draw_next(actual.next, win[2]);
}

void	draw_score(WINDOW *win, int score)
{
  mvwprintw(win, 2, 1, "          ");
  mvwprintw(win, 2, 1, "%d", score);
  wrefresh(win);
}

void	draw_level(WINDOW *win, int lines, int level)
{
  mvwprintw(win, 2, 1, "          ");
  mvwprintw(win, 2, 1, "%d", lines);
  mvwprintw(win, 5, 1, "          ");
  mvwprintw(win, 5, 1, "%d", level);
  wrefresh(win);
}

void	draw_next(t_tetrimino next, WINDOW *win)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  start_color();
  init_pair_color();
  wclear(win);
  box(win, 0, 0);
  mvwprintw(win, 1, 1, "Next :");
  while (next.object[x] != NULL)
    {
      while (next.object[x][y] != '\0')
	{
	  if (next.object[x][y] == '*')
	    mvwaddch(win, x + 2, y + 1, ' ' | A_REVERSE |
		     COLOR_PAIR(next.color));
	  y++;
	}
      y = 0;
      x++;
    }
  wrefresh(win);
}

void	draw_tetrimino(t_actual actual, char ***board)
{
  int	x;
  int	y;

  x = -1;
  y = -1;
  while (actual.cur.object[++x] != NULL)
    {
      while (actual.cur.object[x][++y] != '\0')
	{
	  if (actual.cur.object[x][y] == '*')
	    (*board)[x + actual.row][y + actual.col] = actual.cur.color;
	}
      y = -1;
    }
}
