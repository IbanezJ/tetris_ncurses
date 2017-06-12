/*
** tetris.h for PSU_2016_tetris in /home/rahman_m/Projet en cours/PSU_2016_tetris/include
**
** Made by Mathias Rahmani
** Login   <rahman_m@epitech.net>
**
** Started on  Tue Feb 21 18:02:30 2017 Mathias Rahmani
** Last update Sun Mar 19 23:30:51 2017 Jean-Alexandre IBANEZ
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#  include <stdio.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <string.h>
#  include <signal.h>
#  include <fcntl.h>
#  include <sys/types.h>
#  include <sys/stat.h>
#  include <time.h>
#  include <dirent.h>
#  include <curses.h>

typedef enum	e_keys
{
  keyleft, keyright, keyturn, keydrop, keypause, keyquit
}		t_keys;

typedef struct	s_debug
{
  char	*flag_1;
  char	*flag_2;
  int	(*func)();
}		t_debug;


typedef struct s_tetrimino
{
  int	width;
  int	height;
  int	color;
  char	**object;
}		t_tetrimino;

typedef struct	s_actual
{
  int		row;
  int		col;
  t_tetrimino	cur;
  t_tetrimino	next;
}		t_actual;

typedef struct	s_input
{
  char	key[6][256];
}		t_input;

typedef struct	s_info
{
  int	lines;
  int	score;
  int	level;
  int	row;
  int	col;
  int	debug;
  int	w_next;
}		t_info;

typedef struct	s_game
{
  t_input	input;
  t_info	info;
}		t_game;

/*
** puts.c
*/
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_put_nbr(int nb);
void	print_key(char *str);
int	print_help();

/*
** utils.c && utils2.c
*/
void	find_name(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_atoi(char *str);
char	*my_strdup(char *str);
int	str_equal(char *str);
int	my_strncmp(char *s1, char *s2, int nb);
char	*get_terminal(char **env);
int	is_nbr_only(char *str);

/*
** set_funcs.c && set_funcs2.c
*/
int	set_kl(t_game *game, char *arg);
int	set_kr(t_game *game, char *arg);
int	set_kd(t_game *game, char *arg);
int	set_kp(t_game *game, char *arg);
int	set_kt(t_game *game, char *arg);
int	set_kq(t_game *game, char *arg);
int	set_mapsize(t_game *game, char *arg);
int	set_level(t_game *game, char *arg);
int	set_next(t_game *game, char *arg);
int	set_debug(t_game *game, char *arg);

/*
** struct.c
*/
void	fill_struct(t_debug *dbg, int (*f)(), char *arg1, char *arg2);
t_debug	*init_struct();
void	parse_size_arg(char **nb1, char **nb2, char *str);
char	*parse_arg(char *str);

/*
** process.c
*/
int	dbg_check(char *str);
int	get_param(t_debug *dbg, char **av, t_game *game, int *i);
int	process_param(int ac, char **av, t_debug *dbg, t_game *game);
int	init_param(int ac, char **av, t_debug *dbg, t_game *game);
void	init_keys(t_game *game, char **env);

/*
** checks.c
*/
int	check_all_keys(t_game game);

/*
** set_term.c
*/
int	set_mode(int mode);
int	setup_terminal(char **env, int mode);

/*
** debug_display.c
*/
void	printc_debug_line(char *key_name, char *seq);
void	printi_debug_line(char *arg, int value);
void	display_dbg(t_game game);

/*
** check_tetri.c & check_tetri2.c
*/
int	bad_char(char *line);
int     is_it_only_num(char *line);
int     check_tetri(char *filepath);
int     check_spaces(char *line);
char	*bad_spaces(int fd);

/*
** error_hdl.c
*/
int     good_end(char *file_name);
int     no_disp_struct(t_tetrimino **tetris, struct dirent *dp);
int     check_value_nb(char **first_line);
int	full_struct(t_tetrimino **tetris, struct dirent *dp);
void	free_struct_tetri(t_tetrimino *tetris);

/*
** getnbr.c
*/
int	my_getnbr(char *str);

/*
** display_tetri.c
*/
int		count_dir(char *foldername);
char		*add_tetrimino(char *str);
t_tetrimino	full_case(char *filename);
int		full_tetri(t_tetrimino **tetris);

/*
** no_display.c
*/
int		no_display(t_tetrimino **tetris);

/*
** word_tab.c
*/
char    **put_in_tab(char *str, char search);
void	free_tab(char **tab);
void    disp_tab(char **tab);

/*
** my_printf.c
*/
void	my_printf(char *str, ...);

/*
** my_strcpy.c
*/
int     spaces_only(char *str);
char    *rm_space(char *str);
int     check_spaces_only(char *str);

/*
** hdl_input.c
*/
int    handle_input(int input, t_actual *actual, char **board, t_game *game);

int     col_tetri(t_actual *actual, char **board);

/*
** curses shit
*/
WINDOW	*title_win();
void	init_curse(t_game game, t_tetrimino *tetri);
WINDOW	*board_win(t_game game);

WINDOW  *level_win(t_game game);
WINDOW  *score_win(t_game game);
WINDOW  *next_win(t_tetrimino *tetris, t_game game);

int     game_loop(t_game game);
int	init_tab(t_game game, char ***board);
void	draw_tetrimino(t_actual actual, char ***board);
void	print_tab(WINDOW *win, char **board);
void	draw_next(t_tetrimino next, WINDOW *win);
void	clear_tetrimino(t_actual actual, char ***board);
void	init_pair_color();
void	draw_score(WINDOW *win, int score);
void	draw_level(WINDOW *win, int lines, int level);
void	draw(WINDOW **win, t_game game, t_actual actual);
int	check_line_full(char *line, t_game *game);
int	detect_end(char *str);
int	nb_tetri(t_tetrimino *tetris);
void	check_collisions(char ***board, t_actual *actual, t_tetrimino *tetri, t_game game);
int	init_tab(t_game game, char ***board);
void	print_tab(WINDOW *win, char **board);
void	init_all_win(WINDOW **win, t_game game, t_tetrimino *tetri);
void	actualize_and_disp(t_actual actual, char ***board, WINDOW **win);

#endif /* !TETRIS_H_ */
