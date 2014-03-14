/*
** dumper_get_shdrs.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 19:16:35 2014 raphael defreitas
** Last update Thu Mar 13 19:17:22 2014 raphael defreitas
*/

#include	<elf.h>

#include	"dumper.h"

Elf64_Shdr	**dumper_get_shdrs(t_dumper *this)
{
  return (this->shdrs);
}
