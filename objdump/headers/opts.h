/*
** opts.h for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Mar 14 02:50:55 2014 raphael defreitas
** Last update Fri Mar 14 17:32:44 2014 raphael defreitas
*/

#ifndef		OPTS_H_
# define	OPTS_H_

typedef	struct
{
  int		file_headers;
  int		full_contents;
  int		help;
  char		**files;
}		t_opts;

int		opts_ctor(t_opts *this, int ac, char **av);
void		opts_dtor(t_opts *this);
const char	**opts_opt_files(t_opts *this);
const char	*opts_opt_file_by_index(t_opts *this, int index);
int		opts_opt_file_headers(t_opts *this);
int		opts_opt_full_contents(t_opts *this);
int		opts_opt_help(t_opts *this);

#endif /* !OPTS_H_*/
