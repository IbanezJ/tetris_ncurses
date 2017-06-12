/*
** game_title.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Thu Mar 09 15:37:11 2017 Mathias Rahmani
** Last update Sun Mar 19 23:31:56 2017 Jean-Alexandre IBANEZ
*/

#include "tetris.h"

int	game_loop(t_game game)
{
  char	res[255] = {0};
  int	i;

  if (read(0, res, 255) > 0)
    {
      i = 0;
      while (i < 6)
	{
	  if (my_strcmp(game.input.key[i], res) == 0)
	    return (i);
	  i++;
	}
    }
  return (-1);
}

int	col_tetri(t_actual *actual, char **board)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (actual->cur.object[x][y] != '\0')
    {
      while (actual->cur.object[x] != NULL &&
	     (actual->cur.object[x][y] != '\0'))
	x++;
      x--;
      while (actual->cur.object[x][y] != '*' && x != -1)
	x--;
      if (board[x + actual->row + 1][actual->col + y] != ' ')
	return (1);
      x = 0;
      y++;
    }
  return (0);
}

int	rm_full_line(char ***board, t_game *game)
{
  int	row;

  row = 0;
  while ((*board)[row] != NULL)
    {
      if (check_line_full((*board)[row], game) == 0)
	{
	  while (row > 0)
	    {
	      my_strcpy((*board)[row], (*board)[row - 1]);
	      row--;
	    }
	}
      row++;
    }
  return (0);
}

void	init_actual(t_actual *actual, t_tetrimino *tetri, t_game game)
{
  actual->cur = tetri[rand() % nb_tetri(tetri)];
  actual->next = tetri[rand() % nb_tetri(tetri)];
  actual->row = 0;
  actual->col = game.info.col * 3 / 2;
}

void	init_curse(t_game game, t_tetrimino *tetri)
{
  WINDOW	*win[5];
  t_actual	actual;
  char		**board;

  srand((unsigned int) time(NULL));
  initscr();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  init_all_win(win, game, tetri);
  init_actual(&actual, tetri, game);
  init_tab(game, &board);
  set_mode(0);
  while (1)
    {
      draw(win, game, actual);
      if (detect_end(board[0]) == 1 ||
	  handle_input(game_loop(game), &actual, board, &game) == 1)
	break;
      actualize_and_disp(actual, &board, win);
      check_collisions(&board, &actual, tetri, game);
      rm_full_line(&board, &game);
      usleep(200000);
    }
  set_mode(1);
  endwin();
}
