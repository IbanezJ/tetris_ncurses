/*
** puts.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Mon Feb 27 17:12:34 2017 Mathias Rahmani
** Last update Sun Mar 19 18:48:09 2017 Mathias Rahmani
*/

#include "tetris.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb == 0)
    my_putchar('0');
  if (nb / 10)
    my_put_nbr(nb / 10);
  if (nb != 0)
    my_putchar(nb % 10 + '0');
  return (0);
}

void	print_key(char *str)
{
  while (*str)
    {
      if (*str == ' ')
	  my_putstr("(space)");
      else if (*str == 27)
	  my_putstr("^E");
      else
	my_putchar(*str);
      str++;
    }
}

int	print_help(char **av)
{
  my_putstr("Usage:\t");
  my_putstr(av[0]);
  my_putstr(" [options]\n");
  my_putstr("Options:\n   --help\t\tDisplay this help\n");
  my_putstr("   -l --level={num}\tStart Tetris at level num (def:  1)\n");
  my_putstr("   -kl --key-left={K}\tMove the tetrimino LEFT using the K key");
  my_putstr(" (def:  left arrow)\n   -kr --key-right={K}\t");
  my_putstr("Move the tetrimino RIGHT using the K key (def:  right arrow)\n");
  my_putstr("   -kt --key-turn={K}\tTURN the tetrimino clockwise 90d using ");
  my_putstr("the K key (def:  top arrow)\n   -kd --key-drop={K}\tDROP the ");
  my_putstr("tetrimino using the K key (def:  down arrow)\n   -kq --key-quit");
  my_putstr("={K}\tQUIT the game using the K key (def:  'Q' key)\n   -kp ");
  my_putstr("--key-pause={K}\tPAUSE/RESTART the game using the K key ");
  my_putstr("(def:  space bar)\n   --map-size={row,col}\tSet the numbers of ");
  my_putstr("rows and columns of the map (def:  20,10)\n   -w --without-next");
  my_putstr("\tHide next tetrimino (def:  false)\n   -d --debug\t\tDebug mod");
  my_putstr("e (def: false)\n");
  return (1);
}
