/*
** get_next_line.c for CPE_2016_getnextline in /home/rahman_m/Projet en cours/CPE_2016_getnextline
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Fri Jan 06 15:03:43 2017 Mathias Rahmani
** Last update Sun Mar 19 18:44:40 2017 Mathias Rahmani
*/

#include "get_next_line.h"

char	*my_realloc(char *str, int malloc_size)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = str;
  str = malloc(sizeof(char) * malloc_size);
  if (str == NULL)
    return (NULL);
  str[malloc_size - 1] = '\0';
  while (tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i++;
    }
  free(tmp);
  return (str);
}

char	process_buffer(int fd)
{
  static char	buffer[READ_SIZE];
  static int	readed_bytes = 0;
  static char	*buffer_ptr;
  char		to_return;

  if (readed_bytes == 0)
    {
      readed_bytes = read(fd, buffer, READ_SIZE);
      if (readed_bytes != 0)
	buffer_ptr = &buffer[0];
      else
	return ('\0');
    }
  to_return = *buffer_ptr;
  if (readed_bytes != 0)
    {
      buffer_ptr++;
      readed_bytes--;
    }
  return (to_return);
}

char	*get_next_line(const int fd)
{
  char	processed_char;
  int	i;
  char	*line;

  if (fd < 0)
    return ('\0');
  i = 0;
  if ((line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  line[READ_SIZE] = '\0';
  processed_char = process_buffer(fd);
  if (processed_char == 0)
    {
      free(line);
      return ('\0');
    }
  while (processed_char != '\0' && processed_char != '\n')
    {
      line[i++] = processed_char;
      processed_char = process_buffer(fd);
      if (i % READ_SIZE == 0)
	line = my_realloc(line, i + READ_SIZE + 1);
    }
  line[i] = '\0';
  return (line);
}
