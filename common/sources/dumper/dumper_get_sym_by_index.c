/*
** dumper_get_shdr_by_index.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 19:17:40 2014 raphael defreitas
** Last update Thu Mar 13 20:09:11 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdlib.h>

#include	"dumper.h"

Elf64_Sym	*dumper_get_sym_by_index(t_dumper *this, int index)
{
  if (index < 0 || index >= this->symnum)
    return (NULL);
  return (this->syms[index]);
}
