/*
** dumper_get_shdr_by_index.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 19:17:40 2014 raphael defreitas
** Last update Sat Mar 15 19:38:24 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdlib.h>

#include	"defines.h"
#include	"dumper.h"

Elf64_Shdr	*dumper_get_shdr_by_index(t_dumper *this, int index)
{
  if (this->shdrs == NULL && dumper_load_shdrs(this) != RET_SUCCESS)
    return (NULL);
  if (index < 0 || index >= this->ehdr->e_shnum)
    return (NULL);
  return (this->shdrs[index]);
}
