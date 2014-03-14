/*
** dumper_ctor.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 18:09:30 2014 raphael defreitas
** Last update Fri Mar 14 02:43:13 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"defines.h"
#include	"dumper.h"

static void	set_default_values(t_dumper *this)
{
  this->filename = NULL;
  this->stream = NULL;
  this->ehdr = NULL;
  this->shdrs = NULL;
  this->syms = NULL;
  this->shdr_names = NULL;
  this->sym_names = NULL;
  this->symnum = 0;
}

int		dumper_ctor(t_dumper *this, const char *filename)
{
  set_default_values(this);
  if ((this->filename = strdup(filename)) == NULL)
    return (RET_FAILURE);
  if ((this->stream = fopen(filename, "r")) == NULL)
    {
      fprintf(stderr, "%s: No such file\n", filename);
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}
