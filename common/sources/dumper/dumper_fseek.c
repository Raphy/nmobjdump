/*
** dumper_fseek.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 18:58:34 2014 raphael defreitas
** Last update Thu Mar 13 19:05:40 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"defines.h"
#include	"dumper.h"

int		dumper_fseek(t_dumper *this, long offset)
{
  if (fseek(this->stream, offset, SEEK_SET) == RET_ERROR)
    {
      fprintf(stderr, "File truncated\n");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}
