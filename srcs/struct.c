/*
** struct.c for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/srcs
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Mon Feb 27 16:56:12 2017 Mathias Rahmani
** Last update Sun Mar 19 18:50:12 2017 Mathias Rahmani
*/

#include "tetris.h"

void	fill_struct(t_debug *dbg, int (*f)(), char *arg1, char *arg2)
{
  dbg->func = f;
  dbg->flag_1 = arg1;
  dbg->flag_2 = arg2;
}

int	help()
{
  return (1);
}

t_debug	*init_struct()
{
  t_debug	*dbg;

  if ((dbg = malloc(sizeof(*dbg) * 12)) == NULL)
    return (NULL);
  fill_struct(&dbg[0], set_level, "-l", "--level");
  fill_struct(&dbg[1], set_kl, "-kl", "--key-left");
  fill_struct(&dbg[2], set_kr, "-kr", "--key-right");
  fill_struct(&dbg[3], set_kt, "-kt", "--key-turn");
  fill_struct(&dbg[4], set_kd, "-kd", "--key-drop");
  fill_struct(&dbg[5], set_kq, "-kq", "--key-quit");
  fill_struct(&dbg[6], set_kp, "-kp", "--key-pause");
  fill_struct(&dbg[7], set_mapsize, "--map-size", "--map-size");
  fill_struct(&dbg[8], set_next, "-w", "--without-next");
  fill_struct(&dbg[9], set_debug, "-d", "--debug");
  fill_struct(&dbg[10], help, "--help", "--help");
  fill_struct(&dbg[11], NULL, NULL, NULL);
  return (dbg);
}

void	parse_size_arg(char **nb1, char **nb2, char *str)
{
  int	j;
  char	tmp[256];

  j = 0;
  while (*str != '=')
    str++;
  str++;
  while (*str != ',' && *str != '\0')
    {
      tmp[j] = *str;
      str++;
      j++;
    }
  str++;
  tmp[j] = '\0';
  *nb1 = my_strdup(tmp);
  j = 0;
  while (*str)
    {
      tmp[j] = *str;
      str++;
      j++;
    }
  tmp[j] = '\0';
  *nb2 = my_strdup(tmp);
}

char	*parse_arg(char *str)
{
  if (str_equal(str) == 1)
    return (str);
  while (*str && *str != '=')
    str++;
  str++;
  return (str);
}
