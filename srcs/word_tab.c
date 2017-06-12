/*
** word_tab.c for tetris in /home/ibanez_j/PSU_2016_tetris/srcs
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Tue Feb 21 18:16:17 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:52:16 2017 Mathias Rahmani
*/

#include "tetris.h"

int	count_spaces(char *str, char search)
{
  int	compt;
  int	i;

  compt = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == search && (str[i + 1] != search && str[i + 1] != '\0'))
	compt++;
      i++;
    }
  return (compt);
}

char	**wordtab(char *str, char search)
{
  int	temp;
  int	compt;
  int	x;
  char	**tab;

  temp = 0;
  compt = 0;
  x = 0;
  if ((tab = malloc(sizeof(char*) * (count_spaces(str, search) + 2))) == NULL)
    return (NULL);
  while (str[x] != '\0')
    {
      while (str[x] != search && str[x] != '\0')
	{
	  compt++;
	  x++;
	}
      if ((tab[temp] = malloc(sizeof(char) * (compt + 1))) == NULL)
	return (NULL);
      tab[temp++][compt] = '\0';
      if (str[x] == search)
	x++;
      compt = 0;
    }
  return (tab);
}

char	**put_in_tab(char *str, char search)
{
  int	i;
  int	j;
  int	x;
  char	**tab;

  i = 0;
  j = 0;
  tab = wordtab(str, search);
  x = 0;
  while (str[x] != '\0')
    {
      while (str[x] != search && str[x] != '\0')
	{
	  if (i < count_spaces(str, search) + 1)
	    tab[i][j] = str[x];
	  x++;
	  j++;
	}
      j = 0;
      i++;
      if (str[x] == search)
	x++;
    }
  tab[count_spaces(str, search) + 1] = NULL;
  return (tab);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	disp_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_printf("%s\n", tab[i]);
      i++;
    }
}
