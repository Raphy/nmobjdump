/*
** dumper_get_syms.c for nmbojdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 20:06:33 2014 raphael defreitas
** Last update Thu Mar 13 20:07:30 2014 raphael defreitas
*/

#include	<elf.h>

#include	"dumper.h"

Elf64_Sym	**dumper_get_syms(t_dumper *this)
{
  return (this->syms);
}
