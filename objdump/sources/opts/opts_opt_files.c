/*
** opts_opt_files.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources/opts
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Mar 14 17:09:49 2014 raphael defreitas
** Last update Fri Mar 14 17:15:06 2014 raphael defreitas
*/

#include	"opts.h"

const char	**opts_opt_files(t_opts *this)
{
  return ((const char **)this->files);
}
