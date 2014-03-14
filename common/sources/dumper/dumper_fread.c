/*
** dumper_fread.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 18:59:54 2014 raphael defreitas
** Last update Thu Mar 13 19:03:16 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"defines.h"
#include	"dumper.h"

int		dumper_fread(t_dumper *this, void *ptr, size_t s, size_t nm)
{
  size_t	ret;

  ret = fread(ptr, s, nm, this->stream);
  if ((s == 1 && ret < s * nm) || ret < 1)
    {
      fprintf(stderr, "File truncated\n");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}
