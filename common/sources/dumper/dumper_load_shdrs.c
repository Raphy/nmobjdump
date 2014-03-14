/*
** dumper_load_shdrs.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 18:52:58 2014 raphael defreitas
** Last update Thu Mar 13 19:49:30 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"defines.h"
#include	"dumper.h"
#include	"xfunctions.h"

int		dumper_load_shdrs(t_dumper *this)
{
  int		i;

  if (this->shdrs != NULL)
    return (RET_SUCCESS);
  this->shdrs = xmalloc(this->ehdr->e_shnum * this->ehdr->e_shentsize);
  if (dumper_fseek(this, this->ehdr->e_shoff) != RET_SUCCESS)
    return (RET_FAILURE);
  i = 0;
  while (i < this->ehdr->e_shnum)
    {
      this->shdrs[i] = xmalloc(this->ehdr->e_shentsize);
      if (dumper_fread(this, this->shdrs[i], 1, this->ehdr->e_shentsize) != 0)
	return (RET_FAILURE);
      i++;
    }
  this->shdrs[i] = NULL;
  return (RET_SUCCESS);
}
