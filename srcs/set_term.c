/*
** set_term.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Wed Mar 08 15:27:15 2017 Mathias Rahmani
** Last update Sun Mar 19 18:57:31 2017 Mathias Rahmani
*/

#include <termios.h>
#include <sys/ioctl.h>
#include "tetris.h"
#include <term.h>

int	setup_terminal(char **env, int mode)
{
  static struct termios	old;
  static struct termios	new;
  char			*term;

  if (env && (term = get_terminal(env)) == NULL)
    return (1);
  if (setupterm(term, 1, NULL) == -1)
    return (1);
  if (mode == 0)
    {
      ioctl(0, TCGETS, &new);
      ioctl(0, TCGETS, &old);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      ioctl(0, TCSETS, &new);
    }
  else if (mode == 1)
    ioctl(0, TCSETS, &old);
  return (0);
}

int	set_mode(int mode)
{
  static int		state = 0;
  static struct termios	old;
  struct termios	new;

  if (state == 0)
    {
      ioctl(0, TCGETS, &old);
      state = 1;
    }
  new = old;
  new.c_lflag &= ~ECHO;
  new.c_lflag &= ~ICANON;
  new.c_cc[VMIN] = 0;
  new.c_cc[VTIME] = 1;
  if (mode == 0)
    ioctl(0, TCSETS, &new);
  else if (mode == 1)
    ioctl(0, TCSETS, &old);
  return (0);
}
