/*
** get_next_line.h for CPE_2016_getnextline in /home/rahman_m/Projet en cours/CPE_2016_getnextline
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Fri Jan 06 15:04:18 2017 Mathias Rahmani
** Last update Fri Jan 13 14:46:01 2017 Mathias Rahmani
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef READ_SIZE
#  define READ_SIZE 2
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);
char	process_buffer(int fd);

#endif /* !GET_NEXT_LINE_H_ */
