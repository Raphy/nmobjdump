/*
** dumper_get_shdr_by_name.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 19:17:40 2014 raphael defreitas
** Last update Thu Mar 13 19:43:31 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdlib.h>
#include	<string.h>

#include	"dumper.h"

Elf64_Shdr	*dumper_get_shdr_by_name(t_dumper *this, const char *name)
{
  int		i;
  Elf64_Shdr	*shdr;

  i = 0;
  while ((shdr = dumper_get_shdr_by_index(this, i)))
    {
      if (strcmp(dumper_get_shdr_name(this, shdr), name) == 0)
	return (shdr);
      i++;
    }
  return (NULL);
}
