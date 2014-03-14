/*
** dumper_dtor.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 18:14:40 2014 raphael defreitas
** Last update Thu Mar 13 20:51:01 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"dumper.h"

static void	free_shdrs(t_dumper *this)
{
  int		i;

  i = 0;
  while (this->shdrs && this->shdrs[i])
    {
      free(this->shdrs[i]);
      i++;
    }
  free(this->shdrs);
  free(this->shdr_names);
}

static void	free_syms(t_dumper *this)
{
  int		i;

  i = 0;
  while (this->syms && this->syms[i])
    {
      free(this->syms[i]);
      i++;
    }
  free(this->syms);
  free(this->sym_names);
}

void		dumper_dtor(t_dumper *this)
{
  free(this->filename);
  if (this->stream)
    fclose(this->stream);
  free(this->ehdr);
  free_shdrs(this);
  free_syms(this);
}
