/*
** display_tetri.c for tetris in /home/ibanez_j/PSU_2016_tetris/srcs
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Wed Feb 22 15:21:48 2017 Jean-Alexandre IBANEZ
** Last update Sun Mar 19 18:44:12 2017 Mathias Rahmani
*/

#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include "get_next_line.h"
#include "tetris.h"

int	count_dir(char *foldername)
{
  int		compt;
  DIR		*dirp;
  struct dirent	*dp;

  compt = 0;
  if ((dirp = opendir(foldername)) == NULL)
    return (-1);
  while ((dp = readdir(dirp)) != NULL)
    {
      if (good_end(dp->d_name) == 0)
	compt++;
    }
  closedir(dirp);
  return (compt);
}

char	*add_tetrimino(char *str)
{
  char	*new;
  char	tetrimino[13];
  int	size_str;
  int	size_tetri;
  int	i;
  int	j;

  my_strcpy(tetrimino, "./tetriminos");
  j = 0;
  size_tetri = my_strlen("./tetriminos");
  size_str = my_strlen(str);
  if ((new = malloc(sizeof(char) * (size_tetri + size_str + 2))) == NULL)
    return (NULL);
  i = 0;
  while (tetrimino[i] != '\0')
    {
      new[i] = tetrimino[i];
      i++;
    }
  new[i] = '/';
  i++;
  while (str[j] != '\0')
    new[i++] = str[j++];
  new[i] = '\0';
  return (new);
}

char	**malloc_case(int i, int fd, char *filename, int nb_line)
{
  char	*line;
  char	**object;

  if ((object = malloc(sizeof(char*) * (i + 1))) == NULL)
    return (NULL);
  close(fd);
  line = get_next_line((fd = open(filename, O_RDONLY)));
  free(line);
  i = 0;
  while (i < nb_line && (line = get_next_line(fd)) != NULL)
    {
      object[i] = rm_space(line);
      i++;
      free(line);
    }
  object[i] = NULL;
  return (object);
}

t_tetrimino	full_case(char *filename)
{
  int		i;
  t_tetrimino	case_tetri;
  char	**file;
  int	fd;
  char	*line;

  i = 0;
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (case_tetri);
  file = put_in_tab((line = get_next_line(fd)), ' ');
  free(line);
  case_tetri.width = my_getnbr(file[0]);
  case_tetri.height = my_getnbr(file[1]);
  case_tetri.color = my_getnbr(file[2]);
  while ((line = get_next_line(fd)) != NULL)
    {
      i++;
      free(line);
    }
  case_tetri.object = malloc_case(i, fd, filename, case_tetri.height);
  free_tab(file);
  return (case_tetri);
}

int	full_tetri(t_tetrimino **tetris)
{
  int		compt;
  int		i;
  int		n;
  struct dirent	**dp;

  compt = -1;
  i = 0;
  if ((n = scandir("./tetriminos", &dp, 0, alphasort)) == -1)
    return (84);
  if (((*tetris) = malloc(sizeof(t_tetrimino) * (count_dir("./tetriminos") +
						 1))) == NULL)
    return (84);
  my_printf("Tetriminos : %d\n", count_dir("./tetriminos"));
  while (++compt < n)
    {
      if ((i = full_struct(tetris, dp[compt])) == -1)
	return (84);
    }
  (*tetris)[i].width = -1;
  (*tetris)[i].height = -1;
  (*tetris)[i].object = NULL;
  while (n--)
    free(dp[n]);
  free(dp);
  return (0);
}
