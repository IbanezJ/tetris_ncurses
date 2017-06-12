/*
** hdl_input.c for tetris in /home/ibanez_j/PSU_2016_tetris
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Sun Mar 19 15:18:51 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 19:22:37 2017 Mathias Rahmani
*/

#include "tetris.h"

int	drop_tetri(t_actual *actual, char **board, t_game *game)
{
  while (board[actual->cur.height + actual->row] != NULL &&
	 col_tetri(actual, board) != 1)
    {
      game->info.score += 2;
      actual->row++;
    }
  return (0);
}

int	mv_left(t_actual *actual, char **board)
{
  int	x;
  int	y;

  x = -1;
  while (actual->cur.object[++x] != NULL)
    {
      y = -1;
      while (actual->cur.object[x][++y] == ' ');
      if (board[x + actual->row][actual->col + y - 1] != ' ')
	return (1);
    }
  actual->col--;
  return (0);
}

void	pause_game(t_game game)
{
  while (game_loop(game) != keypause);
}

int	mv_right(t_actual *actual, char **board)
{
  int	x;
  int	y;

  x = -1;
  while (actual->cur.object[++x] != NULL)
    {
      y = -1;
      while (actual->cur.object[x][++y] != '\0');
      if (board[x + actual->row][actual->col + y] != ' ')
	return (1);
    }
  actual->col++;
  return (0);
}

int	handle_input(int input, t_actual *actual, char **board, t_game *game)
{
  if (input == keyleft)
    mv_left(actual, board);
  if (input == keyright)
    mv_right(actual, board);
  if (input == keydrop)
    drop_tetri(actual, board, game);
  if (input == keyquit)
    return (1);
  if (input == keypause)
    pause_game(*game);
  return (0);
}
