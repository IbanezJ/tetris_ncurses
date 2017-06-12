/*
** tab.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Sun Mar 19 18:09:28 2017 Mathias Rahmani
** Last update Sun Mar 19 23:32:09 2017 Jean-Alexandre IBANEZ
*/

#include "tetris.h"

int	init_tab(t_game game, char ***board)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  if (((*board) = malloc(sizeof(char*) * (game.info.row - 1))) == NULL)
    return (-1);
  while (x < (game.info.row - 2))
    {
      if (((*board)[x] = malloc(sizeof(char) * (game.info.col * 3 - 1)))
	  == NULL)
	return (-1);
      while (y < (game.info.col * 3 - 2))
	{
	  (*board)[x][y] = ' ';
	  y++;
	}
      (*board)[x][y] = '\0';
      x++;
      y = 0;
    }
  (*board)[x] = NULL;
  return (0);
}

void	print_tab(WINDOW *win, char **board)
{
  int	x;
  int	y;

  x = -1;
  y = -1;
  start_color();
  init_pair_color();
  while (board[++x] != NULL)
    {
      while (board[x][++y] != '\0')
	{
	  if (board[x][y] != ' ')
	    mvwaddch(win, x + 1, y + 1, ' ' | A_REVERSE | COLOR_PAIR(board[x][y]));
	  else if (board[x][y] == ' ')
	    mvwaddch(win, x + 1, y + 1, ' ' | COLOR_PAIR(board[x][y]));
	}
      y = -1;
    }
  wrefresh(win);
}

void	clear_tetrimino(t_actual actual, char ***board)
{
  int	x;
  int	y;

  x = -1;
  y = -1;
  while (actual.cur.object[++x] != NULL)
    {
      while (actual.cur.object[x][++y] != '\0')
	{
	  if ((*board)[x + actual.row][y + actual.col] != ' '
	      && actual.cur.object[x][y] != ' ')
	    (*board)[x + actual.row][y + actual.col] = ' ';
	}
      y = -1;
    }
}

void	actualize_and_disp(t_actual actual, char ***board, WINDOW **win)
{
  draw_tetrimino(actual, board);
  print_tab(win[1], *board);
}
