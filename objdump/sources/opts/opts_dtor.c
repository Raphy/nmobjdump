/*
** opts_dtor.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources/opts
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Mar 14 16:59:13 2014 raphael defreitas
** Last update Fri Mar 14 17:08:58 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"opts.h"

void		opts_dtor(t_opts *this)
{
  int		i;

  i = 0;
  while (this->files && this->files[i])
    {
      free(this->files[i]);
      i++;
    }
  free(this->files);
}
