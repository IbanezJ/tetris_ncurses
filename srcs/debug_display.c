/*
** debug_display.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Mon Feb 27 17:49:14 2017 Mathias Rahmani
** Last update Sun Mar 19 18:43:50 2017 Mathias Rahmani
*/

#include "tetris.h"

void	printc_debug_line(char *key_name, char *seq)
{
  my_putstr(key_name);
  my_putstr(" : ");
  print_key(seq);
  my_putchar('\n');
}

void	printi_debug_line(char *arg, int value)
{
  my_putstr(arg);
  my_putstr(" : ");
  my_put_nbr(value);
  my_putchar('\n');
}

void	display_dbg(t_game game)
{
  printc_debug_line("Key Left", game.input.key[keyleft]);
  printc_debug_line("Key Right", game.input.key[keyright]);
  printc_debug_line("Key Turn", game.input.key[keyturn]);
  printc_debug_line("Key Drop", game.input.key[keydrop]);
  printc_debug_line("Key Quit", game.input.key[keyquit]);
  printc_debug_line("Key Pause", game.input.key[keypause]);
  my_putstr((game.info.w_next) ? "Next : Yes\n" : "Next : No\n");
  printi_debug_line("Level", game.info.level);
  my_putstr("Size : ");
  my_put_nbr(game.info.row);
  my_putchar('*');
  my_put_nbr(game.info.col);
  my_putchar('\n');
}
