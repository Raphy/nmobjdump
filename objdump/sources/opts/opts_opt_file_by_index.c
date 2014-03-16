/*
** opts_opt_file_by_index.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources/opts
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Mar 14 17:29:49 2014 raphael defreitas
** Last update Fri Mar 14 17:31:37 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"opts.h"

const char	*opts_opt_file_by_index(t_opts *this, int index)
{
  return ((this->files) ? this->files[index] : NULL);
}
