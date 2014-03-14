/*
** dumper_get_shdr_name.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 19:30:14 2014 raphael defreitas
** Last update Thu Mar 13 19:31:38 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdlib.h>

#include	"defines.h"
#include	"dumper.h"

const char *dumper_get_shdr_name(t_dumper *this, Elf64_Shdr *shdr)
{
  if (this->shdr_names == NULL && dumper_load_shdr_names(this) != RET_SUCCESS)
    return (NULL);
  return (this->shdr_names + shdr->sh_name);
}
