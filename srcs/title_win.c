/*
** title_win.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Thu Mar 09 15:43:18 2017 Mathias Rahmani
** Last update Sun Mar 19 18:50:59 2017 Mathias Rahmani
*/

#include "tetris.h"

void	disp_names(WINDOW *win)
{
  attron(A_BOLD);
  wprintw(win, "                    o |_  _ __  _  _     __ _ |");
  wprintw(win, "_ __  _ __  o \n");
  wprintw(win, "                    | |_)(_|| |(/_ /_    |");
  wprintw(win, " (_|| ||||(_|| | | \n");
}

WINDOW	*title_win()
{
  WINDOW	*win;

  win = newwin(10, 80, 0, 0);
  wprintw(win, " _________    _______       _________    ______");
  wprintw(win, "__      ___      ________      \n");
  wprintw(win, "|\\___   ___\\ |\\  ___ \\     |\\___   ___\\ |\\   _");
  wprintw(win, "_  \\    |\\  \\    |\\   ____\\     \n");
  wprintw(win, "\\|___ \\  \\_| \\ \\   __/|    \\|___ \\  \\_| \\ \\  \\|");
  wprintw(win, "\\  \\   \\ \\  \\   \\ \\  \\___|_    \n");
  wprintw(win, "     \\ \\  \\   \\ \\  \\_|/__       \\ \\  \\   \\ \\   ");
  wprintw(win, "_  _\\   \\ \\  \\   \\ \\_____  \\   \n");
  wprintw(win, "      \\ \\  \\   \\ \\  \\_|\\ \\       \\ \\  \\   \\ \\");
  wprintw(win, "  \\\\  \\|   \\ \\  \\   \\|____|\\  \\  \n");
  wprintw(win, "       \\ \\__\\   \\ \\_______\\       \\ \\__\\   \\ \\__");
  wprintw(win, "\\\\ _\\    \\ \\__\\    ____\\_\\  \\ \n");
  wprintw(win, "        \\|__|    \\|_______|        \\|__|    \\|__|\\|__|");
  wprintw(win, "    \\|__|   |\\_________\\\n");
  wprintw(win, "                                                          ");
  wprintw(win, "        \\|_________|\n");
  disp_names(win);
  wrefresh(win);
  return (win);
}
